//二进制 八进制 十六进制 十进制
#include <stdio.h>

int main(int argc, char const *argv[])
{
    int x_0b, x_0, x_0x, x;

    x_0b = 0b10000000;      //0b 二进制
    printf("%0x\n",x_0b);

    x_0 = 0200;             //0  八进制
    printf("%0x\n",x_0);

    x_0x = 0x80;            //0x  十六进制
    printf("%0x\n",x_0x);

    x = 8*16;               // (void)  十进制
    printf("%0x\n",x);


    return 0;
}
