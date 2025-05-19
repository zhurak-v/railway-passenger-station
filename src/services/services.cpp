#include "data/repositories/repositories.hpp"
#include "services/base/employee-service.hpp"

inline EmployeeService employee_service(
    driver_repository,
    head_department_repository,
    technician_repository,
    cashier_repository,
    dispatcher_repository
);