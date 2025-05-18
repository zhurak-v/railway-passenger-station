#pragma once

#include "common/relation/one-to-one.hpp"
#include "data/loaders/link-loader.hpp"
#include "data/repositories/department-repository.hpp"
#include "data/repositories/employee-repository.hpp"

class DepartmentToEmployeeService {
private:
    DepartmentRepository& department_repository;
    EmployeeRepository& employee_repository;

private:
    OneToMany<Department, Employee> department_to_employee;

public:
    DepartmentToEmployeeService(
        DepartmentRepository& department_repository,
        EmployeeRepository& employee_repository
    );
    ~DepartmentToEmployeeService() = default;

public:
    std::vector<std::shared_ptr<Employee>> getEmployeesByDepartment(std::string& id) const;
    std::shared_ptr<Department> getDepartmentByEmployee(std::string& id) const;
};