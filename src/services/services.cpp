#include "services/department-to-head-department.hpp"
#include "services/department-to-employee.hpp"
#include "data/repositories/repositories.hpp"

inline DepartmentToHeadDepartmentSerice department_to_head_department_serice(
    department_repository,
    head_department_repository
);

inline DepartmentToEmployeeService department_to_employee_service(
    department_repository,
    employee_repository
);