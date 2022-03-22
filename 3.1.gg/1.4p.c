/*
 * 程序名：book145.c，此程序演示目录和文件的存取权限和状态信息
 * 作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
 
// 本程序运行要带一个参数，即文件或目录名
int main(int argc,char *argv[])
{
  if (argc != 2)  { printf("请指定目录或文件名。\n"); return -1; }
 
  if (access(argv[1],F_OK) != 0) { printf("文件或目录%s不存在。\n",argv[1]); return -1; }
 
  struct stat ststat;
 
  // 获取文件的状态信息
  if (stat(argv[1],&ststat) != 0) return -1;
 
  if (S_ISREG(ststat.st_mode)) printf("%s是一个文件。\n",argv[1]);
  if (S_ISDIR(ststat.st_mode)) printf("%s是一个目录。\n",argv[1]);
}