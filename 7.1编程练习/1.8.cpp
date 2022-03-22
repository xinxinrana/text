//switch循环
#include<stdio.h>
#include<ctype.h>

#define STOP '|'

//getchar 一次输入的内容将被放在缓冲池中，调用一次拿出一个 输入字符最后一个为\n

int main()
{
    char ch;
    printf("输入一个小写字母，我将告诉你一种动物（他们有关联）\n");
    printf("输入 %c 可退出\n",STOP);

    while ((ch = getchar())!= STOP)
    {
        if('\n'== ch)   continue;
        if(islower(ch))
        {
            switch (ch)
            {
            case 'a':
                printf("argali, a wild sheep of Asia\n");
                break;

            case 'b':
                printf("bbbbbbbbbbbbbbbbb\n");
                break;   

            case 'c':
                printf("ccccccccccccccccc\n");
                break;

            case 'd':
                printf("dddddddddddddddddd\n");
                break;    
            
            default:
                printf("不行，没更新\n");
                break;
            }
        }
        else
            printf("不行，没整对\n");
        while(getchar()!='\n')
            continue;
        printf("输入哈，不然输入%c退出",STOP);
    }
    
    
    return 0;
}
