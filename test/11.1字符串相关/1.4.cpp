//'\0'为假
#include<stdio.h>

int main (void)
{
    char ch = '\0';
    if(ch)
        puts("\\0为真");
    else
        puts("\\0为假");
    return 0;
}