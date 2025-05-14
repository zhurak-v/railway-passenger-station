#include "common/math/math.hpp"

double Math::getDistanceBetweenPointsKm(const std::vector<int>& a, const std::vector<int>& b) {
    if (a.size() != 2 || b.size() != 2) {
        throw std::invalid_argument("Points must have exactly 2 coordinates.");
    }

    return std::sqrt(std::pow(b[0] - a[0], 2) + std::pow(b[1] - a[1], 2));
}

int Math::getTravelTimeMin(double distance, int speed) {
    return std::round((distance / speed) * 60);
}