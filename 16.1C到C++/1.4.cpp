//数据结构
//结构体      与C不同的是C++的结构体是新类新，C是一个一维数组*
#include<stdio.h>
#include<iostream>

struct text
{
    int score;
    int order_text;
};



int main(int argc, char const *argv[])
{
    //结构体
    text t1;
    text t2;

    t1.score = 6;
    t1.order_text = 1;

    t2.score = 3;
    t2.order_text = 2;

    printf("%d,%d\n",t1.score,t1.order_text);
    printf("%d,%d\n",t2.score,t2.order_text);

    return 0;
}
