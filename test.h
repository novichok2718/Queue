#include "Queue.cpp"
#include "Mem.h"

class TestQueue {
    Queue* queue;
    public:
        TestQueue() {
            Mem mem(1000);
            queue = new Queue(mem);
        }
        void insertTest(void* target, size_t targetSize ,void* elem, size_t elemSize);
        void pushTest(size_t size);
        void popTest();
        void findTest(void* elem, size_t targetSize);
        void clear();
        void removeEverySecondElem();
        void removeTest(Container::Iterator* iter);
        void printElem();
    ~TestQueue() {
        if (!queue->empty()) {
            queue->clear();
        }
        delete queue;
    }
};