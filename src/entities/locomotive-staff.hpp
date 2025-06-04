#pragma once

#include <iostream>
#include <string>
#include "entities/base-employee.hpp"

class Staff : public Employee
{
public:
    using Employee::Employee;
    ~Staff() = default;

public:
    static std::string staticClass();
    std::string getClass() const final;

public:
    std::string serialize() const;
    static std::shared_ptr<Staff> deserialize(const std::string& data);
};