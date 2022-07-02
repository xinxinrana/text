//数组学习
//整数的N次幂
#include <stdio.h>

//整数的N次幂
double pow(double mun, int n);

int main()
{
    double p = 12;
    int n = 2;
    printf("底数    指数\n");
    scanf("%lf%d", &p, &n);

    printf("\n\n%6.4lf\n\n", pow(p, n));

    return 0;
}

double pow(double mun, int n)
{
    double p = 1;
    for (int i = 0; i < n; i++)
    {
        p *= mun;
    }
    return p;
}