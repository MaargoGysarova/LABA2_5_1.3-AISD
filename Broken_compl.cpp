#include "Broken_compl.h"

template<class C>
inline Broken_compl<C>::Broken_compl(unsigned int grow_size, unsigned int size)
{
    this->size = size;
    points_compl = new Complex<C>[this->size];
}

template<class C>
inline Complex<C>& Broken_compl<C>::operator[](int index) const
{
    if (index < 0 || index > counter)
        throw out_of_range("Index out of range");
    return points_compl[index];
}

template<class C>
void Broken_compl<C>::operator()(const Complex<C>& value, int index)
{
    if (index < 0 || index > counter)
        throw std::out_of_range("Index out of range");

    points_compl[index] = value;
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator+(const Broken_compl<C>& second_line)
{
    Broken_compl<C> line;
    line.points_compl = new Complex<C>[this->size + second_line.size];
    for (int i = 0; i < this->counter; i++) {
        line.points_compl[i] = points_compl[i];
    }
    for (int i = 0; i < second_line.get_counter(); i++) {
        line.points_compl[this->counter + i] = second_line.points_compl[i];
    }
    line.counter = this->counter + second_line.counter;
    line.set_size(line.counter);
    return line;
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator+=(const Complex<C>& src)
{
    if (counter == size) {
        Complex<C>* tmp;
        tmp = new Complex<C>[this->size + grow_size];
        for (int i = 0; i < size; i++) {
            tmp[i] = points_compl[i];
        }
        tmp[size] = src;
        points_compl = tmp;
    }
    else {
        points_compl[counter] = src;
    }
    counter++;
    return *this;
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator+(const Complex<C>& src)
{
    Complex<C>* tmp;
    if (counter == size) {
        tmp = new Complex<C>[this->size + grow_size];
        tmp[0] = src;
        for (int i = 1; i < this->counter + 1; i++) {
            tmp[i] = points_compl[i - 1];

        }
    }
    else {
        tmp = new Complex<C>[this->counter + 1];
        tmp[0] = src;
        for (int i = 1; i < this->counter + 1; i++) {
            tmp[i] = points_compl[i - 1];
        }
    }
    this->counter++;
    points_compl = tmp;
    return *this;
}

template<class C>
double Broken_compl<C>::get_length() const
{
    double length = 0;
    if (size > 1) {
        for (int i = 0; i < counter; i++) {
            if (i == counter - 1) { length += Complex<C>::GetDistance(points_compl[i], points_compl[0]); }
            else { length += Complex<C>::GetDistance(points_compl[i], points_compl[i + 1]); }
        }
    }
    return length;
}

template<class C>
double Broken_compl<C>::get_length_two_tops(const Complex<C>& A, const Complex<C>& B)
{
    return Complex<C>::GetDistance(A, B);
}

template<class C>
int Broken_compl<C>::get_counter() const
{
    return counter;
}

template<class C>
void Broken_compl<C>::set_size(int new_size)
{
    this->size = new_size;
}


template class Complex <float>;
template class Complex<double>;
template class Broken_compl<float>;
template class Broken_compl<double>;



