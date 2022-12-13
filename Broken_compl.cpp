#include "Broken_compl.h"
#include "ESetErrors.h"



template<class C>
Broken_compl<C>::Broken_compl(){}

template<class C>
inline Broken_compl<C>::Broken_compl(unsigned int grow_size, unsigned int size)
{
    this->size = size;
    
}

template<class C>
Complex<C> Broken_compl<C>::operator[](int index) const
{
   // f(index < 0 || index > counter)
      //  throw out_of_range("Index out of range");
    auto iter = cbegin();
    if (index == 0) {
        return *iter;
    }
    else {
        iter += index;
        return *iter;
    }
}

template<class C>
void Broken_compl<C>::operator()(const Complex<C>& value, int index)
{
   // if (index < 0 || index > counter)
    //    throw std::out_of_range("Index out of range");
    auto iter = begin();
    if (index == 0) {
        *iter = value;
    }
    else {
        iter += index;
        *iter = value;
    }
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator+(const Broken_compl<C>& second_line)
{
    Broken_compl<C> line(5);
    line.points_compl.reserve(this->size + second_line.size);
    for (auto iter = cbegin(); iter != cend(); ++iter)
    {
        line.points_compl.push_back(*iter);
    }
    for (auto iter = second_line.cbegin(); iter != second_line.cend(); ++iter)
    {
        line.points_compl.push_back(*iter);
    }

    line.counter = this->counter + second_line.counter;
    line.set_size(line.counter + 5);
    return  line;
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator+=(const Complex<C>& src)
{
    points_compl.push_back(src);
    counter++;
    return *this;
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator+(const Complex<C>& src)
{
    points_compl.insert(points_compl.begin(), src);
    this->counter++;
    return *this;
}

template<class C>
Broken_compl<C>& Broken_compl<C>::operator=(const Broken_compl<C>& scr)
{
    points_compl.clear();
    this->size = scr.size;
    for (auto iter = scr.cbegin(); iter != scr.cend(); ++iter) {
        points_compl.push_back(*iter);

    }
    counter = scr.counter;
    return *this;
}

template<class C>
double Broken_compl<C>::get_length() const
{
    double length = 0;
    int number = 0;
    if (size > 1) {
        for (auto iter = cbegin(); iter != cend(); ++iter) {
            if (number == counter - 1) { length += Complex<C>::GetDistance(*(cbegin() + (counter - 1)), *cbegin()); }
            else {
                length += Complex<C>::GetDistance(*iter, *(iter++)); iter--;
            }

            number++;
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



