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
    private:
    QueueItem* curr;
    public:
    Iterator(QueueItem* curr) : curr(curr) {}
    Iterator(List* lst)
    {
        curr = lst->head;
    } 

    QueueItem* getCurrent()
    {
        return curr;
    }
    
    void setCurrent(QueueItem* curr)
    {
        this->curr = curr;
    }

    void* getElement(size_t &size)
    {
        size = curr->size;
        return curr->elem;
    }
        
    bool hasNext()
    {
        return curr->next != NULL;
    }
        
    void goToNext()
    {
        curr = curr->next;
    }
        
    bool equals(Iterator *right)
    {
        size_t size = 0;
        void* rhs = right->getElement(size);
        return curr->size == size && !memcmp(rhs, curr->elem, size);
    }
};

class Queue 
{
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
    
    int insert(Iterator *iter, void *elem, size_t size);

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