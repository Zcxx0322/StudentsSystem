#include <stdio.h>
#include <string.h>
#include "student.h"

/**
 * 添加学生信息
 *
 * 将新的学生信息添加到学生数组中。
 *
 * @param students 学生数组
 * @param count    学生数量的指针，用于更新学生数量
 * @param id       新学生的学号
 * @param name     新学生的姓名
 * @param gender   新学生的性别
 */
void addStudent(Student *students, int *count, int id, const char *name, char gender) {
    // 检查是否达到最大学生数量
    if (*count >= MAX_STUDENTS) {
        printf("无法添加学生，已达到最大学生数量。\n");
        return;
    }
    // 添加新的学生信息到数组中
    students[*count].id = id;
    strncpy(students[*count].name, name, NAME_LENGTH - 1);
    students[*count].name[NAME_LENGTH - 1] = '\0';  // 确保字符串以 null 结尾
    students[*count].gender = gender;
    (*count)++;
}

/**
 * 显示学生信息
 *
 * 打印当前存储的所有学生信息。
 *
 * @param students 学生数组
 * @param count    学生数量
 */
void printStudents(const Student *students, int count) {
    printf("学号\t姓名\t\t性别\n");
    printf("---------------------------------\n");
    for (int i = 0; i < count; i++) {
        printf("%d\t%s\t\t%c\n", students[i].id, students[i].name, students[i].gender);
    }
}

/**
 * 删除学生信息
 *
 * 根据学号删除特定的学生信息。
 *
 * @param students 学生数组
 * @param count    学生数量的指针，用于更新学生数量
 * @param id       要删除的学生的学号
 * @return         如果成功删除学生信息，则返回1；否则返回0。
 */
int deleteStudent(Student *students, int *count, int id) {
    for (int i = 0; i < *count; i++) {
        if (students[i].id == id) {
            for (int j = i; j < *count - 1; j++) {
                students[j] = students[j + 1];
            }
            (*count)--;
            return 1; // 成功删除
        }
    }
    return 0; // 学生未找到
}

/**
 * 修改学生信息
 *
 * 根据学号修改特定学生的姓名和性别信息。
 *
 * @param students 学生数组
 * @param count    学生数量
 * @param id       要修改的学生的学号
 * @param name     新的学生姓名
 * @param gender   新的学生性别
 * @return         如果成功修改学生信息，则返回1；否则返回0。
 */
int modifyStudent(Student *students, int count, int id, const char *name, char gender) {
    for (int i = 0; i < count; i++) {
        if (students[i].id == id) {
            strncpy(students[i].name, name, NAME_LENGTH - 1);
            students[i].name[NAME_LENGTH - 1] = '\0';  // 确保字符串以 null 结尾
            students[i].gender = gender;
            return 1; // 成功修改
        }
    }
    return 0; // 学生未找到
}

/**
 * 导出学生信息
 *
 * 将当前存储的所有学生信息导出到指定的文件中。
 *
 * @param students 学生数组
 * @param count    学生数量
 * @param filename 导出文件的路径
 */
void exportStudents(const Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件进行写入。\n");
        return;
    }
    fprintf(file, "学号,姓名,性别\n");
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%c\n", students[i].id, students[i].name, students[i].gender);
    }
    fclose(file);
    printf("学生信息已导出到 %s\n", filename);
}

/**
 * 加载学生信息
 *
 * 从指定的文件中加载学生信息到学生数组中。
 *
 * @param students 学生数组
 * @param count    学生数量的指针，用于更新学生数量
 * @param filename 数据文件的路径
 */
void loadStudents(Student *students, int *count, const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("数据库文件不存在，正在创建新的文件...\n");
        file = fopen(filename, "w");
        if (file == NULL) {
            printf("无法创建数据库文件。\n");
            return;
        }
        fclose(file);
        printf("数据库文件创建成功。\n");
        *count = 0;
        return;
    }
    *count = 0;
    while (fscanf(file, "%d,%49[^,],%c\n", &students[*count].id, students[*count].name, &students[*count].gender) == 3) {
        (*count)++;
    }
    fclose(file);
}

/**
 * 保存学生信息
 *
 * 将当前存储的所有学生信息保存到指定的文件中。
 *
 * @param students 学生数组
 * @param count    学生数量
 * @param filename 数据文件的路径
 */
void saveStudents(const Student *students, int count, const char *filename) {
    FILE *file = fopen(filename, "w");
    if (file == NULL) {
        printf("无法打开文件进行写入。\n");
        return;
    }
    for (int i = 0; i < count; i++) {
        fprintf(file, "%d,%s,%c\n", students[i].id, students[i].name, students[i].gender);
    }
    fclose(file);
}
