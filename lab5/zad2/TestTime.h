//
// Created by mudcrab on 20.11.2021.
//

//Zadanie 2.  Utwórz  klasę  TestTime
// posiadającą dwie  metody  realizujące dokładnie takie  samo  zadanie - odczyt pliku tekstowego -
// jedna metoda jest w  wersji wirtualnej,
// drugą  zaś niewirtualnej.
// Należy wspomnianą  klasę TestTime odziedziczyć w  klasie  potomnej,
// a  następnie  po wykonaniu dokonać porównania czasów (wykorzystując np. bibliotekę time.h)
// wywołania  każdej  z  funkcji : wirtualnej i niewirtualnej
// można się przy tym  posłużyć  biblioteką time.h.
// Oprócz kodu programu, proszę przesłać screen/output z wykonania programu z wyświetleniem czasów realizacji,
// a także plik, który został „zaciągnięty” do programu.


#ifndef LAB5_TESTTIME_H
#define LAB5_TESTTIME_H

#include <string>
#include <string_view>
#include <fstream>
#include <sstream>
#include <iostream>
#include <iterator>

class TestTime
{
public:
    [[nodiscard]] static std::string readFileNotVirtual(std::string_view file);
    [[nodiscard]] virtual std::string readFileVirtual(std::string_view file) const = 0;
};

std::string TestTime::readFileNotVirtual(std::string_view file)
{
    std::ifstream ifs{file.data()};
    std::string text{std::istreambuf_iterator<char>{ifs}, {}};
    return text;
}


#endif //LAB5_TESTTIME_H
