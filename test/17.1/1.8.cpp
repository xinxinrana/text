//哈希加密学习
//文件的简单加密
#include <stdio.h>
#include <string.h>

class encryption
{
private:
    int size_encr;
    long secret_key;
    char encr_ed[129];
    char chs_in[129];

    void mix(void)
    {
    }

public:
    encryption(void)
    {
        size_encr = 0;
        memset(encr_ed, 0, sizeof(encr_ed));
        memset(chs_in, 0, sizeof(chs_in));
    }

    void set_enc(char *chs)
    {
        strncpy(chs_in, chs, 129);
    }

    // char *get_enc(void)
    // {
    //     if (encr_ed[0] == '\0')
    //     {
    //         return "err";
    //     }
    //     return &encr_ed;
    // }
    void set_key(long key)
    {
        secret_key = key;
    }
};

long displacement(const long num_in, int move_to);
int get_one_num_l(const long num, int location);
long ints_to_long(int *list);

int main(int argc, char const *argv[])
{
    int str[32] = {4, 2, 5, 8, 3, 5};
    long num = 992;
    int re = 7;

    // printf("%d\n",get_one_num_l(num,1));

    // printf("%ld\n",ints_to_long(str));

    num = displacement(num, re);
    printf("%ld\n", num);

    return 0;
}

// long数字 位 位移
long displacement(const long num_in, int move_to)
{
    long num = num_in;
    int count = 0;
    int num_list[32];
    memset(num_list, 0, sizeof(num_list));

    while (num != 0)
    {
        num = num / 10;
        count++;
    }

    int hand = 0;
    for (int i = 0; i < count; i++)
    {
        hand = i + move_to;
        while(hand>(count-1))
        {
            hand -= count; 
        }
        
        num_list[i] = get_one_num_l(num_in, hand+1);
    }
    num = ints_to_long(num_list);
    return num;
}

// int数组转long整形
long ints_to_long(int *list)
{
    long re = 0;
    int count = 31;
    while (*(list + count) == 0)
    {
        if (count == 0)
        {
            return 0l;
        }
        count--;
    }
    count++;

    for (int i = 0; i < count; i++)
    {
        re += *(list + i);
        if (i == (count - 1))
        {
            break;
        }
        re *= 10;
    }

    return re;
}

//输出一个数的指定位
int get_one_num_l(const long num_in, int location)
{
    long num = num_in;
    int num_list[32];
    memset(num_list, 0, sizeof(num_list));
    int count = 32;

    for (int i = 0; i < count; i++)
    {
        num_list[i] = (num % 10);
        num = num / 10;
        if (num == 0)
        {
            count = i + 1;
            break;
        }
    }

    if (location > count)
    {
        return 0;
    }
    else
    {
        return num_list[count - location];
    }
}
