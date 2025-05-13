#include <iostream>

#include "common/relation/relation.hpp"
#include "common/date/date.hpp"

#include "entities/entities.hpp"

#include "data/data.hpp"

#include <memory>

int main()
{
    auto today = Date();
    std::cout << today.serialize();
    return 0;
}