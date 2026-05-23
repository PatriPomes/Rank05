#ifndef HTTP_BIGINT
#define HTTP_BIGINT

#include <string>
#include <iostream>
#include <cstdlib>
#include <sstream>

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
        ~bigint();

        bigint &operator+=(const bigint &obj);
        bigint operator+(const bigint &obj) const;
        
        bigint operator++(int);
        bigint operator++();

        //shift number
        bigint operator<<(unsigned int num) const;
        bigint operator>>(unsigned int num) const;
        bigint &operator<<=(unsigned int num);
        bigint &operator>>=(unsigned int num);

        //shift object
        bigint operator<<(const bigint &obj) const;
        bigint operator>>(const bigint &obj) const;
        bigint &operator<<=(const bigint &obj);
        bigint &operator>>=(const bigint &obj);

        //other
        bool operator<(const bigint &obj) const;
        bool operator>(const bigint &obj) const;
        bool operator==(const bigint &obj) const;
        bool operator!=(const bigint &obj) const;
        bool operator<=(const bigint &obj) const;
        bool operator>=(const bigint &obj) const;
        
};

std::ostream &operator<<(std::ostream &os, const bigint &obj);


#endif