#include "entities/base-employee.hpp"

Employee::Employee(const std::string &id,
                   const std::string &full_name,
                   bool sex,
                   int age,
                   int work_experience,
                   int children_count,
                   double salary)
    : Base(id),
      full_name(full_name),
      sex(sex),
      age(age),
      work_experience(work_experience),
      children_count(children_count),
      salary(salary)
{
}

std::string Employee::getFullName() const
{
  return full_name;
};

bool Employee::getSex() const
{
  return sex;
};

int Employee::getAge() const
{
  return age;
};
int Employee::getWorkExperience() const
{
  return work_experience;
};
int Employee::getChildrenCount() const
{
  return children_count;
};
double Employee::getSalary() const
{
  return salary;
};