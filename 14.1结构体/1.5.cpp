//结构体嵌套
#include<stdio.h>
#define MAXTITL 64
#define MAXAUTL 64
#define MAXBKS 24
#define CHARS 64

struct page
    {
        char page_name[CHARS];
        int print_lv;
        int page_start;
        int page_end;
    };

struct book
{
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    struct page page_1,
    page_2;
};


void putchar_s(const char ch,const int num);
int main(int argc, char const *argv[])
{

    struct book book_1{
        "杀手007",
        "佚名",
        99,
        {
            "扉页",
            3,
            0,
            13,
        },
        {
            "前言",
            1,
            14,
            16,
        },
    };

    printf("书籍名：%s 作者：%s 价格：%.2f\n",book_1.title,book_1.author,book_1.value);
    putchar_s(' ',4);
    printf("内容：%s 印刷要求：%d级 开始页码：%d 结束页码：%d\n"
    ,book_1.page_1.page_name,book_1.page_1.print_lv,book_1.page_1.page_start,book_1.page_1.page_end);

    putchar_s(' ',4);
    printf("内容：%s 印刷要求：%d级 开始页码：%d 结束页码：%d\n"
    ,book_1.page_2.page_name,book_1.page_2.print_lv,book_1.page_2.page_start,book_1.page_2.page_end);
    return 0;
}


void putchar_s(const char ch,const int num)
{
    for (int i = 0; i < num; i++)
    {
        putchar(ch);
    }
    
}