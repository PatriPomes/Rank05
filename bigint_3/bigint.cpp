#include "bigint.hpp"

bigint::bigint()
{
    _str = "0";
}

bigint::bigint(unsigned int num)
{
    std::stringstream ss;
    ss << num;
    _str = ss.str();
}

bigint::bigint(const bigint &obj)
{
    *this = obj;
}

bigint &bigint::operator=(const bigint &obj)
{
    if(this != &obj)
        _str = obj._str;
    return *this;
}

std::string bigint::getStr() const
{
    return _str;
}

bigint::~bigint(){};

std::ostream &operator<<(std::ostream &os, const bigint &obj)
{
    os << obj.getStr();
    return os;
}

bigint &bigint::operator+=(const bigint &obj)
{
    std::string digit_a = _str;
    std::string digit_b = obj._str;

    while (digit_a.length() > digit_b.length())
        digit_b = "0" + digit_b;
    while (digit_a.length() < digit_b.length())
        digit_a = "0" + digit_a;
    
    int cont = digit_a.length() - 1;
    int carry = 0;
    std::string result = "";
    while (cont >= 0)
    {
        int sum = (digit_a[cont] - '0') + (digit_b[cont] - '0') + carry;
        result = char(sum % 10 + '0') + result;
        carry = sum / 10;
        cont--;
    }

    if (carry > 0)
        result = char(carry % 10 + '0') + result;
    _str =  result;
    return *this;
}

bigint bigint::operator+(const bigint &obj) const
{
    bigint tmp(*this);
    tmp += obj;
    return tmp;
}

bigint bigint::operator++(int)
{
    bigint plus(1);
    bigint tmp(*this);
    *this += plus;
    return tmp;
}

bigint bigint::operator++()
{
    bigint plus(1);
    *this += plus;
    return *this;
}

bigint bigint::operator<<(unsigned int num) const
{
    bigint tmp(*this);
    tmp._str.insert(tmp._str.end(), num, '0');
    return tmp;
}

bigint bigint::operator>>(unsigned int num) const
{
    bigint tmp(*this);
    size_t len = _str.length();

    if (num > len)
        tmp._str = "0";
    else
        tmp._str.erase(tmp._str.length() - num, num);
    return tmp;
}

bigint &bigint::operator<<=(unsigned int num)
{
    (*this) = (*this) << num;
    return *this;
}

bigint &bigint::operator>>=(unsigned int num)
{
    (*this) = (*this) >> num;
    return *this;
}

//utils
unsigned int stringToUnit(std::string source)
{
    std::stringstream ss(source);
    unsigned int num;
    ss >> num;
    return num;
    
}

bigint bigint::operator<<(const bigint &obj) const
{
    bigint tmp;
    tmp = (*this) << stringToUnit(obj._str);
    return tmp;
}

bigint bigint::operator>>(const bigint &obj) const
{
    bigint tmp;
    tmp = (*this) >> stringToUnit(obj._str);
    return tmp;
}

bigint &bigint::operator<<=(const bigint &obj)
{
    (*this) = (*this) << stringToUnit(obj._str);
    return *this;
}

bigint &bigint::operator>>=(const bigint &obj)
{
    (*this) = (*this) >> stringToUnit(obj._str);
    return *this;
}

bool bigint::operator<(const bigint &obj) const
{
    size_t len_a = _str.length();
    size_t len_b = obj._str.length();
    if ( len_a != len_b)
        return (len_a < len_b);
    return _str < obj._str;
}

bool bigint::operator>(const bigint &obj) const
{
    return obj < *this;
}

bool bigint::operator==(const bigint &obj) const
{
    return _str == obj._str;
}

bool bigint::operator!=(const bigint &obj) const
{
    return _str != obj._str;
}

bool bigint::operator<=(const bigint &obj) const
{
    return ((*this < obj) || (*this == obj));
}

bool bigint::operator>=(const bigint &obj) const
{
    return ((*this > obj) || (*this == obj));
}

