//计算总和
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int temp_in[32] = {0,};
    int sum = 0;
    int count = 0;

    printf("输入0-100之间的整数:\n");
    while((scanf("%d",&temp_in[count]))==1)
    {
        if((temp_in[count]>=0)&&(temp_in[count]<=100))
        {
            sum=sum +temp_in[count];
            count++;
        }
        else
        {
            break;
        }
          
    }
    count--;

    for (int i = 0; i < (count+1); i++)
    {
        if (i==count)
        {
            printf(" %d =",temp_in[i]);

        }
        else
        {
            printf(" %d +",temp_in[i]);
        } 
    }
    printf(" %d \n",sum);
    printf(" 数据个数： %d \n",count+1);
    
    return 0;
}
