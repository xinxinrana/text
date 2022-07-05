// C++ 类构造函数 & 析构函数
#include <stdio.h>
#include <iostream>

using namespace std;

//构造函数：创建对象是执行  特殊的  函数名就是类名  无返回值
class X1_1
{
public:
    X1_1(void)
    {
        cout << "输入长度" << endl;
        cin >> length;
        cout << "输入宽度" << endl;
        cin >> breadth;
        cout << "great!" << endl;
    }
    int get_area(void)
    {
        return length * breadth;
    }

private:
    int length;
    int breadth;
};

class X1_2
{
    public:
    X1_2(int num1,int num2)
    {
        length = num1;
        breadth =num2;
    }
    int get_area(void)
    {
        return length * breadth;
    }

    private:
    int length;
    int breadth;

};
int main(int argc, char const *argv[])
{
    // X1_1 block1;
    // printf("面积是：%d\n",block1.get_area());   //加括号！！！

    X1_2 block2(20,30);
    printf("面积是：%d\n",block2.get_area());


    return 0;
}
