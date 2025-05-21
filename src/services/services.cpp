#include "services/services.hpp"
#include "data/repositories/repositories.hpp"

inline EmployeeService employee_service(
    driver_repository,
    head_department_repository,
    technician_repository,
    cashier_repository,
    dispatcher_repository
);

inline RelationServices relation_service(
    driver_repository,
    locomotive_repository,
    technician_brigade_repository,
    station_repository,
    route_repository,
    trip_repository,
    train_repository
);