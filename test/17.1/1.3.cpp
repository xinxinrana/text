//重载运算符
#include <stdio.h>

class Box
{
public:
    int A, B;
    static int objectcount;

    Box(int num1, int num2)
    {
        A = num1;
        B = num2;
    }

    Box(void) //构造函数的重载，在没有填值的时候其作用
    {
        A = 0;
        B = 0;
    }

    void init(void)
    {
        A = 0;
        B = 0;
    }

    Box operator+(const Box &box_i)
    {
        Box box;
        box.A = this->A + box_i.A;
        box.B = this->B + box_i.B;
        return box;
    }

    Box operator+(int num)
    {
        Box box;
        box.A = this->A + num;
        box.B = this->B + num;
        return box;
    }

    Box operator-(const Box &box_i)
    {
        Box box;
        box.A = this->A - box_i.A;
        box.B = this->B - box_i.B;
        return box;
    }

    Box operator-()
    {
        Box box;
        box.A = -this->A;
        box.B = -this->B;
        return box;
    }

    void operator++(void)
    {
        ++(this->A);
        ++(this->B);
    }

    void operator--(void)
    {
        --(this->A);
        --(this->B);
    }

    void operator=(const Box box)
    {
        A = box.A;
        B = box.B;
    }

    Box operator()(int a, int b, int c)
    {
        Box box;
        box.A = A + a + c;
        box.B = B + b + c;
        return box;
    }

    void p_box(void)
    {

        printf("%d >>%4d%4d\n", objectcount, A, B);
        objectcount++;
    }
};

int Box::objectcount = 0;

int main(int argc, char const *argv[])
{
    Box box1(3, 5);
    Box box2(7, 5);
    Box box3;
    box3 = box1 + box2; //默认前面的为this 后面的为参数
    box3.p_box();
    box3.init();

    box3 = box3 - box2;  //重载  -  减号
    box3.p_box();
    box3.init();

    // box3  = (++box3);//前缀  显得笨拙
    ++box3;         //重载 ++  自增符号
    box3.p_box();   //>>但是这个是例外，他不对应 ++operator
    box3.init();

    box3.A = 10;
    box3.B = 20;
    box3 = -box3; //重载 -  负号
    box3.p_box();
    box3.init();

    box3 = box3 + 5; //重载 + 加号
    box3.p_box();    //>>box3+  对应operator+
    box3.init();

    box3 = box2; //重载 = 赋值符号
    box3.p_box();
    box3.init();

    box3 = box2(13, 15, 30);
    box3.p_box();
    box3.init();

    return 0;
}
