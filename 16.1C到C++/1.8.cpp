//派生类
//书本归类
#include <stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

//基类
class book
{
public:
    long id;
    char name[128];

};

//派生类
class school : public book      //class 派生类名 ： 继承类型  基类名
{
public:
    int floor;
    int typesof;
    void print_info(void)
    {
        printf("%-20s* %s\n","书名:",name);
        printf("%-20s* %ld\n","书籍🆔:",id);
        printf("%-20s* %d\n","楼层:",floor);
        printf("%-20s* %d\n","书籍类型:",typesof);
    }
};

int main(int argc, char const *argv[])
{
    school bok1;
    strncpy(bok1.name,"C++进阶",128);
    bok1.id = 101002;
    bok1.floor = 7;
    bok1.typesof = 2;

    bok1.print_info();

    book bbk1;
    strncpy(bbk1.name,"中文编程",128);
    bbk1.id = 101210;

    printf("书籍：%s\n",bbk1.name);
    
    
    return 0;
}

