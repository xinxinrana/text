//多态的多种调用方法 友元函数调用
#include<stdio.h>

class Animal
{
    public:
    virtual void put() = 0;
    void put_a(void);
    friend void put_f(Animal *animal);
};

class Dog:public Animal
{
    public:
    void put(void)
    {
        printf("woof");
    }
};

class Cat:public Animal
{
    public:
    void put(void)
    {
        printf("meow");
    }
};

void Animal::put_a(void)
{
    printf("put_s for:  >>");
    put();
    putchar('\n');
}

void put_f(Animal *animal)      //
{
    printf("friend for:  >>");
    animal->put();
    putchar('\n');
}



int main(int argc, char const *argv[])
{
    Dog dog1;
    Cat cat1;

    Animal *animal;

    animal = &dog1;
    animal->put();  putchar('\n');      //直接调用
    put_f(animal);                      //友元函数调用
    animal->put_a();                    //基函数的成员函数调用

    puts("/------------/");

    animal = &cat1;
    animal->put();  putchar('\n');
    put_f(animal);
    animal->put_a();

    return 0;
}
