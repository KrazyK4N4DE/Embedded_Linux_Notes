# I2C

## 硬件

![20230901133436](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230901133436.png)

- **一对多**。
- 有时钟线SCL，所以是**同步**通信。
- 只有一条线SDA，用于传输，所以为**异步、半双工**。

---

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

---

## SMBus协议

SMBus协议是I2C协议的一个子集，在I2C的基础上有更高的要求。

### 硬件上

- VDD极限值
  - I2C：范围广，甚至达12V
  - SMBus：1.8V ~ 5V
- 最小时钟频率、最大clock stretching
  - clock stretching即时钟延伸，某个设备需要更多时间来内部处理时，把SCL拉低一段时间占住I2C总线
  - I2C：都没有限制
  - SMBus：时钟频率最小值为10kHz，最大时钟延伸也有限制
- I2C设备接收到它的地址后，是否必须回应？
  - I2C：没有强制要求必须要发送回应信号
  - SMBus：必须要回应
- 数据传输格式
  - I2C：只定义了怎么传输数据，没有定义数据的格式
  - SMBus：定义了数据的格式

### 数据传输格式上

就如同CAN和CANopen一样，CAN只定义了怎么传输数据，没有定义数据的格式；而CANopen定义了数据的格式，如0x18n、0x38n就是表示发送的TPO，0x7nn就是心跳之类的。

SMBus定义的数据格式如下：

![20231015220210](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20231015220210.png)

### SMBus和I2C

- 因为很多设备都实现了SMBus，而不是更宽泛的I2C协议，所以**优先使用SMBus**。
- 即使I2C控制器没有实现SMBus，软件方面也是可以使用I2C协议来模拟SMBus

---

## I2C编程

Linux中，I2C系统有3个重要的结构体：

- 用结构体 `i2c_adapter` 表示I2C控制器。
  - `.nr`：表示第几个I2C控制器/第几条I2C总线
  - `.algorithm.master_xfer`：I2C控制器的传输函数
- 用结构体 `i2c_client` 表示I2C设备。
  - `.addr`：设备地址
  - `.i2c_adapter`：指向某一个I2C控制器，表示设备挂在这个I2C控制器下
- 用结构体 `i2c_msg` 表示传输的数据。
  - `.buf`：数据
  - `.len`：数据长度
  - `.addr`：设备地址
  - `.flags`：表示读还是写

核心的传输函数：

```C
int i2c_transfer(struct i2c_adapter*, struct i2c_msg*, int);
```

将i2c_adapter中的传输函数封装起来，且不需要i2c_client (因为i2c_msg中已经有设备地址)。

### 使用i2c工具访问AP3216C传感器

App访问硬件是必须需要驱动程序的，Linux内核提供了 `drivers/i2c/i2c-dev.c`，这是通用的I2C驱动程序，可以用于直接访问I2C控制器驱动程序。

![20231016110842](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20231016110842.png)

#### i2cdetect

如何查看板子上有多少个I2C控制器/总线？

```sh
i2cdetect -l
```

或

```sh
ls /dev/i2c-*
```

检测各个控制器上有哪些设备挂着：

```sh
i2cdetect -y <i2c_controller_number>
```

- `-y`：表示不需要提示
- `i2c_controller_number`：总线号

![20231016111626](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20231016111626.png) | ![20231016111744](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20231016111744.png)
--- | ---

`UU` 表示该地址上存在I2C设备，且在内核中已有驱动程序；不是UU而是为具体的地址值，如 `1e` 的话，表示设备存在，但没有驱动程序。

#### 访问设备

AP3216C是红外、光强、距离三合一传感器，经查询得知设备地址为0x1E，位于I2CBus0上。操作步骤如下：

1. 复位：往寄存器0写入0x4
2. 使能：往寄存器0写入0x3
3. 读光强：读寄存器0xC、0xD得到2字节的光强值
4. 读距离：读寄存器0xE、0xF得到2字节的距离值

**基于SMBus协议的操作**：

```sh
i2cset -f -y 0 0x1e 0 0x4
i2cset -f -y 0 0x1e 0 0x3
i2cget -f -y 0 0x1e 0xc w
i2cget -f -y 0 0x1e 0xe w
```

- `-f`：强制，对于已有驱动程序的设备，如果不使用这个参数则会操作失败。
- i2cset：写操作。
- i2cget：读操作。默认是读1个字节 (可以用 `b` 显示指定)，结尾加上 `w` 表示读双字节。

**基于I2C协议的操作**：

```sh
i2ctransfer -f -y 0 w2@0x1e 0 0x4
i2ctransfer -f -y 0 w2@0x1e 0 0x3
i2ctransfer -f -y 0 w1@0x1e 0xc r2
i2ctransfer -f -y 0 w1@0x1e 0xe r2
```

- 这里读操作也需要写，是因为要把地址0xc、0xe发给设备。

#### i2c工具的底层原理 (源码)

I2C方式：

![20231016124925](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20231016124925.png)

SMBus方式：

![smbustrans](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/smbustrans.png)
