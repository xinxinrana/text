//格式化输出时间（完成）
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdbool.h>

typedef char p_time[64] ;       //时间字符串存放

char key_word[9][5] = {
        {"yyyy"},       //2022
        {"mm"},         //02
        {"dd"},         //27
        {"hh24"},       //13
        {"hh12"},       //11 00 01
        {"hh"},
        {"mi"},
        {"ss"},
        {"00yy"},
    };


void LocalTime_s(char *out_stime, const char *in_fmt, int in_interval = 0);
int key_order(const char *key);
char *int_to_string (const int num);

int main(void)
{
    p_time chs;
    p_time time_fm = {"yyyy-yyyy-mm-dd hh24:mi:ss"};   

    LocalTime_s(chs, "yyyy-mm-dd hh24:mi:ss");      //关键词还有 hh12  hh   默认为24格式
    printf("%s\n",chs);

    LocalTime_s(chs, "hh:mi:ss",60*60*2);     //调整时间为s
    printf("%s\n",chs);

    LocalTime_s(chs, "hh12:mi:ss mm月dd日 ");    //关键词位置可以自定义
    printf("%s\n",chs);

    LocalTime_s(chs, "hh12:mi:ss 00yy年mm月dd日 ");    //关键词位置可以自定义
    printf("%s\n",chs);
    // yyyy-mm-dd hh24:mi:ss
    return 0;
}


//时间格式输出  可调整时间按  可按格式自定义输出样式
void LocalTime_s(char *out_stime, const char *in_fmt, int in_interval)
{
    int char_count = 0;

    bool is_same = false;
    bool start_is_keyword = false;

    char fmt_division[30][10];
    char out_stime_temp[64];
    int str_count = 0;
    int point[30];

    memset(fmt_division,0,sizeof(fmt_division));
    memset(point,0,sizeof(point));
    memset(out_stime_temp,0,sizeof(out_stime_temp));


    time_t time_new = time(0) + in_interval;     //调整时间
    struct tm *time_new_struct = localtime(&time_new);

    while (*(in_fmt+char_count)!='\000')         //统计字符串长度
    {
        char_count++;
    }

    for (int i = 0; i < 8; i++)                  //首字符串是否是关键词
    {
        if((key_word[i][0])==(in_fmt[0]))
        {
            start_is_keyword = true;
            break;
        }
    }

    if (start_is_keyword==false)
    {
        point[str_count] = 0;
        str_count++;
    }
    
    

    for (int i = 0; i < char_count; i++)        //标记字符串头尾
    {
        for (int j = 0; j < (sizeof(key_word)/5); j++)
        {
            for (int k = 0; k < strlen(key_word[j]); k++)
            {
                if (in_fmt[i + k] != key_word[j][k])
                {
                    break;
                }

                if (k == ((strlen(key_word[j])) - 1))   //判断全符合
                {
                    point[str_count] = i;
                    str_count++;

                    is_same = true;
                    i = i + k;

                    point[str_count] = i+1;
                    str_count++;
                }
            }

            if (is_same)
            {
                is_same = false;
                break;
            }
        }
    }

    if((point[str_count-1])!=(char_count))      //末尾标记
    {
        point[str_count] = char_count;
        str_count++;
    }

    for (int i = 0; i < str_count-1; i++)       //分割字符串到数组中
    {
        for (int j = point[i]; j < point[i+1]; j++)
        {
            fmt_division[i][j-point[i]] = in_fmt[j];
        }
    }

    
    for (int i = 0; i < str_count; i++)     //判定字符串并填充时间
    {
        switch (key_order(fmt_division[i]))
        {
        case 0:strcat(out_stime_temp,int_to_string(1900+time_new_struct->tm_year));
            break;
        case 1:strcat(out_stime_temp,int_to_string(1+time_new_struct->tm_mon));
            break;
        case 2:strcat(out_stime_temp,int_to_string(time_new_struct->tm_mday));
            break;
        case 3:strcat(out_stime_temp,int_to_string(time_new_struct->tm_hour));
            break;
        case 4:strcat(out_stime_temp,int_to_string((time_new_struct->tm_hour)%12));
            break;
        case 5:strcat(out_stime_temp,int_to_string(time_new_struct->tm_hour));
            break;
        case 6:strcat(out_stime_temp,int_to_string(time_new_struct->tm_min));
            break;
        case 7:strcat(out_stime_temp,int_to_string(time_new_struct->tm_sec));
            break;
        case 8:strcat(out_stime_temp,int_to_string((1900+time_new_struct->tm_year)%100));
            break;
        
        default:strcat(out_stime_temp,fmt_division[i]);
            break;
        }  
    }

    strcpy(out_stime,out_stime_temp);
    
}

// key_to_oeder
int key_order(const char *key)
{
    int size_min = 0;
    bool is_key = false;

    for (int i = 0; i < (sizeof(key_word)/5); i++)
    {
        size_min = strlen(key)<strlen(key_word[i])?strlen(key):strlen(key_word[i]);
        for (int j = 0; j < size_min; j++)
        {
            if(key[j]!=key_word[i][j])
                break;
            if (j==size_min-1)
            {
                is_key = true;
            }
        }

    if (is_key)
    {
        return i;
    }
    } 
    return -1;
}

char *int_to_string (const int num)
{
    static char temp_string[64];
    memset(temp_string,0,sizeof(temp_string));

    sprintf(temp_string,"%02d",num);

    return  temp_string;
}



