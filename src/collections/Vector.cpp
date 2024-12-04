#include "collections/Vector.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace {

const size_t kDefaultVectorSize = 8;
const size_t kGrowthFactor = 2;

void ResizeVector(Vector::VecChar& vector) {
    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    size_t newVectorSize = vector.capacity * kGrowthFactor;
    char* buffer = new char[newVectorSize];

    std::copy(vector.vector, vector.vector + vector.size, buffer);

    char* oldVector = vector.vector;
    vector.vector = buffer;

    vector.capacity = newVectorSize;

    delete[] oldVector;
}
}  // namespace

namespace Vector {
VecChar CreateVector() {
    char* array = new char[kDefaultVectorSize];

    return {.size = 0, .capacity = kDefaultVectorSize, .vector = array};
}

void DeleteVector(VecChar& vector) {
    vector.size = 0;
    vector.capacity = 0;

    delete[] vector.vector;

    vector.vector = nullptr;
}

char& GetElement(VecChar& vector, size_t index) {
    if (index >= vector.size) {
        throw std::runtime_error("index out of bound");
    }

    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    return vector.vector[index];
}

char GetElement(const VecChar& vector, size_t index) {
    if (index >= vector.size) {
        throw std::runtime_error("index out of bound");
    }

    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    return vector.vector[index];
}

void PushBack(VecChar& vector, char element) {
    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    if (vector.size >= vector.capacity) {
        ResizeVector(vector);
    }

    vector.vector[vector.size++] = element;
}

void PrintVector(const Vector::VecChar& vector) {
    std::cout << '[';

    for (size_t i = 0; i < vector.size; i++) {
        std::cout << Vector::GetElement(vector, i);
        if (i != vector.size - 1) {
            std::cout << ", ";
        }
    }

    if (vector.size > 0) {
        std::cout << Vector::GetElement(vector, vector.size - 1);
    }

    std::cout << ']' << std::endl;
}

}  // namespace Vector
