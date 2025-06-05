#include "common/utils/parse-type-route.hpp"

std::optional<TypeRoute> parseTypeRoute(const std::string& input) {
    if (input == "Domestic") return TypeRoute::Domestic;
    if (input == "International") return TypeRoute::International;
    if (input == "Tourist") return TypeRoute::Tourist;
    if (input == "Special") return TypeRoute::Special;
    return std::nullopt;
}