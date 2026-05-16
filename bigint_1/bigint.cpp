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
    if (this != &obj)
        _str = obj._str;
    return *this;
}

std::string bigint::getStr() const
{
    return _str;
}

std::ostream &operator<<(std::ostream &os, const bigint &obj)
{
    os << obj.getStr();
    return os;
}

bigint &bigint::operator+=(const bigint &obj)
{
    std::string tmp_a = _str;
    std::string tmp_b = obj._str;
    int carry = 0;

    while (tmp_a.length() < tmp_b.length())
        tmp_a = "0" + tmp_a;
    while (tmp_b.length() < tmp_a.length())
        tmp_b = "0" + tmp_b;

    std::string result = "";
    int cont = tmp_a.length() -1;
    while (cont >= 0)
    {
        int sum = (tmp_a[cont] - '0') + (tmp_b[cont] - '0') + carry;
        result = char((sum % 10) + '0') + result;
        carry = sum / 10;
        cont--;
    }
    if (carry > 0)
        result = char(carry + '0') + result;
    _str = result;
    return (*this);
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

//shift with num
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
    unsigned int res;
    ss >> (res);
    return res;
}

bigint bigint::operator<<(const bigint &obj) const
{
    bigint tmp(*this);
    tmp = (*this) << stringToUnit(obj._str);
    return tmp;
}

bigint bigint::operator>>(const bigint &obj) const
{
    bigint tmp(*this);
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

bool bigint::operator==(const bigint &obj) const
{
    return _str == obj._str;
}

bool bigint::operator!=(const bigint &obj) const
{
    if (*this == obj)
        return false;
    return true;
}

bool bigint::operator<(const bigint &obj) const
{
    size_t len1 = _str.length();
    size_t len2 = obj._str.length();
    
    if (len1 != len2)
        return len1 < len2;
    return _str < obj._str;
}

bool bigint::operator>(const bigint &obj) const
{
    return obj < *this;
}

bool bigint::operator<=(const bigint &obj) const
{
    return (*this < obj || *this == obj);
}

bool bigint::operator>=(const bigint &obj) const
{
    return (*this > obj || *this == obj);
}

