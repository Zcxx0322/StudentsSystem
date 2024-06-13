#ifndef STUDENT_H
#define STUDENT_H

#define NAME_LENGTH 50       // 定义姓名的最大长度
#define COLLEGE_LENGTH 50    // 定义学院的最大长度
#define DORMITORY_LENGTH 20  // 定义宿舍号的最大长度
#define MAX_STUDENTS 100     // 定义最大学生数量

// 定义学生结构体
typedef struct {
    int id;  // 学号
    char name[NAME_LENGTH];  // 姓名
    char gender;  // 性别
    char college[COLLEGE_LENGTH];  // 学院
    char dormitory[DORMITORY_LENGTH];  // 宿舍号
    int age;  // 年龄
} Student;

// 添加学生信息
void addStudent(Student *students, int *count, int id, const char *name, char gender, const char *college, const char *dormitory, int age);

// 显示学生信息
void printStudents(const Student *students, int count);

// 删除学生信息
int deleteStudent(Student *students, int *count, int id);

// 修改学生信息
int modifyStudent(Student *students, int count, int id, const char *name, char gender, const char *college, const char *dormitory, int age);

// 导出学生信息
void exportStudents(const Student *students, int count, const char *filename);

// 用户登录
int login(const char *username, const char *password);

// 加载学生信息
void loadStudents(Student *students, int *count, const char *filename);

// 保存学生信息
void saveStudents(const Student *students, int count, const char *filename);

#endif // STUDENT_H
