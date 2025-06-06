#pragma once
#include <vector>
#include <memory>
#include <string>
#include <algorithm>

template <typename T>
class BaseRepository {
protected:
    std::vector<std::shared_ptr<T>> entities;

public:
    BaseRepository(std::vector<std::shared_ptr<T>> initialEntities = {})
        : entities(std::move(initialEntities)) {}

    virtual ~BaseRepository() = default;

    const std::vector<std::shared_ptr<T>>& getAll() const {
        return entities;
    }

    std::shared_ptr<T> findById(const std::string& id) const {
        for (auto& entity : entities) {
            if (entity->getId() == id) {
                return entity;
            }
        }
    return nullptr;
}
};
