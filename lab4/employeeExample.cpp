#include "./Employee.hpp"

int main()
{
    Supervisor super{
            "Agnieszka",
            "Krol",
            "01270475745",
            "2015.06.04",
            15128,
            "R&D",
            "head of department",
            0.1
    };

    Employee e1{
            "Szczeosny",
            "Krol",
            "51060485838",
            "2020.07.18",
            4716,
            "R&D"
    };

    Employee e2{
            "Tytus",
            "Wojciechowski",
            "73011562054",
            "2019.01.15",
            5592,
            "R&D"
    };

    super.addSubordinate(e1);
    super.addSubordinate(e2);

    super.show();

    return 0;
}
