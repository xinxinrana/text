//派生类
//以私有继承基类
#include <stdio.h>
#include<iostream>
#include<string.h>

using namespace std;

//基类
class book
{
private:
    int pages;

public:
    int text;
    long id;
    char name[128];

    void set_pages(void)
    {
        cout<<"总页码"<<endl;
        cin>>pages;
    }
    void print_info(void)
    {
        puts("*********");
        printf("%s：%s\n","书籍名称",name);
        printf("%s：%ld\n","书籍id",id);
        printf("%s：%d\n","书籍页数",pages);
        puts("*********");

    }
};

//派生类        继承模式：私有    //class 派生类名 ： 继承类型  基类名
class school : private book      
{
public:
    double text;
    int floor;
    int typesof;

    void print_info(void)       //派生覆盖基类！！
    {
        puts("*********");
        printf("%-20s* %s\n","书名:",name);
        printf("%-20s* %ld\n","书籍🆔:",id);
        printf("%-20s* %d\n","楼层:",floor);
        printf("%-20s* %d\n","书籍类型:",typesof);
        printf("%-20s* %.2lf\n","text:",text);
        puts("*********");
    }

    void set_name(void)
    {
        cout<<"输入书籍名称"<<endl;
        cin>>name;
    }

    void set_id(void)
    {
        cout<<"输入书籍🆔"<<endl;
        cin>>id;
    }
};

int main(int argc, char const *argv[])
{   
    //派生类
    school bok1;

    // strncpy(bok1.name,"C++进阶",128);   //同理
    // bok1.id = 101002;       //访问私有成员！报错

    //替换上面两个
    bok1.set_name();
    bok1.set_id();

    bok1.floor = 7;             //公开成员直接操作
    bok1.typesof = 2;
    bok1.text = 12.12;

    bok1.print_info();          //方法调用；

    //基类
    book bbk1;
    strncpy(bbk1.name,"中文编程",128);
    bbk1.id = 101210;
    bbk1.set_pages();

    bbk1.print_info();
    
    
    return 0;
}

