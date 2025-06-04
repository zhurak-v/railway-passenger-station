#include "services/relation/relation.hpp"
#include <iostream>

RelationServices::RelationServices(
        DriverRepository& driver_repository,
        HeadDepartmentRepository& head_department_repository,
        DepartmentRepository &department_repository,
        StaffRepository &staff_repository,
        TechnicianRepository& technician_repository,
        CashierRepository& cashier_repository,
        DispatcherRepository& dispatcher_repository,
        LocomotiveRepository &locomotive_repository,
        TechnicianBrigadeRepository &technician_brigade_repository,
        LocomotiveBrigadeRepository &locomotive_brigade_repository,
        StationRepository &station_repository,
        RouteRepository &route_repository,
        TripRepository &trip_repository,
        TrainRepository &train_repository,
        TicketRepository &ticket_repository

    ) : driver_repository(driver_repository),
        head_department_repository(head_department_repository),
        department_repository(department_repository),
        staff_repository(staff_repository),
        technician_repository(technician_repository),
        cashier_repository(cashier_repository),
        dispatcher_repository(dispatcher_repository),
        locomotive_repository(locomotive_repository),
        technician_brigade_repository(technician_brigade_repository),
        locomotive_brigade_repository(locomotive_brigade_repository),
        station_repository(station_repository),
        route_repository(route_repository),
        trip_repository(trip_repository),
        train_repository(train_repository),
        ticket_repository(ticket_repository)
{
    loadAllLinks(
        this->department_to_employee,
        department_repository.getAll(),
        this->getAllEmployees());
    loadAllLinks(
        this->department_to_head_department,
        department_repository.getAll(),
        head_department_repository.getAll());
    loadAllLinks(
        this->station_to_locomotives,
        station_repository.getAll(),
        locomotive_repository.getAll());
    loadAllLinks(
        this->locomotive_to_drivers,
        locomotive_repository.getAll(),
        driver_repository.getAll());
    loadAllLinks(
        this->technician_brigade_to_locomotives,
        technician_brigade_repository.getAll(),
        locomotive_repository.getAll());
    loadAllLinks(
        this->locomotive_brigade_to_locomotive,
        locomotive_brigade_repository.getAll(),
        locomotive_repository.getAll());
    loadAllLinks(
        this->locomotive_brigade_to_staffs,
        locomotive_brigade_repository.getAll(),
        staff_repository.getAll());
    loadAllLinks(
        this->technician_brigade_to_technician,
        technician_brigade_repository.getAll(),
        technician_repository.getAll());
    loadAllLinks(
        this->routes_to_stations,
        route_repository.getAll(),
        station_repository.getAll());
    loadAllLinks(
        this->route_to_trips,
        route_repository.getAll(),
        trip_repository.getAll());
    loadAllLinks(
        this->locomotives_to_trips,
        locomotive_repository.getAll(),
        trip_repository.getAll());
    loadAllLinks(
        this->train_to_locomotive,
        train_repository.getAll(),
        locomotive_repository.getAll());
    loadAllLinks(
        this->trip_to_tickets,
        trip_repository.getAll(),
        ticket_repository.getAll());
}






std::vector<std::shared_ptr<Employee>> RelationServices::getAllEmployees() const
{
    std::vector<std::shared_ptr<Employee>> employees;

    for (const auto &driver : driver_repository.getAll())
    {
        employees.push_back(std::static_pointer_cast<Employee>(driver));
    }
    for (const auto &head : head_department_repository.getAll())
    {
        employees.push_back(std::static_pointer_cast<Employee>(head));
    }
    for (const auto &technician : technician_repository.getAll())
    {
        employees.push_back(std::static_pointer_cast<Employee>(technician));
    }
    for (const auto &dispatcher : dispatcher_repository.getAll())
    {
        employees.push_back(std::static_pointer_cast<Employee>(dispatcher));
    }
    for (const auto &cashier : cashier_repository.getAll())
    {
        employees.push_back(std::static_pointer_cast<Employee>(cashier));
    }

    return employees;
}

