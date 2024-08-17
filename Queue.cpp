#include "Queue.h"

void deleteQueueItem(QueueItem **tmp)
{
    if (tmp && *tmp)
    {
        free((*tmp)->elem);
        free(*tmp);
    }
}

int Queue::push(void *elem, size_t size)
{
    QueueItem *newItem = (QueueItem *)malloc(sizeof(QueueItem));
    newItem->elem = malloc(sizeof(size));
    memcpy(newItem->elem, elem, size);
    newItem->size = size;
    newItem->next = NULL;
    ++lst->size;
    if (!lst->tail && !lst->head)
    {
        lst->tail = newItem;
        lst->head = newItem;
        return 1;
    }
    lst->tail->next = newItem;
    lst->tail = newItem;
    return 1;
}

int Queue::pop()
{
    if (!lst->head)
    {
        return 0;
    }
    QueueItem *tmp = lst->head;
    lst->head = lst->head->next;
    deleteQueueItem(&tmp);
    --lst->size;
    return 1;
}

void *Queue::front(size_t &size)
{
    size = lst->head->size;
    return lst->head;
}

void *Queue::back(size_t &size)
{
    size = lst->tail->size;
    return lst->tail;
}

int Queue::size() { return lst->size; }

size_t Queue::max_bytes() { return sizeof(lst) * lst->size; }

bool Queue::empty() { return lst->size == 0; }

void Queue::clear()
{
    List** list = &lst;
    if (!list || !*list)
    {
        return;
    }
    if ((*list)->head == NULL)
    {
        free(*list);
        *list = NULL;
        return;
    }
    QueueItem *head = (*list)->head;
    QueueItem *next = NULL;

    while (head)
    {
        free(head->elem);
        next = head->next;
        free(head);
        head = next;
    }
    free(*list);
    *list = NULL;
}


