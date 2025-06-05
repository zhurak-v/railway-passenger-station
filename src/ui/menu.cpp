#include "ui/menu.hpp"
#include <iostream>

Menu::Menu(Services& services)
    : services(services) {}

void Menu::run() const {
    while (true) {
        showMainMenu();
        handleUserChoice();
    }
}

void Menu::showMainMenu() const {
    std::cout << "\n=== Меню ===\n";
    std::cout << "1. Отримати перелік і загальне число усіх працівників залізничної станції\n";
    std::cout << "2. Отримати перелік і загальне число усіх начальників залізничної станції\n";
    std::cout << "3. Отримати перелік і загальне число усіх працівників вказаного відділу\n";
    std::cout << "4. Отримати перелік і загальне число усіх працівників за стажом роборти відділу\n";
    std::cout << "5. Отримати перелік і загальне число усіх працівників за статевою ознакою\n";
    std::cout << "6. Отримати перелік і загальне число усіх працівників за віком\n";
    std::cout << "7. Отримати перелік і загальне число усіх працівників за ознаком наявністю дітей\n";
    std::cout << "8. Отримати перелік і загальне число усіх працівників за кількістю дітей\n";
    std::cout << "9. Отримати перелік і загальне число усіх працівників за розміром заробітньої плати\n";

    std::cout << "10. Отримати перелік і загальне число усіх працівників у бригаді\n";
    std::cout << "11. Отримати перелік і загальне число усіх працівників по всім відділам\n";
    std::cout << "12. Отримати перелік і загальне число усіх працівників обслуговуючий певний локомотив\n";
    std::cout << "13. Отримати перелік і загальне число усіх працівників за середньою зарплатою в бригаді\n";
    
    std::cout << "14. Отримати перелік і загальне число усіх водіїв які пройшли медогляд у вказаний рік\n";
    std::cout << "15. Отримати перелік і загальне число усіх водіїв за статевою ознакою\n";
    std::cout << "16. Отримати перелік і загальне число усіх водіїв за віком\n";
    std::cout << "17. Отримати перелік і загальне число усіх водіїв за зарплатою\n";

    std::cout << "18. Отримати перелік локомотивів приписаних до залізничної станції\n";
    std::cout << "19. Отримати перелік і загальне число локомотивів що знаходяться у вказаній станції в певний час\n";
    std::cout << "20. Отримати перелік і загальне число локомотивів за кількістю скоєних рейсів\n";
    std::cout << "21. Отримати перелік і загальне число локомотивів які пройшли плановий техогляд за певний пераод часу\n";
    std::cout << "22. Отримати перелік і загальне число усіх локомотивів відправлених у ремонт в означений час\n";
    std::cout << "23. Отримати перелік і загальне число усіх локомотивів ремонтованих вказане число разів\n";
    std::cout << "24. Отримати перелік і загальне число усіх локомотивів за кількістю скоєних рейсів до ремонту\n";
    std::cout << "25. Отримати перелік і загальне число усіх локомотивів за віком локомотива\n";

    std::cout << "26. Отримати перелік і загальне число усіх поїздів на зазначеному маршруті\n";
    std::cout << "27. Отримати перелік і загальне число усіх поїздів по дистанції маршруту\n";
    std::cout << "28. Отримати перелік і загальне число усіх поїздів за ціною квитка\n";
    std::cout << "29. Отримати перелік і загальне число усіх поїздів на зазначеному маршруті, по дистанції маршруту та за ціною квитка\n";
    
    std::cout << "30. Отримати перелік і загальне число скасованих рейсів повністю\n";
    std::cout << "31. Отримати перелік і загальне число скасованих рейсів за вказаним маршрутом\n";
    std::cout << "32. Отримати перелік і загальне число скасованих рейсів за вказаним напрямком\n";
    std::cout << "33. Отримати перелік і загальне число затриманих рейсів\n";
    std::cout << "34. Отримати перелік і загальне число затриманих рейсів за причиною\n";
    std::cout << "35. Отримати перелік і загальне число затриманих рейсів за маршрутом\n";
    std::cout << "36. Отримати перелік і загальне число повернутих квитків за рейсом\n";
    
    std::cout << "37. Отримати перелік і середню кількість проданих квитків за вказаний інтервал часу на певні маршрути\n";
    std::cout << "38. Отримати перелік і середню кількість проданих квитків за вказаний інтервал часу за дистанцією маршруту\n";
    std::cout << "39. Отримати перелік і середню кількість проданих квитків за вказаний інтервал часу за ціною квитка\n";
    
    std::cout << "40. Отримати перелік і загальне число маршрутів зазначеної категорії\n";
    std::cout << "41. Отримати перелік і загальне число маршрутів зазначеної категорії в певному порядку\n";
    
    std::cout << "42. Отримати перелік і загальне число пасажирів на зазначеному рейсі\n";
    std::cout << "43. Отримати перелік і загальне число пасажирів які виїхали в зазначений день\n";
    std::cout << "44. Отримати перелік і загальне число пасажирів які виїхали за кордон у зазначений день\n";
    std::cout << "45. Отримати перелік і загальне число пасажирів які за ознакою здачі речей в багажне відділення\n";
    
    std::cout << "46. Отримати перелік і загальне число невикуплених квитків на зазначеному рейсі\n";
    std::cout << "47. Отримати перелік і загальне число невикуплених квитків на зазначеному маршруті\n";
    std::cout << "48. Отримати перелік і загальне число невикуплених квитків в зазначену дату\n";
    
    std::cout << "49. Отримати загальне число зданих квитків на вказаний рейс\n";
    std::cout << "50. Отримати загальне число зданих квитків на вказану дату\n";
    std::cout << "51. Отримати загальне число зданих квитків на вказаний маршрут\n";

    std::cout << "Ваш вибір: ";
}

