//多态的简单实现
#include<stdio.h>

class Animal
{
    public:
    virtual void print() = 0;
    void print_animal(void)
    {
        printf("\n>>");
        print();
        printf("\n");
    }
};

class Dog:public Animal     //继承是 ： 单冒号
{
    public:
    void print(void)
    {
        printf("这是一条狗");
    }
};

class Cat:public Animal
{
    public:
    void print(void)
    {
        printf("这是一只猫");
    }
};


int main(int argc, char const *argv[])
{
    Dog dog1;
    Cat cat1;

    Animal *animal = &dog1;
    animal->print_animal();   

    animal = &cat1;
    animal->print_animal();
    return 0;
}
