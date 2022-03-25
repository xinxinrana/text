//拷贝构造函数
#include <stdio.h>
#include <iostream>

using namespace std;

class Line
{
public:
    Line(int num);
    Line(const Line &obj);
    ~Line();
    int get_ptr(void);

private:
    int *ptr;
};      //相当容易出问题  忘记分号

Line::Line(int num)
{
    printf("这是函数的构造函数\n");
    //为指针分配内存
    ptr = new int;
    *ptr = num;
}

Line::Line(const Line &obj)
{
    printf("这是拷贝构造函数\n");
    //为指针分配内存
    ptr = new int;
    *ptr = *obj.ptr;
}
Line::~Line()
{
    printf("释放指针\n");
    delete ptr;
}
int Line::get_ptr(void)
{
    return *ptr;
}

int main(int argc, char const *argv[])
{
    Line line1(12);
    printf("输入：%d\n\n", line1.get_ptr());

    Line line2(line1);
    printf("line2_ptr:%d\n\n",line2.get_ptr());

    return 0;
}
