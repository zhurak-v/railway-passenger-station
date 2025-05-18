#pragma once
#include "entities/route.hpp"
#include "data/repositories/base-repository.hpp"

class RouteRepository : public BaseRepository<Route> {
public:
    using BaseRepository::BaseRepository;
};
