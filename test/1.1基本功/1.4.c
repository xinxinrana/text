//switch case
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int choice = 0;
    printf("输入你的选择：\n");
    scanf("%d",&choice);

    switch (choice)
    {
    case 1:
        printf("你的选择是%d\n",choice);
        break;
    case 2:
        printf("你的选择是%d\n",choice);
        break;
    case 3:
        printf("你的选择是%d\n",choice);
        break;
    case 4:
        printf("你的选择是%d\n",choice);
        break;
    
    default:
        printf("你什么都没选。\n");
        break;
    }


    return 0;
}
