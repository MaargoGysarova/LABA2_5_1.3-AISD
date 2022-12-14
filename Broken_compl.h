#include "Complex.h"
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;
#pragma once

template<class C>
class Broken_compl
{
private:
    vector <Complex<C>> points_compl;
    unsigned int counter;
    unsigned int size;
    unsigned int grow_size;
public:

    auto begin() { return points_compl.begin(); }
    auto end() { return points_compl.end(); }

    auto cbegin() const { return points_compl.cbegin(); }
    auto cend() const { return  points_compl.cend(); }

    Broken_compl<C>();

    explicit Broken_compl<C>(unsigned int grow_size = 5, unsigned int size = 1);
    Complex<C> operator[](int index)const;
    void operator()(const Complex<C>& value, int index);
    Broken_compl<C> operator+(const Broken_compl<C>& second_line);

    Broken_compl<C>& operator+=(const Complex<C>& src);
    Broken_compl<C>& operator+(const Complex<C>& src);
    Broken_compl<C>& operator=(const Broken_compl<C>& scr);

    double get_length()const;
    static double get_length_two_tops(const Complex<C>& A, const Complex<C>& B);
    int get_counter() const;
    void set_size(int new_size);

};


