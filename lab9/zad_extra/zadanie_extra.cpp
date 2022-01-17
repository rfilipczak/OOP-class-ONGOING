#include <iostream>
#include <vector>
#include <algorithm>


std::vector<int>& reverse(std::vector<int>& vec)
{
    std::reverse(std::begin(vec), std::end(vec));
    return vec;
}

std::vector<int>& sort_inc(std::vector<int>& vec)
{
    std::sort(std::begin(vec), std::end(vec));
    return vec;
}

std::vector<int>& sort_dec(std::vector<int>& vec)
{
    std::sort(std::begin(vec), std::end(vec), std::greater<int>());
    return vec;
}

std::vector<int>& sort_inc_abs(std::vector<int>& vec)
{
    std::sort(std::begin(vec), std::end(vec), [](const int& a, const int& b){
        return std::abs(a) < std::abs(b);
    });
    return vec;
}

std::vector<int>& sort_inc_mod1000(std::vector<int>& vec)
{
    std::sort(std::begin(vec), std::end(vec), [](const int& a, const int& b){
        return (a % 1000) < (b % 1000);
    });
    return vec;
}


int main()
{
    std::cout << "\nZadanie Extra 1\n\n";

    auto printv = [](const std::vector<int>& v) {
        for (const auto& e : v)
            std::cout << e << ' ';
        std::cout << '\n';
    };

    std::vector<int> v{213, -321, 123, 0, 0, 1000, 1, 1002, 123};
    std::cout << "Wektor wejsciowy:\n";
    printv(v);

    ::reverse(v);
    std::cout << "Po odwroceniu:\n";
    printv(v);

    ::sort_inc(v);
    std::cout << "Po posortowaniu(rosnacym):\n";
    printv(v);

    ::sort_dec(v);
    std::cout << "Po posortowaniu(malejacym):\n";
    printv(v);
    
    ::sort_inc_abs(v);
    std::cout << "Po posortowaniu(rosnacym wg wart. absolutnej):\n";
    printv(v);

    ::sort_inc_mod1000(v);
    std::cout << "Po posortowaniu(rosnacym wg reszty z dzielenia przez 1000):\n";
    printv(v);

    return 0;
}
