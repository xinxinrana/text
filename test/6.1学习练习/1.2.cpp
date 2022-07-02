// do while 循环
//密码锁
#include <stdio.h>
#define KEY 1234

int main()
{
    int passkey;

    printf("输入密码：\n");
    printf("提示：1234\n\n");

    scanf("%d", &passkey);
    while (passkey != KEY)
    {
        printf("ERR!\n\a");
        scanf("%d", &passkey);
    }

    printf("OK\n\n");

    return 0;
}
