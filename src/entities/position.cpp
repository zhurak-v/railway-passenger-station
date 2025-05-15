#include "entities/position.hpp"

Position::Position(double x, double y) : x(x), y(y) {};

double Position::getX() const {
    return x;
}

double Position::getY() const {
    return y;
}