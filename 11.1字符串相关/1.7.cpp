//字符转数值
#include <stdio.h>

int atoi(const char *p);
int main(int argc, char const *argv[])
{
    int num = 0;
    // char ch[10] = {""};
    // num = atoi(ch);
    num = atoi("3534");
    printf("%d\n", num);
    return 0;
}

// 字符数字转为整形数值
int atoi(const char *p) //
{
    int num = 0;
    int symbol = 1;
    int symbol_bool = 0;
    int size = 0;
    int temp = p[size];

    if ((temp == 43) || (temp == 45))       //符号
        {
            symbol_bool = 1;
            if (p[size] == 43)
                symbol = 1;

            if (p[size] == 45)
                symbol = -1;

            size++;
        }

    while ((p[size] > 47) && (p[size] < 59))   //字符串长度
    {
        size++;   
    }

    for (int i = symbol_bool; i < size; ++i)    //字符串转数字核心代码
    {
        num = ((num * 10) + *(p + i) - 48);
    }

    if (size ==0)
    {
        return 0;
    }
    
    return symbol * num;
}