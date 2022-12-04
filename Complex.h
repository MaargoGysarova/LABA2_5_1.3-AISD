#pragma once
#include <iostream>

using namespace std;

template<class C>
class Complex{
private:
	C re, im;
public:
	
	Complex(C re=0, C im = 0);
	Complex& operator*(Complex& other);
	Complex& operator*=(C& other);

	friend ostream& operator<< (ostream& out, const Complex& x); //вывод
	friend istream& operator>> (istream& in, Complex& x); //ввод

	// преобразование типа Complex в double
	double return_double() const;

	Complex& operator=(const Complex& other);//оператор присваивания

	C Get_Re()const;
	C Get_Im()const;

	void SetRe(C Re);
	void SetIm(C Im);

	static double GetDistance(const Complex& A, const Complex& B);
};

