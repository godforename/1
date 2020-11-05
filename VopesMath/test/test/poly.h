#ifndef _POLY_H
#define _POLY_H

#include "linklist.h"
#include "matrix.h"

using namespace std;

class Term
{
public:
	double coef;
	int exp;
public:
	Term();
	Term(double Coef, int Exp);
	friend bool operator >(const Term& term1, const Term& term2);
	friend bool operator <(const Term& term1, const Term& term2);
	friend bool operator ==(const Term& term1, const Term& term2);
	friend bool operator >=(const Term& term1, const Term& term2);
	friend bool operator <=(const Term& term1, const Term& term2);
};

class Poly
{
	friend ostream & operator <<(ostream &o, const Poly& P);
private:
	LinkList<Term> termArray;
public:
	LinkList<Term> getTerms()const
	{
		return this->termArray;
	}
public:
	Poly();
	Poly(const Poly& P);

	void clear();
	void newTerm(double Coef, int exp);

	Poly& operator =(const Poly& P);
	Poly  operator -()const;

	Poly read(string& P_str);
	int  deg()const;
	double mainCoef()const;
	double coef(int k)const;
	Complex eval(Complex x)const;
	Complex eval(double x)const;
	Poly com(const Poly& P)const;
	Poly diff()const;

	vector<Complex> roots();

	friend bool operator ==(const Poly& P1, const Poly& P2);
	friend bool operator !=(const Poly& P1, const Poly& P2);

	friend Poly operator +(const Poly& P1, const Poly& P2);
	friend Poly operator -(const Poly& P1, const Poly& P2);
	friend Poly operator *(const Poly& P1, const Poly& P2);
	friend Poly operator *(const Poly& P1, double k);
	friend Poly operator *(double k, const Poly& P2);
	friend Poly operator /(const Poly& P1, const Poly& P2);
	friend Poly operator /(const Poly& P1, double k );
	friend Poly operator %(const Poly& P1, const Poly& P2);
};

Poly unite(int k);

Poly R2P(double x);

Poly gcd(const Poly& P1, const Poly& P2);
Poly lcm(const Poly& P1, const Poly& P2);

Poly pow(const Poly& P, int n);

#endif