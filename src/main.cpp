#include <iostream>
#include <windows.h>
#include "common/relation/relation.hpp"
#include "common/date/date.hpp"
#include "common/math/math.hpp"
#include "entities/entities.hpp"
#include "data/data.hpp"
#include "data/loaders/entity-loader.hpp"

#include "services/services.hpp"
#include "ui/menu.hpp"

int main()
{
    SetConsoleOutputCP(CP_UTF8);

    RelationMenu menu(
        relation_service
    );
    menu.run();

    

    return 0;
}