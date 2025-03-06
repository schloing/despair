#pragma once

namespace despair {
class Arena {
    enum { size = 10000 };
    Arena* next;
    char bin[size];
    Arena(Arena* next)
        : next(next)
    {
    }
    ~Arena()
    {
        if (next)
            delete next;
    }
};

class Node {
    static Arena* arena;
    static char *hwm, *max, *old;
    static void grow();
    void* operator new(size_t x)
    {
        if (hwm + x > max)
            Inst::grow();
        old = hwm;
        hwm += x;
        return old;
    }
    void operator delete(void* ptr)
    {
        if (ptr == old)
            hwm = old;
    }
};
};
