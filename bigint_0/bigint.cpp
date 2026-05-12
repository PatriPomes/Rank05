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

// shift with num
bigint bigint::operator<<(unsigned int n) const
{
    bigint temp = *this;

    temp._str.insert(temp._str.end(), n, '0');
    return (temp);
}

bigint bigint::operator>>(unsigned int n) const
{
    bigint temp = *this;
    size_t len = temp._str.length();
    if (n >= len)
        temp._str = "0";
    else
        temp._str.erase(temp._str.length() - n, n);
    return (temp);
}

bigint &bigint::operator<<=(unsigned int n)
{
    (*this) = (*this) << n;
    return (*this);
}

bigint &bigint::operator>>=(unsigned int n)
{
    (*this) = (*this) >> n;
    return (*this);
}

// utils
unsigned int stringToUINT(std::string str)
{
    std::stringstream ss(str);
    unsigned int res;
    ss >> res;
    return (res);
}

// shift with object
bigint bigint::operator<<(const bigint &other) const
{
    bigint temp;
    temp = (*this) << stringToUINT(other._str);
    return (temp);
}

bigint bigint::operator>>(const bigint &other) const
{
    bigint temp;
    temp = (*this) >> stringToUINT(other._str);
    return (temp);
}

bigint &bigint::operator<<=(const bigint &other)
{
    (*this) = (*this) << stringToUINT(other._str);
    return (*this);
}

bigint &bigint::operator>>=(const bigint &other)
{
    (*this) = (*this) >> stringToUINT(other._str);
    return (*this);
}

// other operators
bool bigint::operator==(const bigint &other) const
{
    if (this->getStr() == other.getStr())
        return (true);
    return (false);
}

bool bigint::operator!=(const bigint &other) const
{
    return (!((*this) == (other)));
}

bool bigint::operator<(const bigint &other) const
{
    std::string str1 = this->_str;
    std::string str2 = other.getStr();
    size_t len1 = str1.length();
    size_t len2 = str2.length();

    if (len1 != len2)
        return (len1 < len2);
    return (str1 < str2);
}

bool bigint::operator>(const bigint &other) const
{
    return (!(((*this) < other)));
}

bool bigint::operator<=(const bigint &other) const
{
    return ((((*this) < other) || ((*this) == other)));
}

bool bigint::operator>=(const bigint &other) const
{
    return ((((*this) > other) || ((*this) == other)));
}
