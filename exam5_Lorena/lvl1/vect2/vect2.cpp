#include "vect2.hpp"

vect2::vect2() : x(0), y(0)
{	
}

vect2::vect2(int num1, int num2) : x(num1), y(num2)
{
}

vect2::vect2(const vect2& other)
{
	(*this) = other;
}

vect2& vect2::operator=(const vect2& other)
{
	if (this != &other)
	{
		x = other.x;
		y = other.y;
	}
	return (*this);
}

//insertion
int vect2::operator[](int index) const
{
	if (index == 0)
		return x;
	return y;
}

int& vect2::operator[](int index)
{
	if (index == 0)
		return x;
	return y;
}

//increment
vect2& vect2::operator++()
{
	x += 1;
	y += 1;
	return (*this);
}

vect2 vect2::operator++(int)
{
	vect2 tmp = (*this);
	++(*this);
	return tmp;
}

//decrement
vect2& vect2::operator--()
{
	x -= 1;
	y -= 1;
	return (*this);
}

vect2 vect2::operator--(int)
{
	vect2 tmp = (*this);
	--(*this);
	return tmp;
}

//addition
vect2 vect2::operator+(const vect2& other) const
{
	vect2 tmp = (*this);

	tmp.x += other.x;
	tmp.y += other.y;
	return tmp;
}

vect2& vect2::operator+=(const vect2& other)
{
	x += other.x;
	y += other.y;
	return (*this);
}

//substraction
vect2 vect2::operator-(const vect2& other) const
{
	vect2 tmp = (*this);

	tmp.x -= other.x;
	tmp.y -= other.y;
	return tmp;
}

vect2& vect2::operator-=(const vect2& other)
{
	x -= other.x;
	y -= other.y;
	return (*this);
}

//multiplication
vect2 vect2::operator*(int num) const
{
	vect2 tmp;
	
	tmp.x = x * num;
	tmp.y = y * num;
	return tmp;
}

vect2& vect2::operator*=(int num)
{
	x *= num;
	y *= num;
	return (*this);
}

//negative
vect2 vect2::operator-() const
{
	vect2 tmp = (*this);

	tmp.x = -tmp.x;
	tmp.y = -tmp.y;
	return tmp;
}

//equality
bool vect2::operator==(const vect2& other) const
{
	if (x == other.x && y == other.y)
		return true;
	return false;
}

bool vect2::operator!=(const vect2& other) const
{
	return (!(other == *this));
}


vect2 operator*(int num, const vect2& obj)
{
	vect2 tmp(obj);
	tmp *= num;
	return(tmp);
}

std::ostream& operator<<(std::ostream& os,const vect2& obj)
{
	os << "{" << obj[0] << ", " << obj[1] << "}";
	return(os);
}