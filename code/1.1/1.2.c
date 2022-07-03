////////////////////////
// 链表学习
//
////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE_S 128

struct Film
{
    int isHave;         //存在为真
    int rating;         //评分
    struct Film *next;  //
    char title[SIZE_S]; //标题
};

struct User
{
    long id;                 //用户ID
    struct Film *moviesHead; //用户喜欢电影 的链表头
    struct User *next;       //
    char name[SIZE_S];       //用户名

} User;

//初始化用户
struct User *initUser()
{
    struct User *user = (struct User *)malloc(sizeof(struct User));
    memset(user, 0, sizeof(User));
    user->moviesHead = (struct Film *)malloc(sizeof( struct Film));
    user->moviesHead->isHave = 0;
    return user;
}

//添加用户
struct User *addUser(struct User *useriterator)
{
    useriterator->next = (struct User *)malloc(sizeof(struct User));
    memset(useriterator->next, 0, sizeof(struct User));
    useriterator->next->moviesHead = (struct Film *)malloc(sizeof(struct Film));
    useriterator->next->moviesHead->isHave = 0;
    return useriterator->next;
}

//添加电影
int addMovie(struct User *useriterator,const char *filmName,const long rating)
{
    struct Film *filmIterator = useriterator->moviesHead;
    int moviesCount = 0;
    while (filmIterator->isHave == 1)
    {
        moviesCount++;
        filmIterator = filmIterator->next;
    }
    memcpy(filmIterator->title, filmName, SIZE_S);
    filmIterator->rating = rating;
    filmIterator->isHave = 1;
    filmIterator->next = (struct Film *)malloc(sizeof(struct Film));
    filmIterator->next->isHave =0;
    moviesCount++;

    return moviesCount;
}

//设置用户信息
void setUserInfo(struct User *user,const struct User* userInfo){
    user->id = userInfo->id;
    memcpy(user->name,userInfo->name,SIZE_S);
}

//设置电影信息
void setFilmInfo(struct Film *film,const struct Film *filmInfo){
    film->rating = filmInfo->rating;
    memcpy(film->title,filmInfo->title,SIZE_S);
}


int main(int argc, char const *argv[])
{
    struct User *userHead = initUser();
    struct User *userIter = userHead;

    userIter = addUser(userIter);
    userIter = addUser(userIter);

    int moviesCount = addMovie(userIter,"title",10L);
    moviesCount = addMovie(userIter,"title",10L);
    moviesCount = addMovie(userIter,"title",10L);
    
    printf("%d moviesCount\n",moviesCount);


    system("pause");

    return 0;
}
