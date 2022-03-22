//程序睡眠
#include <stdio.h>
// #include <unistd.h>
#include<time.h>
#include<sys/time.h>


int time_to_str(const time_t ti,char *time_str);

int main(int argc, char const *argv[])
{
    time_t temp_time = time(0);
    // struct tm *sttm = localtime(&temp_time);
    char time_str[128];

    // yyyy-mm-dd hh24:mi:ss格式输出，此格式用得最多
    // printf("%04u-%02u-%02u %02u:%02u:%02u\n", sttm->tm_year + 1900, sttm->tm_mon + 1,
    //        sttm->tm_mday, sttm->tm_hour, sttm->tm_min, sttm->tm_sec);

    time_to_str(temp_time,time_str);
    puts(time_str);

    
    return 0;
}


int time_to_str(const time_t ti,char *time_str)
{
    struct tm *sttm = localtime(&ti);
    sprintf(time_str,"%04u-%02u-%02u %02u:%02u:%02u",sttm->tm_year + 1900, sttm->tm_mon + 1,
           sttm->tm_mday, sttm->tm_hour, sttm->tm_min, sttm->tm_sec);
    if((time_str[0])!='\0')
        return 0 ;
    else
        return -1;
}



