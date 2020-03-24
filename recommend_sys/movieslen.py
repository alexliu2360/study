#!/usr/bin/env python
# coding: utf-8

# In[1]:


import pandas as pd
from sklearn.model_selection import train_test_split


# In[2]:


MOVIES_PATH = '../data/ml-1m/ml-1m/movies.dat'
RATINGS_PATH = '../data/ml-1m/ml-1m/ratings.dat'
USERS_PATH = '../data/ml-1m/ml-1m/users.dat'


# In[3]:


data_movies = pd.read_csv(MOVIES_PATH, sep='::',header=None,index_col=False,names=['movieId', 'title', 'genres'])
data_ratings = pd.read_csv(RATINGS_PATH, sep='::',header=None,index_col=False,names=['userId', 'movieId', 'rating', 'timestamp'])


# In[4]:


# 聚合
data = pd.merge(data_ratings, data_movies, on='movieId')


# In[9]:


rating_count_by_movie = data.groupby(['movieId', 'title'], as_index=False)['rating'].count()
rating_count_by_movie.head()


# In[7]:


rating_count_by_movie = data.groupby(['movieId', 'title'], as_index=False)['rating'].count()
rating_count_by_movie.columns=['movieId','title','rating_count']
rating_count_by_movie.sort_values(by=['rating_count'], ascending=False,inplace=True)


# In[8]:


rating_count_by_movie


# In[12]:


trainRatingsDF, testRatingsDF = train_test_split(data_ratings, test_size=0.2)


# In[13]:


trainRatingsDF.columns


# In[16]:


trainRatingsPivotDF = pd.pivot_table(trainRatingsDF[['userId','movieId','rating']],columns=['movieId'],index=['userId'],values='rating',fill_value=0)


# In[17]:


trainRatingsPivotDF


# In[18]:


moviesMap = dict(enumerate(list(trainRatingsPivotDF.columns)))
usersMap = dict(enumerate(list(trainRatingsPivotDF.index)))
ratingValues = trainRatingsPivotDF.values.tolist()


# In[ ]:




