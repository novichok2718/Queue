#include "test.h"
#include "chrono"
#include "assert.h"

void TestQueue::findTest(void *elem, size_t targetSize)
{
    auto iter = queue->find(elem, targetSize);
    size_t size = 0;
    size_t *num = (size_t *)iter->getElement(size);
    std::cout << *num;
}

void TestQueue::pushTest(size_t size)
{
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i != size; ++i)
    {
        queue->push(&i, sizeof(size_t));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
}

void TestQueue::popTest()
{
    auto start = std::chrono::high_resolution_clock::now();
    size_t size = queue->size();
    for (size_t i = 0; i != size; ++i)
    {
        queue->pop();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
}

void TestQueue::removeTest(Container::Iterator *iter)
{
    size_t size = queue->size();
    queue->remove(iter);
    assert(queue->size() == size - 1);
}

void TestQueue::clear()
{
    auto start = std::chrono::high_resolution_clock::now();
    queue->clear();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
}

void TestQueue::insertTest(void* target, size_t targetSize, void *elem, size_t elemSize)
{
    auto start = std::chrono::high_resolution_clock::now();
    Container::Iterator* iter = queue->find(target, targetSize);
    queue->insert(iter, elem, elemSize);
    Container::Iterator *Iter = queue->find(elem, elemSize);
    Iter->goToNext();
    assert(Iter->equals(iter));
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
    delete static_cast<QueueIterator*>(iter);
    delete static_cast<QueueIterator*>(Iter);
}

void TestQueue::removeEverySecondElem()
{
    Container::Iterator *iter = queue->newIterator();
    auto start = std::chrono::high_resolution_clock::now();
    size_t i = 0;
    while (iter->hasNext())
    {
        if (i % 2 == 0)
        {
            queue->remove(iter);
        }
        else
        {
            iter->goToNext();
        }
        ++i;
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << " milliseconds" << std::endl;
    // std::cout<<queue->size()<<std::endl;
    delete static_cast<QueueIterator *>(iter);
}

void TestQueue::printElem()
{
    size_t size = queue->size();
    size_t sizeElem = 0;
    Container::Iterator *iter = queue->newIterator();
    for (size_t i = 0; i != size; ++i)
    {
        size_t *elem = (size_t *)iter->getElement(sizeElem);
        std::cout << *elem << std::endl;
        iter->goToNext();
    }
    delete static_cast<QueueIterator *>(iter);
}
