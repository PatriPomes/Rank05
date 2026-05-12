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
};

#endif