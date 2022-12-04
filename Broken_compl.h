#include "Complex.h"
#pragma once

template<class C>
class Broken_compl
{
private:
    Complex<C>* points_compl;
    unsigned int counter;
    unsigned int size;
    unsigned int grow_size;
public:
    explicit Broken_compl<C>(unsigned int grow_size = 5, unsigned int size = 1);
    Complex<C>& operator[](int index)const;
    void operator()(const Complex<C>& value, int index);
    Broken_compl<C>& operator+(const Broken_compl<C>& second_line);

    Broken_compl<C>& operator+=(const Complex<C>& src);
    Broken_compl<C>& operator+(const Complex<C>& src);

    double get_length()const;
    static double get_length_two_tops(const Complex<C>& A, const Complex<C>& B);
    int get_counter() const;
    void set_size(int new_size);

};


