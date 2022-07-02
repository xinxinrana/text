//学生成绩
#include <stdio.h>
#include <string.h>

int main(int argc, char const *argv[])
{
    int people = 4;
    int class_1 = 2;
    double average[class_1];
    double sum[class_1];
    double average_g = 0;
    double sum_g = 0;
    float grade[class_1][people];

    memset(grade, 0, sizeof(grade));
    memset(sum, 0, sizeof(sum));
    memset(average, 0, sizeof(average));

    for (int j = 0; j < class_1; j++)
    {
        for (int i = 0; i < people; i++)
        {
            printf("%d班的第%3d位同学的成绩是:", j + 1, i + 1);
            scanf("%f", &grade[j][i]);

            sum[j] = sum[j] + grade[j][i];
        }
    }

    for (int i = 0; i < class_1; i++)
    {
        average[i] = sum[i] / people;
        sum_g = sum_g + sum[i];
        printf("%d班的平均分是:%.2lf\n", i+1, average[i]);
    }

    printf("年级平均分:%.2lf\n", sum_g / (people * class_1));

    return 0;
}
