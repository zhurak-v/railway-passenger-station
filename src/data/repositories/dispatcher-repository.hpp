#pragma once
#include "entities/dispatcher.hpp"
#include "data/repositories/base-repository.hpp"

class DispatcherRepository : public BaseRepository<Dispatcher> {
public:
    using BaseRepository::BaseRepository;
};
