#pragma once

#include "common/relation/relation.hpp"
#include "common/utils/calculate-arrival-time.hpp"
#include "common/utils/find-station-index.hpp"
#include "data/loaders/link-loader.hpp"

#include "data/repositories/driver-repository.hpp"
#include "data/repositories/head-department-repository.hpp"
#include "data/repositories/technician-repository.hpp"
#include "data/repositories/locomotive-staff-repository.hpp"
#include "data/repositories/cashier-repository.hpp"
#include "data/repositories/dispatcher-repository.hpp"
#include "data/repositories/locomotive-repository.hpp"
#include "data/repositories/train-repository.hpp"
#include "data/repositories/department-repository.hpp"
#include "data/repositories/station-repository.hpp"
#include "data/repositories/route-repository.hpp"
#include "data/repositories/trip-repository.hpp"
#include "data/repositories/ticket-repository.hpp"
#include "data/repositories/technician-brigade-repository.hpp"
#include "data/repositories/locomotive-brigade-repository.hpp"

class RelationServices
{
private:
    DriverRepository &driver_repository;
    HeadDepartmentRepository &head_department_repository;
    DepartmentRepository &department_repository;
    TechnicianRepository &technician_repository;
    StaffRepository &staff_repository;
    CashierRepository &cashier_repository;
    DispatcherRepository &dispatcher_repository;
    LocomotiveRepository &locomotive_repository;
    TechnicianBrigadeRepository &technician_brigade_repository;
    LocomotiveBrigadeRepository &locomotive_brigade_repository;
    StationRepository &station_repository;
    RouteRepository &route_repository;
    TripRepository &trip_repository;
    TrainRepository &train_repository;
    TicketRepository &ticket_repository;

private:
    OneToMany<Department, Employee> department_to_employee;
    OneToOne<Department, HeadDepartment> department_to_head_department;
    OneToMany<Station, Locomotive> station_to_locomotives;
    OneToMany<Locomotive, Driver> locomotive_to_drivers;
    OneToMany<TechnicianBrigade, Locomotive> technician_brigade_to_locomotives;
    OneToOne<LocomotiveBrigade, Locomotive> locomotive_brigade_to_locomotive;
    OneToMany<LocomotiveBrigade, Staff> locomotive_brigade_to_staffs;
    OneToMany<TechnicianBrigade, Technician> technician_brigade_to_technician;
    ManyToMany<Route, Station> routes_to_stations;
    OneToMany<Route, Trip> route_to_trips;
    ManyToMany<Locomotive, Trip> locomotives_to_trips;
    OneToOne<Train, Locomotive> train_to_locomotive;
    OneToMany<Trip, Ticket> trip_to_tickets;

public:
    RelationServices(
        DriverRepository &driver_repository,
        HeadDepartmentRepository &head_department_repository,
        DepartmentRepository &department_repository,
        StaffRepository &staff_repository,
        TechnicianRepository &technician_repository,
        CashierRepository &cashier_repository,
        DispatcherRepository &dispatcher_repository,
        LocomotiveRepository &locomotive_repository,
        TechnicianBrigadeRepository &technician_brigade_repository,
        LocomotiveBrigadeRepository &locomotive_brigade_repository,
        StationRepository &station_repository,
        RouteRepository &route_repository,
        TripRepository &trip_repository,
        TrainRepository &train_repository,
        TicketRepository &ticket_repository);
    ~RelationServices() = default;


public:
    std::vector<std::shared_ptr<Employee>> getAllEmployees() const;

public:
    std::shared_ptr<Employee> getEmployeeById(const std::string& id) const;
    std::shared_ptr<Driver> getDriverById(const std::string& id) const;
    std::shared_ptr<HeadDepartment> getHeadDepartmentById(const std::string& id) const;
    std::shared_ptr<Technician> getTechnicianById(const std::string& id) const;
    std::shared_ptr<Dispatcher> getDispatcherById(const std::string& id) const;
    std::shared_ptr<Cashier> getCashierById(const std::string& id) const;
    
public:
    std::vector<std::shared_ptr<Employee>> getEmployeesByExp(int exp) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByAge(int age) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesBySex(const SEX& sex) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByChildCount(int child_count) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByHasChild(bool is_has_child) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesBySalary(double salary) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByDepartment(const std::string& id) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByBrigade(const std::string& id) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByAllDepartments() const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByServicingLocomotive(const std::string& id) const;
    std::vector<std::shared_ptr<Employee>> getEmployeesByAverageSalaryInBrigade(double salary) const;
public:
    std::vector<std::shared_ptr<HeadDepartment>> getAllHeadDepartment() const;

