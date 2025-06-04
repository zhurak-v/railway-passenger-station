#include "ui/menu.hpp"
#include <iostream>

RelationMenu::RelationMenu(
    RelationServices& relation_services 
)
    : relation_services(relation_services) {}

void RelationMenu::run() const {
    while (true) {
        showMainMenu();
        handleUserChoice();
    }
}

void RelationMenu::showMainMenu() const {
    std::cout << "\n=== Меню ===\n";
    std::cout << "1. Отримати перелік локомотивів приписаних до залізничної станції\n";
    std::cout << "2. Отримати перелік і загальне число локомотивів що знаходяться у вказаній станції в певний час\n";
    std::cout << "3. Отримати перелік і загальне число локомотивів за кількістю скоєних рейсів\n";
    std::cout << "4. Отримати перелік і загальне число локомотивів які пройшли плановий техогляд за певний пераод часу\n";
    
    std::cout << "5. Отримати перелік і загальне число усіх працівників залізничної станції\n";
    std::cout << "6. Отримати перелік і загальне число усіх начальників залізничної станції\n";
    std::cout << "7. Отримати перелік і загальне число усіх працівників вказаного відділу\n";
    std::cout << "8. Отримати перелік і загальне число усіх працівників за стажом роборти відділу\n";
    std::cout << "9. Отримати перелік і загальне число усіх працівників за статевою ознакою\n";
    std::cout << "10. Отримати перелік і загальне число усіх працівників за віком\n";
    std::cout << "11. Отримати перелік і загальне число усіх працівників за ознаком наявністю дітей\n";
    std::cout << "12. Отримати перелік і загальне число усіх працівників за кількістю дітей\n";
    std::cout << "13. Отримати перелік і загальне число усіх працівників за розміром заробітньої плати\n";
    std::cout << "14. Отримати перелік і загальне число усіх працівників у бригаді\n";
    std::cout << "15. Отримати перелік і загальне число усіх працівників по всім відділам\n";
    std::cout << "16. Отримати перелік і загальне число усіх працівників обслуговуючий певний локомотив\n";
    std::cout << "17. Отримати перелік і загальне число усіх працівників за середньою зарплатою в бригаді\n";
    std::cout << "18. Отримати перелік і загальне число усіх водіїв які пройшли медогляд у вказаний рік\n";
    std::cout << "19. Отримати перелік і загальне число усіх водіїв за статевою ознакою\n";
    std::cout << "20. Отримати перелік і загальне число усіх водіїв за віком\n";
    std::cout << "21. Отримати перелік і загальне число усіх водіїв за зарплатою\n";

    std::cout << "Ваш вибір: ";
}

void RelationMenu::handleUserChoice() const {
    int choice;
    std::cin >> choice;

    switch (choice) {
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
        
        default:
            std::cout << "Невірний вибір. Спробуйте ще раз.\n";
    }
}

