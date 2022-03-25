//类的成员
#include <stdio.h>

class Box
{
private:
    double length;
    double breadth;
    double heigth;
    double volume;

public:
    void set(double len, double bre, double hei) //默认内联的
    {
        length = len;
        breadth = bre;
        heigth = hei;
    }
    void set_vol(void)                          //默认内联的
    {
        volume = length * breadth * heigth;
    }
    double get(void);
};

double Box::get(void) //非内联      内联：可理解为代码的直接复制粘贴
{
    return volume;
}

int main(int argc, char const *argv[])
{
    Box box1;

    box1.set(12l, 10l, 1l);
    box1.set_vol();
    printf("%.2lf\n", box1.get());

    return 0;
}
