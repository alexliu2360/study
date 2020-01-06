# -*- coding=utf8 -*-

from bs4 import BeautifulSoup


soup = BeautifulSoup(open('./zks.html'))
divs=soup.find_all('div', {'class':'module-title ng-binding'})
for div in divs:
    print(div['title'])
