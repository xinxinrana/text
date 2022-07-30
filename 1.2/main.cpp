#include <iostream>
#include "LinkedList.h"


int main() {
    cout << "Hello, World!" << endl;

    LinkedList *flimlist_1 = createLinkedList();
    addItem(flimlist_1,"让子弹飞",1001);
    addItem(flimlist_1,"邪不压正",1002);
    addItem(flimlist_1,"一步之遥",1003);

    showItemAll(flimlist_1);

    return 0;
}
