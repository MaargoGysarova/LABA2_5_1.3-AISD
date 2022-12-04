#include "Broken_line.h"
#include "Point.h"
#include "ESetErrors.h"
#include <complex>



template <class T>
Broken_line<T>::Broken_line(unsigned int grow_size,unsigned int size):size(1),points(nullptr),counter(0),grow_size(grow_size) {
   this->size=size;
   points= new Point<T>[this->size];
}

template <class T>
void Broken_line<T>::set_size(int new_size){
    this->size=new_size;
}

template <class T>
Point<T> &Broken_line<T>::operator[](int index)const {
    if (index < 0 || index > counter)
        throw out_of_range("Index out of range");
    return points[index];
}

template <class T>
void Broken_line<T>::operator()(const Point<T> &value, int index) {
	if (index < 0 || index > counter)
		throw std::out_of_range("Index out of range");
	
    points[index] = value;
}

template <class T>
Broken_line<T> &Broken_line<T>::operator+(const Broken_line<T>&second_line) {
    Broken_line<T> line;
    line.points= new Point<T>[this->size+second_line.size];
    for(int i=0;i< this->counter;i++){
        line.points[i]=points[i];
    }
    for(int i=0;i< second_line.get_counter(); i++) {
        line.points[this->counter+i]=second_line.points[i];
    }
    line.counter = this->counter + second_line.counter;
    line.set_size(line.counter);
    return line;
}

template <class T>
Broken_line<T> &Broken_line<T>::operator+=(const Point<T> &src)  {
    if(counter==size) {
        Point<T> *tmp;
        tmp = new Point<T>[this->size + grow_size];
        for (int i = 0; i < size; i++) {
            tmp[i] = points[i];
        }
        tmp[size] = src;
        points = tmp;
    }
    else {
        points[counter]=src;
    }
    counter++;
    return *this;
}

template <class T>
Broken_line<T> &Broken_line<T>::operator+(const Point<T> &src) {
    Point<T> *tmp;
    if(counter==size) {
        tmp = new Point<T>[this->size + grow_size];
        tmp[0]=src;
        for (int i = 1; i < this->counter + 1; i++) {
            tmp[i] = points[i - 1];
        
        }
    }
    else{
        tmp = new Point<T>[this->counter+1];
        tmp[0]=src;
        for (int i = 1; i<this->counter+1; i++) {
            tmp[i] = points[i-1];
        }
    }
    this->counter++;
    points = tmp;
    return *this;
}

template <class T>
double Broken_line<T>::get_length() const{
    double length=0;
    if(size>1) {
        for (int i = 0; i < counter; i++) {
            if (i == counter - 1) { length += Point<T>::GetDistance(points[i], points[0]); }
            else { length += Point<T>::GetDistance(points[i], points[i + 1]); }
        }
    }
    return length;
}

template <class T>
int Broken_line<T>::get_counter() const {
    return (int)counter;
}

template <class T>
double Broken_line<T>::get_length_two_tops(const Point<T> &A, const Point<T> &B) {
    return Point<T>::GetDistance(A,B);
}

template class Point<int>;
template class Point<float>;
template class Point<double>;


template class Broken_line<int>;
template class Broken_line<float>;
template class Broken_line<double>;










