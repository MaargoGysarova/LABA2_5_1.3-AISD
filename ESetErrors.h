
#ifndef LLABA2_5_1_ESETERRORS_H
#define LLABA2_5_1_ESETERRORS_H

#include <iostream>
using namespace std;
#include <cstdio>
class ESetErrors {
public: virtual void print_error() const =0;
};

class InvalidIndex: public ESetErrors
{
public:
    InvalidIndex();
    void print_error() const;
};

class InvalidPoints: public ESetErrors
{
public:
    InvalidPoints();
    void print_error() const;
};







#endif //LLABA2_5_1_ESETERRORS_H
