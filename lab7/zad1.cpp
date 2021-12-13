#include <iostream>
#include <string>


class StringToIntConverter
{
public:
    class NieprawidloweZnakiException : public std::exception
    {
    private:
        std::string error;
    public:
        NieprawidloweZnakiException(const std::string& _error)
            : error{_error}
        {
        }
        const char* what() const noexcept override { return error.c_str(); }
    };

    class LiczbaZaDuzaException : public std::exception
    {
    private:
        std::string error;
    public:
        LiczbaZaDuzaException(const std::string& _error)
            : error{_error}
        {
        }
        const char* what() const noexcept override { return error.c_str(); }
    };

    int convert(const std::string& _str)
    {
        int result;

        try
        {
            result = std::stoi(_str, nullptr, 10);
        }
        catch(const std::invalid_argument& e)
        {
            throw NieprawidloweZnakiException("Nieprawidlowe znaki");
        }
        catch (const std::out_of_range& e)
        {
            throw LiczbaZaDuzaException("Liczba za duza");
        }

        return result;
    }
};


int main()
{
    std::cout << "Lab7\n";

    std::cout << "Podaj ciag znakow do przekonwertowania: ";
    std::string input;
    std::getline(std::cin, input);

    StringToIntConverter converter;
    try
    {
        int convertedValue = converter.convert(input);
        std::cout << "Przekonwertowana liczba: " << convertedValue << '\n';
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }

    return 0;
}
