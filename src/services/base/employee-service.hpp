#pragma once
#include "data/repositories/driver-repository.hpp"
#include "data/repositories/cashier-repository.hpp"
#include "data/repositories/dispatcher-repository.hpp"
#include "data/repositories/head-department-repository.hpp"
#include "data/repositories/technician-repository.hpp"

class EmployeeService {
private:
    DriverRepository& driver_repository;
    HeadDepartmentRepository& head_department_repository;
    TechnicianRepository& technician_repository;
    CashierRepository& cashier_repository;
    DispatcherRepository& dispatcher_repository;

public:
    EmployeeService(
        DriverRepository& driver_repository,
        HeadDepartmentRepository& head_department_repository,
        TechnicianRepository& technician_repository,
        CashierRepository& cashier_repository,
        DispatcherRepository& dispatcher_repository
    );
    ~EmployeeService() = default;

public:
    std::vector<std::shared_ptr<Employee>> getAllEmployees() const;
    int getCountEmployees() const;

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

public:
    std::vector<std::shared_ptr<HeadDepartment>> getAllHeadDepartment() const;
}; 