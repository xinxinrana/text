//计算字符中条件下的个数
#include<stdio.h>

int main(int argc, char const *argv[])
{
    char ch;
    int charcount=0;

    while ((ch = getchar()) != '\n')
    {
        if((ch!='\"')&&(ch!='\''))
        {
            charcount++;
        }
            
    }
    printf("有%d个非\"或\' 的字符",charcount);
    
    return 0;
}
