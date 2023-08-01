# Qt

## Qt工程文件理解

QWidget：所有可视界面类的基类  
QMainWindow：主窗口  
QDialog：对话框弹出框

以类选择QWidget为例，进行文件讲解。

### .pro

`QT`：类库，以模块的形式添加，比如：

```sh
QT += core gui
QT += SQL
```

### widget.h

名称空间Ui里的Widget和class Widget不是同一个。

- .ui编译后会生成一个ui_widget.h，名称空间Ui里的Widget指的就是该.h中的Widget。
- 在这里声明名称空间只是表明除了定义的widget类，还要用到Ui里的Widget类。

### widget.cpp

成员初始化列表：

```c++
Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget)
```

setupUi函数就在ui_widget.h中。

### main.cpp

`a.exec()`：作用是开启一个循环，相当于while(1)，并检测当前应用程序a下是否有事件的发生，有就可以触发一系列动作。

---

## 程序发布

Debug的.exe太大了，改成Release再发布。

Release出来的.exe缺少库(.dll)，使用windeployqt工具：

```sh
windeployqt <dir_path>  # .exe文件所在的目录
```

这种.exe里面不含库的方式为动态链接。

### 设置.exe文件的图标

.ico放到源文件目录中，在工程文件.pro中加入代码：

```sh
RC_ICONS = xx.ico
```

### 对象树(QObject Trees)

比如一个窗体关闭了，其中的组件全都一起销毁(自动调用对应的析构函数)。所以Qt中一般只用写new。

### UI设计和纯代码设计的异同

- UI设计效率高，但是并不是无所不能，有的组件必须由代码实现。
- 优先UI设计，两者结合。

---

## 信号和槽

在初始的.h中有宏Q_OBJECT提供了信号与槽的服务。

- 信号：就是接收信号函数
- 槽：就是处理函数

**连接信号和槽需要connect函数。**  
connect函数若使用自己的槽可能要新建一个类，可以使用Lambda表达式避免这种情况，简化代码。

自定义的信号，要出发的话，使用 `emit`：

```C++
emit MySignal();
```

---

## 控件/组件

### 资源

添加Qt资源文件使用格式 `": + 前缀 + 文件名"`。

### 对话框 (各种Dialog)

- 模态：新对话框弹出后，其他对话框操作不了。
- 非模态：新对话框弹出后，其他对话框可以操作。

以下是Qt中8个标准对话框：

- 颜色对话框
- 文件对话框
- 字体对话框
- 输入对话框
- 消息对话框
- 进度对话框
- 错误消息对话框(其实常用消息对话框的错误对话框表示了)
- 向导对话框

### Item Views 和 Item Widgets

- 一个是 `Model-Based`，用于处理大量、复杂的数据，比如数据库。
- 另一个是 `Item-Based`，操作数据比较简单。

### Text Edit 和 Plain Text Edit

前者可以编辑字体排版，后者不能。

---

## 事件处理

分四步：**事件产生 → 事件过滤 → 事件分发 → 事件处理**

### QMouseEvent

#### 坐标函数和global坐标函数的区别

- `x()`、`y()`：对于当前窗体的x、y坐标(左上角为零点)。
- `globalX()`、`globalY()`：对于屏幕的x、y坐标(左上角为零点)。

#### button()和buttons()

- `button()`：返回**引起事件触发的按钮**，只能单个。
- `buttons()`：返回**事件触发时还处于按下状态的按钮**，是复合的(可以不止一个按钮)。

如，假设左键早已按住：  
若移动鼠标，会发生的move事件，button返回Qt::NoButton，buttons返回LeftButton。  
再按下右键，会发生press事件，button返回RightButton，buttons返回LeftButton|RightButton。

### 事件筛选处理

- 一般会用到 `this->type()`。
- 在结束后，一般会返回父类的默认event事件处理函数，这样除了被筛选的事件，其他事件都按正常处理，实现筛选。

---

## 绘图

`QPainterPath`类：相当于提供一个容器，存放绘制好的图形，方便复用。

- `QPixmap`：图片类，主要用于显示图片，显示前做了优化处理；window和linux平台下可能有区别；只能在主线程进行。
- `QImage`：图片类，不依赖于平台；可以多线程，故多用于图片传输；可做像素级修改。
- `QPicture`：可当作绘图的容器，保存有绘图的纪录和重绘制的指令；存储的形式是二进制。
- `QBitmap`：绘制出来和加载出来的图片会变成黑白的。

## 音视频

- `QMediaPlayer`；操作音频和视频的类。
- `QVideoWidget`：相当于容器，用来防止视频。

### 摄像头

- `QCamera`：用于打开摄像头设备
- `QCameraInfo`： 和摄像头有关的信息和属性
- `QCameraViewfinder`：用于显示摄像头捕获的画面
- `QCameraImageCapture`：用于摄像头截图

## 数据库

Qt中数据库模块分层：

![QtSQL模块分层](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/QtSQL%E6%A8%A1%E5%9D%97%E5%88%86%E5%B1%82.png)

- 驱动层：为具体要操作的数据库和SQL接口层提供桥梁，Qt自带对很多数据库的驱动程序。

`QsqlDatabase::addDatabase()` 的参数列表有**两个参数**的。

- 第一个是数据库驱动名，QString。是固定的，如 `QSQLITE`，`QMYSQL`。
- 第二个是连接名称，区别于数据库名，QString。默认为 `qt_sql_default_connection`。当程序需要处理多个数据库时，最好自定义连接不同的名称。

---

## 进程和线程

- 进程：程序和程序
- 线程：一个程序中多个同时操作

---

## 网络

### TCP

套接字：

- 监听：`QTcpServer`
- 通信：`QTcpSocket`

---

## QStringLiteral：更高效的字符串

Qt5中引入的QStringLiteral宏，相对于QString，可以在编译期把代码里的常量字符串str直接构造为QString对象，于是运行时就不再需要额外的构造开销了。
