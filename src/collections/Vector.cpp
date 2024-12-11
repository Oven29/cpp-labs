#include "collections/Vector.h"
#include <algorithm>
#include <iostream>
#include <stdexcept>

namespace {

const size_t kDefaultVectorSize = 8;
const size_t kGrowthFactor = 2;

void ResizeVector(Vector::VecInt& vector) {
    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    size_t newVectorSize = vector.capacity * kGrowthFactor;

    if (newVectorSize <= vector.capacity) {
        throw std::runtime_error("vector capacity overflow");
    }

    int* buffer = nullptr;
    try {
        buffer = new int[newVectorSize];
    } catch (const std::bad_alloc&) {
        throw std::runtime_error("failed to allocate memory");
    }

    std::copy(vector.vector, vector.vector + vector.size, buffer);

    delete[] vector.vector;

    vector.vector = buffer;
    vector.capacity = newVectorSize;
}

}

namespace Vector {

VecInt CreateVector() {
    int* array = new int[kDefaultVectorSize];

    return {.size = 0, .capacity = kDefaultVectorSize, .vector = array};
}

void DeleteVector(VecInt& vector) {
    vector.size = 0;
    vector.capacity = 0;

    delete[] vector.vector;

    vector.vector = nullptr;
}

int& GetElement(VecInt& vector, size_t index) {
    if (index >= vector.size) {
        throw std::runtime_error("index out of bound");
    }

    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    return vector.vector[index];
}

int GetElement(const VecInt& vector, size_t index) {
    if (index >= vector.size) {
        throw std::runtime_error("index out of bound");
    }

    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    return vector.vector[index];
}

void PushBack(VecInt& vector, int element) {
    if (!vector.vector) {
        throw std::runtime_error("invalid vector");
    }

    if (vector.size == vector.capacity - 1) {
        ResizeVector(vector);
    }

    vector.size++;
    vector.vector[vector.size] = element;
}

void PrintVector(const Vector::VecInt& vector) {
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
