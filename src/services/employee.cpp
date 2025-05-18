#include "services/employee.hpp"

EmployeeService::EmployeeService(
    EmployeeRepository& employee_repository
) : employee_repository(employee_repository) {};

std::vector<std::shared_ptr<Employee>> EmployeeService::getAllEmployees() const {
    return employee_repository.getAll();
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesByWorkExp(int years_of_exp) const {
    std::vector<std::shared_ptr<Employee>> employees;
    for (const std::shared_ptr<Employee>& employee : getAllEmployees())
    {
        if (Date::differenceInYears(Date(), employee->getStartWork()) == years_of_exp)
           employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesBySex(SEX sex) const {
    std::vector<std::shared_ptr<Employee>> employees;
    for (const std::shared_ptr<Employee>& employee : getAllEmployees())
    {
        if (employee->getSex() == sex)
           employees.push_back(employee);
    }
    return employees;
}