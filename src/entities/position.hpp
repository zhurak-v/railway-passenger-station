#pragma once

class Position
{
private:
    double x;
    double y;

public:
    Position(double x, double y);
    ~Position() = default;

public:
    double getX() const;
    double getY() const;
};
