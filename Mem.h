#pragma once
#include "MemoryManager.h"

// Простейший менеджер памяти, использует ::new и ::delete
class Mem: public MemoryManager
{
public:
    Mem(size_t sz): MemoryManager(sz) {}

    void* allocMem(size_t sz)
    {
        return malloc(sz);
    }

    void freeMem(void* ptr)
    {
        free(ptr);
    }
};
