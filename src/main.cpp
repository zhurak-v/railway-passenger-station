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

    auto results = relation_service.getLocomotivesArrivalTimeAtStation("#sta-54335");
    for (const auto& [loco, arrival] : results) {
        std::cout << loco->getId() << " прибуває о " << arrival.serialize() << std::endl;
    }

    // Date t(2025, 6, 1, 0, 0);
    // t.addHours(0);
    // std::cout << t.serialize() << std::endl;

    return 0;
}