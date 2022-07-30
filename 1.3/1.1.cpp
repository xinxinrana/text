#include <iostream>
#include <list>
using namespace std;

class A
{
private:
    
public:
    A();
    ~A();
    virtual int type (int type) const = 0;

protected:

    int temp = 0;

};

A::A()
{

}

A::~A()
{

}  

class B : public A
{
public:
    int type (int type = 10) const{
        return type;
    }

};

class C : public A
{
public:
    int type (int type = 20) const{
        return type;
    }

};


int main(int argc, char const *argv[])
{
    B b;
    C c;

    list <A*> Alist;
    
    
    cout <<"B:"<< b.type()<<"\nC:"<<c.type();
    system("pause");
    return 0;
}
