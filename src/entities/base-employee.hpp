#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "entities/base.hpp"

class Employee : public Base
{
private:
    std::string full_name;
    bool sex;
    int age;
    int work_experience;
    int children_count;
    double salary;

public:
    Employee(const std::string &id,
             const std::string &full_name,
             bool sex,
             int age,
             int work_experience,
             int children_count,
             double salary);
    virtual ~Employee() = default;

public:
    std::string getFullName() const;
    bool getSex() const;
    int getAge() const;
    int getWorkExperience() const;
    int getChildrenCount() const;
    double getSalary() const;

// public:
//     std::string serialize() const override;
};
