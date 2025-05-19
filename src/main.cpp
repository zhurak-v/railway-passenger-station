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

    std::cout << employee_service.getEmployeeById("#hdp-53266")->getFullName();
    
    return 0;
}