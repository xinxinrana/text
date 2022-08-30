#include <iostream>

namespace ASpace
{
    int a = 10;
}

namespace BSpace
{
    int a = 10;
}

namespace CSpace
{
    int b = 10;
}

int main()
{
    {
        //using 是绑定在块中的
        using namespace ASpace;
        using namespace CSpace;

        std::cout << "ASpace "<<"a = " << a << std::endl;
        std::cout << "CSpace "<<"b = " << b << std::endl<<std::endl;
    }
    {

        using namespace BSpace;

        std::cout << "BSpace "<<"a = " << a << std::endl;
    }

    system("pause");
    return 0;
}