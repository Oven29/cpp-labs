#include "App.h"

#include <cmath>
#include <iomanip>
#include <iostream>

#include "utils/Random.h"

namespace {

const int kWidthColumn = 18;
const int kColumnsQuantity = 4;
const int kMaxIter = 100000;

const double kMinA = 0.;
const double kMaxA = 1.;
const double kMinB = 2.;
const double kMaxB = 3.;

[[nodiscard]] double f1(double x) {
    return x;
}

[[nodiscard]] double f2(double x) {
    return std::sin(22 * x);
}

[[nodiscard]] double f3(double x) {
    return std::pow(x, 4);
}

[[nodiscard]] double f4(double x) {
    return std::atan(x);
}

void PrintTable(App::IntegralPrint integralPrint[]) {
    std::cout << std::setw(kWidthColumn) << "Function name" << std::setw(kWidthColumn) << "Calculated Sum" << std::setw(kWidthColumn) << "Actual Sum"
              << std::setw(kWidthColumn) << "N" << std::endl;

    for (int i = 0; i < kColumnsQuantity; i++) {
        std::cout << std::setw(kWidthColumn) << integralPrint[i].FnName << std::setw(kWidthColumn) << integralPrint[i].integralSum
                  << std::setw(kWidthColumn) << integralPrint[i].actualIntegralSum << std::setw(kWidthColumn) << integralPrint[i].n << std::endl;
    }

    std::cout << std::endl;
}

[[nodiscard]] double IntRect(App::TPF f, double a, double b, double epsilon, int& n) {
    n = 1;
    double h = b - a;
    double integral = 0.;
    double previousIntegral = 0.;

    for (int i = 0; i < kMaxIter; ++i) {
        integral = 0.;

        for (int j = 0; j < n; ++j) {
            integral += f(a + j * h) * h;
        }

        if (n > 1 && std::fabs(integral - previousIntegral) < epsilon) {
            break;
        }

        previousIntegral = integral;
        n *= 2;
        h /= 2;
    }

    return integral;
}

[[nodiscard]] double IntTrap(App::TPF f, double a, double b, double epsilon, int& n) {
    n = 1;
    double h = b - a;
    double integral = 0;
    double previousIntegral = 0;

    for (int i = 0; i < kMaxIter; ++i) {
        integral = 0.;

        for (int i = 0; i < n; ++i) {
            double x = a + i * h;
            integral += (f(x) + f(x + h)) * h / 2;
        }

        if (n > 1 && std::fabs(integral - previousIntegral) < epsilon) {
            break;
        }

        previousIntegral = integral;
        n *= 2;
        h /= 2;
    }

    return integral;
}

}  // namespace

namespace App {

void Run() {
    double a = Random::RandDouble(kMinA, kMaxA);
    double b = Random::RandDouble(kMinB, kMaxB);

    std::cout << "a: " << a << " b: " << b << std::endl;

    double epsilon = 0.01;
    int n = 1;

    App::IntegralPrint integral_print[4];

    integral_print[0].FnName = "y = x        ";
    integral_print[0].integralSum = (std::pow(b, 2) - std::pow(a, 2)) / 2.0;
    integral_print[0].n = n;

    integral_print[1].FnName = "y = sin(22x) ";
    integral_print[1].integralSum = (std::cos(a * 22.0) - std::cos(b * 22.0)) / 22.0;
    integral_print[1].n = n;

    integral_print[2].FnName = "y = x^4      ";
    integral_print[2].integralSum = (std::pow(b, 5) - std::pow(a, 5)) / 5.0;
    integral_print[2].n = n;

    integral_print[3].FnName = "y = arctan(x)";
    integral_print[3].integralSum =
        b * std::atan(b) - a * std::atan(a) - (std::log(std::pow(b, 3) + 1) - std::log(std::pow(a, 2) + 1)) / 2.0;
    integral_print[3].n = n;

    for (int i = 0; i <= 4; ++i) {
        integral_print[0].actualIntegralSum = IntRect(f1, a, b, epsilon, n);
        integral_print[1].actualIntegralSum = IntRect(f2, a, b, epsilon, n);
        integral_print[2].actualIntegralSum = IntRect(f3, a, b, epsilon, n);
        integral_print[3].actualIntegralSum = IntRect(f4, a, b, epsilon, n);

        std::cout << "Метод прямоугольников. epsilon = " << std::resetiosflags(std::ios::fixed) << epsilon << std::endl;
        PrintTable(integral_print);

        integral_print[0].actualIntegralSum = IntTrap(f1, a, b, epsilon, n);
        integral_print[1].actualIntegralSum = IntTrap(f2, a, b, epsilon, n);
        integral_print[2].actualIntegralSum = IntTrap(f3, a, b, epsilon, n);
        integral_print[3].actualIntegralSum = IntTrap(f4, a, b, epsilon, n);

        std::cout << "Метод трапеций. epsilon = " << std::resetiosflags(std::ios::fixed) << epsilon << std::endl;
        PrintTable(integral_print);

        epsilon = epsilon / 10;
    }
}

}  // namespace App
