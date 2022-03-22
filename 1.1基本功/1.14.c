//学生成绩
#include<stdio.h>

int main(int argc, char const *argv[])
{
    int people = 10;
    double average = 0;
    double sum = 0;
    float grade[people]={0,};

    for (int i = 0; i < people; i++)
    {
        printf("第%3d位同学的成绩是:",i+1);
        scanf("%f",&grade[i]);

        sum = sum + grade[i];
    }

    average = sum / people;

    printf("这%d个人的平均分是:%.2lf\n",people,average);

    
    return 0;
}
