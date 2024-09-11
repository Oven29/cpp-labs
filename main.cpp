#include <iostream>

int main(int, char**) {
    int h, m;
    std::cout << "Enter hours\n";
    std::cin >> h;
    std::cout << "Enter minutes\n";
    std::cin >> m;

    if (h > 23 || h < 0) {
        std::cout << "Wrong hours input\n";
        return 1;
    }

    if (m > 60 || m < 0) {
        std::cout << "Wrong minutes input\n";
        return 1;
    }

    if (h == 0 && m == 0) {
        std::cout << "Полночь\n";
        return 0;
    }

    if (h == 12 && m == 0) {
        std::cout << "Полдень\n";
        return 0;
    }

    int timeOfDay;  // 1 - утро, 2 - день, 3 - вечер, 4 - ночь
    
    if (h >= 5 && h <= 11) {
        timeOfDay = 1;
    } else if (h >= 12 && h <= 16) {
        timeOfDay = 2;
    } else if (h >= 17 && h <= 21) {
        timeOfDay = 3;
    } else {
        timeOfDay = 4;
    }

    if (h > 12) {
        h -= 12;
    }

    if (h == 1) {
        std::cout << h << " час ";
    } else if (h <= 4) {
        std::cout << h << " часа ";
    } else {
        std::cout << h << " часов ";
    }

    if (m % 10 == 1 && m != 0) {
        std::cout << m << " минута ";
    } else if (m != 0 && m % 10 <= 4 && m % 10 != 0 && !(m >= 11 && m <= 14)) {
        std::cout << m << " минуты ";
    } else if (m != 0) {
        std::cout << m << " минут ";
    }

    if (timeOfDay == 1) {
        std::cout << "утра";
    } else if (timeOfDay == 2) {
        std::cout << "дня";
    } else if (timeOfDay == 2) {
        std::cout << "вечера";
    } else {
        std::cout << "ночи";
    }

    if (m == 0) {
        std::cout << "ровно\n";
    } else {
        std::cout << "\n";
    }

    return 0;
}
