# CMake

跨平台的自动生成Makefile的工具。**只要生成了Makefile，cmake就构建成功了。**
![CMake工作流程](https://image-hosting-1313474851.cos.ap-shanghai.myqcloud.com/Notes/CMake工作流程.png)

- 在CMakeLists.txt中加入 `cmake_minimum_required(VERSION 3.10)` 避免警告。
- CMake中变量的调用/取值在参数列表中要加 `${}`。
- **CMake自带的全局变量**：
  - `${CMAKE_CURRENT_SOURCE_DIR}`：当前文件路径。
  - `${CMAKE_INSTALL_PREFIX}`：安装路径，默认值为/usr/local/。
  - `${PROJECT_NAME}`：项目名。
  - `${PROJECT_BINARY_DIR}`：工程/项目编译路径。
  - `${PROJECT_SOURCE_DIR}`：工程/项目路径。
  - `${EXECUTABLE_OUT_PATH}`：可执行文件输出到的路径。

## 语法

### PROJECT

指定工程名字，默认支持所有语言。

```sh
PROJECT(<projectname>)
PROJECT(HELLO C CXX)  # 指定工程名字为HELLO，支持语言C、C++
```

- PROJECT隐式定义了两个CMake变量：`<projectname>_BINARY_DIR` 和 `<projectname>_SOURCE_DIR`，都指向当前目录。
- 由于改了工程名，这两变量也会改变，所以CMake预定义了两个变量 `PROJECT_BINARY_DIR` 和 `PROJECT_SOURCE_DIR` 来代替这俩。

### ADD_EXECUTABLE

生成可执行文件。

```sh
ADD_EXECUTABLE(<targetname> ./main.cpp)  # 第一个参数为可执行文件名，第二个参数为对应的源文件
```

**Tip：编译文件于源文件分离 (外部构建)**
CMake编译后的文件和源文件放在一起很混乱。解决办法是新建一个build目录 (CMakeLists.txt不用放进去)，进入目录执行 `cmake ../`，编译后再执行 `make`，这样生成的构建文件以及可执行文件都在build目录下了。
外部构建的两个变量： `<projectname>_BINARY_DIR` 指向编译路径，即./build/里；`<projectname>_SOURCE_DIR` 指向工程路径，即./。
构建后效果如下：

```bash
.  
├── build  
│   ├── CMakeCache.txt  
│   ├── CMakeFiles  
│   ├── cmake_install.cmake  
│   ├── hello  
│   └── Makefile  
├── CMakeLists.txt  
└── main.cpp
```

### SET

定义变量。

#### 一般变量

```sh
SET(SRC_LIST main.cpp)  # 指定SRC_LIST变量包含main.cpp
SET(SRC_LIST main.cpp hello.cpp)  # SRC_LIST变量包含多文件
ADD_EXECUTABLE(hello ${SRC_LIST})  # 在ADD_EXECUTABLE中引用变量，使代码整洁
```

父级的SET变量是可以在子CMakeLists.txt里获取的，反之及同级就无法获取。可以加上参数 `PARENT_SCOPE`，向上传递变量：

```sh
SET(SRC_LIST main.cpp PARENT_SCOPE)
```

#### 缓存变量

使变量成为全局变量。

```sh
SET(<var> <value1> [value2, value2 ..] CACHE <type> <description> [FORCE])
```

- `CACHE`：将变量缓存到CMake缓存中，从而将其变为全局变量。
- `type`：决定变量的类型。
  - `BOOL`：ON或OFF
  - `FILEPATH`：文件的全路径
  - `PATH`：目录路径
  - `STRING`：字符串
  - `INTERNAL`：字符串
- `description`：对缓存变量的描述
- `FORCE`：强制修改变量值，用于调用SET变量名相同且想覆盖时。

### MESSAGE

向终端输出用户自定义信息，类似于std::cout。

```sh
MESSAGE(STATUS "This is BINARY dir: ${HELLO_BINARY_DIR}")
```

- `SEND_ERROR`：报错误信息，不终止CMake构建过程。
- `STATUS`：普通输出信息。
- `FATAL_ERROR`：报错误信息，终止CMake构建过程。

### ADD_SUBDIRECTORY

向当前共工程添加存放源文件的子目录，告诉CMake还有其它子目录的CMakeLists.txt需要编译，并可以指定生成的二进制文件的存放位置。

```sh
ADD_SUBDIRECTORY(<dirname> [BINARY_DIR] [EXCLUDE_FROM_ALL])
ADD_SUBDIRECTORY(src bin)  # 将子目录加入工程并指定输出到编译路径下的bin目录
```

- [BINARY_DIR]不指定的话，输出文件将放在当前子目录下。
- [EXCLUDE_FROM_ALL]：将这个子目录从编译中排除。

### ADD_LIBRARY

将源码编译成库。

#### 静态库和动态库

- 静态库的扩展名一般为 `.a` 或 `.lib`；动态库的扩展名一般为 `.so` 或 `.dll`。
- 静态库在编译时会直接整合到目标程序中，编译成功的可执行文件即使没有静态库也可以独立运行。
- 动态库在编译时不会放到链接的目标程序中，编译成功的可执行文件没有动态库无法独立运行 (有时候玩游戏会出现缺少xxx.dll的提示，就是缺少动态库)。

#### 指令

```sh
ADD_LIBRARY(hello SHARED hello.cpp)  # 生成动态库文件，名为libhello.so
ADD_LIBRARY(hello STATIC hello.cpp)  # 生成静态库文件，名为libhello.a
```

- 第二个参数没填的话，默认是静态库。
- 生成的库文件会自动在库名前加lib。
- 如果两条命令都写且名字一样时，只会构建出一个动态库，不会构建出静态库。在实际工程中，往往两种库的名称要求一样的。如何解决呢？使用SET_TARGET_PROPERTIES。

### SET_TARGET_PROPERTIES

- 用来设置输出的名称。
- 对于动态库，还可以指定库版本和API版本。

```sh
ADD_LIBRARY(hello_static STATIC hello.cpp)
SET_TARGET_PROPERTIES(hello_static PROPERTIES OUTPUT_NAME "hello")  # 对hello_static重命名输出为hello
SET_TARGET_PROPERTIES(hello_static PROPERTIES CLEAN_DIRECT_OUTPUT 1)  # cmake在构建一个新的target时，会尝试清理掉其他使用这个名字的库。待会动态库建立还会用到hello这个名字，所以要使用该命令清理下

ADD_LIBRARY(hello_shared STATIC hello.cpp)
SET_TARGET_PROPERTIES(hello_shared PROPERTIES OUTPUT_NAME "hello")  # 对hello_shared重命名输出为hello
SET_TARGET_PROPERTIES(hello_shared PROPERTIES CLEAN_DIRECT_OUTPUT 1)
```

### 链接库

#### LINK_DIRECTORIES

添加第三方库。

```sh
LINK_DIRECTORIES(<path>)
```

#### TARGET_LINK_LIBRARIES

- 添加需要链接的共享库。
- 只需给出动态库的名字即可，前提是**该库在系统的环境变量下**，否则还是得写绝对路径。
- 一定要写在 `ADD_EXECUTABLE` 之后。

```sh
TARGET_LINK_LIBRARIES(<targetname> <libname>)
```

### FIND_LIBRARY

用于查找库。

```sh
FIND_LIBRARY(<var> <libname>)
```

- `var`：变量名，将寻找结果放到这里。
- `NAMES`：为库指定一个或多个可能的名称。
- `HINTS`：除了默认位置，还指定要搜索的目录。

### INSTALL

**本质上就是拷贝，将生成的文件拷贝到指定的系统目录中。**
比如从GitHub上下载下来一个依赖库的安装包，解压后经过cmake、make、make install，该依赖库的对应头文件和库文件就安装到系统中了。

首先有一个比较像工程的目录：

```bash
.  
├── build  
├── CMakeLists.txt  
├── COPYRIGHT  
├── doc  
    └── hello.txt  
├── README.md  
├── runhello.sh  
└── src  
    ├── CMakeLists.txt  
    └── main.cpp
```

#### 安装文件

```sh
INSTALL(FILES COPYRIGHT README.md DESTINATION share/doc/cmake)  # 安装COPYRIGHT和README.md
INSTALL(PROGRAMS runhello.sh DESTINATION bin)  # 安装脚本runhello.sh
INSTALL(DIRECTORY doc/ DESTINATION share/doc/cmake)  # 安装doc中的hello.txt
```

- `DESTINATION`：安装路径。可绝对可相对，相对路径实际上是${CMAKE_INSTALL_PREFIX}/<DESTINATION定义的路径>，以第一行为例，为/usr/local/share/doc/cmake/。
- `FILES`：非编译的文件。
- `PROGRAMS`：非目标文件的可执行文件 (如脚本)。
- `DIRECTORY`：目录，后面的参数为工程目录的相对路径。
  - `doc`：这个目录将被安装到DESTINATION中。
  - `doc/`：这个目录中的内容将被安装到DESTINATION中。

#### 安装共享库和头文件

有以下文件：

```bash
.  
├── build  
├── CMakeLists.txt  
└── lib  
    ├── CMakeLists.txt  
    ├── hello.cpp  
    └── hello.h
```

```sh
INSTALL(FILES hello.h DESTINATION include/hello)  # 头文件用FILES
INSTALL(TARGETS hello_shared hello_static LIBRARY DESTINATION lib ARCHIVE DESTINATION lib)  # 安装库
```

- `TARGET`：安装二进制文件、静态库、动态库都用。
- `LIBRARY`：指动态库。
- `ARCHIVE`：指静态库。
- `RUNTIME`：指二进制可执行目标文件。

在命令行指定安装路径：

```sh
cmake -D CMAKE_INSTALL_PREFIX=/usr ..  # 指定安装路径改为/usr/
```

### 加入头文件搜索路径

#### INCLUDE_DIRECTORIES

如hello.h放在/usr/include/hello/内，则：

```sh
INCLUDE_DIRECTORIES(/usr/include/hello)
```

#### TARGET_INCLUDE_DIRECTORIES

```sh
TARGET_INCLUDE_DIRECTORIES(<targetname> <INTERFACE|PUBLIC|PRIVATE> [path1 ..])
```

- `INTERFACE`：target对应的头文件使用。
- `PRIVATE`：target对应的源文件使用。
- `PUBLIC`：target对应的头文件、源文件都使用。

#### 两者区别

- INCLUDE_DIRECTORIES写在ADD_EXECUTABLE之前，而TARGET_INCLUDE_DIRECTORIES写在之后。
- 如果有不同目录相同名称的头文件会产生影响，不要使用INCLUDE_DIRECTORIES。

### 生成Debug版本

```sh
cmake -D CMAKE_BUILD_TYPE=debug
```

### AUX_SOURCE_DIRECTORY

扫描指定文件夹下的所有源文件，并将源文件以列表的形式存放在变量中。

```sh
AUX_SOURCE_DIRECTORY(${CMAKE_CURRENT_SOURCE_DIR} SRC_FILES)  # 扫描当前文件夹下的所有源文将并将其存放在变量SRC_FILES中
```

## 项目应用

### 环境变量

使用系统环境变量：`$ENV{}`。
也可以使用SET定义：

```sh
SET(ENV{<var>} value)
```

### 交叉编译

```sh
SET(CMAKE_CROSSCOMPILING TRUE)  # 表明是否交叉编译
SET(CMAKE_SYSTEM_NAME Linux)  # 告诉CMake是哪个系统
SET(CMAKE_C_COMPILER $ENV{CROSS_COMPILE}gcc)  # 使用交叉编译工具链的环境变量，定义gcc的工具链
```
