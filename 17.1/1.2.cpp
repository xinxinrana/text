//函数重载
#include<stdio.h>

class Box
{
    public:
    int get_info(const char *chs)   //重载相当的雕了！
    {
        int size = 0;       //注意垃圾值
        while(*(chs+size)!='\0')
        {
            size++;
        }
        return size;
    }
    void get_info(int size)     //重载，根据返回值，型参自动匹配函数！
    {
        for (int i = 0; i < size; i++)
        {
            printf("*");
        }
        putchar('\n'); 
    }
};

int main(int argc, char const *argv[])
{
    Box bp;
    int var1;

    var1 = bp.get_info("中文");

    printf("%d\n",var1);
    bp.get_info(10);


    return 0;
}
