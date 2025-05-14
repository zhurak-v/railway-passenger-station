#pragma once
#include <cmath>
#include <vector>
#include <stdexcept>

class Math
{
private:
    Math() = delete;

public:
    static double getDistanceBetweenPointsKm(const std::vector<int>& a, const std::vector<int>& b);
    static int getTravelTimeMin(double distance, int speed = 60);
};