# SPI

## 硬件

![20230901201113](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901201113.png)

- **一对多**，有片选引脚 `CS`，连多少个从设备就需要多少条片选信号线。**片选引脚同一时刻只能有一个有效**。
- 有时钟线 `SCK`，所以为**同步**通信。
- 数据传输为**异步、全双工**。
  - `MOSI/DO`：主输出，从输入。
  - `MISO/DI`：从输出，主输入。

---

## 数据传输

CS拉到**低电平**的阶段表示在传输数据。DO/DI**首先发送最高位 (MSB)**。

设置SCK的极性 `CPOL` 和相位 `CPHA` 得到SPI的四种工作模式：

|CPOL|CPHA|模式|说明|
|:-:|:-:|:-:|:-:|
|0|0|0|SCK初始为低电平，在第一个跳变边沿采样数据|
|0|1|1|SCK初始为低电平，在第二个跳变边沿采样数据|
|1|0|2|SCK初始为高电平，在第一个跳变边沿采样数据|
|1|1|3|SCK初始为高电平，在第二个跳变边沿采样数据|

如 CPOL = 1, CPHA = 1时：

![20230901210051](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901210051.png)

---

## SPI控制器内部结构

![20230901210555](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901210555.png)

- Control Register：控制寄存器。可设置CPOL和CPHA。
- Status Register：状态寄存器。可用来分辨数据是否传输完毕，也可用来使能中断。
- Baud Rate Register：波特率寄存器。设置波特率。
- Data Register：数据寄存器。发送数据时写入该寄存器；接收数据时读该寄存器。
