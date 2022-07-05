// dir 的控制
#include<stdio.h>
#include<unistd.h>
#define SIZE_S 128

#include<dirent.h>

//readdir(dir指针)    //自动位移
//opendir(目录)
//Dir 指针            //存放opendir返回指针流

int main(int argc, char const *argv[])
{
    char address[SIZE_S] = {"/home/xy/桌面/code/c语言副本/3.1.gg"};
    // getcwd(address,SIZE_S);
    int count_file = 0;

    DIR *catalogue_new;
    catalogue_new = opendir(address);   //获取这个目录首文件/目录的信息流

    struct dirent *stdinfo ;

    while (stdinfo = readdir(catalogue_new))
    {
    printf("name:%s \ntype_num:%d\n>>>\n",stdinfo->d_name,stdinfo->d_type);
    count_file++;
    }
    printf("file_count:%d",count_file);
    
 
    return 0;
}
