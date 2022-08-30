//泛型库
//STL C++标准模板库   
//这章关于Vector
//另外，C++提供基础的标准函数库
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

bool ab(int a, int b) { return (a < b);}

int main(int argc, char const *argv[])
{
    //容器创建
    vector<int> vec;

    //插入数据
    vec.push_back(1);
    vec.push_back(4);

    //实际容器大小
    // cout << "vecSize = " << vec.size() << endl;

    vec.push_back(3);
    //预留容器大小（跟随变化，一定是比size大的）
    // cout << "vecCapacity = " << vec.capacity() << endl; 

    //迭代器
    vector<int>::iterator i = vec.begin();
    while(i != vec.end()) {
        cout << *i << endl;
        i++;
    } 

    //算法
    //排序
    sort(vec.begin(), vec.end());

    

    i = vec.begin();
    cout << "*****"<<endl;
    while(i != vec.end()) {
        cout << *i << endl;
        i++;
    }


    system("pause");
    return 0;
}
