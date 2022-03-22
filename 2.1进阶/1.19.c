//宏嵌套  //最好不要哈
#include<stdio.h>
#define X "bbb"
#define XX X"123"

int main(int argc, char const *argv[])
{
    
    printf("%s\n",X);
    printf("%s\n",XX);      //嵌套成功！
    return 0;
}
