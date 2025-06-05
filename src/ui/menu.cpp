#include "ui/menu.hpp"
#include <iostream>

RelationMenu::RelationMenu(
    RelationServices &relation_services)
    : relation_services(relation_services) {}

void RelationMenu::run() const
{
    while (true)
    {
        showMainMenu();
        handleUserChoice();
    }
}

void RelationMenu::showMainMenu() const
{
    std::cout << "\n=== Меню ===\n";
    std::cout << "1. Переглянути локомотиви, приписані до залізничної станції\n";
    std::cout << "2. Переглянути локомотиви, що знаходяться на станції у вказаний час\n";
    std::cout << "3. Переглянути локомотиви за кількістю виконаних рейсів\n";
    std::cout << "4. Переглянути локомотиви, що пройшли плановий техогляд за певний період\n";

    std::cout << "5. Переглянути всіх працівників залізничної станції\n";
    std::cout << "6. Переглянути всіх начальників залізничної станції\n";
    std::cout << "7. Переглянути працівників вказаного відділу\n";
    std::cout << "8. Переглянути працівників за стажем роботи у відділі\n";
    std::cout << "9. Переглянути працівників за статевою ознакою\n";
    std::cout << "10. Переглянути працівників за віком\n";
    std::cout << "11. Переглянути працівників за наявністю дітей\n";
    std::cout << "12. Переглянути працівників за кількістю дітей\n";
    std::cout << "13. Переглянути працівників за рівнем заробітної плати\n";
    std::cout << "14. Переглянути працівників певної бригади\n";
    std::cout << "15. Переглянути працівників усіх відділів\n";
    std::cout << "16. Переглянути працівників, що обслуговують конкретний локомотив\n";
    std::cout << "17. Переглянути працівників за середньою зарплатою в бригаді\n";
    std::cout << "18. Переглянути водіїв, які пройшли медогляд у вказаному році\n";
    std::cout << "19. Переглянути водіїв за статевою ознакою\n";
    std::cout << "20. Переглянути водіїв за віком\n";
    std::cout << "21. Переглянути водіїв за зарплатою\n";

    std::cout << "22. Переглянути локомотиви, відправлені в ремонт у вказаний час\n";
    std::cout << "23. Переглянути локомотиви, що були в ремонті зазначену кількість разів\n";
    std::cout << "24. Переглянути локомотиви за кількістю рейсів до ремонту\n";
    std::cout << "25. Переглянути локомотиви за віком\n";

    std::cout << "26. Переглянути поїзди на зазначеному маршруті\n";
    std::cout << "27. Переглянути поїзди за довжиною маршруту\n";
    std::cout << "28. Переглянути поїзди за ціною квитка\n";
    std::cout << "29. Переглянути поїзди за маршрутом, дистанцією та ціною квитка\n";

    std::cout << "30. Переглянути повністю скасовані рейси\n";
    std::cout << "31. Переглянути скасовані рейси за маршрутом\n";
    std::cout << "32. Переглянути скасовані рейси за напрямком\n";
    std::cout << "33. Переглянути затримані рейси\n";
    std::cout << "34. Переглянути затримані рейси за причиною\n";
    std::cout << "35. Переглянути затримані рейси за маршрутом\n";

    std::cout << "36. Переглянути повернуті квитки за рейсом\n";
    std::cout << "37. Переглянути середню кількість проданих квитків у зазначений інтервал часу на маршрути\n";
    std::cout << "38. Переглянути середню кількість проданих квитків за дистанцією маршруту\n";
    std::cout << "39. Переглянути середню кількість проданих квитків за ціною\n";

    std::cout << "40. Переглянути маршрути зазначеної категорії\n";
    std::cout << "41. Переглянути маршрути зазначеної категорії у певному порядку\n";

    std::cout << "42. Переглянути пасажирів на зазначеному рейсі\n";
    std::cout << "43. Переглянути пасажирів, які виїхали в зазначений день\n";
    std::cout << "44. Переглянути пасажирів, які виїхали за кордон у зазначений день\n";
    std::cout << "45. Переглянути пасажирів за ознакою здачі речей у багаж\n";

    std::cout << "46. Переглянути невикуплені квитки на зазначений рейс\n";
    std::cout << "47. Переглянути невикуплені квитки на зазначеному маршруті\n";
    std::cout << "48. Переглянути невикуплені квитки на зазначену дату\n";

    std::cout << "49. Переглянути кількість зданих квитків на вказаний рейс\n";
    std::cout << "50. Переглянути кількість зданих квитків на вказану дату\n";
    std::cout << "51. Переглянути кількість зданих квитків на вказаний маршрут\n";

    std::cout << "Ваш вибір: ";
}

