
#include "Point.h"
#include <cmath>
#include <complex>
#include <iostream>
#include <algorithm>
#include <stdio.h>
// complex_imag.cpp
// compile with: /EHsc




template <class T>
T Point<T>::GetPointX()const {return x;
}

template <class T>
T Point<T>::GetPointY()const{return y;}

template <class T>
void Point<T>::SetPointX(T x){this->x=x;}

template <class T>
void Point<T>::SetPointY(T y){this->y=y;
}

template <class T>
Point<T>::Point(T x,T y){this->x=x;this->y=y;}

template <class T>
double Point<T>::GetDistance(const Point &A,const Point &B){ return sqrt(pow((A.x-B.x),2)+pow((A.y-B.y),2));}

template class Point<int>;
template class Point<float>;
template class Point<double>;



