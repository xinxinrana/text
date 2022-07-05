//传度对象  传递对象指针  传递对象引用
#include <stdio.h>

class Box
{
private:
    int pri;

public:
    int pub;
    Box(int a = 2, int b = 3, int c = 4)
    {
        pri = a;
        pub = b;
        pro = c;
    }
    void init(int a = 2, int b = 3, int c = 4)
    {
        pri = a;
        pub = b;
        pro = c;
    }
    void put_box(void)
    {
        printf("%d , %d , %d\n", pri, pub, pro);
    }
    void set_A(Box box)     //对box的副本进行操作
    {
        box.pri = 20;
        box.pub = 30;
        box.pro = 40;
        printf(">>%d , %d , %d\n", box.pri, box.pub, box.pro);
    }
    void set_B(Box *box)
    {
        box->pri = 200;
        box->pub = 300;
        box->pro = 400;
        printf(">>%d , %d , %d\n", box->pri, box->pub, box->pro);
    }
    void set_C(Box &box)
    {
        box.pri = 2000;
        box.pub = 3000;
        box.pro = 4000;
        printf(">>%d , %d , %d\n", box.pri, box.pub, box.pro);
    }

protected:
    int pro;
};


void set_A(Box box);
void set_B(Box *box);
void set_C(Box &box);

int main(int argc, char const *argv[])
{
    Box box1(1);            //缺省至少填充一个参数！！
    Box box2(2);
    Box *box2_p = &box2;
    Box &box2_l = box2;

    //外部函数
    // Box *box_p = &box1;
    // Box &box_l = box1;
    // box1.put_box();
    // set_A(box1);
    // box1.put_box();
    // set_B(box_p);
    // box1.put_box();
    // set_C(box_l);
    // box1.put_box();

    box1.init(2);
    box1.put_box();

    box1.set_A(box2);       //外部，对
    box2.put_box();

    box1.set_B(box2_p);     //可访问，可修改
    box2.put_box();

    box1.set_C(box2_l);     //可访问，可修改
    box2.put_box();

    //若对象成员函数的参数 是此类的一个对象
    //则如何调用这个成员函数对处理此对象无无任何限制


    return 0;
}
//副本，无法修改
void set_A(Box box)
{
    box.pub = 10;
    // printf("%d\n",box.pub);
}
//指针，可修改
void set_B(Box *box)
{
    box->pub =30;
    // printf("%d\n",box->pub);
}
//引用，可修改
void set_C(Box &box)
{
    box.pub = 40;
    // printf("%d\n",box.pub);
    // 外部无论那种引用都是无法访问的
    // printf("%d\n",box.pri);
}
