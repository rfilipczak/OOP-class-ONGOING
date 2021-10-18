#ifndef PERSONAL_H
#define PERSONAL_H

#include <string>
#include <string_view>
#include <vector>
#include <algorithm>
#include <iostream>


class PersonalDataBank
{
private:

    struct PersonalData
    {
        std::string m_name{};
        std::string m_lastname{};
        std::string m_address{};
        std::string m_pesel{};

        PersonalData(std::string_view name, std::string_view lastname, std::string_view address, std::string_view pesel)
            : m_name{ name }, m_lastname{ lastname }, m_address{ address }, m_pesel{ pesel }
        {
        }

        friend std::ostream& operator<<(std::ostream& out, const PersonalData& person)
        {
            out << "PersonalData{" << person.m_name << ',' << person.m_lastname << ',' << person.m_address << ',' << person.m_pesel << '}';
            return out;
        }
    };


    std::vector<const PersonalData *> m_data{};

    auto find(std::string_view pesel) const
    {
        for (auto person = m_data.cbegin(); person != m_data.cend(); ++person)
        {
            if (pesel.compare((*person)->m_pesel) == 0)
                return person;
        }
        return m_data.cend();
    }

public:
    PersonalDataBank() = default;

    PersonalDataBank(const std::vector<const PersonalData *>& li)
    {
        for (const PersonalData *person : li)
        {
            m_data.emplace_back(person);
        }
    }

    ~PersonalDataBank()
    {
        for (auto person : m_data)
        {
            delete person;
        }
    }

    void add(std::string_view name, std::string_view lastname, std::string_view address, std::string_view pesel)
    {
        if (find(pesel) != m_data.cend())
            return; // pesel already in bank

        PersonalData *person = new PersonalData(name, lastname, address, pesel);
        m_data.emplace_back(person);
    }

    void remove(std::string_view pesel)
    {
        if (auto found = find(pesel); found != m_data.cend())
        {
            m_data.erase(found);
            delete *found;
        }
    }

    friend std::ostream& operator<<(std::ostream& out, const PersonalDataBank& bank)
    {
        out << "PersonalDataBank {\n";
        for (auto person : bank.m_data)
        {
            out << '\t' << *person << ",\n";
        }
        out << '}';
        return out;
    }
};

#endif // PERSONAL_H
