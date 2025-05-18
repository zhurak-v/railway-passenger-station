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

    SEX sex = SEX::FEMALE;

    for (const auto& e : employee_service.getEmployeesBySex(sex))
    {
        std::cout << e->getFullName() << std::endl;
    }
    
    return 0;
}