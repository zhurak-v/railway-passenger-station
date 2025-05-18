#include "services/department-to-employee.hpp"

DepartmentToEmployeeService::DepartmentToEmployeeService(
    DepartmentRepository& department_repository,
    EmployeeRepository& employee_repository
) : department_repository(department_repository), 
    employee_repository(employee_repository) {
    loadAllLinks(
        this->department_to_employee, 
        department_repository.getAll(),
        employee_repository.getAll()
    );
}

std::vector<std::shared_ptr<Employee>> DepartmentToEmployeeService::getEmployeesByDepartment(std::string& id) const {
    const std::shared_ptr<Department>& department = department_repository.findById(id);
    return department_to_employee.getLinkedB(department);
}

std::shared_ptr<Department> DepartmentToEmployeeService::getDepartmentByEmployee(std::string& id) const {
    const std::shared_ptr<Employee>& employee = employee_repository.findById(id);
    return department_to_employee.getLinkedA(employee);
}