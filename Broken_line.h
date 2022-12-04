
#ifndef LLABA2_5_1_BROKEN_LINE_H
#define LLABA2_5_1_BROKEN_LINE_H
#include "Point.h"



template <class T>
class Broken_line{
private:
    Point<T> *points;
    unsigned int counter;
    unsigned int size;
    unsigned int grow_size;
public:
     
     explicit Broken_line<T>(unsigned int grow_size=5,unsigned int size=1);

     void set_size(int new_size); //задание кол-ва вершин
	
     Point<T>& operator[](int index)const; //чтение вершины
     void operator()(const Point<T>& value,int index); //запись вершины

     Broken_line<T>& operator+(const Broken_line<T>& second_line); //канкатенация линий

     Broken_line<T>& operator+=(const Point<T>& src) ; //добавление вершины в конец
     Broken_line<T>& operator+(const Point<T>& src); //в начало

     double get_length()const;
     static double get_length_two_tops(const Point<T>& A,const Point<T>& B);
     int get_counter() const;
};


#endif //LLABA2_5_1_BROKEN_LINE_H
