#include "test.h"
#include "chrono"
#include "assert.h"

void TestQueue::findTest(void* elem, size_t targetSize) {
    auto iter = queue->find(elem, targetSize);
    size_t size = 0;
    size_t* num = (size_t*)iter->getElement(size);
    std::cout<<*num;
}

void TestQueue::pushTest() {
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i != 1000000; ++i) {
        queue->push(&i, sizeof(size_t));
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
}

void TestQueue::popTest() {
    auto start = std::chrono::high_resolution_clock::now();
    for (size_t i = 0; i != 1000000; ++i) {
        queue->pop();
    }
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
}

void TestQueue::removeTest(Container::Iterator* iter) {
    size_t size = queue->size();
    queue->remove(iter);
    assert(queue->size() == size - 1);
}

void TestQueue::clear() {
    auto start = std::chrono::high_resolution_clock::now();
    queue->clear();
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
}

void TestQueue::insertTest(Container::Iterator* iter ,void* elem, size_t elemSize) {
    auto start = std::chrono::high_resolution_clock::now();
    queue->insert(iter, elem, elemSize);
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << (end - start).count() / 1e6 << "milliseconds" << std::endl;
}

