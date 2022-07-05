//指向多维数组的指针
#include <stdio.h>

int main(void)
{
    int mar[3][4] = {
        {11, 14, 17, 19},
        {21, 24, 27, 29},
        {31, 34, 37, 39},
    };

    int mar_1[5]={3,4,5,6,7};

    int *P_0;
    int(*P_1)[4];
    int(*P_2)[4];
    int (**P_3)[4];         //只能同类型指针嵌套！
    int **P_4;
    // P_1 = &mar[0];   等效于下面的语句

    P_0 = &mar[2][3];
    P_1 = mar;
    P_2 = mar + 1;
    P_3 = &P_2;
    P_4 = &P_0;
    

    printf("%6s %6p %6d\n","P_1",P_1,*P_1[0]);
    printf("%6s %6p %6d\n","P_2",P_2,**P_2);
    printf("%6s %6p %6p %6d\n","P_3",P_3,**P_3,***P_3);
    printf("%6s %6p %6d\n","P_4",P_4,**P_4);
    return 0;
}