void RelationMenu::getLocomotivesByStation() const {
    std::string id;
    std::cout << "Введіть ID станції: ";
    std::cin >> id;

    auto locomtives = relation_services.getLocomotivesByStation(id);
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getLocomotivesAtStationInTime() const {
    std::string id;
    std::cout << "Введіть ID станції: ";
    std::cin >> id;
    std::string date;
    std::cout << "Введіть час у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> date;

    auto locomtives = relation_services.getLocomotivesAtStationInTime(id, Date::deserialize(date));
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getLocomotivesByCompletedRoutes() const {
    std::string count;
    std::cout << "Введіть кількість скоєних рейсів: ";
    std::cin >> count;

    auto locomtives = relation_services.getLocomotivesByCompletedRoutes(std::stoi(count));
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getLocomotiveByPassedTechInsp() const {
    std::string from;
    std::cout << "Введіть ліву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> from;
    std::string to;
    std::cout << "Введіть праву межу часового діапазону у форматі YYYY-MM-DD-HH:MM: ";
    std::cin >> to;

    auto locomtives = relation_services.getLocomotiveByPassedTechInsp(
        Date::deserialize(from), Date::deserialize(to)
    );
    for (const auto& locomotive : locomtives) {
        std::cout << "Локомотив: " << locomotive->getId() << std::endl;
    }
    std::cout << "Кількість " << locomtives.size() << std::endl;
}

void RelationMenu::getAllEmployees() const {
    auto employees = relation_services.getAllEmployees();
    for (const auto& employee : employees) {
        std::cout << "Працівник: " << employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getAllHeadDepartment() const {
    auto head_departments = relation_services.getAllHeadDepartment();
    for (const auto& head_department : head_departments) {
        std::cout << "Нчальник відділу: " <<  head_department->getId() << " " << head_department->getFullName() << std::endl;
    }
    std::cout << "Кількість " << head_departments.size() << std::endl;
}
void RelationMenu::getEmployeesByDepartment() const {
    std::string id;
    std::cout << "Введіть ID відділу: ";
    std::cin >> id;
    auto employees = relation_services.getEmployeesByDepartment(id);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByExp() const {
    int exp;
    std::cout << "Введіть стаж роботи в роках: ";
    std::cin >> exp;
    auto employees = relation_services.getEmployeesByExp(exp);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesBySex() const {
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto employees = relation_services.getEmployeesBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getEmployeesByAge() const {
    int age;
    std::cout << "Введіть вік працівника в роках: ";
    std::cin >> age;

    auto employees = relation_services.getEmployeesByAge(age);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getEmployeesByHasChild() const {
    std::string has_children;
    std::cout << "Чи є діти (Y or N)";
    std::cin >> has_children;

    auto employees = relation_services.getEmployeesByHasChild(has_children == "Y" ? true : false);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByChildCount() const {
    int child_count;
    std::cout << "Введіть кількість дітей: ";
    std::cin >> child_count;

    auto employees = relation_services.getEmployeesByChildCount(child_count);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}    

void RelationMenu::getEmployeesBySalary() const {
    double salary;
    std::cout << "Введіть розмір заробітньої плати: ";
    std::cin >> salary;

    auto employees = relation_services.getEmployeesBySalary(salary);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}    
void RelationMenu::getEmployeesByBrigade() const {
    std::string id;
    std::cout << "Введіть ID бригади: ";
    std::cin >> id;
    auto employees = relation_services.getEmployeesByBrigade(id);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByAllDepartments() const {
    auto employees = relation_services.getEmployeesByAllDepartments();
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}
void RelationMenu::getEmployeesByServicingLocomotive() const {
    std::string id;
    std::cout << "Введіть ID локомотиву: ";
    std::cin >> id;
    auto employees = relation_services.getEmployeesByServicingLocomotive(id);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getEmployeesByAverageSalaryInBrigade() const {
    double salary;
    std::cout << "Введіть розмір середньої заробітньої плати в бригаді: ";
    std::cin >> salary;

    auto employees = relation_services.getEmployeesByAverageSalaryInBrigade(salary);
    for (const auto& employee : employees) {
        std::cout << "Працівник: " <<  employee->getId() << " " << employee->getFullName() << std::endl;
    }
    std::cout << "Кількість " << employees.size() << std::endl;
}

void RelationMenu::getDriversByPassedMedInsp() const {
    int year;
    std::cout << "Введіть рік проходження медогляду: ";
    std::cin >> year;
    std::string is_passed;
    std::cout << "Вкажіть умову для водіїв які пройшли або не пройшли (Y or N) медогляд у " << year << " році: ";
    std::cin >> is_passed;

    auto drivers = relation_services.getDriversByPassedMedInsp(year, is_passed == "Y" ? true : false);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}
void RelationMenu::getDriversBySex() const {
    std::string sex;
    std::cout << "Введіть Стать працівника (F or M): ";
    std::cin >> sex;

    auto drivers = relation_services.getDriversBySex(sex == "M" ? SEX::MALE : SEX::FEMALE);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}

void RelationMenu::getDriversByAge() const {
    int age;
    std::cout << "Введіть вік працівника в роках: ";
    std::cin >> age;

    auto drivers = relation_services.getDriversByAge(age);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
}
void RelationMenu::getDriversBySalary() const {
    double salary;
    std::cout << "Введіть розмір заробітньої плати: ";
    std::cin >> salary;

    auto drivers = relation_services.getDriversBySalary(salary);
    for (const auto& driver : drivers) {
        std::cout << "Водій: " <<  driver->getId() << " " << driver->getFullName() << std::endl;
    }
    std::cout << "Кількість " << drivers.size() << std::endl;
} 