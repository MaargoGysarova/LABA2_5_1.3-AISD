#include "Broken_line.h"
#include "Point.h"
#include "ESetErrors.h"
#include <complex>
#include <vector>


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
    for (auto iter: points)
     {
     line.points.push_back(iter);
    }
    for (auto iter :second_line.points)
    {
    line.points.push_back(iter);
     }

    line.counter = this->counter + second_line.counter;
    line.set_size(line.counter+5);
    return  line;
}

template <class T>
Broken_line<T> &Broken_line<T>::operator+=(const Point<T> &src)  {
    
    points.push_back(src);
    counter++;
    return *this;
}

template <class T>
Broken_line<T> &Broken_line<T>::operator+(const Point<T> &src) {
    points.insert(points.begin(), src);
    this->counter++;
    return *this;
}

template<class T>
Broken_line<T>& Broken_line<T>::operator=(const Broken_line<T>& scr)
{
    points.clear();
	this->size = scr.size;
    for (auto iter : scr.points) {
		points.push_back(iter);
    
    }
	counter = scr.counter;
    return *this;
}

template <class T>
double Broken_line<T>::get_length() const{
    double length=0;
    int number=0;
    if(size>1) {
        for (auto iter = cbegin(); iter != cend(); ++iter) {
            if (number == counter - 1) { length += Point<T>::GetDistance(*(cbegin()+(counter-1)), *cbegin()); }
            else { length += Point<T>::GetDistance(*iter, *(iter++)); iter--;
            }
            
            number++;
        }
    }
    return length;
}

template <class T>
int Broken_line<T>::get_counter() const {
    return (int)counter;
}

template<class T>
void Broken_line<T>::show_all_tops() const
{
    int i = 1;
    for (auto iter = cbegin(); iter != cend(); ++iter) {
        cout << "[" << i << "]:";
        i++;
        Point<T> tmp = *iter;
        cout << "(" << tmp.GetPointX()<< ";" << tmp.GetPointY() << ")" << endl;
       // cout << tmp;
    }

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










