//初始化列表 很特殊的一种方法
#include <stdio.h>
#include <iostream>

using namespace std;

//构造函数，列表化赋值   "变量名（型参）" = "变量名 = 型参"
class X1_1
{
public:
    //这里的初始化列表 的初始化顺序是按照对象中成员的声明顺序来初始化的！！！
    X1_1(int a, int b, const char *chs) : length(a), breadth(b), name_p(chs) //分别赋值吧
    {
        puts("great!");
    }
    int get(void)
    {
        return length * breadth;
    }
    //输出 name_p 的字符串和地址
    void put_name(void)
    {
        printf("%s\n", name_p);
        printf("%p\n", name_p);
    }

private:
    int length;
    int breadth;
    char name[32];
    const char *name_p;
};

//对象都析构函数  ～作前缀 结束时执行  无输入输出
class X2_1
{
public:
    ~X2_1() //程序结束时也是对象 析构函数 运行时
    {
        putchar('\a');
        puts("X2_1对象的析构函数运行了");
    }
    void set(void)
    {
        cout << "输入长度：" << endl;
        cin >> length;
        cout << "输入宽度：" << endl;
        cin >> breadth;
        cout << "great!" << endl;
    }
    int end(void)
    {
        printf("area:%d\n\n", length * breadth);
        return 0;
    }

private:
    int length;
    int breadth;
};

int main(int argc, char const *argv[])
{
    
    X1_1 block1(20, 30, "haha"); //构造函数的参数可以是数字，地址及字符串
    printf("%d\n", block1.get());
    block1.put_name();

    X2_1 block2; //无构造函数的对象创建
    for (int i = 0; i < 2; i++)
    {
        block2.set();
        block2.end();
    }

    return 0;
}
