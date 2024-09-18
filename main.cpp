#include "test.cpp"
#include "Mem.h"
#include <chrono>

int main()
{
    TestQueue* tq = new TestQueue();
    tq->pushTest();
    delete tq;
    return 0;
}