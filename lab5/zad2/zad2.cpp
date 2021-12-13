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

#include <iostream>
#include <string_view>
#include <chrono>

#include "TestTime.h"

namespace settings
{
    constexpr std::string_view file = R"(../../zad2/testFile.txt)";
}

class FileReader : public TestTime
{
public:
    [[nodiscard]] std::string readFileVirtual(std::string_view file) const override;
};

std::string FileReader::readFileVirtual(std::string_view file) const
{
    std::ifstream ifs{file.data()};
    std::string text{std::istreambuf_iterator<char>{ifs}, {}};
    return text;
}

int main()
{
    FileReader reader;

    using namespace std::chrono;
    using namespace std::literals;

    {
        auto start = steady_clock::now();
        auto text = reader.readFileNotVirtual(settings::file);
        auto end = steady_clock::now();

        std::cout
            << "Non virtual method took "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
            << (end - start) / 1ms << "ms ≈ "
            << (end - start) / 1s << "s.\n";
    }

    {
        auto start = steady_clock::now();
        auto text = reader.readFileVirtual(settings::file);
        auto end = steady_clock::now();

        std::cout
            << "Virtual method took "
            << std::chrono::duration_cast<std::chrono::microseconds>(end - start).count() << "µs ≈ "
            << (end - start) / 1ms << "ms ≈ "
            << (end - start) / 1s << "s.\n";
    }


    return 0;
}
