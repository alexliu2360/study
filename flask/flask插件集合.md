## <span id="mulu">目录</span>
 
<a href="#flask_wtf">1.flask_wtf</a>  
<a href="#flask_socketio">2.flask_socketio</a>  
<a href="#flask_sqlalchemy">3.flask_sqlalchemy</a>  
<a href="#flask_httpauth">3.flask_httpauth</a>  

## <span id="flask_wtf">1. flask_wtf</span>  <a href="#mulu">[回到目录]</a>  

参考：<a href=" http://www.pythondoc.com/flask-sqlalchemy/index.html"> http://www.pythondoc.com/flask-sqlalchemy/index.html</a>

```python
from flask import Flask
from flask.ext.sqlalchemy import SQLAlchemy

app = Flask(__name__)
app.config['SQLALCHEMY_DATABASE_URI'] = 'sqlite:////tmp/test.db'
db = SQLAlchemy(app)


class User(db.Model):
    id = db.Column(db.Integer, primary_key=True)
    username = db.Column(db.String(80), unique=True)
    email = db.Column(db.String(120), unique=True)

    def __init__(self, username, email):
        self.username = username
        self.email = email

    def __repr__(self):
        return '<User %r>' % self.username
```

<!-- ![架构](./assets/flume-2agent.PNG) -->
<!-- <img src="./assets/flume-2agent.PNG" height="400" width="555" > -->

## <span id="flask_socketio">2. flask_socketio</span> <a href="#mulu">[回到目录]</a>    
    

### 架构


## <span id="flask_sqlalchemy">3. flask_sqlalchemy</span>  <a href="#mulu">[回到目录]</a>   

### 架构


## <span id="flask_httpauth">4. flask_httpauth</span>  <a href="#mulu">[回到目录]</a>   

### 架构
