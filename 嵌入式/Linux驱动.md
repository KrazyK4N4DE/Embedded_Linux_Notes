# Linux驱动

应用程序调用 `open`、`read`、`write` 等函数，会进入到内核中，调用内核的`sys_open`、`sys_read`、`sys_write`等函数。驱动程序可以自己提供这些函数，这样，当应用程序使用 `open` 打开某个设备节点时，最终会调用驱动程序提供的 `sys_open` 函数 (read/write同理)。

以open函数为例，原型为：

```C
int open(const char *pathname, int flags, mod e_t mode);
```

APP打开文件时，可以得到一个整数，这个整数被称为文件句柄。对于APP的每一个文件句柄，在内核里面都有一个 `struct file` 与之对应。

![linux驱动open函数](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/linux驱动open函数.png)

**驱动程序的编写步骤**：

1. 确定主设备号，也可以传入0，让内核分配。
2. 定义自己的 `file_operations` 结构体。
3. 实现对应的 `drv_open` / `drv_read` / `drv_write` 等函数，填入结构体中。
4. 写一个**入口函数**：`xxx_init`，安装驱动程序时，就会去调用这个入口函数，随后把结构体告诉内核，注册驱动程序 (注册函数为 `register_chrdev`)。
5. 写一个**出口函数**：`xxx_exit`，卸载驱动程序时，调用出口函数，卸载驱动程序 (`unregister_chrdev`)。
6. 其他完善：
   - 提供设备信息：`class_create`
   - 自动创建设备节点：`device_create`
   - 将函数修饰为入口/出口函数：`module_init`、`module_exit`
   - 协议规定：`MODULE_LICENSE`

---

## 硬件基础——LED为例

如何成为点灯大师？

1. 看**电路原理图**确定控制LED的引脚。
2. 看芯片手册确定如何设置/控制引脚。
3. 写驱动程序。

![145752e8ec0e35b9dce374fbeaa89d5](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/145752e8ec0e35b9dce374fbeaa89d5.jpg)

![1c5b659c782ffd8ea3b14f726782bbc](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/1c5b659c782ffd8ea3b14f726782bbc.jpg)

总结：**主芯片引脚输出高电平/低电平，即可改变LED状态**。不用关心GPIO引脚输出的是3.3V还是1.2V。

- 输出1 → 高电平
- 输出0 → 低电平

---

## GPIO引脚的操作方法

GPIO：General purpose input/output，通用的输入输出口。

普遍的GPIO操作步骤：

**一切都是基于芯片手册，一定要会看！**

1. 使能GPIO模块：设置power/clock control
2. 设置GPIO引脚模式
3. 设置方向，是output还是input
4. 设置数据，为高电平/低电平

那么，如何实现这些操作呢？**读写寄存器**。

*寄存器的操作原则：不要影响到其它位！*

---

## IMX6ULL上的最简单的LED驱动程序

### IMX6ULL的GPIO操作方法

先看芯片手册，GPIO部分：

![20230816095336](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230816095336.png)

1. **使能GPIO模块**：CCM (Clock Controller Module，时钟控制模块)。设置其中的某一个寄存器，可以使能某一组GPIO。
2. **设置GPIO引脚模式**：IOMUXC (IOMUX Controller，IO复用控制器)。设置里面的寄存器来选择对应引脚的模式。对于每个引脚，有对应的两个寄存器：
   - `SW_MUX_CTL_PAD_*`：选择引脚功能，是用于GPIO还是其它。
   - `SW_PAD_CTL_PAD_*`：选择引脚是否使用上/下拉电阻、阻值多大等功能。
3. **设置方向**：设置 `GPIO.GDIR` 寄存器。
4. **输入/输出**：
   - 输出：值写到 `GPIO.DR` 寄存器中。
   - 输入：读 `GPIO.PSR` 寄存器。

*Tip：可能会遇到引脚接地的情况，这时无论设置 `GPIO.DR` 为多少都没效果。在pad settings中设置引脚的loopback功能，这样就可以从 `GPIO.PSR` 中读到引脚的真实电平。*

### IMX6ULL的寄存器查找

#### **先看电路原理图**。IMX6ULL的LED

![20230816144423](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230816144423.png)

可以看出，使用的是**GPIO5的第3个引脚**，引脚名为**SNVS_TAMPER3**。

- 引脚输出高电平，LED灭
- 引脚输出低电平，LED亮

#### **看芯片手册**。CCM部分：CCGR1[CG15]控制GPIO5的使能

![20230816145028](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230816145028.png)

可以看出，对于IMX6ULL，GPIO5默认使能，无需设置。

#### 找对应引脚的IOMUXC：IOMUXC_SNVS_SW_MUX_CTL_PAD_SNVS_TAMPER3

![20230816151443](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230816151443.png)

将最低4位改为101就可以设置位GPIO模式。

#### 设置方向

![20230816151857](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230816151857.png)

GPIO5的基地址查询得：0x020AC000，故GPIO5_GDIR地址：0x020AC004。再将GPIO5_GDIR的第3位设置为1，则第3个引脚就是输出引脚。

#### 设置输出电平

![20230816152559](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230816152559.png)

GPIO5_DR的地址为0x020AC000，其中第3位输出1就是高电平，0就是低电平。

### 写驱动程序

- 寄存器变量要使用 `volatile` 关键字，防止被编译器优化。
- 在Linux驱动程序里，不能直接使用寄存器的物理地址，要映射成虚拟地址。使用 `ioremap`，该函数是按页 (4096bytes) 映射的，返回该段虚拟地址的首地址。

#### ioremap的底层原理

若有一个程序可以打印地址，同时运行该程序2次时，打印结果是一样的。而同时运行2次哦，内存中有两份代码，它们的地址不同，为什么打印出的地址还是一样的？这是因为有**MMU** (Memory Manager Unit)，它的两大作用：

- **地址映射**：CPU发出同样的虚拟地址，执行不同的APP时，由MMU根据进程号不同，映射到不同的物理地址上。
- **权限保护**：一个程序崩溃时，其它程序不会崩溃，这是因为CPU发送的地址，需要MMU的审核之后才可以访问硬件。

ioremap就是通过MMU，将物理地址映射为虚拟地址。

---

## 驱动程序设计的思想

### 1. 面向对象

若每个板子都要重新写一遍，那代码复用率也太低了。故**通用的部分写在一个框架中**，针对不同开发板的具体的操作就单独写。**抽象出一个led_operations结构体**，每个单板自己实现，再由框架调用。

公共部分和单板部分编译成一个.ko文件 (使用Makefile实现)。

### 2. 分层

将驱动程序分成两层：

- 上层：实现硬件无关的操作的程序，比如注册字符设备驱动。
- 下层：实现硬件相关操作的程序，如单板映射寄存器地址并操作。

### 3. 分离

分层中的下层函数里面是固定的寄存器地址，那要是换一个引脚怎么办？重新写一个程序吗？

所以需要分离：

- 分离出**硬件通用代码**：引脚操作都是类似的，故对于某款芯片，可以写出一个**GPIO驱动程序**，让它支持所有GPIO操作。
- 分离出**资源**：再写另一个程序，定义要使用的引脚。

![20230823005742](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/20230823005742.png)
