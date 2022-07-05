//静态成员
#include<stdio.h>


class Box
{
    private:
    int length;

    public:
    static int objectcount;
    static void count_add(void)
    {
        objectcount++;
    }
};

// 初始化类 Box 的静态成员
int Box::objectcount = 0;       //静态成员使用前初始化（创建）！

int main(int argc, char const *argv[])
{
    Box box1;
    box1.count_add();


    return 0;
}
