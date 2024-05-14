#include <stdio.h>
#include <string.h>
#include "student.h"

/**
 * 登录函数
 *
 * 此函数用于验证用户提供的用户名和密码是否与预设的管理员帐号密码匹配。
 *
 * @param username 用户提供的用户名
 * @param password 用户提供的密码
 * @return 如果用户名和密码匹配正确，则返回1；否则返回0。
 */
int login(const char *username, const char *password) {
    // 预设的正确用户名和密码
    const char *correct_username = "admin";
    const char *correct_password = "admin";

    // 比较用户提供的用户名和密码是否与预设的正确值匹配
    if (strcmp(username, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        return 1; // 登录成功
    }
    return 0; // 登录失败
}
