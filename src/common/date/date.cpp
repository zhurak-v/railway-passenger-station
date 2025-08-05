#include "common/date/date.hpp"
#ifdef _WIN32
#include <windows.h>
time_t timegm(struct tm* t) {
    struct tm tmp = *t;
    return _mkgmtime(&tmp);
}
#endif


Date::Date() {
    std::time_t t = std::time(nullptr) + 3 * 3600;
    std::tm* now = std::gmtime(&t);
    if (!now) throw std::runtime_error("Failed to get UTC time");

    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    hour = now->tm_hour;
    minute = now->tm_min;
    timeOnly = false;
}

Date::Date(int year, int month, int day, int hour, int minute)
    : year(year), month(month), day(day), hour(hour), minute(minute), timeOnly(false) {}

Date::Date(int hour, int minute)
    : year(0), month(0), day(0), hour(hour), minute(minute), timeOnly(true) {}

int Date::getYear() const { return year; }
int Date::getMonth() const { return month; }
int Date::getDay() const { return day; }
int Date::getHour() const { return hour; }
int Date::getMinute() const { return minute; }

void Date::setYear(int y) { year = y; }
void Date::setMonth(int m) { month = m; }
void Date::setDay(int d) { day = d; }
void Date::setHour(int h) { hour = h; }
void Date::setMinute(int m) { minute = m; }

std::string Date::toString(const Date& date) {
    std::ostringstream oss;
    if (date.timeOnly) {
        oss << std::setfill('0') << std::setw(2) << date.getHour() << ":"
            << std::setw(2) << date.getMinute();
    } else {
        oss << std::setfill('0') << std::setw(4) << date.getYear() << "-"
            << std::setw(2) << date.getMonth() << "-"
            << std::setw(2) << date.getDay() << "-"
            << std::setw(2) << date.getHour() << ":"
            << std::setw(2) << date.getMinute();
    }
    return oss.str();
}

std::string Date::serialize() const {
    return Date::toString(*this);
}

Date Date::deserialize(const std::string& data) {
    std::regex fullPattern(R"((\d{4})-(\d{2})-(\d{2})-(\d{2}):(\d{2}))");
    std::regex timeOnlyPattern(R"((\d{2}):(\d{2}))");
    std::smatch match;

    if (std::regex_match(data, match, fullPattern)) {
        int y = std::stoi(match[1]);
        int m = std::stoi(match[2]);
        int d = std::stoi(match[3]);
        int h = std::stoi(match[4]);
        int min = std::stoi(match[5]);
        return Date(y, m, d, h, min);
    } else if (std::regex_match(data, match, timeOnlyPattern)) {
        int h = std::stoi(match[1]);
        int min = std::stoi(match[2]);
        return Date(h, min);
    }

    throw std::invalid_argument("Incorrect date format: " + data);
}

void Date::normalize() {
    if (timeOnly) {
        while (minute >= 60) {
            minute -= 60;
            hour += 1;
        }
        while (minute < 0) {
            minute += 60;
            hour -= 1;
        }
        while (hour >= 24) {
            hour -= 24;
        }
        while (hour < 0) {
            hour += 24;
        }
        return;
    }

    std::tm timeStruct = {};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    timeStruct.tm_hour = hour;
    timeStruct.tm_min = minute;
    timeStruct.tm_sec = 0;

    std::time_t t = timegm(&timeStruct);
    if (t == -1) throw std::runtime_error("Invalid time in normalize");

    std::tm* newTime = std::gmtime(&t);
    if (!newTime) throw std::runtime_error("gmtime failed");

    year = newTime->tm_year + 1900;
    month = newTime->tm_mon + 1;
    day = newTime->tm_mday;
    hour = newTime->tm_hour;
    minute = newTime->tm_min;
}

