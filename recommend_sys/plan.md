### 1. ITEnergy课程
#### 1.1. 推荐系统
- 2019小象-推荐系统项目就业班一期
- 2018七月在线推荐系统实战
- 2019黑马头条
- 慕课网个性化推荐算法实战
- 北风网 基于大数据技术推荐系统算法案例实战教程
- 极客时间-推荐系统三十六式
- AI慕课学院推荐系统算法工程师——从入门到就业

#### 1.2. 计算广告
- 七月-互联网计算广告实战
- 太阁 CS209 搜索广告平台实战训练营
  
### 2. 项目开发 
#### 2.1. 用于面试的项目准备
- webMNT项目
  - 鱼书
  - flask/redis/celery/flower/supervisor
- sherlock智能运维项目
  - AI智能运维比赛 基于kpi数据的挖掘/网络异常自动识别
  - 黑客松比赛
- 中开设的技术论坛文章猜你喜欢
  - movieslens推荐系统（demo）
    - 熟悉基本推荐算法的推导及实现
    - 熟悉每个算法的使用场景及优缺点
  - netflix推荐大赛
  - 天池安泰杯跨境电商智能算法大赛
  - 黑马头条推荐系统
    - 将课程中的所有算法基本掌握
    - 将课程中的所有推荐模型、工程都可以完整复现
  - 蜡炬教育推荐系统
  - 开课吧大数据课程 新闻头条推荐系统实战案例

#### 2.2. 刷题
- 刷题网站
  - 牛客网
  - leetcode
  - sofasofa
- 书籍
  - 百面机器学习
  - 美团机器学习实践
  
#### 2.3. 需要准备的知识点
- 语言
  - java c++
  - python
  - scala
  - js
- 数据结构与算法
  
#### 2.4. 知识点
- 环境配置
  - hadoop
  - mapreduce
  - yarn
  - zookeeper
  - spark
  - flume
  - sqoop
  - hive
  - hbase
- 工程知识点
  - sqoop
    - Sqoop导入工具的测试
    - Sqoop数据导入的增量导入形式
  - 用户行为收集
    - 收集用户日志形式、流程
    - flume收集相关配置、hive相关配置
    - supervisor开启flume收集进程管理
  - 文章画像的计算和构建
  - 增量更新代码过程
  - Apscheduler定时更新工具使用
    - Super进程管理与Apscheduler完成定时文章画像更新
  - 用户画像
    - 用户画像建立的流程
    - 用户行为日志的处理过程
    - 用户画像的HBase存储与Hive关联
  - 排序
    - 常见CTR中特征处理方式
    - 常见点击率预测的种类和模型
    - 文章CTR预估主要作用
  - 实时计算
    - 实时计算的业务需求
    - 实时计算的作用
  - 实时推荐
    - grpc对接
    - ABTest分流
    - 推荐中心服务
    - 返回推荐结果和埋点参数封装
- 算法知识点
  - spark tfidf以及TextRank计算工具使用
  - 文章向量计算方式
  - Word2Vec模型原理
  - 文章相似度计算方式
  - Spark完成文章相似度计算
  - 用户画像标签权重的计算公式
  - 召回排序作用
  - 排序模型
    - LR模型、FTRL、Wide&Deep
  - 召回
    - 基于模型协同过滤推荐离线召回：ALS
    - 基于内容的离线召回
  - 

#### 2.5. 黑马头条推荐系统介绍笔记
- mapreduce
  - hadoop streaming  脚本串行化 类似于面向过程
  - mrjob 类似于面向对象的编程  
    ```python
    from mrjob.job import MRJob.MRStep 
    import heapq

    class TopN(MrJob):
        def mapper(self):
            pass
        def container(self, word, count):
            pass
        def 
    ```
  - MRJOB文件合并
  - Mapreduce慢的原因
    - 数据处理的时候频繁的在磁盘和内存中进行数据IO，而不是在内存中进行处理，导致速度比较慢
    - buffer in memory：达到80%数据时，将数据所在内存上，将这部分输出到磁盘上
  - mapreduce架构演变
    - 1.x的时候
      - jobTracker master 计算集群管理
      - TaskTracker slave 负责具体任务执行
      - Task Schedule 作业调度
    - 2.x yarn出现 作业的调度交给yarn处理
      - Mapreduce只是进行具体任务执行
  - hadoop生态系统
    - HDFS(Hadoop分布式存储系统)
    - YARN(相当于Map Reduce)
    - hive(sql query)
    - R Connectors(stactistics)
    - Mahout(machine learning)
    - Pig(scripting)
    - Oozie(workflow)
    - Hbase(Columnar Store 列存储 基于HDFS) happybase
    - Zookeeper(coordination master节点选举) kazoo
    - Flume(Log Collector)
    - Sqoop(Data Exchange mysql/oracle和hdfs/hbase之间的数据交换)
    - Spark 分布式的计算框架基于内存(基于scala)  pyspark
      - spark core -> mapreduce
      - spark sql -> hive
      - spark streaming 
      - spark ML spark MLlib
    - Kafka(MQ 消息队列) 
    - Storm 分布式的流式计算框架 不适合python操作
    - Flink 分布式计算框架 python操作storm
  - hadoop发行版本选择
    - cdh5.7.0  Cloudera Distributed Hadoop
    - 只要cdh版本一致，各个组件不会有兼容性问题
    - cdh版本的组件并没有全部开源
    - hadoop-2.6.0-cdh-5.7.0和flume-cdh-5.7.0

