#pragma once

namespace despair {
template <typename To, typename From>
bool is_instance_of(const From* Val) {
    return To::is_class_of(Val);
}

template <typename To, typename From>
To* dyn_cast(From* Val) {
    return is_instance_of<To>(Val) ? static_cast<To*>(Val) : nullptr;
}

template <typename To, typename From>
const To* dyn_cast(const From* Val) {
    return is_instance_of<To>(Val) ? static_cast<const To*>(Val) : nullptr;
}
} // namespace despair
