#pragma once
#include <sstream>
#include <iomanip>
#include <ctime>
#include <stdexcept>
#include <regex>

class Date {
private:
    int year;
    int month;
    int day;
    int hour;
    int minute;

public:
    Date();
    Date(int year, int month, int day, int hour = 0, int minute = 0);

    int getYear() const;
    int getMonth() const;
    int getDay() const;
    int getHour() const;
    int getMinute() const;

    void setYear(int y);
    void setMonth(int m);
    void setDay(int d);
    void setHour(int h);
    void setMinute(int m);

    static std::string toString(const Date& date);

    std::string serialize() const;

    static Date deserialize(const std::string& data);
};