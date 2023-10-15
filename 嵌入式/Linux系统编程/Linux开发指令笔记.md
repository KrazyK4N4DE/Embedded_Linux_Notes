# Linux开发指令笔记

## vi/vim快捷键

- 向下翻页：`Ctrl+F`
- 向上翻页：`Ctrl+B`

---

## IMX6ULL开发板

### 开发板禁用IPv6

```sh
# 编辑sysctl.conf文件，没有就创建一个
vi /etc/sysctl.conf

# 添加如下命令禁用ipv6
net.ipv6.conf.all.disable_ipv6 = 1
net.ipv6.conf.default.disable_ipv6 = 1

#使配置立即生效，生效的话会显示上边的配置
sysctl -p /etc/sysctl.conf

#查看是否成功，输出1即禁用成功
cat /proc/sys/net/ipv6/conf/all/disable_ipv6
```

### 开发板tslib和Qt环境变量设置 (自用)

```sh
#tslib
export TSLIB_TSDEVICE=/dev/input/event1
export TSLIB_CONFFILE=/etc/ts.conf
export TSLIB_PLUGINDIR=/usr/lib/ts
export TSLIB_CONSOLEDEVICE=none
export TSLIB_FBDEVICE=/dev/fb0

#qt
export QT_QPA_PLATFORM=linuxfb:fb=/dev/fb0
export QT_QPA_FONTDIR=/usr/lib/fonts
export QT_QPA_GENERIC_PLUGINS=tslib:/dev/input/event1  # 加了这和下面那一条，使Qt可以触屏按钮，因为使用了Qt默认基于libinput插件
export QT_QPA_EVDEV_TOUCHSCREEN_PARAMETERS=/dev/input/event1
export QT_QPA_FB_TSLIB=1
export QT_QPA_EGLFS_TSLIB=1
```

注意触摸屏设备的event号和fb号，换了设备可能要更改。

### Qt交叉编译

### QStandardPaths: XDG_RUNTIME_DIR not set, defaulting to '/tmp/runtime-root'

不会影响程序的正常运行，但是要解决的话，在 `/etc/profile` 中加入：

```sh
export XDG_RUNTIME_DIR=/usr/lib/
export RUNLEVEL=3
```

#### qt.qpa.input: xkbcommon not available, not performing key mapping

可能跟QT_QPA_INPUT环境变量设置有关，或者跟xkbcommon有关。

### 时间设置

设置系统时间：

```sh
date -s <"YYYYY-MM-DD hh:mm:ss">
```

重启后系统时间还是会归回1970，为了解决这个问题，将系统时间写入到RTC设备中，使RTC时间和系统时间同步：

```sh
hwclock <cmd>
```

cmd中：

- `-s`：以硬件时钟为准，校正**系统时钟**。
- `-w`：以系统时钟为准，校正**硬件时钟**。

---

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

**修改内核的打印级别，能够在bash中看到内核打印信息**：

```sh
echo "7 4 1 7" > /proc/sys/kernel/printk
```

**手动创建设备节点**：

```sh
mknod /dev/xxx c <major> <minor>
```

- c：表示字符设备
- major：主设备号
- minor：次设备号
