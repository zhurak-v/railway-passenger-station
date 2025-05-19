#include "services/base/employee-service.hpp"

EmployeeService::EmployeeService(
    DriverRepository& driver_repository,
    HeadDepartmentRepository& head_department_repository,
    TechnicianRepository& technician_repository,
    CashierRepository& cashier_repository,
    DispatcherRepository& dispatcher_repository
) : 
    driver_repository(driver_repository),
    head_department_repository(head_department_repository),
    technician_repository(technician_repository),
    cashier_repository(cashier_repository),
    dispatcher_repository(dispatcher_repository) {};

std::vector<std::shared_ptr<Employee>> EmployeeService::getAllEmployees() const {
    std::vector<std::shared_ptr<Employee>> employees;

    for (const auto& driver : driver_repository.getAll()) {
        employees.push_back(std::static_pointer_cast<Employee>(driver));
    }
    for (const auto& head : head_department_repository.getAll()) {
        employees.push_back(std::static_pointer_cast<Employee>(head));
    }
    for (const auto& technician : technician_repository.getAll()) {
        employees.push_back(std::static_pointer_cast<Employee>(technician));
    }
    for (const auto& dispatcher : dispatcher_repository.getAll()) {
        employees.push_back(std::static_pointer_cast<Employee>(dispatcher));
    }
    for (const auto& cashier : cashier_repository.getAll()) {
        employees.push_back(std::static_pointer_cast<Employee>(cashier));
    }

    return employees;
}

int EmployeeService::getCountEmployees() const {
    return getAllEmployees().size();
}

std::shared_ptr<Employee> EmployeeService::getEmployeeById(const std::string& id) const {
    const auto& employees = this->getAllEmployees();
    for (const auto& employee : employees) {
        if (employee->getId() == id)
            return employee;
    }
}

std::shared_ptr<Driver> EmployeeService::getDriverById(const std::string& id) const {
    return driver_repository.findById(id);
}

std::shared_ptr<HeadDepartment> EmployeeService::getHeadDepartmentById(const std::string& id) const {
    return head_department_repository.findById(id);
}

std::shared_ptr<Technician> EmployeeService::getTechnicianById(const std::string& id) const {
    return technician_repository.findById(id);
}

std::shared_ptr<Dispatcher> EmployeeService::getDispatcherById(const std::string& id) const {
    return dispatcher_repository.findById(id);
}

std::shared_ptr<Cashier> EmployeeService::getCashierById(const std::string& id) const {
    return cashier_repository.findById(id);
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesByExp(int exp) const {
    const auto& all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto& employee : all_employees) {
        if (Date::differenceInYears(employee->getStartWork(), Date()) == exp)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesByAge(int age) const {
    const auto& all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto& employee : all_employees) {
        if (Date::differenceInYears(employee->getBrithDate(), Date()) == age)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesBySex(const SEX& sex) const {
    const auto& all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto& employee : all_employees) {
        if (employee->getSex() == sex)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesByChildCount(int child_count) const {
    const auto& all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto& employee : all_employees) {
        if (employee->getChildrenCount() == child_count)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesByHasChild(bool is_has_child) const {
    const auto& all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto& employee : all_employees) {
        if ((employee->getChildrenCount() > 0) && is_has_child)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> EmployeeService::getEmployeesBySalary(double salary) const {
    const auto& all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto& employee : all_employees) {
        if (employee->getSalary() == salary)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<HeadDepartment>> EmployeeService::getAllHeadDepartment() const {
    return head_department_repository.getAll();
}

