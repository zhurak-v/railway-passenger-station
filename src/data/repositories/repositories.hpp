#pragma once

#include "data/repositories/driver-repository.hpp"
#include "data/repositories/locomotive-repository.hpp"
#include "data/repositories/cashier-repository.hpp"
#include "data/repositories/dispatcher-repository.hpp"
#include "data/repositories/head-department-repository.hpp"
#include "data/repositories/department-repository.hpp"
#include "data/repositories/station-repository.hpp"
#include "data/repositories/route-repository.hpp"
#include "data/repositories/trip-repository.hpp"
#include "data/repositories/ticket-repository.hpp"
#include "data/repositories/passenger-repository.hpp"
#include "data/repositories/technician-repository.hpp"
#include "data/repositories/technician-brigade-repository.hpp"
#include "data/repositories/train-repository.hpp"

extern DriverRepository driver_repository;
extern CashierRepository cashier_repository;
extern DispatcherRepository dispatcher_repository;
extern LocomotiveRepository locomotive_repository;
extern HeadDepartmentRepository head_department_repository;
extern DepartmentRepository department_repository;
extern StationRepository station_repository;
extern RouteRepository route_repository;
extern TripRepository trip_repository;
extern TicketRepository ticket_repository;
extern TrainRepository train_repository;
extern PassengerRepository passenger_repository;
extern TechnicianRepository technician_repository;
extern TechnicianBrigadeRepository technician_brigade_repository;