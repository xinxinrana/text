//拷贝构造函数
#include <stdio.h>
#include <iostream>

using namespace std;

class Line
{
public:
    Line(int num);
    Line(const Line &obj); //拷贝构造函数
    ~Line();

    int &set_vars(int n, Line &obj);
    void set_va(int initial);
    void p_vars(void);
    int get_ptr(void);

private:
    int *ptr;
    int vars[10];
}; //相当容易出问题  忘记分号

Line::Line(int num)
{
    printf("这是函数的构造函数\n");
    //为指针分配内存
    ptr = new int;
    *ptr = num;
}

Line::Line(const Line &obj) //引用：使用一个对象的全部成员！（包括私有）
{
    printf("这是拷贝构造函数\n");
    //为指针分配内存
    ptr = new int;
    *ptr = *obj.ptr; //注意 ptr是私有的，但是可以被拷贝构造函数读取到
}

Line::~Line()
{
    printf("释放指针\n");
    delete ptr;
}

int &Line::set_vars(int n, Line &obj)
{
    // printf("%d\n",obj.vars[n]);
    int &temp = obj.vars[n];
    return temp;
}

void Line::set_va(int initial)  //以initial为初值，为vars[] 赋值
{
    for (int i = 0; i < (sizeof(vars) / 4); i++)
    {
        vars[i] = (initial + i);
    }
}

void Line::p_vars(void)
{
    for (int i = 0; i < (sizeof(vars) / 4); i++)
    {
        printf("%4d", vars[i]);
    }
    putchar('\n');
}

int Line::get_ptr(void)
{
    return *ptr;
}

int main(int argc, char const *argv[])
{
    Line line1(20); //构造函数型参初始化
    printf("输入：%d\n\n", line1.get_ptr());

    Line line2(line1); //拷贝构造函数初始化
    printf("line2_ptr:%d\n\n", line2.get_ptr());
    printf("*************\n");

    Line line3(30);
    line2.set_va(4);

    line2.p_vars();
    line3.set_vars(2, line2) = 10; //使用line2 的引用成功修改其私有成员的值
    line2.p_vars();

    return 0;
}
