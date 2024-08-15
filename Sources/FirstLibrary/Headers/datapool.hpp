#pragma once

#include <cstddef>
#include <cstdint>
#include <string>
#include <string.h>
#include <vector>

template<typename T>
class DynamicDataPool {
public:
    std::size_t Size;
    T* Memory;
    static constexpr std::size_t ElementSize = sizeof(T);

    DynamicDataPool(): Size(0), Memory(nullptr) {}
    DynamicDataPool(std::size_t Size): Size(Size), Memory((T*)malloc(Size * ElementSize)) {}
    DynamicDataPool(DynamicDataPool& pool): Size(pool.Size), Memory((T*)malloc(pool.Size)) {
        memcpy(Memory, pool.Memory, pool.Size);
    }
    DynamicDataPool(DynamicDataPool&& pool): Size(pool.Size), Memory(pool.Memory) {
        pool.Size = 0;
        pool.Memory = nullptr;
    }
    ~DynamicDataPool() {
        free(Memory);
    }
};

template<typename T>
void FillDataPool(DynamicDataPool<T>* pool, std::uint8_t value) {
    if (pool->Memory == nullptr) return;
    memset(pool->Memory, value, pool->Size);
}

template<typename T>
void PrintDataPool(DynamicDataPool<T>* pool) {
    if (pool == nullptr) return;
    for (std::size_t i = 0; i < pool->Size * pool->ElementSize; ++i) {
        printf("%02X ", ((std::uint8_t*)pool->Memory)[i]);
    }
}

void Test() {
    DynamicDataPool<int> empty{};
    DynamicDataPool<int> full{6};
    DynamicDataPool<int> copied{full};
    DynamicDataPool<int>&& full_moved = std::move(full);
    DynamicDataPool<int> moved{full_moved};
    PrintDataPool(&moved);
}