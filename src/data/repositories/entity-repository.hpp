#pragma once
#include <memory>
#include "entities/driver.hpp"

class DriverRepository {
private:
    std::vector<std::shared_ptr<Driver>> drivers;

public:
    DriverRepository(std::vector<std::shared_ptr<Driver>> drivers);
    ~DriverRepository() = default;
    
public:
    const std::vector<std::shared_ptr<Driver>>& getAll() const;
};