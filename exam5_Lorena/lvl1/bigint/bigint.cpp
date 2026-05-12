#include "bigint.hpp"

bigint::bigint() : str("0") {}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	str = ss.str();
}

bigint::bigint(const bigint& other)
{
	(*this) = other;
}

bigint& bigint::operator=(const bigint& other)
{
	if(this != &other)
		str = other.str;
	return(*this);
}

//getter
std::string bigint::getStr() const
{
	return(str);
}

//addition
bigint bigint::operator+(const bigint& other)const
{
	bigint result;
	std::string num1 = str;
	std::string num2 = other.str;
	std::string res;
	int carry = 0;

	while(num1.length() < num2.length())
		num1 = "0" + num1;

	while(num2.length() < num1.length())
		num2 = "0" + num2;
	for(int i = num1.length() -1; i>= 0; i--)
	{
		int sum = (num1[i] - '0') + (num2[i] - '0') + carry;
		carry = sum / 10;
		res = char(sum % 10 + '0') + res;
	}
	if (carry)
		res = '1' + res;
	while (res.length() > 1 && res[0] == '0')
		res.erase(0,1);
	result.str = res;
	return result;
}

bigint& bigint::operator+=(const bigint& other)
{
	(*this) = (*this) + other;
	return(*this);
}

//increment
bigint& bigint::operator++()
{
	*(this) = *(this) + bigint(1);
	return(*this);
}

bigint bigint::operator++(int)
{
	bigint temp = (*this);
	*(this) = *(this) + bigint(1);
	return(temp);
}

//shift with num
bigint bigint::operator<<(unsigned int n)const
{
	bigint temp = *this;

	temp.str.insert(temp.str.end(), n, '0');
	return(temp);
}

bigint bigint::operator>>(unsigned int n)const
{
	bigint temp = *this;
	size_t len = temp.str.length();
	if(n >= len)
		temp.str = "0";
	else
		temp.str.erase(temp.str.length() - n, n);
	return(temp);
}

bigint& bigint::operator<<=(unsigned int n)
{
	(*this) = (*this) << n;
	return(*this);
}

bigint& bigint::operator>>=(unsigned int n)
{
	(*this) = (*this) >> n;
	return(*this);
}

//utils
unsigned int stringToUINT(std::string str)
{
	std::stringstream ss(str);
	unsigned int res;
	ss >> res;
	return (res);
}

//shift with object
bigint bigint::operator<<(const bigint& other)const
{
	bigint temp;
	temp = (*this) << stringToUINT(other.str);
	return(temp);
}

bigint bigint::operator>>(const bigint& other)const
{
	bigint temp;
	temp = (*this) >> stringToUINT(other.str);
	return(temp);
}

bigint& bigint::operator<<=(const bigint& other)
{
	(*this) = (*this) << stringToUINT(other.str);
	return(*this);
}

bigint& bigint::operator>>=(const bigint& other)
{
	(*this) = (*this) >> stringToUINT(other.str);
	return(*this);
}

//other operators
bool bigint::operator==(const bigint& other) const
{
	if(this->getStr() == other.getStr())
		return(true);
	return(false);
}

bool bigint::operator!=(const bigint& other) const
{
	return(!((*this) == (other)));
}

bool bigint::operator<(const bigint& other) const
{
	std::string str1 = this->str;
	std::string str2 = other.getStr();
	size_t len1 = str1.length();
	size_t len2 = str2.length();

	if(len1 != len2)
		return(len1 < len2);
	return(str1 < str2);
}

bool bigint::operator>(const bigint& other) const
{
	return(!(((*this) < other)));
}

bool bigint::operator<=(const bigint& other) const
{
	return((((*this) < other) || ((*this) == other)));
}

bool bigint::operator>=(const bigint& other) const
{
	return((((*this) > other) || ((*this) == other)));
}

// non member func
std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
	output << obj.getStr();
	return(output);
}