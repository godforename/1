#include "complex.h"

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
	return sqrt( pow(this->real, 2) + pow(this->imag, 2) );
}

double Complex::arg()const
{
	if( this->imag != 0 || this->real > 0 )
	{
		return 2 * atan( this->imag / (this->real + this->module()) );
	}
	else if( this->real != 0 )
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
	if( Real > -1E-6 && Real < 1E-6 && Imag > -1E-6 && Real < 1E-6 )
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

	if( !isZero(Real) )
	{
		if(Real > 1E-6)
		{
			cout << " ";
		}
		if( Imag > 1E-6 && !isZero(Imag - 1) )
		{
			o << Real << " + i * " << Imag;
		}
		else if( Imag < -1E-6 && !isZero(Imag + 1) )
		{
			o << Real << " - i * " << -Imag;
		}
		else if( isZero(Imag - 1) )
		{
			o << Real << " + i";
		}
		else if( isZero(Imag + 1) )
		{
			o << Real << " - i";
		}
		else if( isZero(Imag) )
		{
			o << Real;
		}
	}
	else
	{
		if( Imag > 1E-6 && !isZero(Imag-1) )
		{
			o << "  i * " << Imag;
		}
		else if( Imag < -1E-6 && !isZero(Imag+1) )
		{
			o << "- i * " << -Imag;
		}
		else if( isZero(Imag - 1) )
		{
			o << "  i";
		}
		else if( isZero(Imag + 1) )
		{
			o << "- i";
		}
		else if( isZero(Imag) )
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
	return Complex( x.real * y.real - x.imag * y.imag,
				    x.imag * y.real + x.real * y.imag );
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
	if( y.isZero() )
	{
		cout << "Error in complex divide: the divisor is zero!" << endl;
		exit(-1);
	}
	else
	{
		double divisor = pow( y.module(), 2 );
		return Complex( (x.real*y.real+x.imag*y.imag) / divisor,
					 	(x.imag*y.real-x.real*y.imag) / divisor );
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
	return exp(z)^(log(a)/log(EXP));
}

//--------------------------------------------------------------------------------

Complex pow(const Complex& x, double n)
{
	double theta = x.arg();
	return pow(x.module(), n) * Complex( cos(n * theta), sin(n * theta) );
}

Complex exp(const Complex& x)
{
	double Imag = x.Im();
	return exp(x.Re()) * Complex( cos(Imag), sin(Imag) );
}

Complex R2C(double x)
{
	return Complex(x, 0);
}

bool isZero(double x)
{
	return ( x > -1E-6 && x < 1E-6 );
}