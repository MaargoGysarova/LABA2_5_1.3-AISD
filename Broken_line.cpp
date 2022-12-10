#include "Broken_line.h"
#include "Point.h"
#include "ESetErrors.h"
#include <complex>
#include <vector>



template <class T>
Broken_line<T>::Broken_line(unsigned int grow_size,unsigned int size):size(1),counter(0),grow_size(grow_size) {
   this->size=size;
}

template <class T>
void Broken_line<T>::set_size(int new_size){
    this->size=new_size;
    
}

template <class T>
Point<T> Broken_line<T>::operator[](int index)const {
    if (index < 0 || index > counter)
        throw out_of_range("Index out of range");
    auto iter = cbegin();
    if(index == 0 ) {
        return *iter;
    }
    else {
        iter += index;
        return *iter;
    }
}

template <class T>
void Broken_line<T>::operator()(const Point<T>& value, int index) {
    if (index < 0 || index > counter)
        throw std::out_of_range("Index out of range");
    auto iter = begin();
    if (index == 0) {
		*iter = value;
    }
    else {
        iter += index;
        *iter = value;
    }
    }
  
 
template <class T>
Broken_line<T> Broken_line<T>::operator+(const Broken_line<T>&second_line) {
    Broken_line<T> line;
	line.points.reserve(this->size + second_line.size);
    for (auto iter = cbegin(); iter != cend(); ++iter)
     {
     line.points.push_back(*iter);
    }
    for (auto iter = second_line.cbegin(); iter != second_line.cend(); ++iter)
    {
    line.points.push_back(*iter);
     }

    line.counter = this->counter + second_line.counter;
    line.set_size(line.counter+5);
    return  line;
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
        for (int i = 0; i < this->counter; i++) {
            points[i] = tmp[i];
        }
    }
    else {
        points.push_back(src);
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
    for (int i = 0; i < this->counter; i++) {
        points[i] = tmp[i];
    }
    return *this;
}

template<class T>
Broken_line<T>& Broken_line<T>::operator=(const Broken_line<T>& scr)
{
    points.clear();
	
    this->size = scr.size;
	//this->points.resize(this->size);
	

    
    //for (int i = 0; i < scr.counter; i++) {
      //  points[i] = *iter;
      //  iter++;
   // }
    for (auto iter = scr.cbegin(); iter != scr.cend(); ++iter) {
		points.push_back(*iter);
    
    }
	counter = scr.counter;
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










