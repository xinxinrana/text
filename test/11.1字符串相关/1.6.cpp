//命令行参数接受
#include<stdio.h>
int main(int argc, char const *argv[])
{
    printf("\n收到了%d个命令行参数\n",argc);

    for (int i = 0; i < argc; ++i)
    {
        printf("%3d: %s\n",i,argv[i]);
    }
    

    return 0;
}
