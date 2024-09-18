#include "Queue.cpp"
#include "Mem.h"

class TestQueue {
    Queue* queue;
    public:
        TestQueue() {
            Mem mem(1000);
            queue = new Queue(mem);
        }
        void insertTest(Container::Iterator* iter ,void* target, size_t targetSize);
        void pushTest();
        void popTest();
        void findTest(void* elem, size_t targetSize);
        void clear();
        void removeTest(Container::Iterator* iter);
    ~TestQueue() {
        if (!queue->empty()) {
            queue->clear();
        }
        delete queue;
    }
};