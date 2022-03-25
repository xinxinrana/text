//继承中的一些可能的问题
#include <stdio.h>
#include <iostream>

class Book
{
private:
    int var;

public:
    void set(int num)
    {
        var = num;
    }
    int get(void)
    {
        return var;
    }
};

class Location
{
public:
    enum region_enum
    {
        A1,
        A2,
        A3,
        B1,
        B2,
        C1,
        C2,
        C3,
        D1,
        D2
    };
    //枚举就像是定义了一群const 变量
    int floor;
    int region;
};

class Library : public Book, public Location
{
public:
    int get_add_1(void)
    {
        // return var+1;        //var 是book私有成员 不可访问
        return get() + 1; // get（）是公开成员，可以被访问
    }
};


//class 类名: virtual 继承方式 父类名   虚拟继承格式，可用在环形继承中出现的问题

    // A->B  B->D
    // A->C  C->D

// class 类名 : virtual 继承方式 基类 

int main(int argc, char const *argv[])
{
    Library bok1;
    bok1.set(12);
    bok1.region = bok1.C2;

    printf("%d\n", bok1.get());
    printf("%d\n", bok1.get_add_1());
    printf("%d\n", bok1.region);
    return 0;
}
