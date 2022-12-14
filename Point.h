
#ifndef LLABA2_5_1_POINT_H
#define LLABA2_5_1_POINT_H

#include <system_error>
#include <complex>
#include "Point.h"
#include <iostream>

using namespace std;
#include <vector>

template <class T>
class Point  {
private:
    T x,y;
public:
    T GetPointX()const;
    T GetPointY()const;
    void SetPointX(T x);
    void SetPointY(T y);

    Point(const Point &it);
    
    friend ostream& operator << (ostream& out, const Point<T>& src);


    explicit Point(T x=0,T y=0);
    static double GetDistance(const Point &A,const Point &B);
};

#endif //LLABA2_5_1_POINT_H
