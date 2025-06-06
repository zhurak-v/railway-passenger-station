#include "services/services/services.hpp"
#include <iostream>

Services::Services(
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
    TicketRepository &ticket_repository,
    PassengerRepository &passenger_repository

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
        ticket_repository(ticket_repository),
        passenger_repository(passenger_repository)
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
    loadAllLinks(
        this->ticket_to_passenger,
        ticket_repository.getAll(),
        passenger_repository.getAll());
}

std::vector<std::shared_ptr<Employee>> Services::getAllEmployees() const
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
    for (const auto &staff : staff_repository.getAll())
    {
        employees.push_back(std::static_pointer_cast<Employee>(staff));
    }

    return employees;
}

std::shared_ptr<Employee> Services::getEmployeeById(const std::string &id) const
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

    if (const auto staff = staff_repository.findById(id))
        return staff;

    return nullptr;
}

std::shared_ptr<Driver> Services::getDriverById(const std::string &id) const
{
    return driver_repository.findById(id);
}

std::shared_ptr<HeadDepartment> Services::getHeadDepartmentById(const std::string &id) const
{
    return head_department_repository.findById(id);
}

std::shared_ptr<Technician> Services::getTechnicianById(const std::string &id) const
{
    return technician_repository.findById(id);
}

std::shared_ptr<Dispatcher> Services::getDispatcherById(const std::string &id) const
{
    return dispatcher_repository.findById(id);
}

std::shared_ptr<Cashier> Services::getCashierById(const std::string &id) const
{
    return cashier_repository.findById(id);
}

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByExp(int exp) const
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

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByAge(int age) const
{
    const auto &all_employees = this->getAllEmployees();
    std::vector<std::shared_ptr<Employee>> employees;
    for (const auto &employee : all_employees)
    {
        if (Date::differenceInYears(Date(), employee->getBrithDate()) == age)
        {
            employees.push_back(employee);
        }
    }
    return employees;
}

std::vector<std::shared_ptr<Employee>> Services::getEmployeesBySex(const SEX &sex) const
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

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByChildCount(int child_count) const
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

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByHasChild(bool is_has_child) const
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

std::vector<std::shared_ptr<Employee>> Services::getEmployeesBySalary(double salary) const
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

