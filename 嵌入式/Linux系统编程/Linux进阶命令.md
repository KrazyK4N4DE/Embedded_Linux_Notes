# Linux进阶命令

## Linux驱动

**安装驱动**：

```sh
insmod <kofile>
```

内核文件需要带.ko

**查看已安装的驱动和设备号**：

```sh
cat /proc/devices
```

**查看内核中已经加载的驱动程序**：

```sh
lsmod
```

**卸载驱动**：

```sh
rmmod <kofile>
```

文件不需要带.ko

**查看printk打印的信息**：

```sh
dmesg
```

**修改内核的打印级别**：

```sh
echo "7 4 1 7" > /proc/sys/kernel/printk
```
