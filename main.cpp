#include <iostream>

namespace {
const int kMaxHours = 23;
const int kMinHours = 0;

const int kMaxMinutes = 59;
const int kMinMinutes = 0;

const int kMorningStart = 5;
const int kMorningEnd = 11;

const int kAfternoonStart = 12;
const int kAfternoonEnd = 16;

const int kEveningStart = 17;
const int kEveningEnd = 21;

const int kMidnightHour = 0;
const int kNoonHour = 12;

const int kHoursFormat = 12;

const int kHoursGenetiveCaseMin = 0;
const int kHoursGenetiveCaseMax = 4;
const int kHoursNominativeCase = 1;

const int kExactMinutes = 0;

const int kMinutesNominativeCase = 1;
const int kMinutesNominativeCasePeriodMin = 5;
const int kMinutesNominativeCasePeriodMax = 9;
const int kMinutesNominativeCaseMin = 10;
const int kMinutesNominativeCaseMax = 20;
const int kMinutesGenetiveCaseMin = 2;
const int kMinutesGenetiveCaseMax = 4;

const int kDecimal = 10;
}  // namespace

int main(int, char**) {
    int hours = 0;
    int minutes = 0;

    std::cout << "Введите часы и минуты через пробел\n";
    std::cin >> hours >> minutes;

    if (hours > kMaxHours || hours < kMinHours) {
        std::cout << "Неверный ввод значения часа, возможные значениея от 0 до 23 включительно\n";
        return 1;
    }

    if (minutes > kMaxMinutes || minutes < kMinMinutes) {
        std::cout << "Неверный ввод значения минут, возможные значения от 0 до 59 включительно\n";
        return 1;
    }

    if (hours == kMidnightHour && minutes == kExactMinutes) {
        std::cout << "Полночь\n";
        return 0;
    }

    if (hours == kNoonHour && minutes == kExactMinutes) {
        std::cout << "Полдень\n";
        return 0;
    }

    int formatedHours = hours;
    if (formatedHours > kHoursFormat) {
        formatedHours -= kHoursFormat;
    }

    if (hours == kHoursNominativeCase) {
        std::cout << formatedHours << " час ";
    } else if (hours >= kHoursGenetiveCaseMin && hours <= kHoursGenetiveCaseMax) {
        std::cout << formatedHours << " часа ";
    } else {
        std::cout << formatedHours << " часов ";
    }

    if (minutes != kExactMinutes) {
        if ((minutes % kDecimal >= kMinutesNominativeCasePeriodMin && minutes % kDecimal <= kMinutesNominativeCasePeriodMax) ||
            (minutes >= kMinutesNominativeCaseMin && minutes <= kMinutesNominativeCaseMax)) {
            std::cout << minutes << " минут ";
        } else if (minutes % kDecimal >= kMinutesGenetiveCaseMin && minutes % kDecimal <= kMinutesGenetiveCaseMax) {
            std::cout << minutes << " минуты ";
        } else {
            std::cout << minutes << " минута ";
        }
    }

    if (formatedHours >= kMorningStart && formatedHours <= kMorningEnd) {
        std::cout << "утра";
    } else if (formatedHours >= kAfternoonStart && formatedHours <= kAfternoonEnd) {
        std::cout << "дня";
    } else if (formatedHours >= kEveningStart && formatedHours <= kEveningEnd) {
        std::cout << "вечера";
    } else {
        std::cout << "ночи";
    }

    if (minutes == kExactMinutes) {
        std::cout << " ровно";
    }
    std::cout << "\n";

    return 0;
}
