#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include <vector>
#include "entities/base.hpp"
#include "common/date/date.hpp"

enum class SEX {
    MALE,
    FEMALE
};

class Employee : public Base
{
private:
    std::string full_name;
    SEX sex;
    Date birth;
    Date start_work;
    int children_count;
    double salary;

public:
    Employee(
        const std::string &id,
        const std::string &full_name,
        SEX sex,
        Date &birth,
        Date &start_work,
        int children_count,
        double salary);
    virtual ~Employee() = default;

public:
    std::string getFullName() const;
    SEX getSex() const;
    Date getBrithDate() const;
    Date getStartWork() const;
    int getChildrenCount() const;
    double getSalary() const;

public:
    static std::string staticClass();
    std::string getClass() const override;
};
