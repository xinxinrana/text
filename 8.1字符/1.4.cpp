//友好型交互设计示例
#include <stdio.h>

int main(void)
{
    char response;
    int guess = 1;
    printf("这个数是：%d吗？",guess);

    while (((response = getchar()) != 'y') && (response != 'Y'))
    {
        if (response == '\n')
        {
            continue;
        }

        if ((response == 'n') || (response == 'N'))
        {
            printf("这个数是：%d吗？", ++guess);
            printf("正确请输入Y，否则输入N");
        }
        else
        {
            printf("我不理解你的表达。");
        }

        while (getchar() != '\n')
            continue;
    }

    return 0;
}
