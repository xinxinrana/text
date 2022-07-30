//////////////////////////////
// 功能：链表的完整实现
// 重要：接口实现与处理数据类型耦合度要低，尽量不相关
// 版本： 1.0
//
/////////////////////////////
#include <iostream>
#include <string>
using namespace std;

struct Film
{
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

struct LinkedList
{
    Item *item;
    LinkedList *next;
};

//拷贝数据
Item *copyItem(const Item *item)
{
    Item *newItem = new Item;

    newItem->filmName = item->filmName;
    newItem->filmID = item->filmID;

    return newItem;
}

//初始化
LinkedList *createLinkedList(const Item *item)
{
    LinkedList *newLinkedList = new LinkedList;

    newLinkedList->item = copyItem(item);
    newLinkedList->next = nullptr;

    return newLinkedList;
}
//末尾添加
LinkedList *addItem(LinkedList *list, const Item *item)
{
    while (list->next != nullptr)
    {
        list = list->next;
    }
    list->next = new LinkedList;
    list = list->next;

    list->item = copyItem(item);
    list->next = nullptr;

    return list;
}

//封装末尾添加  高度耦合项目的封装
LinkedList *addItemDetailed(LinkedList *list, string filmName, const long filmID)
{
    Item *item = new Item;
    item->filmName = filmName;
    item->filmID = filmID;
    LinkedList *newList = addItem(list, item);
    delete item;
    return newList;
}

//输出film项到控制台
void showItem(Item *item)
{
    cout << "filmName: " << item->filmName << endl;
    cout << "filmID: " << item->filmID << endl<<endl;
}

//输出整个链表
int showItemAll(LinkedList *list)
{
    int count = 0;

    while (list->item != nullptr)
    {
        showItem(list->item);
        count++;
        if(list->next == nullptr){
            break;
        }
        list = list->next;
    }

    return count;
}

//获取链表末尾 存在型末尾
LinkedList *getLinkedListEnd(LinkedList *head){
    LinkedList *itor = head;
    while (itor->next != nullptr)
    {
        itor =itor->next;
    }
    return itor;
}

int main(int argc, char const *argv[])
{
    Item *movies = new Item;
    movies->filmName = "变形金刚";
    movies->filmID = 1L;

    LinkedList *head = createLinkedList(movies);
    LinkedList *itor = head;

    itor = addItemDetailed(itor, "喜羊羊", 2L);
    itor = addItemDetailed(itor, "洋洋大冒险", 3L);

    showItemAll(head);

    system("pause");
    return 0;
}
