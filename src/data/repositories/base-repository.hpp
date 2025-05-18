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

    void add(std::shared_ptr<T> entity) {
        entities.push_back(std::move(entity));
    }

    void remove(const std::string& id) {
        for (auto it = entities.begin(); it != entities.end(); ++it) {
            if ((*it)->getId() == id) {
                entities.erase(it);
                break;
            }
        }
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
