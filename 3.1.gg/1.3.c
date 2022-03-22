//文件权限  unistd.h    系统接口头文件
// access 函数使用
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#define SIZE_S 128

//  ****/****/****      可以是目录
//  ****/****/****.abc  也可以是文件    access 都判断权限



int main(int argc, char const *argv[])
{
    char file_1[SIZE_S] = {"1200"};

    char address[SIZE_S]; //读取当前路径并放入BUF中
    memset(address,0,sizeof(address));
    getcwd(address, SIZE_S);            //获取当前路径
    puts(address);

    chdir("测试路径001");               //改变路径
    getcwd(address, SIZE_S);
    puts(address);

    strcat(address,"/");
    strcat(address, file_1);

    if (!(access(address, F_OK)))       //判断文件（目录） 权限/存在
    {
        printf("%s  YES\n", address);
    }
    else
    {
        printf("%s  NO\n", address);
    }

    return 0;
}
