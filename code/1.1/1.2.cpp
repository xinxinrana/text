//////////////////////////////
// 功能：C++显示转换学习（测试） 
// 
// 版本： 1.0
//
/////////////////////////////

#include <iostream>

int main(int argc, char const *argv[])
{
    //隐式转换，数据范围最大原则
    std::cout << std::endl<< "隐式转换:" << std::endl;
    int i1=1;
    double j1 = 1.2f;
    std::cout << i1+j1<<std::endl;        // i>double(i);  i 隐式转换为 double 不会丢失数据

    const int i1_const = (const int)i1;   //C风格是可以变量转常量的；   //或则说这不是转 而是读取变量
              i1       = (int)i1_const;   //C风格是可以常量转变量的；   //或则说这不是转 而是读取常量
    // 隐式转换注意问题：
    // 高位截取     
    // 精度丢失


    //使用角度出发：基本数据类型转换
    //可以尝试隐式转换或C分格显式转换   //这种方式还是比较安全的
    std::cout << std::endl<< "C风格显示转换" << std::endl;
    double j2 =12.2;
    std::cout<< (int)j2<<std::endl;
    //使用角度出发：继承类退化


    // 显式强制转换 reinterpret_cast<type>      //不改变指针的值，只是在编译时重新解释指针类型 具有一定危险性
    std::cout << std::endl<< "C++ 显式强制转换 reinterpret_cast<type>:"<< std::endl;
    int i2 = 2;
    int *pi2 = &i2;
    std::cout << *reinterpret_cast<double*>(pi2) <<"|| 原来是 int 2，强制指针转换后没有相应的函数取解释就有问题" << std::endl;      //这样的转换会导致值出错  适合在已经知道内存模型 通过不同类型指针取操作统一模型


    // 指针const与非const转换 const_cast<type>  //感觉没有必要 不可修改直接深拷贝出来修改就行了，除非一定要修改const指针的值；
    std::cout << std::endl<< "cosnt指针转换为非常量指针 const_cast<type> :"<< std::endl;
    int i3 = 5;
    const int *pi3 = &i3;
    //pi3 =3;                                     //报编译错误，在写代码应该有提示错误
    int *pi4 = const_cast<int *>(&pi3[0]);         //可以转换const指针为变量指针
    *pi4 = 1;                                      //可以修改 i4 注意：i4的地址是原来 const int *pi3的
    std::cout<<*pi4 << std::endl; 


    //继承关系的转换 static_cast<type>
    //简单来说就是为了基类 对象用 派生类数据；


    //动态转换 （不会被编译器检测出问题，需要自己额为注意） dynamic_cast<type>
    //继承类与基类之间的指针转换 为空则表示失败 注意判断

    

    system("pause");
    return 0;
}
