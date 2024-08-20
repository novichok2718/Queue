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

class QueueIterator : public Container::Iterator
{        
    private:
    QueueItem* curr;
    public:
    QueueIterator(QueueItem* curr) : curr(curr) {}
    QueueIterator(List* lst)
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

    void* getElement(size_t &size) override
    {
        size = curr->size;
        return curr->elem;
    }
        
    bool hasNext() override
    {
        return curr->next != NULL;
    }
        
    void goToNext() override
    {
        curr = curr->next;
    }
        
    bool equals(Container::Iterator *right) override
    {
        size_t size = 0;
        void* rhs = right->getElement(size);
        return curr->size == size && !memcmp(rhs, curr->elem, size);
    }
    ~QueueIterator() = default;
};

class Queue : AbstractQueue
{
    List* lst;
    public:
    Queue(MemoryManager &mem) : AbstractQueue(mem)
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
    
    int insert(Container::Iterator *iter, void *elem, size_t size);

    int size();
    
    size_t max_bytes();

    Container::Iterator* find(void *elem, size_t size);    
    
    Container::Iterator* newIterator();
    
    void remove(Container::Iterator *iter);
    
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