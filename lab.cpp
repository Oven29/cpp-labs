#include "lab.h"
#include <iomanip>
#include <iostream>
#include "randmodule.h"

namespace {
bool CmpAsc(int a, int b) {
    return a < b;
}

bool CmpDesc(int a, int b) {
    return a > b;
}

void PrintArray(int* arr, size_t size) {
    std::cout << "[";

    for (size_t i = 0; i < size; ++i) {
        std::cout << arr[i];

        if (i != size - 1) {
            std::cout << ",";
        }
    }

    std::cout << "]";
}

void PrintInitialArray(int* arr, size_t size) {
    std::cout << "Исходный массив: ";

    PrintArray(arr, size);

    std::cout << "\n\n";
}

void PrintArrayFormatted(int* arr, size_t size, lab::SortMethod sortMethod, int swaps, int compares) {
    switch (sortMethod) {
        case lab::SortMethod::SelectionSort:
            std::cout << "Сортировка выбором:   ";
            break;
        case lab::SortMethod::BubbleSort:
            std::cout << "Сортировка пузырьком: ";
            break;
    }

    PrintArray(arr, size);
    std::cout << ", Перестановки: " << swaps << ", " << "Сравнения: " << compares << ", " << "\n";
}

}  // namespace

void copyArray(int* source, int* destination, size_t size) {
    for (size_t i = 0; i < size; ++i) {
        destination[i] = source[i];
    }
}

namespace lab {
void SelectMethodAndRun() {
    int lab = 0;

    std::cout << "Выберите задание:\n"
              << "1 - Сортировка статического массива\n"
              << "2 - Сортировка динамического массива\n"
              << "Ваш выбор: ";

    std::cin >> lab;

    switch (static_cast<Task>(lab)) {
        case Task::Static:
            RunStaticTask();
            break;
        case Task::Dynamic:
            RunDynamicTask();
            break;
        default:
            std::cout << "Неверной ввод заданий!" << std::endl;
    }
}

void RunStaticTask() {
    int staticArr[kStaticArraySize];
    randmodule::FillArray(staticArr, kStaticArraySize);

    PrintInitialArray(staticArr, kStaticArraySize);

    ExecuteSortingTask(SortMethod::BubbleSort, CmpAsc, staticArr, kStaticArraySize);
    ExecuteSortingTask(SortMethod::BubbleSort, CmpAsc, staticArr, kStaticArraySize);
    ExecuteSortingTask(SortMethod::BubbleSort, CmpDesc, staticArr, kStaticArraySize);
    std::cout << "\n";

    ExecuteSortingTask(SortMethod::SelectionSort, CmpAsc, staticArr, kStaticArraySize);
    ExecuteSortingTask(SortMethod::SelectionSort, CmpAsc, staticArr, kStaticArraySize);
    ExecuteSortingTask(SortMethod::SelectionSort, CmpDesc, staticArr, kStaticArraySize);
    std::cout << "\n";
}

void RunDynamicTask() {
    int size = 0;
    std::cout << "Размер массива: ";
    std::cin >> size;

    if (size <= 0) {
        std::cout << "Размер массива должен быть больше 0!" << std::endl;
        return;
    }

    int* dynamicArr = new int[size];
    randmodule::FillArray(dynamicArr, size);
    int* arrCopy = new int[size];
    copyArray(dynamicArr, arrCopy, size);

    PrintInitialArray(dynamicArr, size);

    ExecuteSortingTask(SortMethod::BubbleSort, CmpAsc, dynamicArr, size);
    ExecuteSortingTask(SortMethod::SelectionSort, CmpAsc, arrCopy, size);

    delete[] dynamicArr;
}

void ExecuteSortingTask(SortMethod sorting, CmpFn cmp, int* arr, size_t size) {
    if (!arr) {
        return;
    }

    SortBenchmark benchmark = {0, 0};

    switch (sorting) {
        case SortMethod::BubbleSort:
            BubbleSort(cmp, arr, size, benchmark);
            break;
        case SortMethod::SelectionSort:
            SelectionSort(cmp, arr, size, benchmark);
            break;
    }

    PrintArrayFormatted(arr, size, sorting, benchmark.swaps, benchmark.comparisation);
}

void SelectionSort(CmpFn cmp, int* arr, size_t size, SortBenchmark& benchmark) {
    if (!arr) {
        return;
    }

    for (size_t i = 0; i < size - 1; ++i) {
        size_t pivotIndex = i;

        for (size_t j = i + 1; j < size; ++j) {
            if (cmp(arr[j], arr[pivotIndex])) {
                pivotIndex = j;
            }
            ++benchmark.comparisation;
        }

        if (pivotIndex != i) {
            int temp = arr[i];
            arr[i] = arr[pivotIndex];
            arr[pivotIndex] = temp;

            ++benchmark.swaps;
        }
    }
}

void BubbleSort(CmpFn cmp, int* arr, size_t size, SortBenchmark& benchmark) {
    if (!arr) {
        return;
    };

    bool anySwapped = false;

    for (size_t i = 0; i < size - 1; ++i) {
        anySwapped = false;

        for (size_t j = 0; j < size - i - 1; ++j) {
            if (!cmp(arr[j], arr[j + 1]) && arr[j] != arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                anySwapped = true;

                ++benchmark.swaps;
            }

            ++benchmark.comparisation;
        }
        if (!anySwapped) {
            break;
        }
    }
}

void Start() {
    char input = 'y';

    while (input == 'y') {
        SelectMethodAndRun();

        std::cout << "Продолжить? (y/n): ";
        std::cin >> input;
    }
}
}  // namespace lab
