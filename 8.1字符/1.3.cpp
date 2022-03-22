//打开指定文件（r）
//读取流并输出到屏幕
#include<stdio.h>
#include<stdlib.h>      //为了使用exit（）


int main()
{
    int ch;
    FILE *fp;           //文件地址？可能是吧
    char fname[50];     //存放文件名

    printf("输入你需要打开的文件名(全称 且在统一目录下):\n");
    scanf("%s",fname);
    fp = fopen(fname,"r");  //打开待读取文件
    if (fp==NULL)
    {
        printf("文件打开失败，请检查文件名输入或权限\n");
        exit(1);            //退出
    }

    //getc(fp)  从打开的文件中获取一个字符
    while ((ch=getc(fp))!=EOF)
    {
        putchar(ch);
    }
    fclose(fp);
    
    return 0;
}
