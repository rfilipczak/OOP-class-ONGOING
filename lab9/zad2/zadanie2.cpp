#include <iostream>
#include <vector>
#include <iomanip>

namespace settings
{
    constexpr int rows = 11;
    constexpr int cols = 11;
}

class macierz
{
private:
    int rows, cols;
    std::vector<std::vector<double>> matrix;
public:
    explicit macierz(int _rows, int _cols)
        : rows{ _rows }, cols{ _cols }
    {
        for (int row = 0; row < rows; ++row)
            matrix.emplace_back(std::vector<double>(cols, 0.0));
    }

    double& operator()(int i, int j)
    {
        return matrix.at(i).at(j);
    }

    void print() const
    {
        for (const auto& row : matrix)
        {
            for (const auto& col : row)
                std::cout << std::setw(3) << col << ' ';
            std::cout << '\n';
        }
    }
};

macierz utworz_tabliczke_mnozenia()
{
    macierz tabliczka(settings::rows, settings::cols);
    for (int row = 0; row < settings::rows; ++row)
        tabliczka(row, 0) = row;
    for (int col = 0; col < settings::cols; ++col)
        tabliczka(0, col) = col;
    for (int row = 1; row < settings::rows; ++row)
        for (int col = 1; col < settings::cols; ++col)
            tabliczka(row, col) = row * col;
    return tabliczka;
}

int main()
{
    auto tabliczka = utworz_tabliczke_mnozenia();
    tabliczka.print();
    return 0;
}
