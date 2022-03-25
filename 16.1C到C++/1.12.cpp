//继承——保护成员
#include<stdio.h>
#include<iostream>
class x1_1
{
    protected:
    int i;
};

class x2_1 : public x1_1
{
    public:
    void set_i(int num)
    {
        i = num;        //在继承类中使用了 基类的保护成员 ！
    }

    int get_i(void)
    {
        return i;
    }
};



int main(int argc, char const *argv[])
{
    x2_1  class_1;

    class_1.set_i(20);
    printf("%8d\n",class_1.get_i());
    //易出错项：把对象中的成员函数当 数据成员直接用 ，加强对象编程思维。都是封装，没有能直接操作的数据！！！

    return 0;
}
