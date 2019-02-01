### 6-1 Token概述

用户登录 -> API -> Token -> Client

### 6-2 获取Token令牌
```python
# token.py
def get_token():
    form = ClientForm().validate_for_api()
    promise = {
        ClientTypeEnum.USER_EMAIL:User.verify,
    }
    identity = promise[ClientTypeEnum(form.type.value)(
        form.account.data,
        fomr.secret.data
    )]
    expiration = current_app.congig['TOKEN_EXPIRATION']
    token = generate_auth_token(
        identity['uid'],
        form.type.data,
        identity['scope'],
        expiration
    )
    # 需要将bytes类型的字符串转换为普通的字符串
    t = {'token':token.decode('ascii)}
    return jsonify(t), 201

def gnerate_auth_token(uid, ac_type, scope=None, expiration=7200)
    s = Serializer(current_app.config['SECRET_KEY'],expries_in=expiration)
    return s.dumps({
        'uid':uid,
        'type':ac_type.value,
    })

```

### 6-3 Token的用处
token 开发时间的有效期可以是一个月，实际运行时的有效期一般是2小时
token用于验证身份和是否过期

### 6-4 @auth拦截器执行流程
在视图函数中添加拦截器
```python
# user.py
@api.route('', methods=['GET'])
# auth是在token_auth.py中进行实例化的
@auth.login_required
def get_user():
    return 'alex'
```
```python
# token_auth.py
from flask_httpauth import HTTPBasicAuth

auth = HTTPBasicAuth()

@auth.verifiy_password
def verifiy_password(account, password):
    return True
```
### 6-5 HTTPBasicAuth基本原理
在verify_password方法中获得的account和password参数为空，是因为要遵循HTTPBasicAuth的规则，需要在header中加入'basic base64(account:password)'，比如:
key=Authorization
value=basic base64(qiyue:123456)
base64是一种编解码规范，需要将qiyue:123456进行base64编码，然后得到的码再在header中进行HTTP传送

### 6-6 以BasicAuth的方式发送Token
利用postman直接发送BasicAuth的base64码

### 6-7 验证Token
```python
# token_auth.py
from flask_httpauth import HTTPBasicAuth

User = nametupled('User', ['uid', 'ac_type', 'scope'])
auth = HTTPBasicAuth()

@auth.verifiy_password
def verifiy_password(token, password):
    user_info = verify_auth_token(token)
    if not user_info:
        return Fales
    else:
        g.user = user_info
        return True

def verify_auth_token(token):
    s = Serializer(current_app.config['SECURT_KEY'])
    try:
        data = s.loads(token)
    # 遇到错误了，返回两种，一个不可用的token，一个是超时的token
    except BadSignature:
        raise AuthFailed(msg='token is invalid',
                         error_code)
    except SignatureExpired:
        raise AuthFailed(msg='token is expired',
                         error_code)
    uid = data['uid']
    ac_type = data['type']
    # 使用nametuple来实现返回结果
    return User(uid, ac_type, '')
```

### 6-8 重写first_or_404与get_or_404
在Query中重新定义get_or_404()和first_or_404()方法
```python
# 其中的NotFound是自己定义的异常类型
class Query(BaseQuery):
    def filter_by(self, **kwargs):
        if 'status' not in kwargs.keys():
            kwargs['status'] = 1
        return super(Auery, self).filter_by(**kwargs)

    def get_or_404(self, ident):
        rv = self.get(ident)
        if not rv:
            raise NotFound()
        return rv
    
    def first_or_404(self):
        rv = self.first()
        if not rv:
            raise NotFound()
        return rv
```