### 3. 常见推荐算法面试题
- 请详细说说协同过滤的原理  
- 搜索和推荐中的精度和召回(recall)分别是什么意思？
- 推荐系统有哪些常用的评价标准
- 请详细聊聊推荐系统里的排序算法
- 怎么解决推荐系统中的冷启动问题？
- 请聊聊你所了解的推荐系统算法
- 了解隐语义模型在推荐系统中的应用的么？
- 如何通俗理解奇异值分解
- 请通俗的解释下什么叫张量分解？
- 请说说隐语义模型 LFM 背后的原理
- 请详细说说你对 Learning to rank 的通俗理解
- 简述推荐系统的演进史
- 推荐系统评估(从用户\内容提供方\网站角度)
- 推荐系统常用评估指标
- 推荐系统准确性(学术界)的评估函数
- 推荐系统多样性&新颖性&惊喜性
- 解释 Exploitation & Exploration
- Bandit 算法-原理
- 什么是多层重叠试验框架?
- 预训练方法 BERT 和 OpenAI GPT 有什么区别？
- 对比 BERT、 OpenAI GPT、 ELMo 预训练模型架构间差异
- GCN 方法分为哪两类？
- 什么是图卷积神经网络？
- 如何理解图卷积算法？
- GCN 有哪些特征？
- 已知基于数据驱动的机器学习和优化技术在单场景内的 A/B
- 额、单价都取得了不错的效果。 但是，目前各个场景之
- 哪些比较严重的问题 ？
- 什么是多场景联合排序算法 ？
- IRGAN 框架具体是什么？
- 推荐页与搜索页特性有什么不同？
- 推荐系统常用的评价指标有哪些？
- 请画出点击率预估流程图，分为那两部分？
- 使用 FFM 有哪些需要注意的地方
- 什么是 DSSM?有什么优缺点？
- 什么是 wide&deep 模型？
- Join training 和 ensemble training 有什么区别？
- 简述 DeepFM 模型？
- Collaborative Knowledge Base Embedding使用哪三种知识的学习？
- 怎样将知识图谱引入推荐系统 ？
- 普通的逻辑回归能否用于大规模的广告点击率预估 ，为什么？
- FTRL 在准备训练数据（特征工程）和训练模型时有哪些 trick ？
- 阿里最新开源的 X-Deep Learning 为 Online Learning 提供了哪些解决方案？
- 特征交叉(特征组合)方式有哪些?
- 特征选择的方法有哪些?
- 简述 Multi-task learning(MLT)多任务学习
- 如何离线评价召回阶段各种模型算法的好坏？由于没有明确的
- 还是 auc 都不知道该怎么做？

  






### 3. 中开设论坛帖子分类
大类：
云计算 大数据 人工智能 物联网 智能制造 智慧家庭 能源互联网 大视频 创新研习社 虚拟化技术 软件技术 测试 UX 开源 安全
无线性能 算法 EDA 可靠性 结构技术 现场工艺 材料技术 时钟 电信平台 中兴新支点 软件定义网络 制造质量平台 DevOps
操作系统 存储技术 SQL&NOSQL 自动化集成 领导力 硬件精益 度量 质量 需求 产品级敏捷 教练组 项目管理 终端供应链
Scrum Master 能力发展 HPPD2.0 U型理论 外联内通 新员工园地 培训有话说 Linux云桌面 站务管理 意见反馈 功能发布

