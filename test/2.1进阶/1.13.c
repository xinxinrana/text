//批量创建目录并填文件
#include<stdio.h>
#include<dirent.h>
#include<string.h>
#include <sys/stat.h>   //操作目录 （创建 删除等）
#include <sys/types.h>  
#include <unistd.h>     //读取当前目录  & 切换目录
#define SIZE_STR 257

char *return_cwd(void);     //返回但前函数工作路径字符串首地址
char *to_String(int n);
int mkdir_many(const char *dir_name,const int count = 10);

int main(int argc, char const *argv[])
{
    int dir_num = 20;
    printf("%p,%s\n",return_cwd(),return_cwd());

    mkdir("测试目录",0755);                     //自动判断绝对相对路径
    printf("%p,%s\n",return_cwd(),return_cwd());

    chdir("测试目录");
    mkdir_many("相对路径垃圾场",5);
    mkdir_many("/home/xy/桌面/code/c语言副本/2.1进阶/垃圾场",5);


    
    return 0;
}



int mkdir_many(const char *dir_name,const int count)
{
    char temp_name[301];
    for (int i = 0; i < count; i++)
    {
        if((dir_name[0])!='/')
            sprintf(temp_name,"%s/%s%s",return_cwd(),dir_name,to_String(i));
        else
            sprintf(temp_name,"%s%s",dir_name,to_String(i));
        mkdir(temp_name,0755);
    }
    return 0 ;
    
}


char *return_cwd(void)
{
    static char temp[301];
    getcwd(temp,300);
    // puts(temp);
    return &temp[0];
}


char *to_String(int n)
 {
    //  int max = 100;
     int m = n;
     char s[100];
     static char ss[100];
     int i=0,j=0;
     if (n==0)
     {
         strcpy(ss,"0");
         return ss;
     }
     
     if (n < 0)// 处理负数
     {
         m = 0 - m;
         j = 1;
         ss[0] = '-';
     }    
     while (m>0)
     {
         s[i++] = m % 10 + '0';
         m /= 10;
     }
     s[i] = '\0';
     i = i - 1;
     while (i >= 0)
     {
         ss[j++] = s[i--];
     }    
     ss[j] = '\0';    
     return ss;
 }