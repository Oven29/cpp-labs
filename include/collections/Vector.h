#pragma once

#include <cstddef>

namespace Vector {
struct VecChar {
    size_t size{};
    size_t capacity{};
    char* vector{};
};

[[nodiscard]] VecChar CreateVector();
void DeleteVector(VecChar& vector);

[[nodiscard]] char& GetElement(VecChar& vector, size_t index);
[[nodiscard]] char GetElement(const VecChar& vector, size_t index);
void PushBack(VecChar& vector, char element);
void PrintVector(const VecChar& vector);
}  // namespace Vector
