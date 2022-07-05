// time
#include <stdio.h>
#include<string.h>
#include <ctime>

#define SIZE_STR 128

int main(int argc, char const *argv[])
{
    clock_t start_t = clock();
    for (int i = 0; i < 99999; i++)
    {
        for (int i = 0; i < 99999; i++)
        {
            continue;
        }
        
    }
    
    clock_t end_t = clock();

    printf("总用时：%f",(double)(end_t - start_t)/CLOCKS_PER_SEC);
    

    return 0;
}
