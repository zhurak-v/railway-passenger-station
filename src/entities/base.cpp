#include "entities/base.hpp"
#include "common/utils/generate-id.hpp"

Base::Base(const std::string& id) : id(id) {}

std::string Base::getId() const {
    return id;
}

std::string Base::staticClass() {
    return "Base";
}