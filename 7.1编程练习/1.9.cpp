//工资计算练习
#include <stdio.h>

#define week_hour 40           //标准周工作时常
#define taxation_300 15.0f     //税费（0-300）周薪
#define taxation_300_450 20.0f //税费（300-450）周薪
#define taxation_450p 25.0f    //税费（450+）周薪
#define hourly_wage 10         //时薪

double taxa(int mun);
double wage(int mun);
int main()

{
    int work_hour = 0;
    double wage_get = 0.0;
    double wage_taxa = 0.0;
    double wage_xjb_1=0.0;
    double wage_xjb_2 = 0.0;
    double wage_xjb_h = 0.0;


    printf("输入你的周工作时长\n");
    printf("工作时长    加班时长    工资（函税）    税费    实得工资\n");

    for(work_hour=1;work_hour<=400;work_hour++)
    {
        
        wage_taxa = taxa(wage(work_hour));
        wage_get  = wage(work_hour)-wage_taxa;
        wage_xjb_1 = (wage_get/work_hour);

        if(wage_xjb_1>wage_xjb_2)
        {
            wage_xjb_2 = wage_xjb_1;
            wage_xjb_h = work_hour;
        }
            

        printf("%2d小时     %2d小时     ",work_hour,(work_hour>week_hour)?(work_hour-week_hour):0);
        printf("%4.2f元     %4.2f元     %4.2f元\n",wage(work_hour),wage_taxa,wage_get);
    }
    printf("\n\n\n工作性价比最高的是%0.0f个小时 高达%.2f",wage_xjb_h,wage_xjb_2);
    return 0;
}

double taxa(int num)
{
    double taxa_1 = 0.0f;
    if (num > 0)
    {
        if (!(num > 300))
            taxa_1 = num * (taxation_300 / 100);
        else if (!(num > 450))
            taxa_1 = (300 * (taxation_300 / 100)) + ((num - 300) * (taxation_300_450 / 100));
        else if (num > 450)
            taxa_1 = (300 * (taxation_300 / 100)) + ((450 - 300) * (taxation_300_450 / 100)) + ((num - 450) * (taxation_450p / 100));

        return taxa_1;
    }
    else
        return 0;
}

double wage(int mun)
{
    double wage = 0;

    if (mun > 0)
    {
        if (!(mun > week_hour))
            wage = mun * hourly_wage;
        else
            wage = (week_hour * hourly_wage) + ((mun - week_hour) * hourly_wage * 1.5);

        return wage;
    }
    else
        return 0;
}