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
    void getAllEmployeesCommand() const;
    void getAllHeadDepartmentCommand() const;
    void getEmployeesByDepartmentCommand() const;
    void getEmployeesByExpCommand() const;
    void getEmployeesBySexCommand() const;
    void getEmployeesByAgeCommand() const;
    void getEmployeesByHasChildCommand() const;
    void getEmployeesByChildCountCommand() const;
    void getEmployeesBySalaryCommand() const;

    void getEmployeesByBrigadeCommand() const;
    void getEmployeesByAllDepartmentsCommand() const;
    void getEmployeesByServicingLocomotiveCommand() const;
    void getEmployeesByAverageSalaryInBrigadeCommand() const;
    
    void getDriversByPassedMedInspCommand() const;
    void getDriversBySexCommand() const;
    void getDriversByAgeCommand() const;
    void getDriversBySalaryCommand() const;

    void getLocomotivesByStationCommand() const;
    void getLocomotivesAtStationInTimeCommand() const;
    void getLocomotivesByCompletedRoutesCommand() const;
    
    void getLocomotiveByPassedTechInspCommand() const;
    void getLocomotiveByRepairInTimeCommand() const;
    void getLocomotiveByRepairCountCommand() const;
    void getLocomotivesByCompletedRoutesBeforeRepairCommand() const;
    void getLocomotiveByAgeCommand() const;

    void getTrainsByRouteCommand() const; 
    void getTrainsByRouteDistanceCommand() const;
    void getTrainsByticketPriceCommand() const;
    void getTrainsByRouteByRouteDistanceByticketPriceCommand() const;

    void getCanceledTripsCommand() const;
    void getCanceledTripsByRouteCommand() const;
    void getTripsByTwoStationsInOrderCommand() const;

    void getDelayedTripsCommand() const;
    void getDelayedTripsByReasonCommand() const;
    void getDelayedTripsByRouteCommand() const;
    void getReturnedTicketsForAllDelayedTripsCommand() const;

    void getSoldTicketsByRouteCommand() const;
    void getSoldTicketsByRouteDistanceCommand() const;
    void getSoldTicketsByTicketPriceCommand() const;

    void getRoutesByCategoryCommand() const;
    void getRoutesByCategoryPositonCommand() const;

    void getPassengersByTripCommand() const;
    void getPassengersByLeftCommand() const;
    void getPassengersByLeftForeignCommand() const;
    void getPassengersByHasBaggageCommand() const;
    void getPassengersBySexCommand() const;

    void getUnredeemedTicketByTripCommand() const;
    void getUnredeemedTicketByRouteCommand() const;
    void getUnredeemedTicketByDateCommand() const;

    void getReturnedTicketsByTripCommand() const;
    void getReturnedTicketsByDateCommand() const;
    void getReturnedTicketsByRouteCommand() const;

public:
    Menu(
        Services& services
    );
    void run() const;
};
