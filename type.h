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

inline DataTypeDescriptor operator|(DataTypeDescriptor a, DataTypeDescriptor b)
{
    return static_cast<DataTypeDescriptor>(static_cast<int>(a) | static_cast<int>(b));
}

class Type {
public:
    DataType type;
    DataTypeDescriptor descriptor;

    inline bool isConstant()
    {
        return static_cast<bool>(this->descriptor | DataTypeDescriptor::CONSTANT);
    }
};
}; // namespace despair
