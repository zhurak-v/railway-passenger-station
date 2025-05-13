#include "common/date/date.hpp"


Date::Date() {
    std::time_t t = std::time(nullptr);
    std::tm* now = std::localtime(&t);

    year = now->tm_year + 1900;
    month = now->tm_mon + 1;
    day = now->tm_mday;
    hour = now->tm_hour;
    minute = now->tm_min;
}

Date::Date(int year, int month, int day, int hour, int minute)
    : year(year), month(month), day(day), hour(hour), minute(minute) {}

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
    oss << std::setfill('0') << std::setw(4) << date.getYear() << "-"
        << std::setw(2) << date.getMonth() << "-"
        << std::setw(2) << date.getDay() << "-"
        << std::setw(2) << date.getHour() << ":"
        << std::setw(2) << date.getMinute();

    return oss.str();
}

std::string Date::serialize() const {
    return Date::toString(*this);
}

Date Date::deserialize(const std::string& data) {
    std::regex pattern(R"((\d{4})-(\d{2})-(\d{2})-(\d{2}):(\d{2}))");
    std::smatch match;

    if (std::regex_match(data, match, pattern)) {
        int y = std::stoi(match[1]);
        int m = std::stoi(match[2]);
        int d = std::stoi(match[3]);
        int h = std::stoi(match[4]);
        int min = std::stoi(match[5]);
        return Date(y, m, d, h, min);
    }

    throw std::invalid_argument("Incorrect date format: " + data);
}