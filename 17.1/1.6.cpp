//如果构造函数私有化
#include<stdio.h>

class Animal
{
    private:
    double weight;
    double height;
    Animal()        //构造函数 空值  若声明为私人的 那么就不能以没有参数的方式去创建一个对象
    {
        weight = 10;
        height = 10;
    }

    public:
    Animal(double wei = 10,double hei = 10)
    {
        height = hei;
        weight = wei;
    }
    void get_height(void)
    {
        printf("%.2lf\n",height);
    }
    void get_weight(void)
    {
        printf("%.2lf\n",weight);
    }
};

int main(int argc, char const *argv[])
{
    Animal animal_1(30);
    animal_1.get_weight();

    return 0;
}
