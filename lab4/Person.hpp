#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <string_view>

#include "./Json.hpp"

class Person
{
protected:
    std::string name;
    std::string lastName;
    std::string dateOfBirth;
    Person(std::string_view _name, std::string_view _lastName, std::string_view _dateOfBirth);
public:
    virtual void WypiszInfo() const;
};

Person::Person(std::string_view _name, std::string_view _lastName, std::string_view _dateOfBirth)
    : name{_name}, lastName{_lastName}, dateOfBirth{_dateOfBirth}
{
}

void Person::WypiszInfo() const
{
    Json::Object root;
    root["type"] = "person";
    root["name"] = name;
    root["lastName"] = lastName;
    root["dateOfBirth"] = dateOfBirth;
    root.pretty_print();
}

class Student : public Person
{
private:
    int year;
    int group;
    int index;
public:
    Student(std::string_view _name, std::string_view _lastName, std::string_view _dateOfBirth, int _year, int _group, int _index);
    void WypiszInfo() const override;
};

Student::Student(std::string_view _name, std::string_view _lastName, std::string_view _dateOfBirth, int _year, int _group, int _index)
    : Person{_name, _lastName, _dateOfBirth}, year{_year}, group{_group}, index{_index}
{
}

void Student::WypiszInfo() const
{
    Json::Object root;
    root["type"] = "student";
    root["name"] = name;
    root["lastName"] = lastName;
    root["dateOfBirth"] = dateOfBirth;
    root["year"] = year;
    root["group"] = group;
    root["index"] = index;
    root.pretty_print();
}

class Player : public Person
{
private:
    std::string position;
    std::string club;
    int score{0};
public:
    Player(std::string_view _name, std::string_view _lastName, std::string_view _dateOfBirth, std::string_view _position, std::string_view _club);
    void StrzelGola();
    void WypiszInfo() const override;
};

Player::Player(std::string_view _name, std::string_view _lastName, std::string_view _dateOfBirth, std::string_view _position, std::string_view _club)
    : Person{_name, _lastName, _dateOfBirth}, position{_position}, club{_club}
{
}

void Player::StrzelGola()
{
    ++score;
}

void Player::WypiszInfo() const
{
    Json::Object root;
    root["type"] = "player";
    root["name"] = name;
    root["lastName"] = lastName;
    root["dateOfBirth"] = dateOfBirth;
    root["position"] = position;
    root["club"] = club;
    root["score"] = score;
    root.pretty_print();
}


#endif // PERSON_H
