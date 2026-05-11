#include "vect2.hpp"

vect2::vect2()
{
    _x = 0;
    _y = 0;
}

vect2::vect2(int num1, int num2)
{
    _x = num1;
    _y = num2;
}

vect2::vect2(const vect2 &(source))
{
    *this = source;
}

vect2 &vect2::operator=(const vect2 &source)
{
    if (this != &source)
    {
        _x = source._x;
        _y = source._y;
    }
    return (*this);
}

int vect2::operator[](int index) const
{
    if (index == 0)
        return (_x);
    return (_y);
}

int &vect2::operator[](int index)
{
    if (index == 0)
        return (_x);
    return (_y);
}

std::ostream &operator<<(std::ostream &os, const vect2 &obj)
{
    std::cout << "{" << obj[0] << ", " << obj[1] << "}";
    return os;
}

vect2 vect2::operator++()
{
    _x += 1;
    _y += 1;
    return (*this);
}

vect2 vect2::operator++(int)
{
    vect2 tmp = *this;
    ++(*this);
    return tmp;
}

vect2 vect2::operator--()
{
    _x -= 1;
    _y -= 1;
    return (*this);
}

vect2 vect2::operator--(int)
{
    vect2 tmp = *this;
    --(*this);
    return tmp;
}

vect2 &vect2::operator+=(const vect2 &obj)
{
    _x = _x + obj._x;
    _y = _y + obj._y;
    return *this;
}

vect2 &vect2::operator-=(const vect2 &obj)
{
    _x = _x - obj._x;
    _y = _y - obj._y;
    return *this;
}

// vect2 vect2::operator*=(vect2 obj)
// {
//     _x = _x * obj._x;
//     _y = _y * obj._y;
//     return *this;
// }

vect2 vect2::operator*=(int num)
{
    _x = _x * num;
    _y = _y * num;
    return *this;
}

vect2 vect2::operator+(const vect2 &obj) const
{
    vect2 temp = *this;
    temp._x += obj._x;
    temp._y += obj._y;
    return temp;
}

vect2 vect2::operator-(const vect2 &obj) const
{
    vect2 temp = *this;
    temp._x -= obj._x;
    temp._y -= obj._y;
    return temp;
}

vect2 vect2::operator-() const
{
    vect2 temp(*this);
    temp._x = -temp._x;
    temp._y = -temp._y;
    return (temp);
}

vect2 vect2::operator*(int num) const
{
    vect2 temp = *this;
    temp._x = _x * num;
    temp._y = _y * num;
    return temp;
}

// vect2 vect2::operator*(const vect2 &obj) const
// {
//     vect2 temp = *this;
//     temp._x *= obj._x;
//     temp._y *= obj._y;
//     return temp;
// }

vect2 operator*(int num, const vect2 &obj)
{
    vect2 temp(obj);
    temp *= num;
    return temp;
}

bool vect2::operator==(const vect2 &obj) const
{
    if ((_x == obj._x) && (_y == obj._y))
        return true;
    return false;
}

bool vect2::operator!=(const vect2 &obj) const
{
    if ((_x == obj._x) && (_y == obj._y))
        return false;
    return true;
}