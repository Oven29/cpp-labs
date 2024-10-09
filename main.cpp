#include <cmath>
#include <iomanip>
#include <iostream>

namespace {
const int kTwo = 2;
const int kThree = 3;
const int kFive = 5;
const int kEight = 8;
const int kTen = 10;

const int kPrecision = 6;
const float kStepTaskThree = 0.2;
const double kMaxInaccuracy = 1 / pow(10, 6);
const int kColoumnWidth = 10;
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

double calculateK(double x, int n) {
    double k = -1 * (x * x) / ((n * 2) * (n * 2 - 1));
    return k;
}

void task3() {
    std::cout << std::setw(kColoumnWidth) << "x" << std::setw(kColoumnWidth) << "Y(x)" << std::setw(kColoumnWidth) << " S(x)"
              << std::setw(kColoumnWidth) << "N" << std::endl;

    for (float x = 0; x <= 1.0; x += kStepTaskThree) {
        std::cout << std::setw(kColoumnWidth) << x << std::setw(kColoumnWidth) << std::setprecision(kPrecision) << cos(x);
        int n = 1;
        double result = 1.0;
        double last = 1.0;
        double k = 0;

        while (fabs(last) > kMaxInaccuracy) {
            k = calculateK(x, n);
            last *= k;
            result += last;
            n++;
        }

        std::cout << std::setw(kColoumnWidth) << std::setprecision(kPrecision) << result << std::setw(kColoumnWidth) << n - 1 << std::endl;
    }
}

void task4() {
    int n = 0;
    double y = 0;

    std::cout << "Введите число n" << std::endl;
    std::cin >> n;

    int cycles = 0;
    for (int i = 2 * n; i >= 2; i -= 2) {
        cycles += 1;
        if (i == 2 * n) {
            y = 1.0 / i;
        } else {
            y = 1.0 / (i + y);
        }
        if (cycles == 3 || cycles == kFive || cycles == kTen) {
            std::cout << "Промежуточный результат при " << cycles << " слагаемых: " << std::setprecision(kPrecision) << y << std::endl;
        }
    }

    std::cout << "Результат выполнения 4 задачи с n=" << n << " - " << y << std::endl;
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
