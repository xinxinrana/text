//指向结构的指针
#include <stdio.h>
#include <stdlib.h>
#define CHARS 64

struct book
{
    float value;
    char title[CHARS];
};

void putchar_s(const char ch,const int num )
{
    for (int i = 0; i < num; i++)
    {
        putchar(ch);
    }
    putchar('\n');
    
}
struct book get_book_1(void);
void pull_book_1(struct book books);
int s_gets(char *schar, const int size);
int get_book(struct book *books);
void pull_book(struct book *bookp, int count);

int main(int argc, char const *argv[])
{
    int count = 2;
    int size = sizeof(struct book);
    FILE *fp;
    struct book book_1[10];
    struct book books[10] = {
        {
            134,
            "198",
        },
        {
            43,
            "197",
        },
    };
    struct book *bookp = &books[0];
    struct book *bookp_1 = &book_1[0];

    fp = fopen("结构体存储.txt","w+");
    printf("book的内存占用为: %zd\n",sizeof(struct book));

    pull_book(books, count);
    while (count < 10)
    {
        if((get_book(bookp + count))==0)
        {
            break;
        }
        count++;
        pull_book(&books[0], count); // books == &books[0]
    }

    fwrite(bookp,size,count,fp);
    rewind(fp);
    for (int i = 0; i < count; i++)
    {
        fread(&book_1[i],size,1,fp);
    }

    putchar_s('*',20);
    pull_book(bookp_1,count);
    
    

    return 0;
}


//为book 结构赋值
int get_book(struct book *books)
{
    printf("输入书籍名：\n");
    if (s_gets(books->title, CHARS - 1) == 0)
    {
        printf("\nDone!\n");
        return 0;
    }
    printf("价格：");
    scanf("%f", &books->value);
    while (getchar() != '\n')
        continue;

    return 1;
}

//输出全部内容
void pull_book(struct book *bookp, int count)
{
    //输出全部内容
    printf("%20s| %10s|\n", "书名", "价格");
    for (int i = 0; i < count; i++)
    {
        printf("%18s| %8.2f|\n", (bookp + i)->title, (bookp + i)->value);
    }
}

//字符串get         //可用 size 为 （size —1）
int s_gets(char *schar, const int size)
{
    int count = 0;

    while ((count < size - 1) && ((schar[count] = getchar()) != '\n'))
    {
        count++;
    }

    if (count < size - 1)
    {
        schar[count] = '\0';
    }

    else
    {
        schar[count] = '\0';
        while (getchar() != '\n')
            continue;
    }

    return count;
}

//传递结构体作为参数 和返回结构体
//输出结构体
void pull_book_1(struct book books)
{
    printf("%18s %8.2f\n", books.title, books.value);
}

struct book get_book_1(void)
{
    struct book books = {
        543,
        "9999",
    };
    return books;
}