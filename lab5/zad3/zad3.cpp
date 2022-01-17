#include <string>
#include <string_view>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <utility>

class Number
{
protected:
	std::string str;
public:
	virtual void show() const = 0;
};

static inline int convert(char c)
{
    static const int lookuptable[] =
    {
            0,1,2,3,4,5,6,7,8,9,
            -1,-1,-1,-1,-1,-1,-1,
            10,11,12,13,14,15
    };
    return lookuptable[c - 48];
}

const std::unordered_map<int, char>* getItocMap()
{
    static const std::unordered_map<int, char> itocmap = {
            {0, '0'},
            {1, '1'},
            {2, '2'},
            {3, '3'},
            {4, '4'},
            {5, '5'},
            {6, '6'},
            {7, '7'},
            {8, '8'},
            {9, '9'},
            {10, 'A'},
            {11, 'B'},
    };

    return &itocmap;
}


template<int base>
std::string add(std::string_view a, std::string_view b)
{
    std::string_view shorter;
    std::string_view longer;

    if (a.length() < b.length())
    {
        shorter = a;
        longer = b;
    }
    else
    {
        shorter = b;
        longer = a;
    }

    std::ostringstream oss;

    int carry = 0;
    auto longIt = longer.rbegin();
    for (auto shortIt = shorter.rbegin(); shortIt != shorter.rend(); ++shortIt, ++longIt)
    {
        int res = static_cast<int>(*shortIt + *longIt - 96) + carry;
        if (res >= base)
            carry = 1;
        else
            carry = 0;
        oss << res % base;
    }

    for (; longIt != longer.rend(); ++longIt)
    {
        int res = static_cast<int>(*longIt - 48) + carry;
        if (res >= base)
            carry = 1;
        else
            carry = 0;
        oss << res % base;
    }

    if (carry)
        oss << carry;

    std::string s = oss.str();
    std::reverse(s.begin(), s.end());

    return s;
}

class Decimal : public Number
{
public:
	explicit Decimal(std::string_view _sv)
	{
        this->str = _sv;
	}

	Decimal operator+(const Decimal& other)
	{
		return Decimal(add<10>(this->str, other.str));
	}

    void show() const override
    {
        std::cout << "Decimal(" << std::quoted(str) << ')' << '\n';
    }
};

class Binary : public Number
{
public:
    explicit Binary(std::string_view _sv)
    {
        this->str = _sv;
    }

    Binary operator+(const Binary& other)
    {
        return Binary(add<2>(this->str, other.str));
    }

    void show() const override
    {
        std::cout << "Binary(" << std::quoted(str) << ')' << '\n';
    }
};

class Hexadecimal : public Number
{
public:
    explicit Hexadecimal(std::string_view _sv)
    {
        this->str = _sv;
    }

    Hexadecimal operator+(const Hexadecimal& other)
    {
        return Hexadecimal(add<16>(this->str, other.str));
    }

    void show() const override
    {
        std::cout << "Hexadecimal(" << std::quoted(str) << ')' << '\n';
    }
};

int main()
{
    {
        Decimal a{"1300"};
        Decimal b{"501"};
        auto c = a + b;
        c.show();
    }

    {
		Binary a{"100101"};
		Binary b{"100001"};
		auto c = a + b;
        c.show(); // Binary("100110")
    }

    {
        Hexadecimal a{"1231321"};
        Hexadecimal b{"92131"};
        auto c = a + b;
        c.show();
    }

    std::cout << getItocMap()->at(10);

}
