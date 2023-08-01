# Git

## 概述

分布式版本控制系统
和GitHub的区别：GitHub就是Git的托管平台。

---

## 基本命令

**设置用户名和邮箱(仅仅是身份说明)**：

```sh
git config --global user.name "User"
git config --global user.email "email@example.com"
```

**初始化本地库**：

```sh
git init
```

**查看文件状态**：

```sh
git status
```

**添加文件到暂存区**：

```sh
git add <name>
git add .  # 添加全部文件
```

**从暂存区移除**：

```sh
git rm <name>  # --cache为留住本地文件
```

**提交到本地库**：

```sh
git commit -m '提交信息'
```

- `-a`：提交全部暂存区的文件。
- `-m`：要有提交备注。

**查看现在文件和上一个版本有什么区别**：

```sh
git diff
```

**查看版本号**：

```sh
git log  # 详细的
```

- `--all`：查看所有分支，包括未合并的。
- `--graph`：以图形化方式显示分支。
- `--oneline`：每个版本信息展示占用限制为一行。

**查看操作记录**：

```sh
git reflog
```

**显示最新一次提交记录**：

```sh
git show
```

**回滚**：

```sh
git reset <commitID>
```

- `--hard`：本地文件也会跟着改动回commitID版本中的文件。
- `--soft`：与hard相反。

---

## 分支操作

**查看分支**：

```sh
git branch
```

- `-v`：带版本号和提交信息的。
- `-a`：查看所有的分支，包括远程仓库的。

**创建分支**：

```sh
git branch <name>
```

- `-m`：给已有分支改名。

```sh
git branch -m <originalname> <newname>
```

**切换到指定分支**：

```sh
git checkout <name>
```

- `-b`：创建并切换到分支。

**合并某个分支到现所在分支中**：

```sh
git merge <name>
```

合并分支有时会产生冲突。

**变基**：

注意，是现所在分支变基到指定分支上。

```sh
git rebase <name>
```

- 变基后分支开始的位置就会改变，所以会丢弃一些提交。
- 若有partner在此分支上修改，而你将此分支变基了，那partner的工作就白干了，所以变基需慎用。

**优选**：

```sh
git cherry-pick <commitID>
```

将该提交版本作用于现所在分支上，分支位置不会有变动。

---

## 远程仓库

**remote操作**：

```sh
git remote  # 查看当前所有远程地址的别名
git remote add <reponame> <address>  # 链接远程仓库
git remote rm <reponame>  # 删除对远程仓库的关联
git remote get-url <reponame>  # 查看远程仓库的地址
git remote set-url <reponame> <address>  # 修改远程仓库的地址
```

- `<reponame>` 是可自定义的名称。
- `-v`：带详细点的信息查看。

**将版本推送给远程仓库**：

```sh
git push <reponame> <branch>:<repobranch>
```

- `-f`：强制推送，一般用于**反悔了，想删除远程仓库的一些版本**。

**将远程和本地的分支进行绑定**：

```sh
git push --set-upstream <reponame> <branch>:<repobranch>
git push <reponame>
```

这样之后推送该分支时，就不用再指定分支名了。

**克隆远程仓库到本地**：

```sh
git clone <address>
```

**抓取和拉取**：

```sh
git fetch <reponame>
git pull <reponame>
```

- fetch是只获取但不合并远程分支，后面需要手动合并才能提交。
- pull是获取加合并。
