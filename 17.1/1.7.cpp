//更多的多态相关
//多重继承的多态调用
#include <stdio.h>

class Line_parent
{
public:
    virtual void put_info(void)     //基类的多态函数影响派生类的多态判定
        //  void put_info(void)     //若基类有 virtual 修饰则正常，否则会调用失败
    {
        puts("这是父级");
    }
};

class Line_part : public Line_parent
{
public:
    virtual void put_info(void)
    {
        puts("这是子集");
    }
};

class Line_par : public Line_part
{
public:
    virtual void put_info(void)
    {
        puts("这是孙集");
    }
};

int main(int argc, char const *argv[])
{
    Line_par line1;
    Line_parent *line_p = &line1;

    line_p->put_info();
    return 0;
}
