#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

#include "./Json.hpp"

class EmployeesCommon
{
protected:
    std::string name;
    std::string lastName;
    std::string nip;
    std::string dateOfEmployment;
    double salary;
    std::string department;

    EmployeesCommon(
            std::string_view _name,
            std::string_view _lastName,
            std::string_view _nip,
            std::string_view _dateOfEmployment,
            double _salary,
            std::string_view _department
    );

public:
    [[nodiscard]] virtual Json::Object json() const;

    virtual void show() const;
};

EmployeesCommon::EmployeesCommon(
        std::string_view _name,
        std::string_view _lastName,
        std::string_view _nip,
        std::string_view _dateOfEmployment,
        double _salary,
        std::string_view _department
)
        : name{_name}, lastName{_lastName}, nip{_nip}, dateOfEmployment{_dateOfEmployment}, salary{_salary},
        department{_department}
{
}

Json::Object EmployeesCommon::json() const
{
    Json::Object root;
    root["name"] = name;
    root["lastName"] = lastName;
    root["nip"] = nip;
    root["dateOfEmployment"] = dateOfEmployment;
    root["salary"] = salary;
    root["department"] = department;
    return root;
}

void EmployeesCommon::show() const
{
    json().pretty_print();
}


class Employee : public EmployeesCommon
{
public:
    Employee(
            std::string_view _name,
            std::string_view _lastName,
            std::string_view _nip,
            std::string_view _dateOfEmployment,
            double _salary,
            std::string_view _department
    );

    [[nodiscard]] Json::Object json() const override;
};

Employee::Employee(
        std::string_view _name,
        std::string_view _lastName,
        std::string_view _nip,
        std::string_view _dateOfEmployment,
        double _salary,
        std::string_view _department
)
        : EmployeesCommon(_name, _lastName, _nip, _dateOfEmployment, _salary, _department)
{
}

Json::Object Employee::json() const
{
    Json::Object root;
    root["type"] = "employee";
    root += EmployeesCommon::json();
    return root;
}

class Supervisor : public EmployeesCommon
{
private:
    std::string supervisionType;
    double dutyAllowance;
    std::size_t subordinatesCount{0};
    std::vector<Employee> subordinates{};

public:
    Supervisor(
            std::string_view _name,
            std::string_view _lastName,
            std::string_view _nip,
            std::string_view _dateOfEmployment,
            double _salary,
            std::string_view _department,
            std::string_view _supervisionType,
            double _dutyAllowance
    );

    Supervisor& addSubordinate(const Employee& employee);

    [[nodiscard]] Json::Object json() const override;
};

Supervisor::Supervisor(std::string_view _name, std::string_view _lastName, std::string_view _nip,
                       std::string_view _dateOfEmployment, double _salary, std::string_view _department,
                       std::string_view _supervisionType, double _dutyAllowance)
        : EmployeesCommon{_name, _lastName, _nip, _dateOfEmployment, _salary, _department},
        supervisionType{_supervisionType}, dutyAllowance{_dutyAllowance}
{
}

Supervisor& Supervisor::addSubordinate(const Employee& employee)
{
    ++subordinatesCount;
    subordinates.emplace_back(employee);
    return *this;
}

Json::Object Supervisor::json() const
{
    Json::Object root;
    root["type"] = "supervisor";

    root += EmployeesCommon::json();
    root["superVisionType"] = supervisionType;
    root["dutyAllowance"] = dutyAllowance;
    root["subordinatesCount"] = subordinatesCount;

    for (std::size_t i = 0; i < subordinatesCount; ++i)
        root["subordinates"][i] = subordinates.at(i).json();

    return root;
}


#endif //EMPLOYEE_H
