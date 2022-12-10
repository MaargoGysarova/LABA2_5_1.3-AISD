
#ifndef LLABA2_5_1_BROKEN_LINE_H
#define LLABA2_5_1_BROKEN_LINE_H
#include "Point.h"
#include <vector>
#include <stdio.h>
#include <iostream>

using namespace std;


template <class T>
class Broken_line{
private:
    
    vector <Point<T>> points;
    unsigned int counter;
    unsigned int size;
    unsigned int grow_size;


public:
    
     auto begin() { return points.begin(); }
     auto end() { return points.end(); }

     auto cbegin() const { return points.cbegin(); }
     auto cend() const { return points.cend(); }


     explicit Broken_line<T>(unsigned int grow_size=5,unsigned int size=1);

     void set_size(int new_size); 
	
     Point<T> operator[](int index)const; 
     void operator()(const Point<T>& value,int index); 

     Broken_line<T> operator+(const Broken_line<T>& second_line); 

     Broken_line<T>& operator+=(const Point<T>& src) ; 
     Broken_line<T>& operator+(const Point<T>& src); 

     Broken_line<T>& operator=(const Broken_line<T>& scr);

     double get_length()const;
     static double get_length_two_tops(const Point<T>& A,const Point<T>& B);
     int get_counter() const;
};


#endif //LLABA2_5_1_BROKEN_LINE_
