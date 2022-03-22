// 当前目录读取
#include <stdio.h>
#include <string.h>     //目录头文件
#include <sys/stat.h>   //操作目录 （创建 删除等）
#include <sys/types.h>  
#include <unistd.h>     //读取当前目录  & 切换目录


int main(int argc, char const *argv[])
{
    char strpwd[301];
    FILE *fp_r;
    char temp[1024];

    memset(strpwd, 0, sizeof(strpwd));
    getcwd(strpwd, 300);
    printf("当前目录是：%s\n", strpwd);

    chdir("/home/xy/桌面/code/c语言副本/15.1练习");

    getcwd(strpwd, 300);
    printf("当前目录是：%s\n", strpwd);
    fp_r = fopen("1.1.c", "r+");

    while (1) //文件内容输出
    {
        if ((fgets(temp, 1024, fp_r)) == NULL)
        {
            break;
        }
        fputs(temp, stdout);
    }
    putchar('\n');

    mkdir("/home/xy/桌面/code/c语言副本/15.1练习/测试", 0755);
    // rmdir("/home/xy/桌面/code/c语言副本/15.1练习/测试");

    return 0;
}
