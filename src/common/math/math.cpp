#include "common/math/math.hpp"

double Math::getDistanceBetweenPointsKm(const Position& a, const Position& b) {
    return std::sqrt(std::pow(b.getX() - a.getX(), 2) + std::pow(b.getY() - a.getY(), 2));
}

Date Math::getTravelTime(double distance, int speed) {
    return Date::fromHours(distance / static_cast<double>(speed));
}