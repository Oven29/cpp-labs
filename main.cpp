#include <cmath>
#include <iostream>

void task1() {
    int n = 0;
    int m = 0;
    std::cout << "Введите n и m через пробел " << std::endl;
    std::cin >> n >> m;

    int sum = 0;

    for (int i = 5; i <= n; i += 5) {
        if (i % m != 0) {
            sum += 1;
        }
    }

    std::cout << "Результат - " << sum << std::endl;
}

void task2() {
    std::cout << "task2" << std::endl;
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
