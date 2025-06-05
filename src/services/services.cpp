#include "services/services.hpp"
#include "data/repositories/repositories.hpp"

inline RelationServices relation_service(
    driver_repository,
    head_department_repository,
    department_repository,
    staff_repository,
    technician_repository,
    cashier_repository,
    dispatcher_repository,
    locomotive_repository,
    technician_brigade_repository,
    locomotive_brigade_repository,
    station_repository,
    route_repository,
    trip_repository,
    train_repository,
    ticket_repository,
    passenger_repository
);