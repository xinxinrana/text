//接受多个字符串
#include <stdio.h>
#include<string.h>

int main(int argc, char const *argv[])
{
    int count = 2,num = 3, width = 30;
    char str[count][num][width];

    memset(str,0,sizeof(str));

    for (int j = 0; j < count; j++)
    {
       for (int i = 0; i < num; i++)
        {
            printf("请输入第%d组第%d个字符串: ",j+1,i+1);
            scanf("%s",str[j][i]);   
        } 
    }
    
    

    printf("\n*********\n");
    for (int j = 0; j < count; j++)
    {
        for (int i = 0; i < num; i++)
        {
            printf("第%d组第%d个字符串是:%s\n",j+1,i+1,str[j][i]);
        }
    }
    

    
    

    return 0;
}
