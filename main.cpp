#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kTwo = 2;
const int kThree = 3;
const int kFive = 5;
const int kEight = 8;
}  // namespace

void task1() {
    int n = 0;
    int m = 0;
    std::cout << "Введите n и m через пробел (n >= 1, m < n)" << std::endl;
    std::cin >> n >> m;

    if (n < 1) {
        std::cout << "n должно быть больше 1" << std::endl;
        return;
    }

    if (m >= n) {
        std::cout << "m должно быть меньше n" << std::endl;
        return;
    }

    int result = 0;

    for (int i = 0; i <= n; i += kFive) {
        if (i % m != 0) {
            result += 1;
        }
    }

    std::cout << "Результат выполнения 1 программы с n=" << n << " и m=" << m << " - " << result << std::endl;
}

void task2() {
    int a = 0;
    std::cout << "Введите a " << std::endl;
    std::cin >> a;

    int result = 1;

    if (a >= 0) {
        for (int i = 2; i <= kEight; i += kTwo) {
            result *= i * i - a;
        }
    } else {
        for (int i = 3; i <= kThree; i += kThree) {
            result *= i - 2;
        }
    }

    std::cout << "Результат выполнения 2 задачи с a=" << a << " - " << result << std::endl;
}

void task3() {
    std::cout << "task3" << std::endl;
}

void task4() {
    std::cout << "task4" << std::endl;
}

int main(int, char**) {
    int mode = 0;
    bool appIsRunning = true;

    while (appIsRunning) {
        std::cout << "Введите цифру от 1 до 4 для запуска соответсвующей программы ";
        std::cout << "или любую другую цифру для выхода" << std::endl;
        std::cin >> mode;

        if (mode == 1) {
            task1();
        } else if (mode == 2) {
            task2();
        } else if (mode == 3) {
            task3();
        } else if (mode == 4) {
            task4();
        } else {
            appIsRunning = false;
        }
    }

    return 0;
}
