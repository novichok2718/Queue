#include "test.cpp"
#include "Mem.h"
#include <chrono>

int main()
{
    TestQueue* tq = new TestQueue();
    tq->pushTest(10);
    //tq->removeEverySecondElem();
    //tq->printElem();
    size_t tar = 9;
    size_t elem = 99;
    tq->insertTest(&tar, sizeof(size_t), &elem, sizeof(size_t));
    tq->printElem();
    delete tq;
    return 0;
}