#pragma once
#include <cstddef>
#include <new>
#include <memory>

namespace despair {
class Arena {
private:
    char* buffer;
    std::size_t offset;
    std::size_t capacity;
public:
    explicit Arena(std::size_t size)
        : buffer(::operator new(size)), capacity(size), offset(0);

    ~Arena() {
        ::operator delete(buffer_);
    }
};
} // namespace despair