void RelationMenu::handleUserChoice() const
{
    int choice;
    if (!(std::cin >> choice))
    {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некоректне значення. Спробуйте ще раз.\n";
        return;
    }

    switch (choice)
    {
    case 1:
        getLocomotivesByStation();
        break;
    case 2:
        getLocomotivesAtStationInTime();
        break;
    case 3:
        getLocomotivesByCompletedRoutes();
        break;
    case 4:
        getLocomotiveByPassedTechInsp();
        break;

    case 5:
        getAllEmployees();
        break;
    case 6:
        getAllHeadDepartment();
        break;
    case 7:
        getEmployeesByDepartment();
        break;
    case 8:
        getEmployeesByExp();
        break;
    case 9:
        getEmployeesBySex();
        break;
    case 10:
        getEmployeesByAge();
        break;
    case 11:
        getEmployeesByHasChild();
        break;
    case 12:
        getEmployeesByChildCount();
        break;
    case 13:
        getEmployeesBySalary();
        break;
    case 14:
        getEmployeesByBrigade();
        break;
    case 15:
        getEmployeesByAllDepartments();
        break;
    case 16:
        getEmployeesByServicingLocomotive();
        break;
    case 17:
        getEmployeesByAverageSalaryInBrigade();
        break;
    case 18:
        getDriversByPassedMedInsp();
        break;
    case 19:
        getDriversBySex();
        break;
    case 20:
        getDriversByAge();
        break;
    case 21:
        getDriversBySalary();
        break;
    case 22:
        getLocomotiveByRepairInTime();
        break;
    case 23:
        getLocomotiveByRepairCount();
        break;
    case 24:
        getLocomotivesByCompletedRoutesBeforeRepair();
        break;
    case 25:
        getLocomotiveByAge();
        break;
    case 26:
        getTrainsByRoute();
        break;
    case 27:
        getTrainsByRouteDistance();
        break;
    case 28:
        getTrainsByticketPrice();
        break;
    case 29:
        getTrainsByRouteByRouteDistanceByticketPrice();
        break;
    case 30:
        getCanceledTrips();
        break;
    case 31:
        getCanceledTripsByRoute();
        break;
    case 32:
        getTripsByTwoStationsInOrder();
        break;
    case 33:
        getDelayedTrips();
        break;
    case 34:
        getDelayedTripsByReason();
        break;
    case 35:
        getDelayedTripsByRoute();
        break;
    case 36:
        getReturnedTicketsForAllDelayedTrips();
        break;
    case 37:
        getSoldTicketsByRoute();
        break;
    case 38:
        getSoldTicketsByRouteDistance();
        break;
    case 39:
        getSoldTicketsByTicketPrice();
        break;
    case 40:
        getRoutesByCategory();
        break;
    case 41:
        getRoutesByCategoryPositon();
        break;
    case 42:
        getPassengersByTrip();
        break;
    case 43:
        getPassengersByLeft();
        break;
    case 44:
        getPassengersByLeftForeign();
        break;
    case 45:
        getPassengersByHasBaggage();
        break;
    case 46:
        getUnredeemedTicketByTrip();
        break;
    case 47:
        getUnredeemedTicketByRoute();
        break;
    case 48:
        getUnredeemedTicketByDate();
        break;
    case 49:
        getReturnedTicketsByTrip();
        break;
    case 50:
        getReturnedTicketsByDate();
        break;
    case 51:
        getReturnedTicketsByRoute();
        break;

    default:
        std::cout << "Невірний вибір. Спробуйте ще раз.\n";
    }
}

