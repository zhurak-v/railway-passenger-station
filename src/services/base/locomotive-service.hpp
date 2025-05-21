#pragma once

#include "data/repositories/locomotive-repository.hpp"

class LocomotiveService {
private:
    LocomotiveRepository& locomotive_repository;

public:
    LocomotiveService(
        LocomotiveRepository& locomotive_repository
    );
    ~LocomotiveService() = default;

public:
    std::shared_ptr<Locomotive> getLocomotiveById(const std::string& id) const;
    std::vector<std::shared_ptr<Locomotive>> getAllLocomotives() const;
    int getCountLocomotives() const;

public:
    bool getPassedTechInspection(const std::string& id, int year) const;
};