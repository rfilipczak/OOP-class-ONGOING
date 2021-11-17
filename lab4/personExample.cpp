#include "./Person.hpp"


int main()
{
    Student student{
        "Mikolaj",
        "Borkowski",
        "1952.07.16",
        2015,
        3,
        123312
    };

    Player player{
        "Wielislaw",
        "Gorski",
        "1947.12.05",
        "goalkeeper",
        "West Bromwich Albion FC"
    };

    student.WypiszInfo();
    
    player.StrzelGola();
    player.WypiszInfo();

    return 0;
}
