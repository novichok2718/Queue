#include "Queue.h"

int Queue::push(void *elem, size_t size)
{
    if (size > 0)
    {
        QueueItem *newItem = (QueueItem *)malloc(sizeof(QueueItem));
        if (!newItem)
            return 0;

        newItem->elem = malloc(size);
        if (!newItem->elem)
        {
            free(newItem);
            return 0;
        }

        memcpy(newItem->elem, elem, size);
        newItem->size = size;
        newItem->next = NULL;

        if (lst->tail == NULL)
        {
            lst->head = lst->tail = newItem;
        }
        else
        {
            lst->tail->next = newItem;
            lst->tail = newItem;
        }

        ++lst->size;
        return 1;
    }
    return 0;
}

int Queue::pop()
{
    if (lst->head == NULL)
    {
        return 0;
    }
    QueueItem *tmp = lst->head;
    lst->head = lst->head->next;
    free(tmp->elem);
    free(tmp);
    --lst->size;
    return 1;
}

void *Queue::front(size_t &size)
{
    if (lst->head)
    {
        size = lst->head->size;
        return lst->head->elem;
    }
    size = 0;
    return NULL;
}

void *Queue::back(size_t &size)
{
    if (lst->tail)
    {
        size = lst->tail->size;
        return lst->tail->elem;
    }
    size = 0;
    return NULL;
}

int Queue::size() { return lst ? lst->size : 0; }

size_t Queue::max_bytes() { return 1; }

bool Queue::empty() { return lst ? lst->size == 0 : true; }

void Queue::clear()
{
    if (lst == NULL)
    {
        return;
    }

    QueueItem *current = lst->head;
    while (current != NULL)
    {
        QueueItem *next = current->next;
        free(current->elem);
        free(current);
        current = next;
    }

    free(lst);
    lst = nullptr;
}

int Queue::insert(Iterator *iter, void *elem, size_t size)
{
    if (!iter || !iter->getCurrent())
    {
        return 0;
    }

    QueueItem *newItem = (QueueItem *)malloc(sizeof(QueueItem));
    if (!newItem)
    {
        return 0;
    }

    newItem->elem = malloc(size);
    if (!newItem->elem)
    {
        free(newItem);
        return 0;
    }

    memcpy(newItem->elem, elem, size);
    newItem->size = size;

    newItem->next = iter->getCurrent();

    if (iter->getCurrent() == lst->head)
    {
        lst->head = newItem;
    }
    else
    {
        QueueItem *prev = lst->head;
        while (prev->next != iter->getCurrent())
        {
            prev = prev->next;
        }
        prev->next = newItem;
    }

    ++lst->size;
    return 1;
}
