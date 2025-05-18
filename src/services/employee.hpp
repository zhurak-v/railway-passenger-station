#pragma once

#include "data/repositories/employee-repository.hpp"

class EmployeeService {
private:
    EmployeeRepository& employee_repository;

public:
    EmployeeService(
        EmployeeRepository& employee_repository
    );
    ~EmployeeService() = default;

public:
    std::vector<std::shared_ptr<Employee>> getAllEmployees() const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByWorkExp(int years_of_exp) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesBySex(SEX sex) const;
}; 