std::vector<std::shared_ptr<HeadDepartment>> Services::getAllHeadDepartment() const
{
    return head_department_repository.getAll();
}

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByDepartment(const std::string &id) const
{
    const auto department = department_repository.findById(id);
    return department_to_employee.getLinkedB(department);
}

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByBrigade(const std::string &id) const
{
    std::vector<std::shared_ptr<Employee>> result;

    if (const auto brigade = technician_brigade_repository.findById(id))
    {
        const auto &technicians = technician_brigade_to_technician.getLinkedB(brigade);
        for (const auto &technician : technicians)
        {
            result.push_back(std::static_pointer_cast<Employee>(technician));
        }
        return result;
    }

    if (const auto brigade = locomotive_brigade_repository.findById(id))
    {
        const auto &staffs = locomotive_brigade_to_staffs.getLinkedB(brigade);
        for (const auto &staff : staffs)
        {
            result.push_back(std::static_pointer_cast<Employee>(staff));
        }
        return result;
    }

    return result;
}

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByAllDepartments() const
{
    std::vector<std::shared_ptr<Employee>> result;

    const auto all_departments = department_repository.getAll();
    for (const auto &department : all_departments)
    {
        const auto employees = department_to_employee.getLinkedB(department);
        for (const auto &employee : employees)
        {
            result.push_back(employee);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByServicingLocomotive(const std::string &id) const
{
    std::vector<std::shared_ptr<Employee>> result;
    const auto locomotive = locomotive_repository.findById(id);

    const auto locomotive_brigade = locomotive_brigade_to_locomotive.getLinkedA(locomotive);
    const auto technician_brigade = technician_brigade_to_locomotives.getLinkedA(locomotive);

    const auto stuffs = locomotive_brigade_to_staffs.getLinkedB(locomotive_brigade);
    const auto technicians = technician_brigade_to_technician.getLinkedB(technician_brigade);

    for (const auto &stuff : stuffs)
    {
        result.push_back(std::static_pointer_cast<Employee>(stuff));
    }
    for (const auto &technician : technicians)
    {
        result.push_back(std::static_pointer_cast<Employee>(technician));
    }

    return result;
}

std::vector<std::shared_ptr<Employee>> Services::getEmployeesByAverageSalaryInBrigade(double salary) const
{
    std::vector<std::shared_ptr<Employee>> result;

    auto processBrigades = [&](const auto &brigades, const auto &relation)
    {
        for (const auto &brigade : brigades)
        {
            const auto members = relation.getLinkedB(brigade);
            if (members.empty())
                continue;

            double sum = 0;
            for (const auto &member : members)
            {
                sum += member->getSalary();
            }

            double average = sum / members.size();
            if (average == salary)
            {
                result.insert(result.end(), members.begin(), members.end());
            }
        }
    };

    processBrigades(technician_brigade_repository.getAll(), technician_brigade_to_technician);
    processBrigades(locomotive_brigade_repository.getAll(), locomotive_brigade_to_staffs);

    return result;
}

std::vector<std::shared_ptr<Driver>> Services::getDriversByPassedMedInsp(const int year, const bool is_passed) const
{
    const auto all_drivers = driver_repository.getAll();
    std::vector<std::shared_ptr<Driver>> drivers;

    for (const auto &driver : all_drivers)
    {
        const auto &med_insp = driver->getPassedMedexam();

        bool passed_in_year = false;
        for (const auto &date : med_insp)
        {
            if (date.getYear() == year)
            {
                passed_in_year = true;
                break;
            }
        }

        if ((is_passed && passed_in_year) || (!is_passed && !passed_in_year))
        {
            drivers.push_back(driver);
        }
    }

    return drivers;
}

std::vector<std::shared_ptr<Driver>> Services::getDriversBySex(const SEX &sex) const
{
    const auto all_drivers = driver_repository.getAll();
    std::vector<std::shared_ptr<Driver>> drivers;

    for (const auto &driver : all_drivers)
    {
        if (driver->getSex() == sex)
        {
            drivers.push_back(driver);
        }
    }
    return drivers;
}

std::vector<std::shared_ptr<Driver>> Services::getDriversByAge(int age) const
{
    const auto &all_drivers = driver_repository.getAll();
    std::vector<std::shared_ptr<Driver>> drivers;
    for (const auto &driver : all_drivers)
    {
        if (Date::differenceInYears(Date(), driver->getBrithDate()) == age)
        {
            drivers.push_back(driver);
        }
    }
    return drivers;
}

std::vector<std::shared_ptr<Driver>> Services::getDriversBySalary(double salary) const
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

std::vector<std::shared_ptr<Station>> Services::getStationsByRoute(const std::string &id) const
{
    const auto route = route_repository.findById(id);
    return routes_to_stations.getLinkedB(route);
}

std::vector<std::shared_ptr<Route>> Services::getRoutesByStation(const std::string &id) const
{
    const auto station = station_repository.findById(id);
    return routes_to_stations.getLinkedA(station);
}

std::vector<std::shared_ptr<Trip>> Services::getTripsByRoute(const std::string &id) const
{
    const auto route = route_repository.findById(id);
    return route_to_trips.getLinkedB(route);
}

std::shared_ptr<Route> Services::getRouteByTrip(const std::string &id) const
{
    const auto trip = trip_repository.findById(id);
    return route_to_trips.getLinkedA(trip);
}

std::vector<std::shared_ptr<Locomotive>>
Services::getLocomotivesAtStationInTime(
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
            if (trip->getTripStatus() == Status::Delayed)
            {
                departure_time.addHours(trip->getDelayTime().getHour());
                departure_time.addMinutes(trip->getDelayTime().getMinute());
            }
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

std::vector<std::shared_ptr<Locomotive>> Services::getLocomotivesByStation(
    const std::string &id) const
{
    auto station = station_repository.findById(id);
    return station_to_locomotives.getLinkedB(station);
}

std::vector<std::shared_ptr<Locomotive>> Services::getLocomotivesByCompletedRoutes(
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
Services::getLocomotivesArrivalTimeAtStation(const std::string &station_id) const
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
            if (trip->getTripStatus() == Status::Delayed)
            {
                departure_time.addHours(trip->getDelayTime().getHour());
                departure_time.addMinutes(trip->getDelayTime().getMinute());
            }

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

std::vector<std::shared_ptr<Locomotive>> Services::getLocomotiveByPassedTechInsp(
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

std::vector<std::shared_ptr<Locomotive>> Services::getLocomotiveByRepairInTime(
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

std::vector<std::shared_ptr<Locomotive>> Services::getLocomotiveByRepairCount(
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

std::vector<std::shared_ptr<Locomotive>> Services::getLocomotivesByCompletedRoutesBeforeRepair(
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

std::vector<std::shared_ptr<Locomotive>> Services::getLocomotiveByAge(
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

std::vector<std::shared_ptr<Train>> Services::getTrainsByRoute(const std::string &id) const
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

std::vector<std::shared_ptr<Train>> Services::getTrainsByRouteDistance(
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

std::vector<std::shared_ptr<Train>> Services::getTrainsByticketPrice(
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

std::vector<std::shared_ptr<Train>> Services::getTrainsByRouteByRouteDistanceByticketPrice(
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

std::vector<std::shared_ptr<Trip>> Services::getCanceledTrips() const
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

std::vector<std::shared_ptr<Trip>> Services::getCanceledTripsByRoute(
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

std::vector<std::shared_ptr<Trip>> Services::getTripsByTwoStationsInOrder(
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

std::vector<std::shared_ptr<Trip>> Services::getDelayedTrips() const
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

std::vector<std::shared_ptr<Trip>> Services::getDelayedTripsByReason(
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

std::vector<std::shared_ptr<Trip>> Services::getDelayedTripsByRoute(
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

std::vector<std::shared_ptr<Ticket>> Services::getSoldTicketsByRoute(
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
        auto departure = trip->getDepartureTime();
        if (trip->getTripStatus() == Status::Delayed)
        {
            departure.addHours(trip->getDelayTime().getHour());
            departure.addMinutes(trip->getDelayTime().getMinute());
        }
        if (
            Date::differenceInMinutes(departure, start) >= 0 &&
            Date::differenceInMinutes(end, departure) >= 0)
        {
            int sold_for_trip = 0;
            for (const auto &ticket : trip_to_tickets.getLinkedB(trip))
            {
                if (ticket->getPurchasedAt().isTimeOnly())
                {
                    continue;
                }

                all_sold_tickets.push_back(ticket);
                sold_for_trip++;
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

std::vector<std::shared_ptr<Ticket>> Services::getSoldTicketsByRouteDistance(
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

        if (fabs(dist - distance) < 1)
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
            auto departure = trip->getDepartureTime();
            if (trip->getTripStatus() == Status::Delayed)
            {
                departure.addHours(trip->getDelayTime().getHour());
                departure.addMinutes(trip->getDelayTime().getMinute());
            }

            if (
                Date::differenceInMinutes(departure, start) >= 0 &&
                Date::differenceInMinutes(end, departure) >= 0)
            {
                int sold = 0;
                for (const auto &ticket : trip_to_tickets.getLinkedB(trip))
                {
                    if (!ticket->getPurchasedAt().isTimeOnly())
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
Services::getSoldTicketByTicketPrice(
    const double price,
    const Date &start, const Date &end) const
{
    const auto all_tickets = ticket_repository.getAll();
    std::vector<std::shared_ptr<Ticket>> result;

    for (const auto &ticket : all_tickets)
    {
        if (
            Date::differenceInMinutes(ticket->getPurchasedAt(), start) >= 0 &&
            Date::differenceInMinutes(end, ticket->getPurchasedAt()) >= 0 &&
            ticket->getPrice() == price)
        {
            result.push_back(ticket);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>> Services::getUnredeemedTicketByTrip(
    const std::string &id) const
{
    const auto trip = trip_repository.findById(id);
    std::vector<std::shared_ptr<Ticket>> result;

    const auto tickets = trip_to_tickets.getLinkedB(trip);
    for (const auto &ticket : tickets)
    {
        if (ticket->getPurchasedAt().isTimeOnly())
        {
            result.push_back(ticket);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>> Services::getUnredeemedTicketByRoute(
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
        if (ticket->getPurchasedAt().isTimeOnly())
        {
            result.push_back(ticket);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>> Services::getUnredeemedTicketByDate(
    const Date &date) const
{
    std::vector<std::shared_ptr<Ticket>> result;
    const auto all_tickets = ticket_repository.getAll();
    for (const auto &ticket : all_tickets)
    {
        if (ticket->getPurchasedAt().isTimeOnly())
        {
            result.push_back(ticket);
        }
        else if (
            ticket->getPurchasedAt().getYear() != date.getYear() ||
            ticket->getPurchasedAt().getMonth() != date.getMonth() ||
            ticket->getPurchasedAt().getDay() != date.getDay())
        {
            result.push_back(ticket);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Ticket>> Services::getReturnedTicketsForAllDelayedTrips() const
{
    std::vector<std::shared_ptr<Ticket>> result;

    const auto all_trips = trip_repository.getAll();
    for (const auto& trip : all_trips)
    {
        if (trip->getTripStatus() != Status::Delayed)
        {
            continue;
        }

        auto departure_time = trip->getDepartureTime();
        auto departure_time_delay = departure_time;
        departure_time_delay.addHours(trip->getDelayTime().getHour());
        departure_time_delay.addMinutes(trip->getDelayTime().getMinute());

        const auto tickets = trip_to_tickets.getLinkedB(trip);
        for (const auto& ticket : tickets)
        {
            if (ticket->getStatus() &&
                Date::differenceInMinutes(departure_time_delay, ticket->getReturnedAt()) >= 0 &&
                Date::differenceInMinutes(ticket->getReturnedAt(), departure_time) >= 0)
            {
                result.push_back(ticket);
            }
        }
    }

    return result;
}

std::vector<std::shared_ptr<Route>> Services::getRoutesByCategory(const TypeRoute &category) const
{
    const auto all_routes = route_repository.getAll();
    std::vector<std::shared_ptr<Route>> result;
    for (const auto &route : all_routes)
    {
        if (route->getTypeRoute() == category)
        {
            result.push_back(route);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Route>> Services::getRoutesByCategoryPositon(
    const std::vector<TypeRoute> &position) const
{
    const auto all_routes = route_repository.getAll();
    std::vector<std::shared_ptr<Route>> result;

    for (const auto &category : position)
    {
        for (const auto &route : all_routes)
        {
            if (route->getTypeRoute() == category)
            {
                result.push_back(route);
            }
        }
    }

    return result;
}

std::vector<std::shared_ptr<Passenger>> Services::getPassengersByTrip(
    const std::string &id) const
{
    const auto trip = trip_repository.findById(id);
    const auto tickets = trip_to_tickets.getLinkedB(trip);

    std::vector<std::shared_ptr<Passenger>> passengers;
    for (const auto &ticket : tickets)
    {
        const auto passenger = ticket_to_passenger.getLinkedB(ticket);
        passengers.push_back(passenger);
    }
    return passengers;
}

std::vector<std::shared_ptr<Passenger>> Services::getPassengersByLeft(
    const Date &date) const
{
    const auto all_passangers = passenger_repository.getAll();
    std::vector<std::shared_ptr<Passenger>> result;

    for (const auto &passanger : all_passangers)
    {
        const auto ticket = ticket_to_passenger.getLinkedA(passanger);
        if (ticket->getStatus())
        {
            continue;
        }
        const auto trip = trip_to_tickets.getLinkedA(ticket);
        if (trip->getDepartureTime().getDay() == date.getDay())
        {
            result.push_back(passanger);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Passenger>> Services::getPassengersByLeftForeign(
    const Date &date) const
{
    const auto all_passangers = passenger_repository.getAll();
    std::vector<std::shared_ptr<Passenger>> result;

    for (const auto &passanger : all_passangers)
    {
        const auto ticket = ticket_to_passenger.getLinkedA(passanger);
        if (ticket->getStatus())
        {
            continue;
        }
        const auto trip = trip_to_tickets.getLinkedA(ticket);
        const auto route = route_to_trips.getLinkedA(trip);
        if (trip->getDepartureTime().getDay() == date.getDay() && route->getTypeRoute() == TypeRoute::International)
        {
            result.push_back(passanger);
        }
    }

    return result;
}

std::vector<std::shared_ptr<Passenger>> Services::getPassengersByHasBaggage(
    const bool has_baggage) const
{
    const auto all_passangers = passenger_repository.getAll();
    std::vector<std::shared_ptr<Passenger>> result;

    for (const auto &passanger : all_passangers)
    {
        if (passanger->getHasBaggage() == has_baggage)
        {
            result.push_back(passanger);
        }
    }

    return result;
}
std::vector<std::shared_ptr<Passenger>> Services::getPassengersBySex(
    const SEX &sex) const
{
    const auto all_passangers = passenger_repository.getAll();
    std::vector<std::shared_ptr<Passenger>> result;

    for (const auto &passanger : all_passangers)
    {
        if (passanger->getSex() == sex)
        {
            result.push_back(passanger);
        }
    }
    return result;
}
std::vector<std::shared_ptr<Passenger>> Services::getPassengersByAge(
    const int age) const
{
    const auto all_passangers = passenger_repository.getAll();
    std::vector<std::shared_ptr<Passenger>> result;
    for (const auto &passanger : all_passangers)
    {
        if (Date::differenceInYears(Date(), passanger->getBrithDate()) == age)
        {
            result.push_back(passanger);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Ticket>> Services::getReturnedTicketsByTrip(const std::string &id) const
{
    std::vector<std::shared_ptr<Ticket>> result;
    const auto trip = trip_repository.findById(id);

    if (trip->getTripStatus() != Status::Delayed)
    {
        return result;
    }
    auto departure_time = trip->getDepartureTime();

    auto departure_time_delay = departure_time;
    departure_time_delay.addHours(trip->getDelayTime().getHour());
    departure_time_delay.addMinutes(trip->getDelayTime().getMinute());

    const auto tickets = trip_to_tickets.getLinkedB(trip);
    for (const auto &ticket : tickets)
    {

        if (ticket->getStatus() &&
            Date::differenceInMinutes(departure_time_delay, ticket->getReturnedAt()) >= 0 &&
            Date::differenceInMinutes(ticket->getReturnedAt(), departure_time) >= 0)
        {
            result.push_back(ticket);
        }
    }
    return result;
}

std::vector<std::shared_ptr<Ticket>> Services::getReturnedTicketsByDate(const Date& date) const
{
    std::vector<std::shared_ptr<Ticket>> result;
    const auto all_tickets = ticket_repository.getAll();

    for (const auto& ticket : all_tickets)
    {
       if (ticket->getStatus())
       {
           if (
            ticket->getReturnedAt().getYear() == date.getYear() &&
            ticket->getReturnedAt().getMonth() == date.getMonth() &&
            ticket->getReturnedAt().getDay() == date.getDay()
           )
           {
                result.push_back(ticket);
           }
            
       }
       
    }

    return result;
    
}

std::vector<std::shared_ptr<Ticket>> Services::getReturnedTicketsByRoute(const std::string &id) const
{
    std::vector<std::shared_ptr<Ticket>> result;

    const auto route = route_repository.findById(id);
    const auto trips = route_to_trips.getLinkedB(route);

    for (const auto& trip : trips)
    {
        if (trip->getTripStatus() != Status::Delayed)
        {
            return result;
        }
        auto departure_time = trip->getDepartureTime();

        auto departure_time_delay = departure_time;
        departure_time_delay.addHours(trip->getDelayTime().getHour());
        departure_time_delay.addMinutes(trip->getDelayTime().getMinute());

        const auto tickets = trip_to_tickets.getLinkedB(trip);
        for (const auto &ticket : tickets)
        {

            if (ticket->getStatus() &&
                Date::differenceInMinutes(departure_time_delay, ticket->getReturnedAt()) >= 0 &&
                Date::differenceInMinutes(ticket->getReturnedAt(), departure_time) >= 0)
            {
                result.push_back(ticket);
            }
        }
    }

    return result;
}