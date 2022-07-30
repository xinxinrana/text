//
// Created by xy on 2022/7/9.
// Version 1.0
//
#include "LinkedList.h"

Item *copyItem(const Item *item)
{
    Item *newItem = new Item;

    newItem->filmName = item->filmName;
    newItem->filmID = item->filmID;

    return newItem;
}

LinkedList *createLinkedList(void) {
    LinkedList *newLinkedList = new LinkedList;

    newLinkedList->item = nullptr;
    newLinkedList->next = nullptr;

    return newLinkedList;
}

LinkedList *addItem(LinkedList *list, const Item *item) {
    if(list->item== nullptr)
    {
        list->item = copyItem(item);
        list->next = nullptr;
    }
    else
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

}

LinkedList *addItem(LinkedList *list, string filmName, const long filmID) {
    Item *item = new Item;
    item->filmName = filmName;
    item->filmID = filmID;
    LinkedList *newList = addItem(list, item);
    delete item;
    return newList;
}

void showItem(Item *item) {
    cout << "filmName: " << item->filmName << endl;
    cout << "filmID: " << item->filmID << endl<<endl;
}

int showItemAll(LinkedList *list) {
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

LinkedList *getLinkedListEnd(LinkedList *head) {
    LinkedList *itor = head;
    while (itor->next != nullptr)
    {
        itor =itor->next;
    }
    return itor;
}
