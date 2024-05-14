#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include "student.h"

#define MAX_ATTEMPTS 3
#define DATA_DIR "data"
#define DATA_FILE "data/students_information.txt"

/**
 * 显示菜单
 *
 * 打印系统功能菜单，供用户选择操作。
 */
void displayMenu() {
    printf("\n学生信息管理系统\n");
    printf("1. 显示信息\n");
    printf("2. 添加信息\n");
    printf("3. 删除信息\n");
    printf("4. 修改信息\n");
    printf("5. 导出信息\n");
    printf("6. 退出系统\n");
    printf("请输入您的选择: ");
}

/**
 * 主函数
 *
 * 程序的入口点，实现了学生信息管理系统的主要功能。
 */
int main() {
    // 声明学生数组和相关变量
    Student students[MAX_STUDENTS];
    int count = 0; // 学生数量
    char username[50]; // 用户名
    char password[50]; // 密码
    int loggedIn = 0; // 是否成功登录标志

    // 创建数据目录（如果不存在）
    struct stat st = {0};
    if (stat(DATA_DIR, &st) == -1) {
        mkdir(DATA_DIR, 0700);
    }

    // 加载学生信息
    loadStudents(students, &count, DATA_FILE);

    // 用户登录
    for (int attempts = 0; attempts < MAX_ATTEMPTS && !loggedIn; attempts++) {
        printf("请输入用户名: ");
        scanf("%s", username);
        printf("请输入密码: ");
        scanf("%s", password);
        if (login(username, password)) {
            loggedIn = 1; // 登录成功
        } else {
            printf("登录失败，请重试。\n");
        }
    }

    if (!loggedIn) {
        printf("尝试次数过多，系统退出。\n");
        return 1;
    }

    int choice;
    // 主循环，等待用户选择操作
    while (1) {
        displayMenu(); // 显示菜单
        scanf("%d", &choice); // 获取用户选择

        switch (choice) {
            case 1:
                printStudents(students, count); // 显示学生信息
                break;
            case 2: {
                // 添加学生信息
                int id;
                char name[NAME_LENGTH];
                char gender;
                printf("请输入学号: ");
                scanf("%d", &id);
                printf("请输入姓名: ");
                scanf("%s", name);
                printf("请输入性别 (M/F): ");
                scanf(" %c", &gender);
                addStudent(students, &count, id, name, gender);
                saveStudents(students, count, DATA_FILE);
                break;
            }
            case 3: {
                // 删除学生信息
                int id;
                printf("请输入要删除的学号: ");
                scanf("%d", &id);
                if (deleteStudent(students, &count, id)) {
                    printf("学生信息删除成功。\n");
                    saveStudents(students, count, DATA_FILE);
                } else {
                    printf("未找到该学生信息。\n");
                }
                break;
            }
            case 4: {
                // 修改学生信息
                int id;
                char name[NAME_LENGTH];
                char gender;
                printf("请输入要修改的学号: ");
                scanf("%d", &id);
                printf("请输入新姓名: ");
                scanf("%s", name);
                printf("请输入新性别 (M/F): ");
                scanf(" %c", &gender);
                if (modifyStudent(students, count, id, name, gender)) {
                    printf("学生信息修改成功。\n");
                    saveStudents(students, count, DATA_FILE);
                } else {
                    printf("未找到该学生信息。\n");
                }
                break;
            }
            case 5:
                exportStudents(students, count, "students.csv"); // 导出学生信息
                break;
            case 6:
                printf("系统退出。\n");
                saveStudents(students, count, DATA_FILE); // 保存学生信息并退出
                return 0;
            default:
                printf("无效的选择，请重试。\n"); // 无效选择
        }
    }

    return 0;
}
