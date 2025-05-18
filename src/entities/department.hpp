#pragma once

#include <string>
#include <sstream>
#include <vector>
#include "entities/base.hpp"

class Department : public Base
{
private:
    std::string department_name;

public:
    Department(
        const std::string &id,
        const std::string &department_name);
    ~Department() = default;

public:
    std::string getClass() const final;
    static std::string staticClass();

    std::string getDepartmentName() const;

public:
    std::string serialize() const override;

    static std::shared_ptr<Department> deserialize(const std::string &data);
};
