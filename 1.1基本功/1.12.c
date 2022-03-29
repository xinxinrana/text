//二维数组在for中的调用
#include <stdio.h>
#include <string.h>

int main(void)
{
    int ii = 0;                    // 用于组别循环的计数器
    int jj = 0;                    // 用于超女人数循环的计数器
    double average = 0;            // 平均值
    int class_1 = 3;               // 小组总数，初始化为3
    int total = 5;                 // 每个组超女的总人数，初始化为5
    double weight[class_1][total]; // 定义二维数组，存放超女的体重
    double sum[class_1];           // 定义一维数组存放超女体重的和

    memset(weight, 0, sizeof(weight)); // 初始化数组为0
    memset(sum, 0, sizeof(sum));       // 初始化数组为0

    // 采用两个循环，第一级循环为小组数，第二级循环为超女人数
    for (ii = 0; ii < class_1; ii++)
    {
        for (jj = 0; jj < total; jj++)
        {
            printf("请输入第%d组第%d名超女的体重：", ii + 1, jj + 1);
            scanf("%lf", &weight[ii][jj]);      // 接受从键盘输入的体重
            sum[ii] = sum[ii] + weight[ii][jj]; // 计算小组超女体重的和
        }
    }

}