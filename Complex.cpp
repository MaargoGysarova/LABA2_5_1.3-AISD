#include "Complex.h"
#include <cmath>

template<class C>
Complex<C>::Complex(C re, C im): re(re), im(im)
{}

template<class C>
Complex<C>& Complex<C>::operator*(Complex& other) {
    Complex tmp(*this);
    re = tmp.re * other.re - tmp.im * other.im;
    im = tmp.re * other.im + tmp.im * other.re;
        return (*this);
}

template<class C>
Complex<C>& Complex<C>::operator*=(C& other) {
    Complex tmp(*this);
    re = tmp.re * other;
    re = tmp.im * other;
       return (*this);
}

template<class C>
ostream& operator<<(ostream& out, const Complex<C>& x)
{
    return (out << "(" << x.re << "," << x.im << ")");
}

template<class C>
istream& operator>>(istream& in, Complex<C>& x)
{
    return (in >> x.re >> x.im);
}

template<class C>
double Complex<C>::return_double() const
{
    return sqrt(re * re - im * im);
}

template<class C>
Complex<C>& Complex<C>::operator=(const Complex<C>& other)
{
    re = other.re;
    im = other.im;
    return *this;
}

template<class C>
C Complex<C>::Get_Re()const {
    return this->re;
}

template<class C>
C Complex<C>::Get_Im()const {
    return this->im;
}

template<class C>
void Complex<C>::SetRe(C Re)
{
    this->re = Re;
}

template<class C>
void Complex<C>::SetIm(C Im)
{
    this->im = Im;
}

template<class C>
double Complex<C>::GetDistance(const Complex& A, const Complex& B)
{
    Complex<C> tmp;
    tmp.re = A.re - B.re;
    tmp.im = A.im - B.im;
    return tmp.return_double();
}

template class Complex <float>;
template class Complex<double>;