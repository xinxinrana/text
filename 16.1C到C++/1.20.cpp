//静态成员和静态函数
//有bug！！！
#include <stdio.h>

class Box
{
private:
    int length;

public:
    static int objectCount;

    Box(void)
    {
        length = 10;
        objectCount++;
    }

    void p_box(void)
    {
        printf("length:%d\n", length);
        printf("count:%d\n", objectCount);
    }

    void set_length(int leng)
    {
        length = leng;
    }

    void count_add_one(void)
    {
        objectCount++;
    }

    static int p_count(void)
    {
        // length = 20; //在静态成员函数中无效使用成员“Box:：length”
        printf(">>%d\n", objectCount);
        return objectCount;
    }
};
//初始化Box的静态成员
int Box::objectCount = 0; //静态成员是默认不存在的，所以要初始化

int main(int argc, char const *argv[])
{
    Box::p_count();

    Box box1;
    box1.p_box();
    Box::p_count();

    Box box2;
    box2.p_box();
    Box::p_count();

    return 0;
}
