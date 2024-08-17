#include "Queue.h"

void deleteQueueItem(QueueItem** tmp) 
{
    if (tmp && *tmp)
    {
        free((*tmp)->elem);
        free((*tmp)->next);
        free(*tmp);
    }
}

int Queue::push(void* elem, size_t size)
{
    QueueItem* newItem = (QueueItem*)malloc(sizeof(QueueItem));
    newItem->elem = malloc(sizeof(size));
    memcpy(newItem->elem, elem, size);
    newItem->next = NULL;
    if (!lst->tail && !lst->head) 
    {
        lst->tail = newItem;
        lst->head = newItem;
    }
    lst->tail->next = newItem;
    lst->tail = newItem;
    return 1;
}

int Queue::pop() 
{
    if (!lst->tail) 
    {
        return 0;
    }
    QueueItem* tmp = lst->head;
    lst->head = lst->head->next;
    deleteQueueItem(&tmp);
}

void* Queue::front(size_t& size) 
{
    size = lst->head->size;
    return lst->head;
}

void* Queue::back(size_t& size) 
{
    size = lst->tail->size;
    return lst->tail;
}

