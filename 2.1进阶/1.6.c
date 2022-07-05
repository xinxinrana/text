//分发扑克
#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<algorithm>


int random_num(const int max, const int min = 0);
int comp(const void*a,const void*b);
void poker_init(int *poker);
void poker_mix(int *poker);
void poker_put(int *poker , int count = 54);
void poker_deal(int mix[],int (*poker_one)[18],int people_num);

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));        //初始化随机数种子
    int people_num = 3;
    int people_poker = 54/people_num+1;
    int poker_people[people_num][18];

    int (*ppp)[18] = poker_people;

    int Poker[54];
    poker_init(Poker);
    poker_mix(Poker);
    poker_deal(Poker,ppp,people_num);

    for (int i = 0; i < people_num; i++)
    { 
        qsort(poker_people[i],18,4,comp);
        poker_put(poker_people[i],54/people_num);
    }

    return 0;
}

//排序函数辅助 指针函数
int comp(const void*a,const void*b)
{
return *(int*)a-*(int*)b;
}

//扑克分发      //由于二维函数作参数的限制 导致目前只能是三人分发
//限制待解决
void poker_deal(int mix[],int (*poker_one)[18],int people_num)
{
    if ((54%people_num)!=0)
    {
        printf("err");
    }
    else
    {
        int poker_for_one = 54/people_num;

        for (int i = 0; i < people_num; i++)
        {
            for (int j = 0; j < poker_for_one; j++)
            {
                poker_one[i][j] = mix[i*poker_for_one+j];
            }  
        }  
    }
    
}

//初始化扑克，规律排序
void poker_init(int *poker) 
{
    int count = 54;
    for (int i = 0; i < count; i++)
    {
        *(poker + i) = 1000 + i + 1; //扑克牌第一个为：1001  最后为: 1054
    }
}

//打乱数组 要求传入数组首地址  可通过调节count改变混乱度
void poker_mix(int *poker)  
{
    int temp_num,temp_1,temp_2;
    int count = 100;

    for (int i = 0; i < count; i++)
    {
        temp_1 = random_num(53);
        temp_2 = random_num(53);

        temp_num = poker[temp_1];
        poker[temp_1] = poker[temp_2];
        poker[temp_2] = temp_num;
    }
}

//随机数字 最大值 最小值(默认0)
int random_num(const int max, const int min)
{
    int temp;
    temp = (rand()) % (max + 1);

    while (temp < min)
    {
        temp = (rand()) % (max + 1);
    }

    return temp;
}

//输出数组
void poker_put(int *poker,int count )
{
    puts("\n***\n\n");
    for (int i = 0; i < count; i++)
    {
        printf("%4d\n",poker[i]);
    }
    puts("\n***\n\n");
    
}