void Menu::handleUserChoice() const {
    int choice;
    if (!(std::cin >> choice)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Некоректне значення. Спробуйте ще раз.\n";
        return;
    }

    switch (choice) {
        case 1:
            getAllEmployees();
            break;
        case 2:
            getAllHeadDepartment();
            break;
        case 3:
            getEmployeesByDepartment();
            break;
        case 4:
            getEmployeesByExp();
            break;
        case 5:
            getEmployeesBySex();
            break;
        case 6:
            getEmployeesByAge();
            break;
        case 7:
            getEmployeesByHasChild();
            break;
        case 8:
            getEmployeesByChildCount();
            break;
        case 9:
            getEmployeesBySalary();
            break;

        case 10:
            getEmployeesByBrigade();
            break;
        case 11:
            getEmployeesByAllDepartments();
            break;
        case 12:
            getEmployeesByServicingLocomotive();
            break;
        case 13:
            getEmployeesByAverageSalaryInBrigade();
            break;

        case 14:
            getDriversByPassedMedInsp();
            break;
        case 15:
            getDriversBySex();
            break;
        case 16:
            getDriversByAge();
            break;
        case 17:
            getDriversBySalary();
            break;

        case 18:
            getLocomotivesByStation();
            break;
        case 19:
            getLocomotivesAtStationInTime();
            break;
        case 20:
            getLocomotivesByCompletedRoutes();
            break;
        case 21:
            getLocomotiveByPassedTechInsp();
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

void Menu::getLocomotivesByStation() const {
    std::string id;
    std::cout << "Введіть ID станції: ";
    std::cin >> id;

    auto locomtives = services.getLocomotivesByStation(id);
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void Menu::getLocomotivesAtStationInTime() const {
    std::string id;
    std::cout << "Введіть ID станції: ";
    std::cin >> id;
    std::string date;
    std::cout << "Введіть час у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto locomtives = services.getLocomotivesAtStationInTime(id, Date::deserialize(date));
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void Menu::getLocomotivesByCompletedRoutes() const {
    std::string count;
    std::cout << "Введіть кількість скоєних рейсів: ";
    std::cin >> count;

    auto locomtives = services.getLocomotivesByCompletedRoutes(std::stoi(count));
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void Menu::getLocomotiveByPassedTechInsp() const {
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;

    auto locomtives = services.getLocomotiveByPassedTechInsp(
        Date::deserialize(from), Date::deserialize(to)
    );
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void Menu::getAllEmployees() const {
    auto employees = services.getAllEmployees();
    for (const auto& employee : employees) {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void Menu::getAllHeadDepartment() const {
    auto head_departments = services.getAllHeadDepartment();
    for (const auto& head_department : head_departments) {
        std::cout << "Нчальник відділу: " <<  head_department->getId() << " " << head_department->getFullName() << std::endl;
    }
    std::cout << "Кількість " << head_departments.size() << std::endl;
}
void Menu::getEmployeesByDepartment() const {
    std::string id;
    std::cout << "Введіть ID відділу: ";
    std::cin >> id;
    auto employees = services.getEmployeesByDepartment(id);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void Menu::getEmployeesByExp() const {
    int exp;
    std::cout << "Введіть стаж роботи в роках: ";
    std::cin >> exp;
    auto employees = services.getEmployeesByExp(exp);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void Menu::getEmployeesBySex() const {
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto employees = services.getEmployeesBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void Menu::getEmployeesByAge() const {
    int age;
    std::cout << "Введіть вік працівника в роках: ";
    std::cin >> age;

    auto employees = services.getEmployeesByAge(age);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void Menu::getEmployeesByHasChild() const {
    std::string has_children;
    std::cout << "Чи є діти (Y or N)";
    std::cin >> has_children;

    auto employees = services.getEmployeesByHasChild(has_children == "Y");
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void Menu::getEmployeesByChildCount() const {
    int child_count;
    std::cout << "Введіть кількість дітей: ";
    std::cin >> child_count;

    auto employees = services.getEmployeesByChildCount(child_count);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}    

void Menu::getEmployeesBySalary() const {
    double salary;
    std::cout << "Введіть розмір заробітньої плати: ";
    std::cin >> salary;

    auto employees = services.getEmployeesBySalary(salary);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}    
void Menu::getEmployeesByBrigade() const {
    std::string id;
    std::cout << "Введіть ID бригади: ";
    std::cin >> id;
    auto employees = services.getEmployeesByBrigade(id);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void Menu::getEmployeesByAllDepartments() const {
    auto employees = services.getEmployeesByAllDepartments();
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void Menu::getEmployeesByServicingLocomotive() const {
    std::string id;
    std::cout << "Введіть ID локомотиву: ";
    std::cin >> id;
    auto employees = services.getEmployeesByServicingLocomotive(id);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void Menu::getEmployeesByAverageSalaryInBrigade() const {
    double salary;
    std::cout << "Введіть розмір середньої заробітньої плати в бригаді: ";
    std::cin >> salary;

    auto employees = services.getEmployeesByAverageSalaryInBrigade(salary);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void Menu::getDriversByPassedMedInsp() const {
    int year;
    std::cout << "Введіть рік проходження медогляду: ";
    std::cin >> year;
    std::string is_passed;
    std::cout << "Вкажіть умову для водіїв які пройшли або не пройшли (Y or N) медогляд у " << year << " році: ";
    std::cin >> is_passed;

    auto drivers = services.getDriversByPassedMedInsp(year, is_passed == "Y" ? true : false);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}
void Menu::getDriversBySex() const {
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto drivers = services.getDriversBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}

void Menu::getDriversByAge() const {
    int age;
    std::cout << "Введіть вік працівника в роках: ";
    std::cin >> age;

    auto drivers = services.getDriversByAge(age);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}
void Menu::getDriversBySalary() const {
    double salary;
    std::cout << "Введіть розмір заробітньої плати: ";
    std::cin >> salary;

    auto drivers = services.getDriversBySalary(salary);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
} 
void Menu::getLocomotiveByRepairInTime() const {
    std::string date;
    std::cout << "Введіть дату відправлення у ремонт у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto locomtives = services.getLocomotiveByRepairInTime(
        Date::deserialize(date)
    );
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}
void Menu::getLocomotiveByRepairCount() const {
    int count;
    std::cout << "Введіть кількість ремонтів: ";
    std::cin >> count;

    auto locomtives = services.getLocomotiveByRepairCount(count);
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}
void Menu::getLocomotivesByCompletedRoutesBeforeRepair() const {
    int count;
    std::cout << "Введіть кількість рейсів до ремонту: ";
    std::cin >> count;

    auto locomtives = services.getLocomotivesByCompletedRoutesBeforeRepair(count);
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}
void Menu::getLocomotiveByAge() const {
    int age;
    std::cout << "Введіть вік локомотиву в роках: ";
    std::cin >> age;

    auto locomtives = services.getLocomotiveByAge(age);
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void Menu::getTrainsByRoute() const {
    std::string id;
    std::cout << "Введіть ID маршруту: ";
    std::cin >> id;

    auto trains = services.getTrainsByRoute(id);
    for (const auto& train : trains) {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void Menu::getTrainsByRouteDistance() const {
    double distance;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> distance;

    auto trains = services.getTrainsByRouteDistance(distance);
    for (const auto& train : trains) {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void Menu::getTrainsByticketPrice() const {
    double price;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> price;

    auto trains = services.getTrainsByticketPrice(price);
    for (const auto& train : trains) {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void Menu::getTrainsByRouteByRouteDistanceByticketPrice() const {
    std::string id;
    std::cout << "Введіть ID маршруту: ";
    std::cin >> id;
    double distance;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> distance;
    double price;
    std::cout << "Введіть дистанцію маршруту: ";
    std::cin >> price;

    auto trains = services.getTrainsByRouteByRouteDistanceByticketPrice(id, distance, price);
    for (const auto& train : trains) {
        std::cout << "Потяг: " << train->getId() << std::endl;
    }
    std::cout << "Кількість " << trains.size() << std::endl;
}
void Menu::getCanceledTrips() const {
    auto trips = services.getCanceledTrips();
    for (const auto& trip : trips) {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void Menu::getCanceledTripsByRoute() const {
    std::string id;
    std::cout << "Введіть ID маршруту: ";
    std::cin >> id;
    auto trips = services.getCanceledTripsByRoute(id);
    for (const auto& trip : trips) {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void Menu::getTripsByTwoStationsInOrder() const {
    std::string id1;
    std::cout << "Введіть ID першої станції: ";
    std::cin >> id1;
    std::string id2;
    std::cout << "Введіть ID другої станції: ";
    std::cin >> id2;
    auto trips = services.getTripsByTwoStationsInOrder(id1, id2);
    for (const auto& trip : trips) {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}

void Menu::getDelayedTrips() const {
    auto trips = services.getDelayedTrips();
    for (const auto& trip : trips) {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void Menu::getDelayedTripsByReason() const {
    std::string reason;
    std::cout << "Введіть причину затримання: ";
    std::cin >> reason;
    auto trips = services.getDelayedTripsByReason(reason);
    for (const auto& trip : trips) {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void Menu::getDelayedTripsByRoute() const {
    std::string id;
    std::cout << "Введіть id маршруту: ";
    std::cin >> id;
    auto trips = services.getDelayedTripsByRoute(id);
    for (const auto& trip : trips) {
        std::cout << "Рейс: " << trip->getId() << std::endl;
    }
    std::cout << "Кількість " << trips.size() << std::endl;
}
void Menu::getReturnedTicketsForAllDelayedTrips() const {
    auto tickets = services.getReturnedTicketsForAllDelayedTrips();
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " << ticket->getId() <<  std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void Menu::getSoldTicketsByRoute() const {
    std::string id;
    std::cout << "Введіть id Маршруту: ";
    std::cin >> id;
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;
    auto tickets = services.getSoldTicketsByRoute(id, Date::deserialize(from), Date::deserialize(to));
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " << ticket->getId() <<  std::endl;
    }
}
void Menu::getSoldTicketsByRouteDistance() const {
    double distance;
    std::cout << "Введіть id Маршруту: ";
    std::cin >> distance;
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;
    auto tickets = services.getSoldTicketsByRouteDistance(distance, Date::deserialize(from), Date::deserialize(to));
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " << ticket->getId() <<  std::endl;
    }
}
void Menu::getSoldTicketsByTicketPrice() const {
    double price;
    std::cout << "Введіть id Маршруту: ";
    std::cin >> price;
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;
    auto tickets = services.getSoldTicketByTicketPrice(price, Date::deserialize(from), Date::deserialize(to));
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " << ticket->getId() <<  std::endl;
    }
}

void Menu::getRoutesByCategory() const {
    std::string category;
    std::cout << "Введіть Категорію Маршруту (Domestic, International, Tourist, Special): ";
    std::cin >> category;
    
    auto type_route = parseTypeRoute(category);
    if (!type_route.has_value()) {
        std::cout << "Невідома категорія маршруту!" << std::endl;
        return;
    }

    auto routes = services.getRoutesByCategory(type_route.value());
    for (const auto& route : routes) {
        std::cout << "Маршрут: " << route->getId() <<  std::endl;
    }
}

void Menu::getRoutesByCategoryPositon() const {
    std::cout << "Введіть Категорії Маршруту в певній послідовності (приклад: Domestic International Tourist Special): ";
    
    std::string line;
    std::getline(std::cin >> std::ws, line);

    std::istringstream iss(line);
    std::string token;
    std::vector<TypeRoute> categories;

    while (iss >> token) {
        auto parsed = parseTypeRoute(token);
        if (parsed.has_value()) {
            categories.push_back(parsed.value());
        } else {
            std::cout << "Невідома категорія: " << token << std::endl;
            return;
        }
    }

    auto routes = services.getRoutesByCategoryPositon(categories);
    for (const auto& route : routes) {
        std::cout << "Маршрут: " << route->getId() << std::endl;
    }
}

void Menu::getPassengersByTrip() const {
    std::string id;
    std::cout << "Введіть id Рейсу: ";
    std::cin >> id;
    auto passengers = services.getPassengersByTrip(id);
    for (const auto& passenger : passengers) {
        std::cout << "Пасажир: " << passenger->getId() <<  std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}
void Menu::getPassengersByLeft() const {
    std::string date;
    std::cout << "Введіть дату виїзду у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;
    auto passengers = services.getPassengersByLeft(Date::deserialize(date));
    for (const auto& passenger : passengers) {
        std::cout << "Пасажир: " << passenger->getId() <<  std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}
void Menu::getPassengersByLeftForeign() const {
    std::string date;
    std::cout << "Введіть дату виїзду у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;
    auto passengers = services.getPassengersByLeftForeign(Date::deserialize(date));
    for (const auto& passenger : passengers) {
        std::cout << "Пасажир: " << passenger->getId() <<  std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}

void Menu::getPassengersByHasBaggage() const {
    std::string has_baggage;
    std::cout << "Чи задв пасажир свій багаж (Y or N): ";
    std::cin >> has_baggage;
    auto passengers = services.getPassengersByHasBaggage(has_baggage == "Y");
    for (const auto& passenger : passengers) {
        std::cout << "Пасажир: " << passenger->getId() <<  std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}
void Menu::getPassengersBySex() const {
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto passengers = services.getPassengersBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto& passenger : passengers) {
        std::cout << "Пасажир: " <<  passenger->getId() << std::endl;
    }
    std::cout << "Кількість " << passengers.size() << std::endl;
}

void Menu::getUnredeemedTicketByTrip() const {
    std::string id;
    std::cout << "Введіть id рейсу: ";
    std::cin >> id;

    auto tickets = services.getUnredeemedTicketByTrip(id);
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " <<  ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void Menu::getUnredeemedTicketByRoute() const {
    std::string id;
    std::cout << "Введіть id маршруту: ";
    std::cin >> id;

    auto tickets = services.getUnredeemedTicketByRoute(id);
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " <<  ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void Menu::getUnredeemedTicketByDate() const {
    std::string date;
    std::cout << "Введіть зазнеачену дату у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto tickets = services.getUnredeemedTicketByDate(Date::deserialize(date));
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " <<  ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void Menu::getReturnedTicketsByTrip() const {
    std::string id;
    std::cout << "Введіть id рейсу: ";
    std::cin >> id;

    auto tickets = services.getReturnedTicketsByTrip(id);
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " <<  ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void Menu::getReturnedTicketsByRoute() const {
    std::string id;
    std::cout << "Введіть id маршруту: ";
    std::cin >> id;

    auto tickets = services.getReturnedTicketsByRoute(id);
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " <<  ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}
void Menu::getReturnedTicketsByDate() const {
    std::string date;
    std::cout << "Введіть зазнеачену дату у форматиі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto tickets = services.getReturnedTicketsByDate(Date::deserialize(date));
    for (const auto& ticket : tickets) {
        std::cout << "Квиток: " <<  ticket->getId() << std::endl;
    }
    std::cout << "Кількість " << tickets.size() << std::endl;
}