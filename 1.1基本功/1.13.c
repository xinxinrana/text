//字符串
#include<stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    char str[64];
    int count = 0;

    memset(str,0,sizeof(str));

    scanf("%s",str);

    while (1)
    {
        if(str[count]=='\0')
        {
            count--;
            break;
        }
        count++;
    }

    printf("%s 位数:%d\n",str,count+1);
    for (int i = 0; i < (count+1); i++)
    {
        putchar(str[count-i]);
        putchar('_');
    }
    
    


    return 0;
}
