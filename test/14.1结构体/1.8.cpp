//伸缩型数组成员
#include <stdio.h>
#include <stdlib.h>


struct Flex{
    size_t count;
    double average;
    double scores[];        //伸缩数组成员
};


int main(int argc, char const *argv[])
{
    struct Flex *p1,*p2;
    // p1 = malloc(sizeof(struct Flex)+3*sizeof(double));  //好像有问题

    return 0;
}

