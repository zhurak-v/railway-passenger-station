#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <memory>
#include "entities/base-employee.hpp"

class HeadDepartment : public Employee
{
public:
    HeadDepartment(
        const std::string& id,
        const std::string &full_name,
        bool sex,
        int age,
        int work_experience,
        int children_count,
        float salary);

    ~HeadDepartment() = default;

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<HeadDepartment> deserialize(const std::string& data);
};