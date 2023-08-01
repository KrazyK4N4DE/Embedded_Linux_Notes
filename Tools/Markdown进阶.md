# Markdown进阶

## 树状目录

需要 `tree` 命令。
以ubuntu为例，安装tree：

```sh
sudo apt-get install tree
```

- `-a`：显示所有。
- `-d`：只显示文件夹。
- `-L n`：显示项目的层级，n表示层级数。
- `-I "filename"`：用于过滤不想要显示的文件或文件夹。
- `N`：防止中文名乱码。

要生成树状目录，需使用 `>` 重定向输出到指定文件：

```sh
tree -L 2 -I "README.md" > README.md
```

效果如下：

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

2 directories, 6 files
```

---

## 链接当前文档的某处

现在该处加个锚点：

```Markdown
# 第一章 {#Chapter1}
```

然后就可以使用该锚点：

```Markdown
[跳转](#Chapter1)
```

---

## 图片并排显示

类似表格操作：

```Markdown
![图片](xxx.jpg) | ![图片](xxx.png)
---|---
```
