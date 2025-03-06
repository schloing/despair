#pragma once
#include <cstdint>

namespace despair {
enum DataType {
    VOID,
    INTEGRAL,
};

enum class DataTypeDescriptor : uint8_t {
    CONSTANT = 0,
    POINTER = 1 << 0,
};

class Type {
public:
    DataType type;
    DataTypeDescriptor descriptor;
};
}; // namespace despair
