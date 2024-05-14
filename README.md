# 学生信息管理系统

这是一个简单的学生信息管理系统，用于管理学生的基本信息，包括学号、姓名和性别。该系统提供了基本的功能，包括信息显示、添加、删除、修改、导出以及系统退出。

## 项目结构
    StudentsSystem/
    ├── data
    │   └── students_information.txt # 数据文件，存储学生信息
    ├── include
    │   └── student.h                # 学生信息管理系统的头文件
    └── src 
        └── main.c                   # 主程序文件，包含系统的主要功能实现
        ├── student.c                # 学生信息管理函数的实现
        └── utils.c                  # 登陆函数的实现
    ├── LICENSE                      # 开源许可证文件
    ├── Makefile                     # 用于编译项目的Makefile文件
    ├── password.txt                 # 存储管理员密码的文件
    └── README.md                    # 项目说明文件


## 功能介绍

### 1.登陆系统

用户可以通过帐号密码登陆系统。

### 2. 显示信息

用户可以选择显示当前存储的所有学生信息。

### 3. 添加信息

用户可以添加新的学生信息，包括学号、姓名和性别。

### 4. 删除信息

用户可以根据学号删除特定的学生信息。

### 5. 修改信息

用户可以根据学号修改特定学生的姓名和性别信息。

### 6. 导出信息

用户可以将当前存储的所有学生信息导出到CSV文件中。

### 7. 退出系统

用户可以选择退出系统。

## 如何运行

1. 确保你的系统已安装了`gcc`编译器。
2. 使用终端进入项目根目录。
3. 执行以下命令编译项目：

    ```
    make
    ```

4. 编译完成后，执行以下命令运行系统：

    ```
    ./student_management_system
    ```

## 作者

这个项目由[Zcxx0322]编写。

## 开源许可证

本项目采用 [MIT 许可证](LICENSE)进行许可。