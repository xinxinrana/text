//分开声明结构体与变量
#include <stdio.h>

struct class_all
{
    int number;
    char class_ID[64];
};

int main(int argc, char const *argv[])
{
    struct class_all banji_1 = {
        .number = 30,
        // .class_ID = "任何内容",    // 字符串数组不能这样付初值
        "FX0231", //但是直接这样是允许的！！
        // "EDX0001",// “class_all”的初始值设定项太多
    };

    printf("class_1 班级有%d 人\n班级ID是: %s\n", banji_1.number, banji_1.class_ID);

    return 0;
}
