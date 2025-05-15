#include <iostream>

#include "common/relation/relation.hpp"
#include "common/date/date.hpp"
#include "common/math/math.hpp"

#include "entities/entities.hpp"

#include "data/data.hpp"

#include <memory>

int main()
{
    registerEntity();


    // auto driver = std::make_shared<Driver>("DRV-16254", "Alex White", 0, 35, 10, 2, 22000.0, std::vector<int> {2020, 2022});
    // std::cout << driver->getFullName();

    // saveEntitiesByType({driver});
    
    auto loaded_entities = loadAllEntitiesFromFolder();
    std::vector<std::shared_ptr<Driver>> drivers;

    for (const auto &entity : loaded_entities)
    {
        if (auto driver = std::dynamic_pointer_cast<Driver>(entity))
        {
            drivers.push_back(driver);
        }
    }

    std::cout << drivers[0]->getFullName();

    return 0;
}