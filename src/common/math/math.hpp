#pragma once
#include <cmath>
#include <vector>
#include <stdexcept>
#include "common/date/date.hpp"
#include "entities/position.hpp"

class Math
{
private:
    Math() = delete;

public:
    static double getDistanceBetweenPointsKm(const Position& a, const Position& b);
    static Date getTravelTimeH(double distance, int speed = 60);
};