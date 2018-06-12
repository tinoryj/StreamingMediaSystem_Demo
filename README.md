#README 
系统级软件开发综合设计实验

## 申报表

### 题目: 
流媒体系统
### 题目难度等级: 
3
### 主要任务: 
使用面向对象程序设计技术，采用C＋＋语言，设计并实现一个功能较为复杂的流媒体系
### 详细功能描述:	
使用面向对象程序设计技术，设计一个流媒体系统，包括客户端和服务器，服务器存放视频数据，客户端采用流方式播放视频，最后使用C＋＋语言实现
### 预期成果/目标:
演示程序	
### 编程语言:
C++
### 相关专业课程:
计算机网络，多媒体技术	
### 对学生的要求
需要学生具有较强的学习新知识与技术的能力，学生最好参与完成过较复杂的课题
### 考核指标及方法;
程序演示与教师运行程序检查
增加功能难度加分

## 技术路线
### 环境
Linux/UNIX 
测试环境ubuntu16.04.4 LTS

### 基础传输协议

> [协议参考](https://www.cnblogs.com/jiaoxiangjie/p/6736656.html)

#### RTP
实时传输协议（Real-time Transport Protocol或简写RTP）
RTP 使用一个 偶数 UDP port.

RTP协议详细说明了在互联网上传递音频和视频的标准数据包格式。 

RTP为Internet上端到端的实时传输提供时间信息和流同步，但并不保证服务质量，服务质量由RTCP来提供。

#### RTCP
实时传输控制协议（Real-time Transport Control Protocol或RTP Control Protocol或简写RTCP）是实时传输协议（RTP）的一个姐妹协议。

RTCP为RTP媒体流提供信道外（out-of-band）控制。RTCP本身并不传输数据，但和RTP一起协作将多媒体数据打包和发送。RTCP定期在多媒体流会话参加者之间传输控制数据。

RTCP的主要功能是为RTP所提供的服务质量（Quality of Service）提供反馈。

RTCP收集相关媒体连接的统计信息，例如：传输字节数，传输分组数，丢失分组数，jitter，单向和双向网络延迟等等，网络应用程序即可利用RTCP的统计信息来控制传输的品质，比如当网络带宽高负载时限制信息流量或改用压缩比较小的编解码器。

RTCP 则使用 RTP 的下一个 port，也就是一个奇数 port。

#### RTSP
即时串流协定（Real Time Streaming Protocol，RTSP）是用来控制声音或影像的多媒体串流协议，并允许同时多个串流需求控制

允许同时多个串流需求控制（Multicast），除了可以降低服务器端的网络用量，更进而支持多方视讯会议（Video Conference）。 
因为与HTTP1.1的运作方式相似，所以代理服务器（Proxy）的缓冲功能（Cache）也同样适用于RTSP，并因RTSP具有重新导向功能，可视实际负载情况来转换提供服务的服务器，以避免过大的负载集中于同一服务器而造成延迟。

传输层：
传输时所用的网络通讯协定并不在其定义的范围内，服务器端可以自行选择使用TCP或UDP来传送串流内容，它的语法和运作跟HTTP 1.1类似，但并不特别强调时间同步，所以比较能容忍网络延迟。

#### 综合使用

* RTP: 一般用于多媒体数据的传输。
* RTCP: 同RTP一起用于数据传输的监视，控制功能。
* RTSP: 用于多媒体数据流的控制，如播放，暂停等。

RTP位于传输层（通常是UDP）之上，应用程序之下，实时语音、视频数据经过模数转换和压缩编码处理后，先送给RTP封装成为RTP数据单元，RTP数据单元被封装为UDP数据报，然后再向下递交给IP封装为IP数据包。这么说RTP是没有保证传输成功的，

用RTCP保证传输成功
RTCP消息含有已发送数据的丢包统计和网络拥塞等信息，服务器可以利用这些信息动态的改变传输速率，甚至改变净荷的类型。RTCP消息也被封装为UDP数据报进行传输。



### 客户端
#### GUI界面
基于Qt的图形化界面
![GUI](media/GUI.png)

##### 提供三个按钮:

* 播放/暂停
* 快进
* 快退

##### 提供一个搜索框:

用于填入所需获取的资源路径

##### 提供一个进度条:
用于拖拽播放指定位置

##### 提供一个音量调节slider
用于播放音量的控制

#### 功能
* 快进(前进5s)
* 快退(后退5s)
* 播放/暂停切换
* 进度条拖动
* 音量控制
* 获取server端的视频资源

### 后台

RTP/RTCP/RTSP支持



## update in 2018.5.3

change plan to HLS
