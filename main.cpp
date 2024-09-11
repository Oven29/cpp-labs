#include <iostream>

int main(int, char**) {
    const int kMaxHours = 23;
    const int kMinHours = 0;
    const int kMaxMinutes = 60;
    const int kMinMinutes = 0;
    const int kMorningStart = 5;
    const int kMorningEnd = 11;
    const int kAfternoonStart = 12;
    const int kAfternoonEnd = 16;
    const int kEveningStart = 17;
    const int kEveningEnd = 21;
    const int kMidnightHour = 0;
    const int kNoonHour = 12;
    const int kSingleHour = 1;
    const int kFewHoursEnd = 4;
    const int kTeenStart = 11;
    const int kTeenEnd = 14;
    const int kSingleMinuteRemainder = 1;
    const int kFewMinutesEnd = 4;
    const int kDecimel = 10;

    int h = 0;
    int m = 0;

    std::cout << "Введите часы и минуты через пробел\n";
    std::cin >> h;
    std::cin >> m;

    if (h > kMaxHours || h < kMinHours) {
        std::cout << "Wrong hours input\n";
        return 1;
    }

    if (m > kMaxMinutes || m < kMinMinutes) {
        std::cout << "Wrong minutes input\n";
        return 1;
    }

    if (h == kMidnightHour && m == kMidnightHour) {
        std::cout << "Полночь\n";
        return 0;
    }

    if (h == kNoonHour && m == kMidnightHour) {
        std::cout << "Полдень\n";
        return 0;
    }

    int timeOfDay = 0;

    if (h >= kMorningStart && h <= kMorningEnd) {
        timeOfDay = 1;
    } else if (h >= kAfternoonStart && h <= kAfternoonEnd) {
        timeOfDay = 2;
    } else if (h >= kEveningStart && h <= kEveningEnd) {
        timeOfDay = 3;
    } else {
        timeOfDay = 4;
    }

    if (h > kNoonHour) {
        h -= kNoonHour;
    }

    if (h == kSingleHour) {
        std::cout << h << " час ";
    } else if (h <= kFewHoursEnd) {
        std::cout << h << " часа ";
    } else {
        std::cout << h << " часов ";
    }

    if (m % kDecimel == kSingleMinuteRemainder && m != kMidnightHour) {
        std::cout << m << " минута ";
    } else if (m != kMidnightHour && m % kDecimel <= kFewMinutesEnd && m % kDecimel != kMidnightHour && !(m >= kTeenStart && m <= kTeenEnd)) {
        std::cout << m << " минуты ";
    } else if (m != kMidnightHour) {
        std::cout << m << " минут ";
    }

    if (timeOfDay == 1) {
        std::cout << "утра";
    } else if (timeOfDay == 2) {
        std::cout << "дня";
    } else if (timeOfDay == 3) {
        std::cout << "вечера";
    } else {
        std::cout << "ночи";
    }

    if (m == kMidnightHour) {
        std::cout << "ровно\n";
    } else {
        std::cout << "\n";
    }

    return 0;
}
