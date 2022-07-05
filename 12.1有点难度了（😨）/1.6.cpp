// const  restrict  _Atomic  标识符
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char const *argv[])
{
    // const    只读
    const int i_1 = 1; //限定 i_1 对该地址下的数据为只读
    int i_2 = 1;
    const int *p_1 = &i_1; // const修饰符只能用const的指针接受
    int *const p_2 = &i_2;

    // i_1 = i_1+1;     //const 限定为只读()
    // (*p_1)++;        //*p_1 也被const限定
    p_1 = &i_2; // p_1 的值可以改变

    // *p_2++;             //++ 优先级是高于 * 的！！！  报错是修改了p_2的值
    (*p_2)++; //正常运行 i_2的值被修改 通过地址p_2
    printf("p_1的地址是:%p 指向 %p 值是%d\n", &p_1, p_1, *p_1);
    printf("p_2的地址是:%p 指向 %p 值是%d\n", &p_2, p_2, *p_2);

    // volatile  易被代理修改（非变量所在程序）
    volatile int times_1 = 0; //现在这个变量将被编译器识别 若代理修改了变量就会有效

    // 如果两个指针是独立的 那将可以让编译器优化
    // restrict 仅修饰指针 表示该指针是访问数据对象的 唯一且初始 的方式

    // int ar[10];
    // int *restrict p1 = (int *)malloc(10 * sizeof(int));      //未知错误 未解决
    // int *par = ar;

    // _Atomic 人直接麻住

    return 0;
}
