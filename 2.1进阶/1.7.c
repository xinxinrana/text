//多行字符输出
#include <stdio.h>

static const char pch[2][4][5]{
    {
        {"****"},
        {"* **"},
        {"****"},
        {"****"},
    },

    {
        {"****"},
        {"** *"},
        {"** *"},
        {"****"},
    },
};

void pp(const char *ch);
int main(int argc, char const *argv[])
{

    char ch[3] = {"ab"};

    pp(ch);

}

void pp(const char *ch)
{
    97;
    int size = 0;
    int char_temp;
    while (ch[size]!='\0')
    {
        size++;
    }

    for(int k = 0;k<4;k++)
    {
        for(int j=0;j<size;j++)
        {
            for (int i = 0; i < 4; i++)
            {
                char_temp= pch[ch[j]-97][k][i];
                putchar(char_temp);
            }
            printf("    ");
        }
        putchar('\n');
    }
        


}
