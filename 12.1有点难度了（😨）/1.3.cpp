//地址大小？
#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    char chs[10];
    int *p;
    p=(int*)malloc(12);
    for (int i = 0; i < 12/4; i++)
    {
        *(p+i)=i;
        printf("%p  %d\n",p+i,*(p+i));
    }
    // free(p+1);   //err           //内存像是连续的水坑 但是有时又是三五结群的池塘
    free(p);

    int *s;
    s=(int*)malloc(12);
    for (int i = 0; i < 12/4; i++)
    {
        *(s+i)=i;
        printf("%p  %d\n",s+i,*(s+i));
    }
    free(s);


    for (int i = 0; i < 10; i++)
    {
        printf("%p\n",chs+i);
    }
    
    return 0;
}
