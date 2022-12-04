
#ifndef LLABA2_5_1_POINT_H
#define LLABA2_5_1_POINT_H

#include <system_error>
#include <complex>

template <class T>
class Point  {
private:
    T x,y;
public:
    T GetPointX()const;
    T GetPointY()const;
    void SetPointX(T x);
    void SetPointY(T y);

    explicit Point(T x=0,T y=0);
    static double GetDistance(const Point &A,const Point &B);
};

#endif //LLABA2_5_1_POINT_H
