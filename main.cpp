#include <cmath>
#include <iostream>
#include <iomanip>

namespace {
const int kFive = 5;
}  // namespace

void task1() {
    float n = 0;
    float m = 0;
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
        if (fmod(i, m) != 0) {
            result += 1;
        }
    }

    std::cout << "Результат - " << result << std::endl;
}

void task2() {
    int a = 0;
    std::cout << "Введите a " << std::endl;
    std::cin >> a;

    int result = 0;

    if (a >= 0) {
        
    } else {

    }

    std::cout << "Результат - " << result << std::endl;
}

void task3() {
    std::cout << "task3" << std::endl;
}

void task4() {
    std::cout << "task4" << std::endl;
}

[[noreturn]] void start() {
    int mode = 0;
    std::cout << "Введите цифру от 1 до 4 для запуска соответсвующей программы ";
    std::cout << "или любую другую цифру для выхода" << std::endl;
    std::cin >> mode;

    switch (mode) {
        case 1:
            task1();
            start();
            break;
        case 2:
            task1();
            start();
            break;
        case 3:
            task1();
            start();
            break;
        case 4:
            task1();
            start();
            break;
        default:
            exit(0);
            break;
    }
}

int main(int, char**) {
    start();

    return 0;
}
