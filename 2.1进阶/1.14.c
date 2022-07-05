//时间 结构体
#include <stdio.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    time_t temp_time = time(0);
    struct tm *sttm = localtime(&temp_time);

    // yyyy-mm-dd hh24:mi:ss格式输出，此格式用得最多
    printf("%04u-%02u-%02u %02u:%02u:%02u\n", sttm->tm_year + 1900, sttm->tm_mon + 1,
           sttm->tm_mday, sttm->tm_hour, sttm->tm_min, sttm->tm_sec);

    printf("%04u年%02u月%02u日%02u时%02u分%02u秒\n", sttm->tm_year + 1900,
           sttm->tm_mon + 1, sttm->tm_mday, sttm->tm_hour, sttm->tm_min, sttm->tm_sec);

    // 只输出年月日
    printf("%04u-%02u-%02u\n", sttm->tm_year + 1900, sttm->tm_mon + 1, sttm->tm_mday);

    return 0;
}
