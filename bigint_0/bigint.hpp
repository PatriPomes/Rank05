#ifndef BIGINT_HPP
#define BIGINT_HPP

#include <sstream>
#include <iostream>
#include <string>
#include <cstdlib>

class bigint
{
private:
    std::string _str;

public:
    bigint();
    bigint(unsigned int number);
    bigint(const bigint &source);
    bigint &operator=(const bigint &source);
    std::string getStr() const;
    ~bigint();

    bigint &operator+=(const bigint &obj);

    bigint operator+(const bigint &obj) const;

    bigint operator++();
    bigint operator++(int);

    bigint &operator<<=(int num);
    bigint operator<<(int num) const;

    bigint &bigint::operator>>(unsigned num) const;
    bigint &operator>>=(const bigint &num);
};

std::ostream &operator<<(std::ostream &output, const bigint &obj);

#endif