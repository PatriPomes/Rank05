#ifndef HTTP_BIGINT
#define HTTP_BIGINT

#include <iostream>
#include <string>
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
};

std::ostream &operator<<(std::ostream &os, const bigint &obj);

#endif