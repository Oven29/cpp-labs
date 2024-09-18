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

const int kHoursNominative = 1;
const int kHoursGenitiveMin = 2;
const int kHoursGenitiveMax = 4;

const int kExactHours = 0;

const int kMinutesNominative = 1;
const int kMinutesNominativePeriodMin = 5;
const int kMinutesNominativePeriodMax = 9;
const int kMinutesNominativeMin = 10;
const int kMinutesNominativeMax = 20;
const int kMinutesGenitiveMin = 2;
const int kMinutesGenitiveMax = 4;

const int kTheBasisOfTheNumberSystem = 10;
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

    if (hours == kMidnightHour && minutes == kExactHours) {
        std::cout << "Полночь\n";
        return 0;
    }

    if (hours == kNoonHour && minutes == kExactHours) {
        std::cout << "Полдень\n";
        return 0;
    }

    int formatedHours = hours;
    if (formatedHours > kHoursFormat) {
        formatedHours -= kHoursFormat;
    }

    if (formatedHours == kHoursNominative) {
        std::cout << formatedHours << " час ";
    } else if (formatedHours >= kHoursGenitiveMin && formatedHours <= kHoursGenitiveMax) {
        std::cout << formatedHours << " часа ";
    } else {
        std::cout << formatedHours << " часов ";
    }

    if (minutes != kExactHours) {
        if ((minutes % kTheBasisOfTheNumberSystem >= kMinutesNominativePeriodMin &&
             minutes % kTheBasisOfTheNumberSystem <= kMinutesNominativePeriodMax) ||
            (minutes >= kMinutesNominativeMin && minutes <= kMinutesNominativeMax)) {
            std::cout << minutes << " минут ";
        } else if (minutes % kTheBasisOfTheNumberSystem >= kMinutesGenitiveMin && minutes % kTheBasisOfTheNumberSystem <= kMinutesGenitiveMax) {
            std::cout << minutes << " минуты ";
        } else {
            std::cout << minutes << " минута ";
        }
    }

    if (hours >= kMorningStart && hours <= kMorningEnd) {
        std::cout << "утра";
    } else if (hours >= kAfternoonStart && hours <= kAfternoonEnd) {
        std::cout << "дня";
    } else if (hours >= kEveningStart && hours <= kEveningEnd) {
        std::cout << "вечера";
    } else {
        std::cout << "ночи";
    }

    if (minutes == kExactHours) {
        std::cout << " ровно";
    }
    std::cout << "\n";

    return 0;
}
