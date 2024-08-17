#include "QueueAbstract.h"

struct QueueItem {
    void *elem;
    size_t size;
    QueueItem* next;
};

struct List {
    QueueItem* head;
    QueueItem* tail;
};

class Queue {
    List* lst;
    public:
    Queue()
    {
        lst = (List*)malloc(sizeof(List));
    }

    int push(void *elem, size_t size);
    
    int pop();
    
    void* front(size_t &size);

    void* back(size_t &size);
    
    
    //int insert(Iterator *iter, void *elem, size_t size) = 0;
};