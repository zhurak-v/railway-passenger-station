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
    bool timeOnly = false;

    void normalize();

public:
    Date();
    Date(int year, int month, int day, int hour = 0, int minute = 0);
    Date(int hour, int minute);

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

    void addMinutes(int minutes);
    void addHours(int hours);
    void addDays(int days);

    void addMinutes(double minutes);
    void addHours(double hours);
    void addDays(double days);

    static int differenceInMinutes(const Date& a, const Date& b);
    static int differenceInHours(const Date& a, const Date& b);
    static int differenceInDays(const Date& a, const Date& b);
    static int differenceInYears(const Date& a, const Date& b);

    static Date fromHours(double hours);

    bool isTimeOnly() const;
};
