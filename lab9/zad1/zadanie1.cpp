#include <iostream>
#include <list>


int main()
{
    std::cout << "Zadanie 1\n\n";

    int N;

    std::cout << "Podaj N: ";
    std::cin >> N;
    if (!std::cin || N <= 0)
    {
        std::cout << "Nieprawidlowe dane\n";
        return 1;
    }

    std::list<int> li;
    
    std::cout << "Podaj " << N << " liczb (odzielone spacja): ";

    for (int i = 0; i < N; ++i)
    {
        int tmp;
        
        std::cin >> std::ws >> tmp;
        if (!std::cin)
        {
            std::cout << "Nieprawidlowe dane\n";
            return 1;
        }

        if (tmp < 0)
            li.emplace_front(tmp);
        else
            li.emplace_back(tmp);
    }

    std::cout << "Liczby w liscie:\n";

    for (const auto& el : li)
        std::cout << el << ' ';
    std::cout << '\n';

    return 0;
}
