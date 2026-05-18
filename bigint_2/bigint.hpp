#ifndef HTTP_BIGINT
#define HTTP_BIGINT

#include <string>
#include <cstdlib>
#include <iostream>
#include <sstream>

class bigint
{
    private:
    std::string _str;

    public:
    bigint();
    bigint(unsigned int num);
    bigint(const bigint &obj);
    ~bigint();
    bigint &operator=(const bigint &obj);
    std::string getStr() const;

    bigint &operator+=(const bigint &obj);
    bigint operator+(const bigint &obj) const;

    bigint operator++();
    bigint operator++(int);

    //shift number
    bigint operator<<(unsigned int num)const;
    bigint operator>>(unsigned int num)const;
    bigint &operator<<=(unsigned int num);
    bigint &operator>>=(unsigned int num);

    //shift obj
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