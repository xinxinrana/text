#include <iostream>

class C{
public:
    C(){m_b = 1;}
    int m_a = 10;
    static int B(){
        
        // m_b++;
        return m_b;
    }
private:
    static int m_b;
};


int main(int argc, char** argv){
    C *c = new C;
    // std::cout << "m_a = " << c->m_a << std::endl; 


    delete(c);

    std::cout << "m_b = " << C::B() << std::endl;
    std::cout << "m_b = " << C::B() << std::endl;


    system("pause");
    return 0;
}