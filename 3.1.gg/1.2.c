/*
 * 程序名：book160.c，此程序演示errno全局变量和strerror函数。
 * 作者：C语言技术网(www.freecplus.net) 日期：20190525
*/
#include <stdio.h>
#include <string.h>
#include <errno.h>
 
int main()
{
  FILE *fp=0;     // 定义文件指针变量fp
 
  // 以只读的方式打开文件/tmp/book1.c
  if ( (fp=fopen("/tmp/book1.c","r")) == 0 )
  {
    printf("打开文件/tmp/book1.c失败(%d：%s)。\n",errno,strerror(errno)); 
  }
  
  // 关闭文件
  if ( fp!=0 ) fclose(fp);
 
  return 0;
}