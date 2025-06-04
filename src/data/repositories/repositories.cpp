#include "data/repositories/repositories.hpp"
#include "data/loaders/entity-loader.hpp"
#include "data/loaders/split-entities.hpp"


auto loaded_entities = loadAllEntitiesFromFolder();
EntitiesBuckets buckets = splitEntities(loaded_entities);

inline DriverRepository driver_repository(buckets.drivers);
inline CashierRepository cashier_repository(buckets.cashiers);
inline DispatcherRepository dispatcher_repository(buckets.dispatchers);
inline LocomotiveRepository locomotive_repository(buckets.locomotives);
inline HeadDepartmentRepository head_department_repository(buckets.head_departments);
inline DepartmentRepository department_repository(buckets.departments);
inline StationRepository station_repository(buckets.stations);
inline RouteRepository route_repository(buckets.routes);
inline TripRepository trip_repository(buckets.trips);
inline TicketRepository ticket_repository(buckets.tickets);
inline TrainRepository train_repository(buckets.trains);
inline PassengerRepository passenger_repository(buckets.passengers);
inline TechnicianRepository technician_repository(buckets.technicians);
inline StaffRepository staff_repository(buckets.staffs);
inline TechnicianBrigadeRepository technician_brigade_repository(buckets.technician_brigades);
inline LocomotiveBrigadeRepository locomotive_brigade_repository(buckets.locomotive_brigades);