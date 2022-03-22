// Rabnud 博士的朋友
#include <stdio.h>

/*
    博士有5个朋友，每过一周少一个，
    剩下朋友又再介绍一个朋友给博士认识。
    十周之后，博士还有多少朋友？
*/
int main()
{
    int friend_1 = 5;
    int week = 10;

    for (int i = 0; i < week; i++)
    {
        friend_1 -= 1;
        friend_1 *= 2;
        printf("博士%d周后朋友有:%d\n", i + 1, friend_1);
    }

    return 0;
}