std::shared_ptr<Employee> RelationServices::getEmployeeById(const std::string &id) const
{
    if (const auto driver = driver_repository.findById(id))
        return driver;

    if (const auto head = head_department_repository.findById(id))
        return head;

    if (const auto technician = technician_repository.findById(id))
        return technician;

    if (const auto dispatcher = dispatcher_repository.findById(id))
        return dispatcher;

    if (const auto cashier = cashier_repository.findById(id))
        return cashier;

    return nullptr;
}

std::shared_ptr<Driver> RelationServices::getDriverById(const std::string &id) const
{
    return driver_repository.findById(id);
}

std::shared_ptr<HeadDepartment> RelationServices::getHeadDepartmentById(const std::string &id) const
{
    return head_department_repository.findById(id);
}

std::shared_ptr<Technician> RelationServices::getTechnicianById(const std::string &id) const
{
    return technician_repository.findById(id);
}

std::shared_ptr<Dispatcher> RelationServices::getDispatcherById(const std::string &id) const
{
    return dispatcher_repository.findById(id);
}

std::shared_ptr<Cashier> RelationServices::getCashierById(const std::string &id) const
{
    return cashier_repository.findById(id);
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByExp(int exp) const
{
    const auto &all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &employee : all_employees)
    {
        if (Date::differenceInYears(employee->getStartWork(), Date()) == exp)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByAge(int age) const
{
    const auto &all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &employee : all_employees)
    {
        if (Date::differenceInYears(Date(), employee->getBrithDate()) == age) {
            employees.push_back(employee);
        }
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesBySex(const SEX &sex) const
{
    const auto &all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &employee : all_employees)
    {
        if (employee->getSex() == sex)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByChildCount(int child_count) const
{
    const auto &all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &employee : all_employees)
    {
        if (employee->getChildrenCount() == child_count)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByHasChild(bool is_has_child) const
{
    const auto &all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &employee : all_employees)
    {
        if ((employee->getChildrenCount() > 0) && is_has_child)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesBySalary(double salary) const
{
    const auto &all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &employee : all_employees)
    {
        if (employee->getSalary() == salary)
            employees.push_back(employee);
    }
    return employees;
}

std::vector<std::shared_ptr<HeadDepartment>> RelationServices::getAllHeadDepartment() const
{
    return head_department_repository.getAll();
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByDepartment(const std::string& id) const {
    const auto department = department_repository.findById(id);
    return department_to_employee.getLinkedB(department);
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByBrigade(const std::string& id) const {
    std::vector<std::shared_ptr<Employee>> result;

    if (const auto brigade = technician_brigade_repository.findById(id)) {
        const auto& technicians = technician_brigade_to_technician.getLinkedB(brigade);
        for (const auto& technician : technicians) {
            result.push_back(std::static_pointer_cast<Employee>(technician));
        }
        return result;
    }

    if (const auto brigade = locomotive_brigade_repository.findById(id)) {
        const auto& staffs = locomotive_brigade_to_staffs.getLinkedB(brigade);
        for (const auto& staff : staffs) {
            result.push_back(std::static_pointer_cast<Employee>(staff));
        }
        return result;
    }

    return result;
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByAllDepartments() const {
    std::vector<std::shared_ptr<Employee>> result;
    
    const auto all_departments = department_repository.getAll();
    for (const auto& department : all_departments)
    {
        const auto employees = department_to_employee.getLinkedB(department);
        for (const auto& employee : employees)
        {
            result.push_back(employee);
        }
        
    }

    return result;
    
}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByServicingLocomotive(const std::string& id) const {
    std::vector<std::shared_ptr<Employee>> result;
    const auto locomotive = locomotive_repository.findById(id);

    const auto locomotive_brigade = locomotive_brigade_to_locomotive.getLinkedA(locomotive);
    const auto technician_brigade = technician_brigade_to_locomotives.getLinkedA(locomotive);

    const auto stuffs = locomotive_brigade_to_staffs.getLinkedB(locomotive_brigade);
    const auto technicians = technician_brigade_to_technician.getLinkedB(technician_brigade);

    for (const auto& stuff : stuffs)
    {
        result.push_back(std::static_pointer_cast<Employee>(stuff));
    }
    for (const auto& technician : technicians)
    {
        result.push_back(std::static_pointer_cast<Employee>(technician));
    }

    return result;

}

std::vector<std::shared_ptr<Employee>> RelationServices::getEmployeesByAverageSalaryInBrigade(double salary) const {
    std::vector<std::shared_ptr<Employee>> result;

    auto processBrigades = [&](const auto& brigades, const auto& relation) {
        for (const auto& brigade : brigades) {
            const auto members = relation.getLinkedB(brigade);
            if (members.empty()) continue;

            double sum = 0;
            for (const auto& member : members) {
                sum += member->getSalary();
            }

            double average = sum / members.size();
            if (average == salary) {
                result.insert(result.end(), members.begin(), members.end());
            }
        }
    };

    processBrigades(technician_brigade_repository.getAll(), technician_brigade_to_technician);
    processBrigades(locomotive_brigade_repository.getAll(), locomotive_brigade_to_staffs);

    return result;
}


std::vector<std::shared_ptr<Driver>> RelationServices::getDriversByPassedMedInsp(const int year, const bool is_passed) const {
    const auto all_drivers = driver_repository.getAll();
    std::vector<std::shared_ptr<Driver>> drivers;

    for (const auto& driver : all_drivers) {
        const auto& med_insp = driver->getPassedMedexam();

        bool passed_in_year = false;
        for (const auto& date : med_insp) {
            if (date.getYear() == year) {
                passed_in_year = true;
                break;
            }
        }

        if ((is_passed && passed_in_year) || (!is_passed && !passed_in_year)) {
            drivers.push_back(driver);
        }
    }

    return drivers;
}

std::vector<std::shared_ptr<Driver>> RelationServices::getDriversBySex(const SEX& sex) const {
    const auto all_drivers = driver_repository.getAll();
    std::vector<std::shared_ptr<Driver>> drivers;

    for (const auto& driver : all_drivers) {
        if (driver->getSex() == sex)
        {
            drivers.push_back(driver);
        }
    }
    return drivers;

}

std::vector<std::shared_ptr<Driver>> RelationServices::getDriversByAge(int age) const
{
    const auto &all_drivers = driver_repository.getAll();
    std::vector<std::shared_ptr<Driver>> drivers;
    for (const auto &driver : all_drivers)
    {
        if (Date::differenceInYears(Date(), driver->getBrithDate()) == age) {
            drivers.push_back(driver);
        }
    }
    return drivers;
}

std::vector<std::shared_ptr<Driver>> RelationServices::getDriversBySalary(double salary) const
{
    const auto &all_drivers = driver_repository.getAll();
    std::vector<std::shared_ptr<Driver>> drivers;
    for (const auto &driver : all_drivers)
    {
        if (driver->getSalary() == salary)
            drivers.push_back(driver);
    }
    return drivers;
}

std::vector<std::shared_ptr<Station>> RelationServices::getStationsByRoute(const std::string &id) const
{
    const auto route = route_repository.findById(id);
    return routes_to_stations.getLinkedB(route);
}

std::vector<std::shared_ptr<Route>> RelationServices::getRoutesByStation(const std::string &id) const
{
    const auto station = station_repository.findById(id);
    return routes_to_stations.getLinkedA(station);
}

std::vector<std::shared_ptr<Trip>> RelationServices::getTripsByRoute(const std::string &id) const
{
    const auto route = route_repository.findById(id);
    return route_to_trips.getLinkedB(route);
}

std::shared_ptr<Route> RelationServices::getRouteByTrip(const std::string &id) const
{
    const auto trip = trip_repository.findById(id);
    return route_to_trips.getLinkedA(trip);
}

std::vector<std::shared_ptr<Locomotive>>
RelationServices::getLocomotivesAtStationInTime(
    const std::string &id,
    const Date &time) const
{
    auto station = station_repository.findById(id);
    auto routes = routes_to_stations.getLinkedA(station);
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &route : routes)
    {
        auto stations = routes_to_stations.getLinkedB(route);
        auto trips = route_to_trips.getLinkedB(route);

        for (const auto &trip : trips)
        {
            Date departure_time = trip->getDepartureTime();
            auto locomotives = locomotives_to_trips.getLinkedA(trip);

            for (const auto &loco : locomotives)
            {
                auto train = train_to_locomotive.getLinkedA(loco);
                auto start_station = station_to_locomotives.getLinkedA(loco);

                int start_index = findStationIndex(stations, start_station->getId());
                if (start_index == -1)
                    continue;

                if (start_station->getId() == id)
                {
                    if (Date::differenceInMinutes(departure_time, time) == 0)
                    {
                        result.push_back(loco);
                    }
                    continue;
                }

                double speed = static_cast<double>(train->getTrainType());
                Date arrival_time = calculateArrivalTime(
                    departure_time, stations, start_index, id, speed, *trip);

                if (Date::differenceInMinutes(arrival_time, time) == 0)
                {
                    result.push_back(loco);
                }
            }
        }
    }

    return result;
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotivesByStation(
    const std::string &id) const
{
    auto station = station_repository.findById(id);
    return station_to_locomotives.getLinkedB(station);
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotivesByCompletedRoutes(
    const int completed_routest) const
{
    auto locomotives = locomotive_repository.getAll();
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &locomotive : locomotives)
    {
        if (locomotive->getCompletedRoutes() == completed_routest)
            result.push_back(locomotive);
    }
    return result;

}

std::vector<std::pair<std::shared_ptr<Locomotive>, Date>>
RelationServices::getLocomotivesArrivalTimeAtStation(const std::string &station_id) const
{
    auto station = station_repository.findById(station_id);
    auto routes = routes_to_stations.getLinkedA(station);
    std::vector<std::pair<std::shared_ptr<Locomotive>, Date>> result;

    for (const auto &route : routes)
    {
        auto stations = routes_to_stations.getLinkedB(route);
        auto trips = route_to_trips.getLinkedB(route);

        for (const auto &trip : trips)
        {
            auto departure_time = trip->getDepartureTime();
            auto locomotives = locomotives_to_trips.getLinkedA(trip);

            for (const auto &loco : locomotives)
            {
                auto train = train_to_locomotive.getLinkedA(loco);
                auto start_station = station_to_locomotives.getLinkedA(loco);

                int start_index = findStationIndex(stations, start_station->getId());
                if (start_index == -1)
                    continue;

                if (start_station->getId() == station_id)
                {
                    result.emplace_back(loco, departure_time);
                    continue;
                }

                double speed = static_cast<double>(train->getTrainType());
                Date arrival_time = calculateArrivalTime(
                    departure_time, stations, start_index, station_id, speed, *trip);

                result.emplace_back(loco, arrival_time);
            }
        }
    }

    return result;
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotiveByPassedTechInsp(
    const Date &from, const Date &to) const
{
    const auto locomotives = locomotive_repository.getAll();
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &loco : locomotives)
    {
        const auto &inspections = loco->getPassedTechInspection();
        for (const auto &date : inspections)
        {
            if (Date::differenceInMinutes(date, from) >= 0 && Date::differenceInMinutes(to, date) >= 0)
            {
                result.push_back(loco);
                break;
            }
        }
    }
    return result;
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotiveByRepairInTime(
    const Date &repair_date) const
{
    const auto locomotives = locomotive_repository.getAll();
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &loco : locomotives)
    {
        const auto &repairs = loco->getRepairs();
        for (const auto &date : repairs)
        {
            if (Date::differenceInMinutes(repair_date, date) == 0)
            {
                result.push_back(loco);
                break;
            }
        }
    }
    return result;
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotiveByRepairCount(
    const int repair_count) const
{
    const auto locomotives = locomotive_repository.getAll();
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &loco : locomotives)
    {
        if (loco->getRepairsCount() == repair_count)
        {
            result.push_back(loco);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotivesByCompletedRoutesBeforeRepair(
    const int completed_routes_before_repair) const
{
    const auto locomotives = locomotive_repository.getAll();
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &loco : locomotives)
    {
        if (loco->getCompletedRoutesBeforeRepair() == completed_routes_before_repair)
        {
            result.push_back(loco);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Locomotive>> RelationServices::getLocomotiveByAge(
    const int age) const
{
    const auto locomotives = locomotive_repository.getAll();
    std::vector<std::shared_ptr<Locomotive>> result;

    for (const auto &loco : locomotives)
    {
        if (Date::differenceInYears(Date(), loco->getManufactureDate()) == age)
        {
            result.push_back(loco);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Train>> RelationServices::getTrainsByRoute(const std::string &id) const
{
    const auto route = route_repository.findById(id);
    const auto trips = route_to_trips.getLinkedB(route);

    std::vector<std::shared_ptr<Locomotive>> unique_locomotives;

    for (const auto &trip : trips)
    {
        auto locomotives = locomotives_to_trips.getLinkedA(trip);
        for (const auto &loco : locomotives)
        {
            bool alreadyExists = false;
            for (const auto &existing : unique_locomotives)
            {
                if (existing->getId() == loco->getId())
                {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
            {
                unique_locomotives.push_back(loco);
            }
        }
    }

    std::vector<std::shared_ptr<Train>> result;
    for (const auto &loco : unique_locomotives)
    {
        result.push_back(train_to_locomotive.getLinkedA(loco));
    }

    return result;
}

std::vector<std::shared_ptr<Train>> RelationServices::getTrainsByRouteDistance(
    const double distance) const
{
    const auto all_routes = route_repository.getAll();
    std::vector<std::shared_ptr<Route>> matching_routes;

    for (const auto &route : all_routes)
    {
        const auto &stations = routes_to_stations.getLinkedB(route);
        double dist = 0;
        for (size_t i = 0; i + 1 < stations.size(); ++i)
        {
            dist += Math::getDistanceBetweenPointsKm(stations[i]->getPosition(), stations[i + 1]->getPosition());
        }
        if (dist == distance)
        {
            matching_routes.push_back(route);
        }
    }

    std::vector<std::shared_ptr<Locomotive>> unique_locomotives;

    for (const auto &route : matching_routes)
    {
        auto trips = route_to_trips.getLinkedB(route);
        for (const auto &trip : trips)
        {
            auto locomotives = locomotives_to_trips.getLinkedA(trip);
            for (const auto &loco : locomotives)
            {
                bool alreadyExists = false;
                for (const auto &existing : unique_locomotives)
                {
                    if (existing->getId() == loco->getId())
                    {
                        alreadyExists = true;
                        break;
                    }
                }
                if (!alreadyExists)
                {
                    unique_locomotives.push_back(loco);
                }
            }
        }
    }

    std::vector<std::shared_ptr<Train>> result;
    for (const auto &loco : unique_locomotives)
    {
        result.push_back(train_to_locomotive.getLinkedA(loco));
    }

    return result;
}

std::vector<std::shared_ptr<Train>> RelationServices::getTrainsByticketPrice(
    const double price) const
{
    const auto all_tickets = ticket_repository.getAll();
    std::vector<std::shared_ptr<Ticket>> matching_tickets;

    for (const auto &ticket : all_tickets)
    {
        if (ticket->getPrice() == price)
        {
            matching_tickets.push_back(ticket);
        }
    }

    std::vector<std::shared_ptr<Locomotive>> unique_locomotives;

    for (const auto &ticket : matching_tickets)
    {

        auto trip = trip_to_tickets.getLinkedA(ticket);
        auto locomotives = locomotives_to_trips.getLinkedA(trip);

        for (const auto &loco : locomotives)
        {
            bool alreadyExists = false;
            for (const auto &existing : unique_locomotives)
            {
                if (existing->getId() == loco->getId())
                {
                    alreadyExists = true;
                    break;
                }
            }
            if (!alreadyExists)
            {
                unique_locomotives.push_back(loco);
            }
        }
    }

    std::vector<std::shared_ptr<Train>> result;
    for (const auto &loco : unique_locomotives)
    {
        auto train = train_to_locomotive.getLinkedA(loco);
        if (train)
        {
            result.push_back(train);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Train>> RelationServices::getTrainsByRouteByRouteDistanceByticketPrice(
    const std::string &id,
    const double distance,
    const double price) const
{
    const auto trains_by_route = getTrainsByRoute(id);
    const auto trains_by_distance = getTrainsByRouteDistance(distance);
    const auto trains_by_price = getTrainsByticketPrice(price);

    std::vector<std::shared_ptr<Train>> result;

    for (const auto &train : trains_by_route)
    {
        bool in_distance = false;
        for (const auto &d_train : trains_by_distance)
        {
            if (d_train->getId() == train->getId())
            {
                in_distance = true;
                break;
            }
        }

        if (!in_distance)
            continue;

        bool in_price = false;
        for (const auto &p_train : trains_by_price)
        {
            if (p_train->getId() == train->getId())
            {
                in_price = true;
                break;
            }
        }

        if (in_price)
        {
            result.push_back(train);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Trip>> RelationServices::getCanceledTrips() const
{
    const auto all_trips = trip_repository.getAll();
    std::vector<std::shared_ptr<Trip>> result;

    for (const auto &trip : all_trips)
    {
        if (trip->getTripStatus() == Status::Canceled)
        {
            result.push_back(trip);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Trip>> RelationServices::getCanceledTripsByRoute(
    const std::string &id) const
{
    const auto route = route_repository.findById(id);
    const auto trips = route_to_trips.getLinkedB(route);
    std::vector<std::shared_ptr<Trip>> result;

    for (const auto &trip : trips)
    {
        if (trip->getTripStatus() == Status::Canceled)
        {
            result.push_back(trip);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Trip>> RelationServices::getTripsByTwoStationsInOrder(
    const std::string &stationA_id,
    const std::string &stationB_id) const
{
    std::vector<std::shared_ptr<Trip>> result;

    auto all_trips = trip_repository.getAll();

    for (const auto &trip : all_trips)
    {
        auto route = getRouteByTrip(trip->getId());
        if (!route)
            continue;

        auto stations = routes_to_stations.getLinkedB(route);

        int indexA = -1;
        int indexB = -1;

        for (size_t i = 0; i < stations.size(); ++i)
        {
            if (stations[i]->getId() == stationA_id)
                indexA = static_cast<int>(i);
            else if (stations[i]->getId() == stationB_id)
                indexB = static_cast<int>(i);
        }

        if (indexA != -1 && indexB != -1 && indexA < indexB)
        {
            result.push_back(trip);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Trip>> RelationServices::getDelayedTrips() const
{
    const auto all_trips = trip_repository.getAll();
    std::vector<std::shared_ptr<Trip>> result;

    for (const auto &trip : all_trips)
    {
        if (trip->getTripStatus() == Status::Delayed)
        {
            result.push_back(trip);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Trip>> RelationServices::getDelayedTripsByReason(
    const std::string &reason) const
{
    const auto all_trips = trip_repository.getAll();
    std::vector<std::shared_ptr<Trip>> result;

    for (const auto &trip : all_trips)
    {
        if (trip->getTripStatus() == Status::Delayed && trip->getTripReason() == reason)
        {
            result.push_back(trip);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Trip>> RelationServices::getDelayedTripsByRoute(
    const std::string &id) const
{
    const auto route = route_repository.findById(id);
    const auto trips = route_to_trips.getLinkedB(route);
    std::vector<std::shared_ptr<Trip>> result;

    for (const auto &trip : trips)
    {
        if (trip->getTripStatus() == Status::Delayed)
        {
            result.push_back(trip);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>> RelationServices::getSoldTicketsByRoute(
    const std::string &id,
    const Date &start, const Date &end) const
{
    const auto route = route_repository.findById(id);
    const auto trips = route_to_trips.getLinkedB(route);

    std::vector<std::shared_ptr<Ticket>> all_sold_tickets;
    int total_sold_tickets = 0;
    int trip_count = 0;

    for (const auto &trip : trips)
    {
        const auto departure = trip->getDepartureTime();
        if (
            Date::differenceInMinutes(departure, start) >= 0 &&
            Date::differenceInMinutes(end, departure) >= 0)
        {
            int sold_for_trip = 0;
            for (const auto &ticket : trip_to_tickets.getLinkedB(trip))
            {
                if (!ticket->getStatus())
                {
                    all_sold_tickets.push_back(ticket);
                    sold_for_trip++;
                }
            }
            if (sold_for_trip > 0)
            {
                total_sold_tickets += sold_for_trip;
                trip_count++;
            }
        }
    }

    double average = trip_count > 0
                         ? static_cast<double>(total_sold_tickets) / trip_count
                         : 0.0;

    std::cout << "Average sold tickets per trip: " << average << std::endl;

    return all_sold_tickets;
}

std::vector<std::shared_ptr<Ticket>> RelationServices::getSoldTicketsByRouteDistance(
    const double distance,
    const Date &start, const Date &end) const
{
    const auto all_routes = route_repository.getAll();
    std::vector<std::shared_ptr<Route>> matching_routes;

    for (const auto &route : all_routes)
    {
        const auto &stations = routes_to_stations.getLinkedB(route);
        double dist = 0;
        for (size_t i = 0; i + 1 < stations.size(); ++i)
        {
            dist += Math::getDistanceBetweenPointsKm(
                stations[i]->getPosition(),
                stations[i + 1]->getPosition());
        }

        if (dist == distance)
        {
            matching_routes.push_back(route);
        }
    }

    std::vector<std::shared_ptr<Ticket>> result;
    int total_sold = 0;
    int trip_count = 0;

    for (const auto &route : matching_routes)
    {
        const auto &trips = route_to_trips.getLinkedB(route);

        for (const auto &trip : trips)
        {
            const auto departure = trip->getDepartureTime();
            if (
                Date::differenceInMinutes(departure, start) >= 0 &&
                Date::differenceInMinutes(end, departure) >= 0)
            {
                int sold = 0;
                for (const auto &ticket : trip_to_tickets.getLinkedB(trip))
                {
                    if (!ticket->getStatus() &&
                        Date::differenceInMinutes(ticket->getPurchasedAt(), Date(0, 0)) != 0)
                    {
                        result.push_back(ticket);
                        sold++;
                    }
                }

                total_sold += sold;
                trip_count++;
            }
        }
    }

    if (trip_count > 0)
    {
        double average = static_cast<double>(total_sold) / trip_count;
        std::cout << "Середня кількість проданих квитків на рейс: " << average << std::endl;
    }
    else
    {
        std::cout << "Рейсів з довжиною " << distance << " км не знайдено у вказаний інтервал." << std::endl;
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>>
RelationServices::getSoldTicketByTicketPrice(
    const double price,
    const Date &start, const Date &end) const
{
    const auto all_tickets = ticket_repository.getAll();
    std::vector<std::shared_ptr<Ticket>> result;

    for (const auto &ticket : all_tickets)
    {
        if (
            !ticket->getStatus() &&
            Date::differenceInMinutes(ticket->getPurchasedAt(), start) >= 0 &&
            Date::differenceInMinutes(end, ticket->getPurchasedAt()) >= 0 &&
            ticket->getPrice() == price)
        {
            result.push_back(ticket);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>> RelationServices::getUnredeemedTicketByTrip(
    const std::string &id) const
{
    const auto trip = trip_repository.findById(id);
    std::vector<std::shared_ptr<Ticket>> result;

    const auto tickets = trip_to_tickets.getLinkedB(trip);
    for (const auto &ticket : tickets)
    {
        if (Date::differenceInMinutes(ticket->getPurchasedAt(), Date()) == 0)
        {
            result.push_back(ticket);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>> RelationServices::getUnredeemedTicketByRoute(
    const std::string &id) const
{
    const auto route = route_repository.findById(id);
    const auto trips = route_to_trips.getLinkedB(route);
    std::vector<std::shared_ptr<Ticket>> result;

    std::vector<std::shared_ptr<Ticket>> tickets;
    for (const auto &trip : trips)
    {
        for (const auto &ticket : trip_to_tickets.getLinkedB(trip))
        {
            tickets.push_back(ticket);
        }
    }

    for (const auto &ticket : tickets)
    {
        if (Date::differenceInMinutes(ticket->getPurchasedAt(), Date()) == 0)
        {
            result.push_back(ticket);
        }
    }

    return result;
}

