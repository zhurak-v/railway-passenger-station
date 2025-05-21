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

    for (const auto locomotive : relation_service.getLocomotivesAtStationInTime("#sta-65434", Date(2025, 5, 21, 11, 10)))
    {
        // std::cout << locomotive->getId() << std::endl;
    }


    return 0;
}