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

    // shift with num
    bigint operator<<(unsigned int n) const;
    bigint operator>>(unsigned int n) const;
    bigint &operator<<=(unsigned int n);
    bigint &operator>>=(unsigned int n);

    // shift with object
    bigint operator<<(const bigint &other) const;
    bigint operator>>(const bigint &other) const;
    bigint &operator<<=(const bigint &other);
    bigint &operator>>=(const bigint &other);

    // ==, !=, <, >, <=, >=
    bool operator==(const bigint &other) const;
    bool operator!=(const bigint &other) const;
    bool operator<(const bigint &other) const;
    bool operator>(const bigint &other) const;
    bool operator<=(const bigint &other) const;
    bool operator>=(const bigint &other) const;
};

std::ostream &operator<<(std::ostream &output, const bigint &obj);

#endif