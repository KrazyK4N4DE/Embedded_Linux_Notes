# I2C

## 硬件

![20230901133436](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901133436.png)

- **一对多**。
- 有时钟线SCL，所以是**同步**通信。
- 只有一条线SDA，用于传输，所以为**异步、半双工**。

## I2C协议帧

**写操作**：

![20230901144246](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901144246.png)

**读操作**：

![20230901144406](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901144406.png)

- 白色表示 `主 → 从`，灰色表示 `从 → 主`。
- 设备地址：用于确定往哪个芯片读/写数据。
- 方向：0表示写，1表示读。
- 数据传输**首先发送最高位 (MSB)**。
- 发送完地址+方向后，从芯片要发送1位ACK位；收到数据后，接收方也要发送ACK位。低电平表示回应。
- 开始位和结束位都是由主芯片发起。

### I2C位传输规则

![20230901152417](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901152417.png)

![20230901152602](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901152602.png)

- SCL为高电平时，才能读取SDA。SCL为低电平时，才允许SDA变化。
- SCL为高电平时，检测到**下降沿**，即为开始；检测到**上升沿**时，即为结束。
- 开始后，SCL从恒定高电平变为**脉冲时钟**，结束后再恢复原样。
- SCL高电平且SDA电平保持稳定时，SDA传输的数据才有效。

### I2C电路

可以注意到，SDA有时是主芯片驱动，有时是从芯片驱动。万一出现一方输出高电平、另一方出现低电平的情况，就会短路，电路烧坏！

于是，I2C采用以下电路：

![I2C电路](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/I2C电路.png)

只要有其中一方驱动MOS管，SDA就会被拉低为**低电平**。

|A OUT|B OUT|SDA|
|:-:|:-:|:-:|
|0|0|1|
|0|1|0|
|1|0|0|
|1|1|0|

SCL时钟线同理。
