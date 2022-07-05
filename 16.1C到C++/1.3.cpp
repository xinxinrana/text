//cout 
#include<iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    char str[] = {"Hello C++"};
    char str_in1[64];
    char str_in2[64];

    bool tx = false;

    tx = true;
    // cout<<"这个字符串是："<<str<<endl;
    // cin>>str_in1>>str_in2;
    // cout<<"你输入的是："<<str_in1<<'|'<<str_in2<<endl;

    if (tx)
    {
        cerr<<"严重错误"<<endl;
    }
    

    return 0;
}
