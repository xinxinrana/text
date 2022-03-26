//友元函数
#include<stdio.h>

ma


class Box
{
    private:
    int var1;

    public:
    void set(int i);
    friend void get_box_var(Box box); //友元函数是一个正常函数，但是可以访问类的成员(私有也可)
};

void Box::set(int i)
{
    var1 = i;
}
void get_box_var(Box box)//注意，他不是成员函数，
{
    printf("%4d\n",box.var1); //所以要指定对象中的成员！
}



int main(int argc, char const *argv[])
{
    Box box1;
    box1.set(3);

    get_box_var(box1);
    
    return 0;
}
