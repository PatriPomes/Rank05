#ifndef HTTP_BIGINT
#define HTTP_BIGINT

#include <sstream>
#include <string>
#include <cstdlib>
#include <iostream>

class bigint
{
private:
    std::string _str;

public:
    bigint();
    bigint(unsigned int num);
    bigint(const bigint &obj);
    bigint &operator=(const bigint &obj);
    std::string getStr() const;

    bigint operator+(const bigint &obj) const;
    
    bigint &operator+=(const bigint &obj);

    bigint operator++();
    bigint operator++(int);

    //shift with num
    bigint operator<<(unsigned int num) const;;
    bigint operator>>(unsigned int num) const;
    bigint &operator<<=(unsigned int num);
    bigint &operator>>=(unsigned int num);

    //shift with objects
    bigint operator<<(const bigint &obj) const;
    bigint operator>>(const bigint &obj) const;
    bigint &operator<<=(const bigint &obj);
    bigint &operator>>=(const bigint &obj);

    bool operator==(const bigint &obj) const;
    bool operator!=(const bigint &obj) const;
    bool operator<(const bigint &obj) const;
    bool operator>(const bigint &obj) const;
    bool operator<=(const bigint &obj) const;
    bool operator>=(const bigint &obj) const;

};

std::ostream &operator<<(std::ostream &os, const bigint &obj);

#endif