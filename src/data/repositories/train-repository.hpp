#pragma once
#include "entities/train.hpp"
#include "data/repositories/base-repository.hpp"

class TrainRepository : public BaseRepository<Train> {
public:
    using BaseRepository::BaseRepository;
};
