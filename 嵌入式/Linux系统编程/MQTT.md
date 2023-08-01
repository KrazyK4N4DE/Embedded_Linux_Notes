# MQTT

适合用来传输较小的数据，适合物联网。

## 框架

![20230515223832](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230515223832.png)

手机或开发板这些设备可以是发布者或订阅者，AKA客户端。

上图关系可以用记者、电视台、观众来类比：  
![20230515224304](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230515224304.png)

电视台是MQTT中的服务器(broker)，记者和观众是客户端，可以发布新闻给电视台，也可以订阅电视台的消息。

## MQTT程序怎么写？

**应用层(APP)**：

```c++
while(1)
{
   wait_for_msg();  // 等待消息，可以使用MQTT/SSH/FTP
   deal();  // 处理消息
}
```

**协议层**：

MQTT / SSH / FTP

**驱动层**：

多线程 / Timer定时器 / 网卡收发

对于开发板的角色：

1. 先运行服务器
2. 客户端连接服务器connect
3. 订阅消息
4. while(1)
   - 读MQTT数据包(指定超时时间)
   - 处理收到的数据
   - 发出ping包，当作心跳，证明还在
