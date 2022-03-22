//目录打开 与操作
#include<stdio.h>
#include <dirent.h>

int main(int argc, char const *argv[])
{
    DIR *dir;           //定义目标指针
    dir = opendir("/home/xy/桌面/code/c语言副本/15.1练习");

    struct dirent *stdinfo;

    while (1)
    {
        // 读取一条记录并显示到屏幕
        if ((stdinfo=readdir(dir)) == 0) break;
    
        printf("name=%s,type=%d\n",stdinfo->d_name,stdinfo->d_type);
    }
    
    closedir(dir);   // 关闭目录指针
    return 0;
}
