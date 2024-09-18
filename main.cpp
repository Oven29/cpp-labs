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

const int kHoursNominativeSingular = 1;
const int kHoursGenitivePluralMin = 2;
const int kHoursGenitivePluralMax = 4;

const int kFullHourMinutes = 0;

const int kMinutesNominativeSingular = 0;
const int kMinutesNominativePluralPeriodMin = 5;
const int kMinutesNominativePluralPeriodMax = 9;
const int kMinutesNominativePluralMin = 10;
const int kMinutesNominativePluralMax = 20;
const int kMinutesGenitivePluralMin = 2;
const int kMinutesGenitivePluralMax = 4;

const int kDecimalBase = 10;
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

    if (hours == kMidnightHour && minutes == kFullHourMinutes) {
        std::cout << "Полночь\n";
        return 0;
    }

    if (hours == kNoonHour && minutes == kFullHourMinutes) {
        std::cout << "Полдень\n";
        return 0;
    }

    int formatedHours = (hours > kHoursFormat) ? (hours - kHoursFormat) : hours;

    if (formatedHours == kHoursNominativeSingular) {
        std::cout << formatedHours << " час ";
    } else if (formatedHours >= kHoursGenitivePluralMin && formatedHours <= kHoursGenitivePluralMax) {
        std::cout << formatedHours << " часа ";
    } else {
        std::cout << formatedHours << " часов ";
    }

    int firstNumberOfMinutes = minutes % kDecimalBase;
    if (minutes != kFullHourMinutes) {
        if ((firstNumberOfMinutes >= kMinutesNominativePluralPeriodMin && firstNumberOfMinutes <= kMinutesNominativePluralPeriodMax) ||
            (minutes >= kMinutesNominativePluralMin && minutes <= kMinutesNominativePluralMax) || (firstNumberOfMinutes == kMinutesNominativeSingular)) {
            std::cout << minutes << " минут ";
        } else if (firstNumberOfMinutes >= kMinutesGenitivePluralMin && firstNumberOfMinutes <= kMinutesGenitivePluralMax) {
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

    if (minutes == kFullHourMinutes) {
        std::cout << " ровно";
    }
    std::cout << "\n";

    return 0;
}
