#include "common/math/math.hpp"

double Math::getDistanceBetweenPointsKm(const Position& a, const Position& b) {
    return std::sqrt(std::pow(b.getX() - a.getX(), 2) + std::pow(b.getY() - a.getY(), 2));
}

Date Math::getTravelTimeH(double distance, int speed) {
    return Date::fromDoubleHours(distance / speed);
}