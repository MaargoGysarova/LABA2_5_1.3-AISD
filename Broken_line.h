
#ifndef LLABA2_5_1_BROKEN_LINE_H
#define LLABA2_5_1_BROKEN_LINE_H
#include "Point.h"
#include <vector>


template <class T>
class Broken_line{
private:
    
    vector<Point<T>> points;
    unsigned int counter;
    unsigned int size;
    unsigned int grow_size;
public:
     
     explicit Broken_line<T>(unsigned int grow_size=5,unsigned int size=1);

     void set_size(int new_size); //������� ���-�� ���設
	
     Point<T>& operator[](int index)const; //�⥭�� ���設�
     void operator()(const Point<T>& value,int index); //������ ���設�

     Broken_line<T>& operator+(const Broken_line<T>& second_line); //�����⥭��� �����

     Broken_line<T>& operator+=(const Point<T>& src) ; //���������� ���設� � �����
     Broken_line<T>& operator+(const Point<T>& src); //� ��砫�

     double get_length()const;
     static double get_length_two_tops(const Point<T>& A,const Point<T>& B);
     int get_counter() const;
};


#endif //LLABA2_5_1_BROKEN_LINE_H