    std::vector<std::shared_ptr<Driver>> getDriversByPassedMedInsp(const int year, const bool is_passed) const;
    std::vector<std::shared_ptr<Driver>> getDriversBySex(const SEX& sex) const;
    std::vector<std::shared_ptr<Driver>> getDriversByAge(int age) const;
    std::vector<std::shared_ptr<Driver>> getDriversBySalary(double salary) const;

public:
    std::vector<std::shared_ptr<Station>> getStationsByRoute(
        const std::string &id) const;
    std::vector<std::shared_ptr<Route>> getRoutesByStation(
        const std::string &id) const;

    std::vector<std::shared_ptr<Trip>> getTripsByRoute(
        const std::string &id) const;

    std::shared_ptr<Route> getRouteByTrip(
        const std::string &id) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotivesAtStationInTime(
        const std::string &id,
        const Date &time) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotivesByStation(
        const std::string &id) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotivesByCompletedRoutes(
        const int completed_routest) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotivesByCompletedRoutesBeforeRepair(
        const int completed_routes_before_repair) const;

    std::vector<std::pair<std::shared_ptr<Locomotive>, Date>>
    getLocomotivesArrivalTimeAtStation(
        const std::string &id) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotiveByPassedTechInsp(
        const Date &from, const Date &to) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotiveByRepairInTime(
        const Date &repair_date) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotiveByRepairCount(
        const int repair_count) const;

    std::vector<std::shared_ptr<Locomotive>> getLocomotiveByAge(
        const int age) const;

    std::vector<std::shared_ptr<Train>> getTrainsByRoute(
        const std::string &id) const;

    std::vector<std::shared_ptr<Train>> getTrainsByRouteDistance(
        const double distance) const;

    std::vector<std::shared_ptr<Train>> getTrainsByticketPrice(
        const double price) const;

    std::vector<std::shared_ptr<Train>> getTrainsByRouteByRouteDistanceByticketPrice(
        const std::string &id,
        const double distance,
        const double price) const;

    std::vector<std::shared_ptr<Trip>> getCanceledTrips() const;

    std::vector<std::shared_ptr<Trip>> getCanceledTripsByRoute(
        const std::string &id) const;

    std::vector<std::shared_ptr<Trip>> RelationServices::getTripsByTwoStationsInOrder(
        const std::string &stationA_id,
        const std::string &stationB_id) const;

    std::vector<std::shared_ptr<Trip>> getDelayedTrips() const;

    std::vector<std::shared_ptr<Trip>> getDelayedTripsByReason(
        const std::string &reason) const;

    std::vector<std::shared_ptr<Trip>> getDelayedTripsByRoute(
        const std::string &id) const;

    std::vector<std::shared_ptr<Ticket>> getSoldTicketsByRoute(
        const std::string &id,
        const Date &start, const Date &end) const;

    std::vector<std::shared_ptr<Ticket>> getSoldTicketsByRouteDistance(
        const double distance,
        const Date &start, const Date &end) const;

    std::vector<std::shared_ptr<Ticket>> getSoldTicketByTicketPrice(
        const double price,
        const Date &start, const Date &end) const;

    std::vector<std::shared_ptr<Ticket>> getUnredeemedTicketByTrip(
        const std::string &id) const;

    std::vector<std::shared_ptr<Ticket>> getUnredeemedTicketByRoute(
        const std::string &id) const;
};