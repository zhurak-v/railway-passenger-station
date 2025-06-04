#pragma once
#include "services/relation/relation.hpp"

class RelationMenu {
private:
    RelationServices& relation_services;

private:
    void showMainMenu() const;
    void handleUserChoice() const;

private:
    void getAllEmployees() const;
    void getAllHeadDepartment() const;
    void getEmployeesByDepartment() const;
    void getEmployeesByExp() const;
    void getEmployeesBySex() const;
    void getEmployeesByAge() const;
    void getEmployeesByHasChild() const;
    void getEmployeesByChildCount() const;
    void getEmployeesBySalary() const;

    void getEmployeesByBrigade() const;
    void getEmployeesByAllDepartments() const;
    void getEmployeesByServicingLocomotive() const;
    void getEmployeesByAverageSalaryInBrigade() const;
    
    void getDriversByPassedMedInsp() const;
    void getDriversBySex() const;
    void getDriversByAge() const;
    void getDriversBySalary() const;

    void getLocomotivesByStation() const;
    void getLocomotivesAtStationInTime() const;
    void getLocomotivesByCompletedRoutes() const;
    
    void getLocomotiveByPassedTechInsp() const;


public:
    RelationMenu(
        RelationServices& relation_services
    );
    void run() const;
};
