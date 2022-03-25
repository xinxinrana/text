//类 对象       均公开可见
#include <stdio.h>

class Box
{
public:
    int order;
    double length;
    double breadth;
    double heigth;

    double get_volume(void);
    void print_volume(double length_in, double breadth_in, double heigth_in);
    void set(double length_in, double breadth_in, double heigth_in);
};

double Box::get_volume(void)
{
    return length * breadth * heigth;
}
void Box::set(double length_in, double breadth_in, double heigth_in)
{
    length  = length_in;
    breadth = breadth_in;
    heigth  = heigth_in;
}

void Box::print_volume(double length_in, double breadth_in, double heigth_in)
{
    length  = length_in;
    breadth = breadth_in;
    heigth  = heigth_in;

    printf("长：%.1lf 宽：%.1lf 高：%.1lf 体积：%.2lf \n",length,breadth,heigth,length * breadth * heigth);
}

int main(int argc, char const *argv[])
{
    Box box1;
    Box box2;
    Box box3;

    box1.order = 0;
    box1.length = 12l;
    box1.breadth = 10l;
    box1.heigth = 2l;

    printf("%.2lf\n",box1.get_volume());

    box2.set(12l,10l,3l);
    printf("%.2lf\n",box2.get_volume());

    box3.print_volume(13l,12l,1l);


    return 0;
}
