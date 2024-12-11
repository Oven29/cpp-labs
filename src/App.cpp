#include "App.h"

#include <cmath>
#include <iostream>

#include "RSA.h"

namespace {

bool IsSimple(int number) {
    if (number <= 1) {
        return false;
    }
    if (number <= 3) {
        return true;
    }
    if (number % 2 == 0 || number % 3 == 0) {
        return false;
    }

    for (int i = 5; i * i <= number; i += 6) {
        if (number % i == 0 || number % (i + 2) == 0) {
            return false;
        }
    }

    return true;
}

}  // namespace

namespace App {

void RunInteractive() {
    int p = 0;
    int q = 0;
    std::cout << "Введите два простых числа: ";
    std::cin >> p >> q;

    if (!IsSimple(p)) {
        std::cout << "Первое число не является простым" << std::endl;
        return;
    }

    if (!IsSimple(q)) {
        std::cout << "Второе число не является простым" << std::endl;
        return;
    }

    const int n = RSA::GetN(p, q);
    const int phi = RSA::GetPhi(p, q);
    const int e = RSA::GetE(phi);
    const int d = RSA::GetD(e, phi);

    long message = 0;
    std::cout << "Введите число для шифрования: ";
    std::cin >> message;

    long encoded = RSA::Encode(message, e, n);
    long decoded = RSA::Decode(encoded, d, n);

    std::cout << "Зашифрованное сообщение: " << encoded << std::endl;
    std::cout << "Расшифрованное сообщение: " << decoded << std::endl;
}

void RunExample() {
    const int p = 11;
    const int q = 13;

    const int n = RSA::GetN(p, q);
    const int phi = RSA::GetPhi(p, q);
    const int e = RSA::GetE(phi);
    const int d = RSA::GetD(e, phi);

    const int message = 7;

    std::cout << "Открытый ключ: " << e << " " << n << std::endl;
    std::cout << "Приватный ключ: " << d << " " << n << std::endl;

    std::cout << "Число для шифрования: " << message << std::endl;

    long encoded = RSA::Encode(message, e, n);
    long decoded = RSA::Decode(encoded, d, n);

    std::cout << "Зашифрованное сообщение: " << encoded << std::endl;
    std::cout << "Расшифрованное сообщение: " << decoded << std::endl;
}

void RunTask() {
    const int e = 53;
    const int n = 299;
    const long encoded_message = 171;

    // подобранные простые числа p и q для N = 299
    const int p = 13;
    const int q = 23;

    const int phi = RSA::GetPhi(p, q);
    const int d = RSA::GetD(e, phi);
    long decoded = RSA::Decode(encoded_message, d, n);

    std::cout << "Число для расшифровки: " << encoded_message << std::endl;
    std::cout << "Приватный ключ: " << d << " " << n << std::endl;
    std::cout << "Расшифрованное сообщение: " << decoded << std::endl;
}

void Run() {
    std::cout << "Пример:" << std::endl;
    RunExample();
    std::cout << std::endl;

    std::cout << "Задание:" << std::endl;
    RunTask();
    std::cout << std::endl;

    char input = 'y';
    while (input == 'y') {
        std::cout << "Интерактивный режим:" << std::endl;
        RunInteractive();
        std::cout << std::endl;
        std::cout << "Продолжить?(y/n): ";
        std::cin >> input;
    }
}

}  // namespace App