|大类|频道(channel)|
| ----- | --------- |
|云计算|云操作系统 NFV&APP 网络技术 MANO 存储技术 服务器技术 PaaS/SaaS/微服务 高可用软件 OpenStack社区 建设运维 iVLM 云计算资讯|
|大数据|资讯 技术讨论|
|人工智能| 资讯技术 讨论AI 达人秀 |
|物联网| 资讯市场 需求与技术合作 综合解决方案 硬件 软件 技术讨论 |
|智能制造| 生产云 生产自动化 工艺研究 产品导入 Devops 技术COP |
|智慧家庭| 商业模式 用户痛点 产品经理圈 创意大讨论 资料分享 活动专题 产品解剖 版务&建议 |
|能源互联网| 资料 自由讨论 |
|大视频| 资讯 技术讨论 |
|创新研习社| 创新研习社 创新读书会 创意广场 创新资讯 黑客松 |
|虚拟化技术| 通用技术 边缘计算 云管 PaaS 运维监控 专家大讲堂 能力竞技场 敏捷实践 经典实践 管理提升 |
|软件技术| 架构&设计 高级设计培训专题 编程&开发 研发工具链 软件能力 开源网络技术 秀酷(show code) 数据库 客户端技术 面向未来增值业务架构 终端技术 DPDK 架构&设计大赛 代码重构PK大赛 内源组件大赛 DDD 技术微刊 |
|测试| 测试设计 自动化测试 流程与探索性测试 性能测试 云测试 测试 活动工具终端测试 最佳实践 渗透性测试 |
|UX| 产品运营 设计思维 用户研究 交互设计 视觉设计 前端开发 最佳实践 |
|开源| 开源 GPL研发治理 外源社区参与&建设 开源地图 扫描工具 开源法律 |
|安全| 安全资讯 技术讨论 实践分享 |
|无线性能| 自由讨论区 资料空间 西行游记 技术专题 工具、可服与运维 |
|算法| 技术问答 业界资讯 精华分享 |
|EDA| 互连设计 仿真测试 降成本设计 EDA库设计 工具开发 基础管理 技术支持 |
|可靠性| 分答 可靠性管理 共创项目 对外合作 系统可靠性 EMC和防雷 材料及工艺可靠性 热设计 环境可靠性 安规认证 环保技术 |
|结构技术| 结构设计技术 工业设计 热设计 结构材料&加工技术 线缆&连接器技术 结构MBD与数字化工厂 精益设计 云T&能源结构技术 |
|现场工艺| 信息发布 工艺交流 设备工艺 典型案例 |
|材料技术| 材料知识 材料质量 材料沙龙 材料实验技术 材料分析案例 |
|时钟| 同步技术 时钟方案 时钟材料 时钟测试 |
|电信平台| 虚拟化技术 以太网与交换技术 媒体面技术 刀片与带外管理 外场巡检与运维 平台硬件频道 |
|中兴新支点| 电信级服务器 操作系统 桌面操作系统 高可用集群 嵌入式操作系统 |
|软件定义网络| SDN OpenDayLight ONOS OpenCORD P4 DevOps实践 |
|制造质量平台| 业务能力 管控能力 质量技术能力 流程能力 产品质量 |
|DevOps| DevOps工具链介绍 DevOps实践 外联内通 DevOps共创 硬件开发工具 结构开发工具 |
|操作系统| 编译器技术 调试器技术 嵌入式技术 虚拟化 服务器操作系统 AI技术 linux内核 桌面操作系统 调测工具 容器技术 安全技术 智能终端技术 理论 • 前沿 操作系统架构设计 |
|存储技术| 分布式文件系统 分布式块存储 关系数据库 NOSQL技术 新型非易失存储器 存储体系结构与生态链 用户态存储网络协议栈 |
|SQL&NOSQL| RDB PostgreSQL DCACHE5 REDIS 行业动态 |
|自动化集成| 集成交付 TaaS 组网 NFV集成 |
|领导力| 金字塔 管理技能 影响力 OKR试点 对话 经典案例 |
|硬件精益| 精益教练认证 硬件技术 工具共享 精益管理 材料空间 电源 |
|度量| 度量COP动态 度量教程 度量案例 度量问答 趣味度量 终端度量 度量专题探索 |
|质量| 公司质量 无线代码工具 无线质量策划 无线质量创新 无线质量大事记&观察 终端实践出真知 终端藏宝阁 终端质量会客室 有线质量 政能质量 |
|需求| 需求能力提升 需求流程优化 需求管理工具 需求挖掘&分析 实例化需求 活动&公告 需求质量 |
|产品级敏捷| 模型、流程、方法 案例地图&实践 持续产品规划 产品交付 产品文档 工具 终端产品 活动&公告 |
|教练组| 公司级教练CoP&教练组 教练评聘 南京地区教练CoP 深圳地区教练CoP 上海地区教练CoP 西安地区教练CoP 成都地区教练CoP 教练能力中心 无线院教练组(存档) 《前沿》 |
|项目管理| 项目管理 |
|终端供应链| 业务流程与系统 计划交付端到端 终端制造 采购园地 社区公告 |
|Scrum Master| SM能力探讨 问题诊所 最佳实践 资源 行动教练 |
|能力发展| 岗位管理 能力提升 |
|HPPD2.0| 总体组 软件过程改进 组件化开发 |
|U型理论| 理论资料 实践心得 |
|外联内通| 外部大会/公开课信息 线上/下活动总结贴 课程信息共享 CoC公告 |
|新员工园地| 新人风采 成长点滴 技术之路 |
|培训有话说| 培训制度 培训资讯 荣誉殿堂 |
|Linux云桌面| 自研Linux云桌面支持 IT系统Linux化 |
|站务管理| 站务公告 版主园地 专刊 |
|意见反馈| 需求提交  问题反馈 | 
|功能发布| 功能发布 |


### 4. 用户画像
|属性|画像内容|使用方法|
|--|--|--|
|文章|大类 频道 关键词 主题词 |tf-idf textrank |
|用户|入职时间 兴趣 点击量|

