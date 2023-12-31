# UART

通用异步收发传输器 (Universal Asynchronous Receiver and Transmitter)，简称**串口**。

串口的用途：

- 打印调试信息。
- 外接各种模块：GPS、蓝牙。

## 硬件

![20230831233135](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230831233135.png)

没有时钟、两条传输线，所以为**异步、全双工**通信。

### UART协议帧

![20230901000311](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901000311.png)

**默认空闲位为高电平。**

- 起始位：1位低电平。
- 数据位：5~8位，传输的位为1时输出高电平，为0时输出低电平。**先发低位后发高位**。
- 校验位：有奇校验和偶校验，保证 `数据位 + 校验位` 后**为1的位的个数**为奇/偶数。随着时代的进步，校验位已经可有可无了。
- 停止位：高电平，占据多少位可以自己规定，一般占1、1.5、2位。

图中的电平为**逻辑电平**，即具体电压要看实际的电路。

**TTL/CMOS逻辑电平**：

0~5V之间，超过x电压为逻辑1，低于y电压为逻辑0，x、y不定。

![20230901001645](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901001645.png)

**RS-232逻辑电平**：

-12~-3V表示逻辑1，3~12V表示逻辑0。

![20230901001746](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901001746.png)

- TTL/CMOS逻辑电平电压太小，相比于RS-232逻辑电平，不适合长距离传输。
- ARM开发板上一般为TTL/CMOS逻辑电平，PC机上一般为RS-232逻辑电平，两者连接需要一个电平转换芯片。现在电脑上很多都没有串口了，所以需要接USB转串口芯片。

### 收发数据

开发板如何将内存上的数据通过串口发送呢？

- 串口的结构上有**移位器**，能够实现数据的**串行收发**。
- 结构中还存在**FIFO模式的寄存器**，程序将内存的数据写入FIFO寄存器，然后就可以排队进入移位器了。

接收部分同样存在移位器和FIFO寄存器，接收原理是一样的。

如何知道数据收发完了呢？收发器使用**中断**。

---

## Linux串口编程

在Linux中，UART表现为设备文件，基于**TTY体系**。对于imx6ull，一般是 `/dev/ttymxcN` (N为数字)，其它的表示有：

- `/dev/tty`：当前程序使用的tty
- `/dev/tty0`：前台的程序的tty
- `/dev/ttyN`：分别对应不同程序的虚拟终端
- `/dev/console`：在内核的cmdline中可以指定一个terminal为console，若没有指定，则/dev/console就对应第1个串口

### TTY驱动程序框架

![20230901132152](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901132152.png)

- 应用程序可以使用**TTY**的统一接口，从而不用去区分设备是串口还是其它输入输出设备，就可以访问它们。
- **行规程** (Line discipline) 处于应用程序和驱动程序之间，负责处理输入与输出。
  - 应用程序可以通过 `ioctl()` 或其它封装好的函数，设置行规程。

### 编程思路

对于UART，编程的套路就是：

1. open()
2. **设置行规程**
   - 波特率
   - 数据位
   - 停止位
   - 校验位
   - RAW模式 (原始模式，让行规程不处理UART传来的数据)
   - 一有数据就返回 (默认情况下，行规成接收到数据先保存，输入回车后才传给应用程序，而外界模块时需要及时获取数据)
3. read() / write()

那么如何控制行规程呢？串口在Linux中被抽象成一个结构体 `termios` (terminal io system)：

![20231011231633](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20231011231633.png)

设置好flag之后，将结构体发给驱动程序。可以使用ioctl()来实现，但Linux在这之上封装了一些函数，更快捷一些：

函数名 | 作用
:--- | :---
tcgetattr | 获得终端的属性
tcsetattr | 修改终端参数
tcflush | 清空终端未完成的输入/输出请求及数据
cfsetispeed | 设置输入波特率
cfsetospeed | 设置输出波特率
cfsetspeed | 同时设置输入、输出波特率

(函数名中，tc表示terminal control，cf表示control flag)
