#include <iostream>
#include <windows.h>
#include "common/relation/relation.hpp"
#include "common/date/date.hpp"
#include "common/math/math.hpp"
#include "entities/entities.hpp"
#include "data/data.hpp"
#include "data/loaders/entity-loader.hpp"

#include "services/services.hpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    std::string id = "#dpm-42315";
    
    const std::vector<std::shared_ptr<Employee>>& employees = department_to_employee_service.getEmployeesByDepartment(id);
    for (const auto& e : employees)
    {
        std::cout << e->serialize() << std::endl;
    }
    

    return 0;
}