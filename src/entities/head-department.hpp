#pragma once

#include <iostream>
#include <string>
#include "entities/base-employee.hpp"

class HeadDepartment : public Employee
{
public:
    using Employee::Employee;

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<HeadDepartment> deserialize(const std::string& data);
};