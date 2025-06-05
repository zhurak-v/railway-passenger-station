#pragma once
#include "services/services/services.hpp"
#include "common/utils/parse-type-route.hpp"

class Menu {
private:
    Services& services;

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
    void getLocomotiveByRepairInTime() const;
    void getLocomotiveByRepairCount() const;
    void getLocomotivesByCompletedRoutesBeforeRepair() const;
    void getLocomotiveByAge() const;

    void getTrainsByRoute() const; 
    void getTrainsByRouteDistance() const;
    void getTrainsByticketPrice() const;
    void getTrainsByRouteByRouteDistanceByticketPrice() const;

    void getCanceledTrips() const;
    void getCanceledTripsByRoute() const;
    void getTripsByTwoStationsInOrder() const;

    void getDelayedTrips() const;
    void getDelayedTripsByReason() const;
    void getDelayedTripsByRoute() const;
    void getReturnedTicketsForAllDelayedTrips() const;

    void getSoldTicketsByRoute() const;
    void getSoldTicketsByRouteDistance() const;
    void getSoldTicketsByTicketPrice() const;

    void getRoutesByCategory() const;
    void getRoutesByCategoryPositon() const;

    void getPassengersByTrip() const;
    void getPassengersByLeft() const;
    void getPassengersByLeftForeign() const;
    void getPassengersByHasBaggage() const;
    void getPassengersBySex() const;

    void getUnredeemedTicketByTrip() const;
    void getUnredeemedTicketByRoute() const;
    void getUnredeemedTicketByDate() const;

    void getReturnedTicketsByTrip() const;
    void getReturnedTicketsByDate() const;
    void getReturnedTicketsByRoute() const;

public:
    Menu(
        Services& services
    );
    void run() const;
};
