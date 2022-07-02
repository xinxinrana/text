//目录指针的使用
#include <stdio.h>
#include<string.h>
#include <dirent.h>

//readdir(dir指针)    //自动位移
//opendir(目录)
//Dir 指针            //存放opendir返回指针流
 
// 列出目录及子目录下的文件
int ReadDir(const char *strpathname);
 
int main(int argc,char *argv[])
{
//   if (argc != 2)  { printf("请指定目录名。\n"); return -1; }
 
  // 列出目录及子目录下的文件
  ReadDir("/home/xy/桌面/code/c语言副本/2.1进阶");
}
 
// 列出目录及子目录下的文件
int ReadDir(const char *strpathname)
{
  DIR *dir;   // 定义目录指针
  char strchdpath[257];  // 子目录的全路径    //最大文件名 长度+1  //否者会报 警告
  memset (strchdpath,0,257);
 
  if ( (dir=opendir(strpathname)) == 0 ) return -1; // 打开目录
 
  struct dirent *stdinfo; // 用于存放从目录读取到的文件和目录信息
 
  while (1)
  {
    if ((stdinfo=readdir(dir)) == 0) break;   // 读取一记录
 
    if (strncmp(stdinfo->d_name,".",1)==0) continue;  // 以.开始的文件不读
 
    if (stdinfo->d_type==8)    // 如果是文件，显示出来
      printf("name=%s/%s\n",strpathname,stdinfo->d_name);
 
    if (stdinfo->d_type==4)   // 如果是目录，再调用一次ReadDir
    {
    // strcat(strchdpath,strpathname);
    // strcat(strchdpath,"/");
    // strcat(strchdpath,stdinfo->d_name);
    sprintf(strchdpath,"%s/%s",strpathname,stdinfo->d_name);
    ReadDir(strchdpath);
    }
  }
  closedir(dir);   // 关闭目录指针
  return 0 ;
}