#include "data/repositories/repositories.hpp"

#include "services/department-to-head-department.hpp"
#include "services/department-to-employee.hpp"
#include "services/employee.hpp"

inline DepartmentToHeadDepartmentSerice department_to_head_department_serice(
    department_repository,
    head_department_repository
);

inline DepartmentToEmployeeService department_to_employee_service(
    department_repository,
    employee_repository
);

inline EmployeeService employee_service(
    employee_repository
);