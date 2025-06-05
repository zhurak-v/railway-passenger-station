#pragma once
#include <sstream>
#include <vector>
#include "entities/base.hpp"
#include "common/date/date.hpp"
#include "entities/sex.hpp"
class Passenger : public Base
{
private:
    bool has_baggage;
    SEX sex;
    Date birth;

public:
    Passenger(
        const std::string& id,
        const bool has_baggage,
        SEX sex,
        Date& birth
    );
    ~Passenger() = default;

public:
    bool getHasBaggage() const;
    SEX getSex() const;
    Date getBrithDate() const;

public:
    std::string getClass() const final;
    static std::string staticClass();

public:
    std::string serialize() const override;
    static std::shared_ptr<Passenger> deserialize(const std::string &data);
};
