### 5-1 重写WTForms 一
代码冗余
抛出异常不完备

### 5-2 重写WTForms 二
重写父类BaseForm
```python
from app.libs.error_code import ParameterException
class BaseForm():
    def __init__(self, data):
        super(BaseForm, self).__init__(data=data)
    
    def validate_for_api(self, ):
        valid = super(BaseForm, self)
        if not valid:
            raise ParameterException(msg=self.errors)
```

### 5-3 可以接受定义的复杂，但不能接受调用的复杂
定义的次数少，而调用次数多
```python
def create_client():
    # data = request.json # 代码中的data直接在ClientForm中通过request.json获取到
    # 直接将data赋给ClientForm中的关键字data，实例化form
    form = ClientForm().validate_for_api()
    promise = {
        ClientEnum.USER_EMAIL:__register_user_by_email,
    }
    # 在forms.py中赋值 self.type = client
    promise[form.type.data]()

    return Success()
```
这里的Success()类定义如下：
```python
class Success(APIException):
    msg = 'ok'
    error_code = 0
    code = 201
```

### 5-4 已知异常与未知异常
异常的抛出都是需要以json格式抛出的

### 5-5 全局异常处理
AOP思想
```python
@app.errorhandler(Exception):
def framework_error(e):
    if isinstance(e, APIException):
        return e
    if isinstance(e, HTTPException):
        code = e.code
        msg = e.description
        error_code = 1007
        return APIException(msg, code, error_code)
    else:
        # 调试模式
        # 可以加入log
        if not app.config['DEBUG']:
            # 生产环境下，直接返回以json格式的统一的错误
            return ServerError()
        else:
            # 调试模式下，直接返回一开始的底层错误，这样可以跟踪错误
            return e
```

