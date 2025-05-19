#pragma once
#include "entities/cashier.hpp"
#include "data/repositories/base-repository.hpp"

class CashierRepository : public BaseRepository<Cashier> {
public:
    using BaseRepository::BaseRepository;
};
