<script type="text/javascript" async src="https://cdn.mathjax.org/mathjax/latest/MathJax.js?config=TeX-MML-AM_CHTML"> </script>

## <span id="mulu">目录</span>
<a href="#SSE">SSE</a>   
<a href="#SSR">SSR</a>    
<a href="#SST">SST</a>  
<a href="#MSE">MSE</a>  
<a href="#RMSE">RMSE</a>  
<a href="#R-square">R-square</a>

## <span id="SSE">1. SSE</span>  
<a href="#mulu">[回到目录]</a>  
- 定义：统计参数计算的是**预测数据**和**原始数据**对应点的误差的平方和
- 公式：$$SSE=\sum_{i=1}^{n}{(\hat{y} -{y})^2}$$
- 效果：SSE越接近于0，说明模型选择和拟合更好，数据预测也越成功。接下来的MSE和RMSE因为和SSE是同出一宗，所以效果一样

## <span id="SSR">2. SSR</span>  
<a href="#mulu">[回到目录]</a>  
- 定义：Sumof squares of the regression，即**预测数据**与**原始数据均值**之差的平方和
- 公式：$SSR=\frac{1}{M}\sum_{i=1}^{n}{(\hat{y} - \overline{y})^2}$
- 效果：

## <span id="SST">3. SST</span>  
<a href="#mulu">[回到目录]</a>  
- 定义：Totalsum of squares，即**均值**和原始数据之差的平方和
- 公式：$SST=\sum_{i=1}^{n}{({y} - \overline{y})^2}$
- 效果：

## <span id="MSE">4. MSE</span>  
<a href="#mulu">[回到目录]</a>  
- 定义：统计参数是预测数据和原始数据对应点误差的平方和的均值，也就是SSE/n，和SSE没有太大的区别
- 公式：$MSE=\frac{1}{M}\sum_{i=1}^{n}{(\hat{y} - {y})^2}$
- 效果：与SSE相似

## <span id="RMSE">5. RMSE</span>  
<a href="#mulu">[回到目录]</a>  
- 定义：统计参数是预测数据和原始数据对应点误差的平方和的均值，也就是SSE/n，和SSE没有太大的区别
- 公式：$RMSE=\sqrt{\frac{1}{M}\sum_{i=1}^{n}{(\hat{y} - {y})^2}}$
- 效果：与SSE相似

## <span id="R-square">6. R-square</span>  
<a href="#mulu">[回到目录]</a>  
- 定义：用于检测真实值与预测值之间的差距
- 公式：$R-square=\frac{SSR}{SST}=\frac{SST-SSE}{SST}=1-\frac{SSE}{SST}$
- 效果：$\frac{SSE}{SST}$被称为“确定系数”。“确定系数”是通过数据的变化来表征一个拟合的好坏。由上面的表达式可以知道“确定系数”的正常取值范围为[0 1]，越接近1，表明方程的变量对y的解释能力越强，这个模型对数据拟合的也较好