void Date::addMinutes(int minutes) {
    std::tm timeStruct = {};
    timeStruct.tm_year = year - 1900;
    timeStruct.tm_mon = month - 1;
    timeStruct.tm_mday = day;
    timeStruct.tm_hour = hour;
    timeStruct.tm_min = minute;
    timeStruct.tm_sec = 0;

    std::time_t t = timegm(&timeStruct);
    if (t == -1) throw std::runtime_error("Invalid time in addMinutes");

    t += minutes * 60;

    std::tm* newTime = std::gmtime(&t);
    if (!newTime) throw std::runtime_error("gmtime failed");

    year = newTime->tm_year + 1900;
    month = newTime->tm_mon + 1;
    day = newTime->tm_mday;
    hour = newTime->tm_hour;
    minute = newTime->tm_min;
}

void Date::addHours(int hours) {
    addMinutes(hours * 60);
}

void Date::addDays(int days) {
    addMinutes(days * 1440);
}

void Date::addMinutes(double minutes) {
    addMinutes(static_cast<int>(minutes + 0.5));
}

void Date::addHours(double hours) {
    addMinutes(static_cast<int>(hours * 60 + 0.5));
}

void Date::addDays(double days) {
    addMinutes(static_cast<int>(days * 86400 + 0.5));
}

void Date::removeMinutes(int minutes) {
    addMinutes(-minutes);
}

void Date::removeHours(int hours) {
    addMinutes(-hours * 60);
}

void Date::removeDays(int days) {
    addMinutes(-days * 1440);
}

void Date::removeMinutes(double minutes) {
    addMinutes(-static_cast<int>(minutes + 0.5));
}

void Date::removeHours(double hours) {
    addMinutes(-static_cast<int>(hours * 60 + 0.5));
}

void Date::removeDays(double days) {
    addMinutes(-static_cast<int>(days * 1440 + 0.5));
}

bool Date::isSameDay(const Date &a, const Date &b) {
    return a.getYear() == b.getYear() &&
           a.getMonth() == b.getMonth() &&
           a.getDay() == b.getDay();
}
int Date::compareDates(const Date &a, const Date &b) {
    if (a.getYear() != b.getYear())
        return a.getYear() - b.getYear();

    if (a.getMonth() != b.getMonth())
        return a.getMonth() - b.getMonth();

    if (a.getDay() != b.getDay())
        return a.getDay() - b.getDay();

    if (a.getHour() != b.getHour())
        return a.getHour() - b.getHour();

    if (a.getMinute() != b.getMinute())
        return a.getMinute() - b.getMinute();

    return 0;
}

bool Date::isInRange(const Date &target, const Date &from, const Date &to) {
    return compareDates(target, from) >= 0 && compareDates(target, to) <= 0;
}

int Date::differenceInMinutes(const Date& a, const Date& b) {
    std::tm ta = {}, tb = {};
    ta.tm_year = a.year - 1900;
    ta.tm_mon = a.month - 1;
    ta.tm_mday = a.day;
    ta.tm_hour = a.hour;
    ta.tm_min = a.minute;
    ta.tm_sec = 0;

    tb.tm_year = b.year - 1900;
    tb.tm_mon = b.month - 1;
    tb.tm_mday = b.day;
    tb.tm_hour = b.hour;
    tb.tm_min = b.minute;
    tb.tm_sec = 0;

    std::time_t t_a = timegm(&ta);
    std::time_t t_b = timegm(&tb);

    return static_cast<int>(std::difftime(t_a, t_b) / 60);
}

int Date::differenceInHours(const Date& a, const Date& b) {
    return differenceInMinutes(a, b) / 60;
}

int Date::differenceInDays(const Date& a, const Date& b) {
    return differenceInMinutes(a, b) / 1440;
}

int Date::differenceInYears(const Date& a, const Date& b) {
    int yearDiff = a.year - b.year;

    if (a.month < b.month || (a.month == b.month && a.day < b.day)) {
        yearDiff--;
    }

    return yearDiff;
}

Date Date::fromHours(double hours) {
    int h = static_cast<int>(hours);
    int m = static_cast<int>((hours - h) * 60 + 0.5);
    return Date(h, m);
}

bool Date::isTimeOnly() const {
    return timeOnly;
}