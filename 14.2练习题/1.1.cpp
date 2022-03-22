//随机信息生成
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int random_num(const int max, const int min = 0);
char *random_chars(const int size);

int main(int argc, char const *argv[])
{
    srand((unsigned)time(NULL));

    

    return 0;
}

//随机数字 最大值 最小值(默认0)
int random_num(const int max, const int min)
{
    
    int temp;
    temp = (rand()) % (max + 1);

    while (temp < min)
    {
        temp = (rand()) % (max + 1);
    }

    return temp;
}

//随机英文名（伪） 长度
char *random_chars(const int size)
{
    char temp[size+1];
    char *re=(char*)malloc(sizeof(char)*(size+1));

    temp[0]=(char)(random_num(90,65));

    for (int i = 1; i < size; i++)
    {
        temp[i]=(char)(random_num(122,97));
    }
    temp[size]='\0';

    for (int j = 0; j < (size+1); j++)
    {
        *(re+j)=temp[j];
    }

    return re;
    

    

}
