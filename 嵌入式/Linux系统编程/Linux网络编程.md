# Linux网络编程

![TCP_IP网络参考模型](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/TCP_IP网络参考模型.png)

## TCP编程

TCP协议的交互过程如下图所示：

![TCP交互过程](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/TCP交互过程.png)

### 服务器端 (server)

1. `socket()`：
   - 创建用于通信的结点，并返回结点的描述符。
   - 第二个参数：`SOCK_STREAM` 为TCP/IP协议，`SOCK_DGRAM` 为UDP协议。
   - 成功，返回一个套接字的描述符；失败，返回-1。
     - 该套接字用于与**监听与连接客户端的请求**。
2. `bind()`：
   - socket()返回描述符时，并没有源地址和端口也没有目标地址和端口，需要bind()将描述符与地址绑定起来。
   - 地址原本用结构体 `sockaddr` 表示，现用结构体 `sockaddr_in` 表示，相比前者信息更简洁。
   - 结构体大小一致，传参时强制转换就行。
   - `sockaddr_in` 中 (linux中用 `man 7 ip` 命令查询)：
     - `sin_family` 和 socket() 的协议域一致。
     - `sin_port` 为端口号，使用 `htons` 转换成网络字节序 (大端)。
     - `sin_addr.s_addr` 为IP地址，参数 `INADDR_ANY` 表示主机内所有IP。
3. `listen()`：
   - 监听数据。
   - 第二个参数：表示监听队列最多有多少路。
4. `accept()`：
   - 等待、建立一条连接，用来接受连接，一般放while里。
   - 第二个参数：建立连接的客户端地址，声明一个sockaddr来存放。
     - 收到的IP地址要通过 `inet_ntoa` 函数将网络字节序转换成IPv4字符串。
   - 成功，返回一个套接字的描述符；失败，返回-1。
     - 该套接字用于**与连接的客户端进行通信**。
5. 接收/发送数据：
   - 接收：`recv()`。
   - 发送：`send()`。
6. `close()`：关闭连接。

### 客户端 (client)

1. `socket()`。
2. `connect()`：
   - `sockaddr_in` 中，可以用 `inet_addr` 或 `inet_aton` 将指定要连接的IP地址字符串转化为网络字节序。
3. 接收/发送数据。
4. `close()`。

---

## UDP编程

UDP协议的交互过程如下图所示：

![UDP交互过程](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/UDP交互过程.png)

### 服务器端

1. `socket()`。
2. `bind()`。
3. 接收/发送数据：
   - 接收：`recvfrom()`，多了发送源的参数，声明一个sockaddr_in来存放。
   - 发送：`sendto()`，多了目的地的参数，声明一个sockaddr_in来存放。
4. `close()`。

### 客户端

1. `socket()`。
2. 设置 `sockaddr_in` 的目的端口号和IP地址，`connect()` 可有可无。
3. 接收/发送数据。
4. `close()`。

---

## 并发服务器模型

并发服务器模型一般就两种设计：

- 预先创建好多个进程、线程，时刻就绪等待多个客户端的请求。
  - 优点：响应及时。
  - 缺点：若请求没那么多，则会造成资源浪费；或是请求过多，则有一部分会先处于阻塞、排队状态，响应不及时。
- 并不预先派发多个进程线程，来一个客户端请求，创建一个进程或线程来处理。
  - 优点：不会造成系统资源浪费。
  - 缺点：响应及时性没那么好。
