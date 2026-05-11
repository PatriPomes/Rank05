#include "bigint.hpp"

bigint::bigint()
{
    _str = "0";
}

bigint::bigint(unsigned int number)
{
    std::stringstream ss;
    ss << number;
    _str = ss.str();
}

bigint::bigint(const bigint &source)
{
    (*this) = source;
}

bigint &bigint::operator=(const bigint &source)
{
    if (this != &source)
        _str = source._str;
    return (*this);
}

std::string bigint::getStr() const
{
    return _str;
}

bigint::~bigint() {}

std::ostream &operator<<(std::ostream &output, const bigint &obj)
{
    output << obj.getStr();
    return output;
}

bigint &bigint::operator+=(const bigint &obj)
{
    int carry = 0;
    std::string tmp_a = _str;
    std::string tmp_b = obj._str;

    // rellenar con 0
    while (tmp_a.length() < tmp_b.length())
        tmp_a = "0" + tmp_a;
    while (tmp_a.length() > tmp_b.length())
        tmp_b = "0" + tmp_b;

    // sumar de atras a delante
    std::string result = "";
    int cont = tmp_a.length() - 1;
    while (cont >= 0)
    {
        int digit_a = tmp_a[cont] - '0';
        int digit_b = tmp_b[cont] - '0';
        int sum = digit_a + digit_b + carry;
        result = char((sum % 10) + '0') + result;
        carry = sum / 10;
        cont--;
    }

    if (carry > 0)
        result = char(carry + '0') + result;
    _str = result;
    return *this;
}

bigint bigint::operator+(const bigint &obj) const
{
    bigint tmp(*this);
    tmp += obj;
    return tmp;
}

bigint bigint::operator++()
{
    bigint plus(1);
    *this += plus;
    return *this;
}

bigint bigint::operator++(int)
{
    bigint tmp(*this);
    bigint plus(1);
    *this += plus;
    return tmp;
}

bigint bigint::operator<<(int num) const
{
    bigint tmp(*this);

    for (int cont = 0; cont < num; cont++)
        tmp._str = tmp._str + "0";
    return tmp;
}

bigint &bigint::operator<<=(int num)
{
    for (int cont = 0; cont < num; cont++)
        _str = _str + "0";
    return *this;
}

// chekear que la cantidad de numeros a borrar no sea mayor que el numero a borrar

bigint &bigint::operator>>(unsigned int num) const
{
    _str = _str.substr(0, num);
    return *this;
}

bigint &bigint::operator>>=(const bigint &num)
{
    _str.(0, );
    return *this;
}
