// this 指针
#include <stdio.h>
#include <string.h>
#define SIZE_STR 64

class Box
{
private:
    char chs[SIZE_STR];
    int var;

public:
    void set_var(int num);
    bool compare(Box box);
    void set_chs(const char *chs_p);
    void put_chs(void);
    void all_chs(const char *chs_pall);


};

void Box::set_var(int num)
{
    var = num;
}
bool Box::compare(Box box)
{
    // return var>box.var;      //没有问题  因为默认就是this指针所指的成员函数
    return this->var>box.var;   //也没有问题
}
void Box::set_chs(const char *chs_p)
{
    strncpy(chs, chs_p, SIZE_STR);
}
void Box::put_chs(void)
{
    puts(chs);
}
void Box::all_chs(const char *chs_pall)
{
    Box::set_chs(chs_pall);
    Box::put_chs();
}

bool turn_info(void);

int main(int argc, char const *argv[])
{
    Box box1;
    Box box2;
    // box1.set_chs("这是一段话");
    // box1.put_chs();
    box1.all_chs("这是一段话");

    if (turn_info())
    {
        puts("真！");
        printf("%d\n", turn_info());
    }
    else
    {
        puts("一眼假！");
        printf("%d\n", turn_info());
    }
    puts("**************");

    box1.set_var(60);
    box2.set_var(30);

    if (box1.compare(box2))
    {
        puts("box1 更大");
    }
    else
    {
        puts("非也");
    }
    

    return 0;
}

bool turn_info(void)
{
    return 2 >= 2;
}
