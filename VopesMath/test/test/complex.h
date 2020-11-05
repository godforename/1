#ifndef _COMPLEX_H
#define _COMPLEX_H

#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <stdbool.h>

#define PI 3.141592654
#define EXP  2.718281828

using namespace std;

class Complex
{
	friend ostream & operator <<(ostream &o, const Complex& x);

private:
	double real;
	double imag;

public:

	Complex():real(0), imag(0) {};
	Complex(double re, double im):real(re), imag(im) {};
	Complex(double x)
	{
		this->real = x;
		this->imag = 0;
	}
	Complex(const Complex& x)
	{
		this->real = x.real;
		this->imag = x.imag;
	}

	Complex& operator =(const Complex& x)
	{
		this->real = x.real;
		this->imag = x.imag;

		return *this;
	}

	Complex& operator =(double k)
	{
		this->real = k;
		this->imag = 0;

		return *this;
	}

	Complex operator -()const
	{
		return Complex(-this->real, -this->imag);
	}

	bool isZero()const;

	double  Re()const;
	double  Im()const;

	double  module()const;
	double  arg()const;
	Complex conj()const;

	friend bool operator ==(const Complex& x, const Complex& y);
	friend bool operator !=(const Complex& x, const Complex& y);

	friend Complex operator +(const Complex& x, const Complex& y);
	friend Complex operator +(double  k, const Complex& x);
	friend Complex operator +(const Complex& x, double  k);

	friend Complex operator -(const Complex& x, const Complex& y);
	friend Complex operator -(double  k, const Complex& x);
	friend Complex operator -(const Complex& x, double  k);

	friend Complex operator *(const Complex& x, const Complex& y);
	friend Complex operator *(double  k, const Complex& x);
	friend Complex operator *(const Complex& x, double  k);

	friend Complex operator /(const Complex& x, const Complex& y);
	friend Complex operator /(double  k, const Complex& x);
	friend Complex operator /(const Complex& x, double  k);

	friend Complex operator ^(const Complex& x, double  n);
	friend Complex operator ^(double  a, const Complex& z);
};

Complex pow(const Complex& x, double n);
Complex exp(const Complex& x);
Complex R2C(double x);

bool isZero(double x);

#endif