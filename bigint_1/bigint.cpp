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
