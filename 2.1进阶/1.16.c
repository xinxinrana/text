//字符串时间转 结构 整形时间
//总结：不建议使用非自创结构体做 自定义运算 黑盒 debug相当耗时！！！
#include <stdio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int time_str_to_time_t(const char *time_str, time_t *ti);

int main(int argc, char const *argv[])
{
    time_t ttt = 0;
    // time_t *tttt = &ttt;
    int sssssss = 0;
    char time_str[64] = {"2022-03-19 17:42:57"} ;
    
    sssssss =  time_str_to_time_t (time_str,&ttt);

    printf("%p\n",&ttt);
    printf("%lu\n",ttt);
    printf("%lu\n",time(0));

    return 0;
}

int time_str_to_time_t(const char *time_str, time_t *ti)
{

    struct tm time_temp_struct;
    struct tm *time_temp_struct_p;
    int temp_t[6] = {0,0,0,0,0,0};
    int temp_t_count = 0;
    int count = 0;
    bool is_collec = false;
    char temp_str[32];
    memset(temp_t,0,6);


    while (time_str[count])
    {
        count++;
    }

    for (int i = 0; i < count; i++)
    {

        if (is_collec == false)
        {
            if (isdigit(time_str[i]))
            {
                is_collec = true;
            }
        }

        if (is_collec == true)
        {
            int str_i = 0;
            while (1)
            {
                temp_str[str_i] = time_str[i];
                str_i++;
                i++;
                if ((isdigit(time_str[i])) == false)
                {
                    temp_t[temp_t_count] = atoi(temp_str);
                    temp_t_count++;
                    memset(temp_str, 0, sizeof(temp_str));
                    is_collec = false;
                    break;
                }
            }
        }
    
    if(temp_t_count == 6)
        break;
    }

    time_t tt = time(0);
    time_temp_struct_p = localtime(&tt);    // Debug   两小时内容
    time_temp_struct = *time_temp_struct_p; // 解决方法 将新建的tm结构初始化为当前状态的；

    time_temp_struct.tm_year = temp_t[0]-1900;
    time_temp_struct.tm_mon  = temp_t[1]-1;
    time_temp_struct.tm_mday = temp_t[2];
    time_temp_struct.tm_hour = temp_t[3];
    time_temp_struct.tm_min  = temp_t[4];
    time_temp_struct.tm_sec  = temp_t[5];

    *ti = mktime(&time_temp_struct);

    return 100;

    // return 0;
}
