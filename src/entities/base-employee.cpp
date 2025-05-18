#include "entities/base-employee.hpp"

Employee::Employee(const std::string &id,
                   const std::string &full_name,
                   SEX sex,
                   Date& birth,
                   Date& start_work,
                   int children_count,
                   double salary)
    : Base(id),
      full_name(full_name),
      sex(sex),
      birth(birth),
      start_work(start_work),
      children_count(children_count),
      salary(salary)
{
}

std::string Employee::getFullName() const
{
  return full_name;
};

SEX Employee::getSex() const
{
  return sex;
};

Date Employee::getBrithDate() const
{
  return birth;
};
Date Employee::getStartWork() const
{
  return start_work;
};
int Employee::getChildrenCount() const
{
  return children_count;
};
double Employee::getSalary() const
{
  return salary;
};

std::string Employee::staticClass()
{
    return "Employee";
}
std::string Employee::getClass() const { 
    return staticClass();
}