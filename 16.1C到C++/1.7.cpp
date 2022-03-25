//类成员的调用
#include <iostream> 
#include <iomanip>
#include <string>
#include <cstdio>
#include <cstring>
using namespace std;

class student
{
    public:
        char name[20];
        char sex[10];
        float math;
        float english;
        float cprogram;
        void input_name();
        void input_sex();
        void input_math();
        void input_english();
        void input_cprogram();
        void input(class student *stu);     //调用了类的其他成员/函数
        void show_student_massage(class student *stu);
};

void student::input_name()
{
    cout << "输入学生姓名： " << endl;
    cin.getline(name,sizeof(name));
    cout << "学生姓名 ： "<< name << endl;
}

void student::input_sex()
{
    cout << "输入学生性别： " << endl;
    cin.getline(sex,sizeof(sex));
    cout << "性别 ： "<< sex << endl;
}

void student::input_math()
{
    cout << "输入学生数学： " << endl;
    cin >> math;
}

void student::input_english()
{
    cout << "输入学生英语： " << endl;
    cin >> english;
}

void student::input_cprogram()
{
    cout << "输入学生C语言： " << endl;
    cin >> cprogram;
}

void student::show_student_massage(class student *stu)
{
    cout << "学生姓名 ： "<< stu->name << endl;
    cout << "学生性别 ： "<< stu->sex << endl;
    cout << "学生数学 ： "<< stu->math << endl;
    cout << "学生英语 ： "<< stu->english << endl;
    cout << "学生C语言： "<< stu->cprogram << endl;
}

void student::input(class student *stu)
{
    stu->input_name();
    stu->input_sex();
    stu->input_math();
    stu->input_english();
    stu->input_cprogram();
}

int main()
{
    student xiaoming;
    student *xiaoming_point = &xiaoming;
    xiaoming.input(xiaoming_point);
    xiaoming.show_student_massage(xiaoming_point);
    return 0;
}