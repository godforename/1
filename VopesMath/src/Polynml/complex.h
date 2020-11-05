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

double Complex::Re()const
{
	return this->real;
}

double Complex::Im()const
{
	return this->imag;
}

//-------------------------------------------------------------------------------

double Complex::module()const
{
	return sqrt(pow(this->real, 2) + pow(this->imag, 2));
}

double Complex::arg()const
{
	if (this->imag != 0 || this->real > 0)
	{
		return 2 * atan(this->imag / (this->real + this->module()));
	}
	else if (this->real != 0)
	{
		return PI;
	}
	else
	{
		return 0;
	}
}

Complex Complex::conj()const
{
	return Complex(this->real, this->imag);
}

bool Complex::isZero()const
{
	double Real = this->real;
	double Imag = this->imag;
	if (Real > -1E-6 && Real < 1E-6 && Imag > -1E-6 && Real < 1E-6)
	{
		return true;
	}
	else
	{
		return false;
	}
}

//------------------------------------------------------------------------------

ostream & operator <<(ostream & o, const Complex& x)
{
	double Real = x.real;
	double Imag = x.imag;

	if (!isZero(Real))
	{
		if (Real > 1E-6)
		{
			cout << " ";
		}
		if (Imag > 1E-6 && !isZero(Imag - 1))
		{
			o << Real << " + i * " << Imag;
		}
		else if (Imag < -1E-6 && !isZero(Imag + 1))
		{
			o << Real << " - i * " << -Imag;
		}
		else if (isZero(Imag - 1))
		{
			o << Real << " + i";
		}
		else if (isZero(Imag + 1))
		{
			o << Real << " - i";
		}
		else if (isZero(Imag))
		{
			o << Real;
		}
	}
	else
	{
		if (Imag > 1E-6 && !isZero(Imag - 1))
		{
			o << "  i * " << Imag;
		}
		else if (Imag < -1E-6 && !isZero(Imag + 1))
		{
			o << "- i * " << -Imag;
		}
		else if (isZero(Imag - 1))
		{
			o << "  i";
		}
		else if (isZero(Imag + 1))
		{
			o << "- i";
		}
		else if (isZero(Imag))
		{
			o << "  0";
		}
	}

	return o;
}

//--------------------------------------------------------------------------------

bool operator ==(const Complex& x, const Complex& y)
{
	return (x.real == y.real && x.imag == y.imag);
}

bool operator !=(const Complex& x, const Complex& y)
{
	return (x.real != y.real || x.imag != y.imag);
}

Complex operator +(const Complex& x, const Complex& y)
{
	return Complex(x.real + y.real, x.imag + y.imag);
}

Complex operator +(double k, const Complex& x)
{
	Complex y = R2C(k);
	return y + x;
}

Complex operator +(const Complex& x, double k)
{
	Complex y = R2C(k);
	return x + y;
}

Complex operator -(const Complex& x, const Complex& y)
{
	return x + (-y);
}

Complex operator -(double k, const Complex& x)
{
	return R2C(k) - x;
}

Complex operator -(const Complex& x, double k)
{
	return x - R2C(k);
}

Complex operator *(const Complex& x, const Complex& y)
{
	return Complex(x.real * y.real - x.imag * y.imag,
		x.imag * y.real + x.real * y.imag);
}

Complex operator *(double k, const Complex& x)
{
	return R2C(k) * x;
}

Complex operator *(const Complex& x, double k)
{
	return x * R2C(k);
}

Complex operator /(const Complex& x, const Complex& y)
{
	if (y.isZero())
	{
		cout << "Error in complex divide: the divisor is zero!" << endl;
		exit(-1);
	}
	else
	{
		double divisor = pow(y.module(), 2);
		return Complex((x.real*y.real + x.imag*y.imag) / divisor,
			(x.imag*y.real - x.real*y.imag) / divisor);
	}
}

Complex operator /(double k, const Complex& x)
{
	return R2C(k) / x;
}

Complex operator /(const Complex& x, double k)
{
	return x / R2C(k);
}

Complex operator ^(const Complex& x, double n)
{
	return pow(x, n);
}

Complex operator ^(double a, const Complex& z)
{
	return exp(z) ^ (log(a) / log(EXP));
}

//--------------------------------------------------------------------------------

Complex pow(const Complex& x, double n)
{
	double theta = x.arg();
	return pow(x.module(), n) * Complex(cos(n * theta), sin(n * theta));
}

Complex exp(const Complex& x)
{
	double Imag = x.Im();
	return exp(x.Re()) * Complex(cos(Imag), sin(Imag));
}

Complex R2C(double x)
{
	return Complex(x, 0);
}

bool isZero(double x)
{
	return (x > -1E-6 && x < 1E-6);
}

#endif