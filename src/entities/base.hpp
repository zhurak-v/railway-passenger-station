#pragma once
#include <iostream>
#include <string>

class Base {
private:
    std::string id;

public:
    Base(const std::string& id);
    virtual ~Base() = default;

public:
    std::string getId() const;

    virtual std::string getClass() const = 0;
    static std::string staticClass();
    virtual std::string serialize() const = 0;

    auto get() {
        return this;
    }
};