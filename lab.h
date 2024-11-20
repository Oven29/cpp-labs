#pragma once

#if defined(size_t)
#else
typedef unsigned long size_t;
#endif

namespace lab {

const int kStaticArraySize = 3;
using CmpFn = bool (*)(int, int);

enum class Task {
    Static = 1,
    Dynamic
};

enum class SortMethod {
    BubbleSort,
    SelectionSort
};

struct SortBenchmark {
    int swaps = 0;
    int comparisation = 0;
};

void SelectMethodAndRun();
void RunStaticTask();
void RunDynamicTask();

void ExecuteSortingTask(SortMethod sorting, CmpFn cmp, int* initialArr, size_t size);

void SelectionSort(CmpFn cmp, int* arr, size_t size, SortBenchmark& result);
void BubbleSort(CmpFn cmp, int* arr, size_t size, SortBenchmark& result);

void Start();
}  // namespace lab
