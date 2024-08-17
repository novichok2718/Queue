#include "QueueAbstract.h"

struct QueueItem {
    void *elem;
    size_t size;
    QueueItem* next;
};

struct List {
    QueueItem* head;
    QueueItem* tail;
    size_t size;
};

class Iterator
{        
    QueueItem* curr;
    public:
    Iterator(QueueItem* curr) : curr(curr) {}
    Iterator(List* lst)
    {
        curr = lst->head;
    } 
    void* getElement(size_t &size);
        
    bool hasNext();
        
    void goToNext();
        
    bool equals(Iterator *right);
};

class Queue {
    List* lst;
    public:
    Queue()
    {
        lst = (List*)malloc(sizeof(List));
        lst->head = NULL;
        lst->tail = NULL;
        lst->size = 0;
    }

    int push(void *elem, size_t size);
    
    int pop();
    
    void* front(size_t &size);

    void* back(size_t &size);
    
    //int insert(Iterator *iter, void *elem, size_t size);

    int size();
    
    size_t max_bytes();

    //Iterator* find(void *elem, size_t size);    
    
    //Iterator* newIterator();
    
    //void remove(Iterator *iter);
    
    void clear();
    
    bool empty();
    ~Queue()
    {
        if (lst)
        {
            clear();
        }
    }
};