//
// Created by xy on 2022/7/9.
//

#ifndef INC_1_2_LINKEDLIST_H
#define INC_1_2_LINKEDLIST_H

#include <iostream>
#include <string>

using namespace std;

struct Film {
    string filmName;
    long filmID;
};

// 数据耦合度太高 不易修改和维护
// struct linkedList
// {
//     Film file;
//     linkedList *next;
// };

typedef struct Film Item;

struct LinkedList {
    Item *item;
    LinkedList *next;
};


//拷贝数据
Item *copyItem(const Item *item);
//初始化   //创建的一个链表的入口
LinkedList *createLinkedList(void);
//末尾添加
LinkedList *addItem(LinkedList *list, const Item *item);
//封装末尾添加  高度耦合项目的封装
LinkedList *addItem(LinkedList *list, string filmName, const long filmID);
//输出film项到控制台
void showItem(Item *item);
//输出整个链表
int showItemAll(LinkedList *list);
//获取链表末尾 存在型末尾
LinkedList *getLinkedListEnd(LinkedList *head);


#endif //INC_1_2_LINKEDLIST_H