void RelationMenu::getLocomotivesByStation() const
{
    std::string id;
    std::cout << "Введіть ID станції: ";
    std::cin >> id;

    auto locomtives = relation_services.getLocomotivesByStation(id);
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getLocomotivesAtStationInTime() const
{
    std::string id;
    std::cout << "Введіть ID станції: ";
    std::cin >> id;
    std::string date;
    std::cout << "Введіть час у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto locomtives = relation_services.getLocomotivesAtStationInTime(id, Date::deserialize(date));
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getLocomotivesByCompletedRoutes() const
{
    std::string count;
    std::cout << "Введіть кількість скоєних рейсів: ";
    std::cin >> count;

    auto locomtives = relation_services.getLocomotivesByCompletedRoutes(std::stoi(count));
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getLocomotiveByPassedTechInsp() const
{
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;

    auto locomtives = relation_services.getLocomotiveByPassedTechInsp(
        Date::deserialize(from), Date::deserialize(to));
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getAllEmployees() const
{
    auto employees = relation_services.getAllEmployees();
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getAllHeadDepartment() const
{
    auto head_departments = relation_services.getAllHeadDepartment();
    for (const auto &head_department : head_departments)
    {
        std::cout << "Нчальник відділу: " << head_department->getId() << " " << head_department->getFullName() << std::endl;
    }
    std::cout << "Кількість " << head_departments.size() << std::endl;
}
void RelationMenu::getEmployeesByDepartment() const
{
    std::string id;
    std::cout << "Введіть ID відділу: ";
    std::cin >> id;
    auto employees = relation_services.getEmployeesByDepartment(id);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByExp() const
{
    int exp;
    std::cout << "Введіть стаж роботи в роках: ";
    std::cin >> exp;
    auto employees = relation_services.getEmployeesByExp(exp);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesBySex() const
{
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto employees = relation_services.getEmployeesBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getEmployeesByAge() const
{
    int age;
    std::cout << "Введіть вік працівника в роках: ";
    std::cin >> age;

    auto employees = relation_services.getEmployeesByAge(age);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getEmployeesByHasChild() const
{
    std::string has_children;
    std::cout << "Чи є діти (Y or N)";
    std::cin >> has_children;

    auto employees = relation_services.getEmployeesByHasChild(has_children == "Y");
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByChildCount() const
{
    int child_count;
    std::cout << "Введіть кількість дітей: ";
    std::cin >> child_count;

    auto employees = relation_services.getEmployeesByChildCount(child_count);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesBySalary() const
{
    double salary;
    std::cout << "Введіть розмір заробітньої плати: ";
    std::cin >> salary;

    auto employees = relation_services.getEmployeesBySalary(salary);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getEmployeesByBrigade() const
{
    std::string id;
    std::cout << "Введіть ID бригади: ";
    std::cin >> id;
    auto employees = relation_services.getEmployeesByBrigade(id);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByAllDepartments() const
{
    auto employees = relation_services.getEmployeesByAllDepartments();
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getEmployeesByServicingLocomotive() const
{
    std::string id;
    std::cout << "Введіть ID локомотиву: ";
    std::cin >> id;
    auto employees = relation_services.getEmployeesByServicingLocomotive(id);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByAverageSalaryInBrigade() const
{
    double salary;
    std::cout << "Введіть розмір середньої заробітньої плати в бригаді: ";
    std::cin >> salary;

    auto employees = relation_services.getEmployeesByAverageSalaryInBrigade(salary);
    for (const auto &employee : employees)
    {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getDriversByPassedMedInsp() const
{
    int year;
    std::cout << "Введіть рік проходження медогляду: ";
    std::cin >> year;
    std::string is_passed;
    std::cout << "Вкажіть умову для водіїв які пройшли або не пройшли (Y or N) медогляд у " << year << " році: ";
    std::cin >> is_passed;

    auto drivers = relation_services.getDriversByPassedMedInsp(year, is_passed == "Y" ? true : false);
    for (const auto &driver : drivers)
    {
        std::cout << "Водій: " << driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}
void RelationMenu::getDriversBySex() const
{
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto drivers = relation_services.getDriversBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto &driver : drivers)
    {
        std::cout << "Водій: " << driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}

void RelationMenu::getDriversByAge() const
{
    int age;
    std::cout << "Введіть вік працівника в роках: ";
    std::cin >> age;

    auto drivers = relation_services.getDriversByAge(age);
    for (const auto &driver : drivers)
    {
        std::cout << "Водій: " << driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}
void RelationMenu::getDriversBySalary() const
{
    double salary;
    std::cout << "Введіть розмір заробітньої плати: ";
    std::cin >> salary;

    auto drivers = relation_services.getDriversBySalary(salary);
    for (const auto &driver : drivers)
    {
        std::cout << "Водій: " << driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}
void RelationMenu::getLocomotiveByRepairInTime() const
{
    std::string date;
    std::cout << "Введіть дату відправлення у ремонт у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto locomtives = relation_services.getLocomotiveByRepairInTime(
        Date::deserialize(date));
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}
void RelationMenu::getLocomotiveByRepairCount() const
{
    int count;
    std::cout << "Введіть кількість ремонтів: ";
    std::cin >> count;

    auto locomtives = relation_services.getLocomotiveByRepairCount(count);
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}
void RelationMenu::getLocomotivesByCompletedRoutesBeforeRepair() const
{
    int count;
    std::cout << "Введіть кількість рейсів до ремонту: ";
    std::cin >> count;

    auto locomtives = relation_services.getLocomotivesByCompletedRoutesBeforeRepair(count);
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}
void RelationMenu::getLocomotiveByAge() const
{
    int age;
    std::cout << "Введіть вік локомотиву в роках: ";
    std::cin >> age;

    auto locomtives = relation_services.getLocomotiveByAge(age);
    for (const auto &locomotive : locomtives)
    {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getTrainsByRoute() const
{
    std::string id;
    std::cout << "Введіть ID маршруту: ";
    std::cin >> id;

    auto trains = relation_services.getTrainsByRoute(id);
    for (const auto &train : trains)
    {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void RelationMenu::getTrainsByRouteDistance() const
{
    double distance;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> distance;

    auto trains = relation_services.getTrainsByRouteDistance(distance);
    for (const auto &train : trains)
    {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void RelationMenu::getTrainsByticketPrice() const
{
    double price;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> price;

    auto trains = relation_services.getTrainsByticketPrice(price);
    for (const auto &train : trains)
    {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void RelationMenu::getTrainsByRouteByRouteDistanceByticketPrice() const
{
    std::string id;
    std::cout << "Введіть ID маршруту: ";
    std::cin >> id;
    double distance;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> distance;
    double price;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> price;

    auto trains = relation_services.getTrainsByRouteByRouteDistanceByticketPrice(id, distance, price);
    for (const auto &train : trains)
    {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void RelationMenu::getCanceledTrips() const
{
    auto trips = relation_services.getCanceledTrips();
    for (const auto &trip : trips)
    {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void RelationMenu::getCanceledTripsByRoute() const
{
    std::string id;
    std::cout << "Введіть ID маршруту: ";
    std::cin >> id;
    auto trips = relation_services.getCanceledTripsByRoute(id);
    for (const auto &trip : trips)
    {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void RelationMenu::getTripsByTwoStationsInOrder() const
{
    std::string id1;
    std::cout << "Введіть ID першої станції: ";
    std::cin >> id1;
    std::string id2;
    std::cout << "Введіть ID другої станції: ";
    std::cin >> id2;
    auto trips = relation_services.getTripsByTwoStationsInOrder(id1, id2);
    for (const auto &trip : trips)
    {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}

void RelationMenu::getDelayedTrips() const
{
    auto trips = relation_services.getDelayedTrips();
    for (const auto &trip : trips)
    {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void RelationMenu::getDelayedTripsByReason() const
{
    std::string reason;
    std::cout << "Введіть причину затримання: ";
    std::cin >> reason;
    auto trips = relation_services.getDelayedTripsByReason(reason);
    for (const auto &trip : trips)
    {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void RelationMenu::getDelayedTripsByRoute() const
{
    std::string id;
    std::cout << "Введіть id маршруту: ";
    std::cin >> id;
    auto trips = relation_services.getDelayedTripsByRoute(id);
    for (const auto &trip : trips)
    {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void RelationMenu::getReturnedTicketsForAllDelayedTrips() const
{
    auto tickets = relation_services.getReturnedTicketsForAllDelayedTrips();
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void RelationMenu::getSoldTicketsByRoute() const
{
    std::string id;
    std::cout << "Введіть id Маршруту: ";
    std::cin >> id;
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;
    auto tickets = relation_services.getSoldTicketsByRoute(id, Date::deserialize(from), Date::deserialize(to));
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
}
void RelationMenu::getSoldTicketsByRouteDistance() const
{
    double distance;
    std::cout << "Введіть id Маршруту: ";
    std::cin >> distance;
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;
    auto tickets = relation_services.getSoldTicketsByRouteDistance(distance, Date::deserialize(from), Date::deserialize(to));
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
}
void RelationMenu::getSoldTicketsByTicketPrice() const
{
    double price;
    std::cout << "Введіть id Маршруту: ";
    std::cin >> price;
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;
    auto tickets = relation_services.getSoldTicketByTicketPrice(price, Date::deserialize(from), Date::deserialize(to));
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
}

void RelationMenu::getRoutesByCategory() const
{
    std::string category;
    std::cout << "Введіть Категорію Маршруту (Domestic, International, Tourist, Special): ";
    std::cin >> category;

    auto type_route = parseTypeRoute(category);
    if (!type_route.has_value())
    {
        std::cout << "Невідома категорія маршруту!" << std::endl;
        return;
    }

    auto routes = relation_services.getRoutesByCategory(type_route.value());
    for (const auto &route : routes)
    {
        std::cout << "Маршрут: " << route->getId() << std::endl;
    }
}

void RelationMenu::getRoutesByCategoryPositon() const
{
    std::cout << "Введіть Категорії Маршруту в певній послідовності (приклад: Domestic International Tourist Special): ";

    std::string line;
    std::getline(std::cin >> std::ws, line);

    std::istringstream iss(line);
    std::string token;
    std::vector<TypeRoute> categories;

    while (iss >> token)
    {
        auto parsed = parseTypeRoute(token);
        if (parsed.has_value())
        {
            categories.push_back(parsed.value());
        }
        else
        {
            std::cout << "Невідома категорія: " << token << std::endl;
            return;
        }
    }

    auto routes = relation_services.getRoutesByCategoryPositon(categories);
    for (const auto &route : routes)
    {
        std::cout << "Маршрут: " << route->getId() << std::endl;
    }
}

void RelationMenu::getPassengersByTrip() const
{
    std::string id;
    std::cout << "Введіть id Рейсу: ";
    std::cin >> id;
    auto passengers = relation_services.getPassengersByTrip(id);
    for (const auto &passenger : passengers)
    {
        std::cout << "Пасажир: " << passenger->getId() << std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}
void RelationMenu::getPassengersByLeft() const
{
    std::string date;
    std::cout << "Введіть дату виїзду у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;
    auto passengers = relation_services.getPassengersByLeft(Date::deserialize(date));
    for (const auto &passenger : passengers)
    {
        std::cout << "Пасажир: " << passenger->getId() << std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}
void RelationMenu::getPassengersByLeftForeign() const
{
    std::string date;
    std::cout << "Введіть дату виїзду у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;
    auto passengers = relation_services.getPassengersByLeftForeign(Date::deserialize(date));
    for (const auto &passenger : passengers)
    {
        std::cout << "Пасажир: " << passenger->getId() << std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}

void RelationMenu::getPassengersByHasBaggage() const
{
    std::string has_baggage;
    std::cout << "Чи задв пасажир свій багаж (Y or N): ";
    std::cin >> has_baggage;
    auto passengers = relation_services.getPassengersByHasBaggage(has_baggage == "Y");
    for (const auto &passenger : passengers)
    {
        std::cout << "Пасажир: " << passenger->getId() << std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}
void RelationMenu::getPassengersBySex() const
{
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto passengers = relation_services.getPassengersBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto &passenger : passengers)
    {
        std::cout << "Пасажир: " << passenger->getId() << std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}

void RelationMenu::getUnredeemedTicketByTrip() const
{
    std::string id;
    std::cout << "Введіть id рейсу: ";
    std::cin >> id;

    auto tickets = relation_services.getUnredeemedTicketByTrip(id);
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void RelationMenu::getUnredeemedTicketByRoute() const
{
    std::string id;
    std::cout << "Введіть id маршруту: ";
    std::cin >> id;

    auto tickets = relation_services.getUnredeemedTicketByRoute(id);
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void RelationMenu::getUnredeemedTicketByDate() const
{
    std::string date;
    std::cout << "Введіть зазнеачену дату у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto tickets = relation_services.getUnredeemedTicketByDate(Date::deserialize(date));
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void RelationMenu::getReturnedTicketsByTrip() const
{
    std::string id;
    std::cout << "Введіть id рейсу: ";
    std::cin >> id;

    auto tickets = relation_services.getReturnedTicketsByTrip(id);
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void RelationMenu::getReturnedTicketsByRoute() const
{
    std::string id;
    std::cout << "Введіть id маршруту: ";
    std::cin >> id;

    auto tickets = relation_services.getReturnedTicketsByRoute(id);
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void RelationMenu::getReturnedTicketsByDate() const
{
    std::string date;
    std::cout << "Введіть зазнеачену дату у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto tickets = relation_services.getReturnedTicketsByDate(Date::deserialize(date));
    for (const auto &ticket : tickets)
    {
        std::cout << "Квиток: " << ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}