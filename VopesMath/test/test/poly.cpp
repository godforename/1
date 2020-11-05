#include "poly.h"

Term::Term()
{
	this->coef = 0;
	this->exp  = 0;
}
Term::Term(double Coef, int Exp)
{
	this->coef = Coef;
	this->exp  = Exp;
}
bool operator >(const Term& term1, const Term& term2)
{
	return (term1.exp > term2.exp);
}
bool operator <(const Term& term1, const Term& term2)
{
	return (term1.exp < term2.exp);
}
bool operator ==(const Term& term1, const Term& term2)
{
	return (term1.exp == term2.exp);
}
bool operator >=(const Term& term1, const Term& term2)
{
	return (term1.exp >= term2.exp);
}
bool operator <=(const Term& term1, const Term& term2)
{
	return (term1.exp <= term2.exp);
}

Poly::Poly()
{
	(this->termArray).init();
	Term Zero;
	Zero.coef = 0;
	Zero.exp = 0;
	(this->termArray).insert(Zero);
}

Poly::Poly(const Poly& P)
{
	this->termArray = P.termArray;
}

void Poly::clear()
{
	Poly ZERO;
	*this = ZERO;
}

void Poly::newTerm(double Coef, int Exp)
{
	if(Coef != 0)
	{
		Term new_term;
		new_term.coef = Coef;
		new_term.exp  = Exp;
		LinkNode<Term>* p = (this->termArray).find(new_term);
		if( p == NULL )
		{
			(this->termArray).insert(new_term);
		}
		else
		{
			(p->data).coef += Coef;
			if( (p->data).coef == 0 )
			{
				(this->termArray).erase(p);
			}
		}
	}
}

Poly& Poly::operator =(const Poly& P)
{
	this->termArray = P.termArray;
	return *this;
}

Poly Poly::operator -()const
{
	Poly Result = *this;

	LinkNode<Term>* p = (Result.termArray).begin();
	while( p != (Result.termArray).end() )
	{
		(p->data).coef = -(p->data).coef;
		p = p->link;
	}
	return Result;
}

int Poly::deg()const
{
	return ( (this->termArray).begin()->data ).exp;
}

double Poly::mainCoef()const
{
	return ( (this->termArray).begin()->data ).coef;
}

double Poly::coef(int k)const
{
	Term U(1, k);
	LinkNode<Term>* p = (this->termArray).find(U);
	if( p == NULL )
	{
		return 0;
	}
	else
	{
		return ( p->data ).coef;
	}
}

Complex Poly::eval(Complex x)const
{
	Complex Result;
	LinkNode<Term>* p = (this->termArray).begin();
	for(; p != NULL; p = p->link)
	{
		Result = Result + (p->data).coef * pow(x, (p->data).exp);
	}
	return Result;
}

Complex Poly::eval(double x)const
{
	return this->eval(R2C(x));
}

Poly Poly::com(const Poly& P)const
{
	Poly Q;
	LinkNode<Term>* p = (this->termArray).begin();
	for(; p != NULL; p = p->link)
	{
		Q = Q + (p->data).coef * pow(P, (p->data).exp);
	}
	return Q;
}

Poly unite(int k)
{
	Poly U;
	U.newTerm(1, k);
	return U;
}

bool operator ==(const Poly& P1, const Poly& P2)
{
	LinkNode<Term>* p1 = (P1.termArray).begin();
	LinkNode<Term>* p2 = (P2.termArray).begin();
	bool result = true;
	while( p1 != (P1.termArray).end() && p2 != (P2.termArray).end() )
	{
		if( (p1->data).coef == (p2->data).coef && 
			(p1->data).exp == (p2->data).exp )
		{
			p1 = p1->link;
			p2 = p2->link;
		}
		else
		{
			result = false;
			break;
		}
	}
	return result;
}

bool operator !=(const Poly& P1, const Poly& P2)
{
	return !(P1 == P2);
}

Poly operator +(const Poly& P1, const Poly& P2)
{
	Poly P_result;
	LinkNode<Term>* p1 = (P1.termArray).begin();
	LinkNode<Term>* p2 = (P2.termArray).begin();
	double Coef;
	int Exp;
	while( p1 != (P1.termArray).end() && p2 != (P2.termArray).end() )
	{
		if( (p1->data).exp > (p2->data).exp )
		{
			Coef = (p1->data).coef;
			Exp  = (p1->data).exp;
			P_result.newTerm(Coef, Exp);
			p1 = p1->link;
		}
		else if( (p1->data).exp < (p2->data).exp )
		{
			(P_result.termArray).insert(p2->data);
			p2 = p2->link;
		}
		else
		{
			Coef = (p1->data).coef + (p2->data).coef;
			Exp  = (p1->data).exp;
			P_result.newTerm(Coef, Exp);
			p1 = p1->link;
			p2 = p2->link;
		}
	}

	if( p1 == (P1.termArray).end() && p2 != (P2.termArray).end() )
	{
		while( p2 != (P2.termArray).end() )
		{
			Coef = (p2->data).coef;
			Exp  = (p2->data).exp;
			P_result.newTerm(Coef, Exp);
			p2 = p2->link;
		}
	}
	else if( p1 != (P1.termArray).end() && p2 == (P2.termArray).end() )
	{
		while( p1 != (P1.termArray).end() )
		{
			Coef = (p1->data).coef;
			Exp  = (p1->data).exp;
			P_result.newTerm(Coef, Exp);
			p1 = p1->link;
		}
	}

	return P_result;
}

Poly operator -(const Poly& P1, const Poly& P2)
{
	return P1 + (-P2);
}

Poly operator *(const Poly& P1, const Poly& P2)
{
	Poly P_result;
	LinkNode<Term> *p1, *p1_begin = (P1.termArray).begin();
	LinkNode<Term> *p2, *p2_begin = (P2.termArray).begin();
	double Coef;
	int Exp;
	for(p1 = p1_begin; p1 != (P1.termArray).end(); p1 = p1->link)
	{
		for(p2 = p2_begin; p2 != (P2.termArray).end(); p2 = p2->link)
		{
			Coef = (p1->data).coef * (p2->data).coef;
			Exp  = (p1->data).exp  + (p2->data).exp;
			P_result.newTerm(Coef, Exp);
		}
	}
	return P_result;
}

Poly operator *(double k, const Poly& P2)
{
	Poly P1 = R2P(k);
	return P1 * P2;
}

Poly operator *(const Poly& P1, double k)
{
	return k * P1;
}

Poly operator /(const Poly& P1, const Poly& P2)
{
	Poly ZERO;
	if( P2.mainCoef() == 0 )
	{
		cout << "[ Error in P1 / P2 : " << endl
			 << "  P2 = 0 is not permitted! ]" << endl;
		exit(-1);
	}
	else if( P1.deg() < P2.deg() )
	{
		return ZERO;
	}

	Poly Q, R;
	R = P1;
	while(R.deg() >= P2.deg() && R.mainCoef() != 0)
	{
		Poly new_term = R.mainCoef() / P2.mainCoef() * unite( R.deg() - P2.deg() );
		Q = Q + new_term;
		R = R - new_term * P2;
	}
	return Q;
}

Poly operator /(const Poly& P1, double k)
{
	if( k == 0 )
	{
		cout << "[ Error in P1 / k :"<< endl
			 << "  k = 0 is not permitted! ]" << endl;
		exit(-1);
	}

	return 1/k * P1;
}

Poly operator %(const Poly& P1, const Poly& P2)
{
	Poly ZERO;
	if( P2.mainCoef() == 0 )
	{
		cout << "[ Error in P1 % P2 : " << endl
			 << "  P2 = 0 is not permitted! ]" << endl;
		exit(-1);
	}
	else if( P1.deg() < P2.deg() )
	{
		return P1;
	}

	Poly Q, R;
	R = P1;
	while(R.deg() >= P2.deg() && R.mainCoef() != 0)
	{
		Poly new_term = R.mainCoef() / P2.mainCoef() * unite( R.deg() - P2.deg() );
		Q = Q + new_term;
		R = R - new_term * P2;
	}
	return R;
}

Poly R2P(double x)
{
	Poly P;
	P.newTerm(x, 0);
	return P;
}

ostream & operator <<(ostream & o, const Poly & P)  
{
	Poly ZERO;
	if( P.mainCoef() == 0 )
    {
    	o << "0";
    }
    else
    {
	    LinkNode<Term>* p = (P.termArray).begin();
	    if( (p->data).coef > 0 &&  (p->data).coef != 1 )
		{
			if( (p->data).exp >= 2 )
			{
				o << (p->data).coef << "*X^" << (p->data).exp;
			}
			else if( (p->data).exp == 1 )
			{
				o << (p->data).coef << "*X";
			}
			else if( (p->data).exp == 0 )
			{
				o << (p->data).coef;
			}
		}
		else if( (p->data).coef == 1 )
		{
			if( (p->data).exp >= 2 )
			{
				o << "X^" << (p->data).exp;
			}
			else if( (p->data).exp == 1 )
			{
				o << "X";
			}
			else if( (p->data).exp == 0 )
			{
				o << 1;
			}
		}
		else if( (p->data).coef < 0 && (p->data).coef != -1 )
		{
			if( (p->data).exp >= 2 )
			{
				o << " - " << -(p->data).coef << "*X^" << (p->data).exp;
			}
			else if( (p->data).exp == 1 )
			{
				o << " - " << -(p->data).coef << "*X";
			}
			else if( (p->data).exp == 0 )
			{
				o << " - " << -(p->data).coef;
			}
		}
		else if( (p->data).coef == -1 )
		{
			if( (p->data).exp >= 2 )
			{
				o << " - " << "X^" << (p->data).exp;
			}
			else if( (p->data).exp == 1 )
			{
				o << " - " << "X";
			}
			else if( (p->data).exp == 0 )
			{
				o << " - " << 1;
			}
		}
		p = p->link;
	    for(; p != (P.termArray).end(); p = p->link)
	    {
	    	if( (p->data).coef > 0 &&  (p->data).coef != 1 )
	    	{
	    		if( (p->data).exp >= 2 )
	    		{
	    			o << " + " << (p->data).coef << "*X^" << (p->data).exp;
	    		}
	    		else if( (p->data).exp == 1 )
	    		{
	    			o << " + " << (p->data).coef << "*X";
	    		}
	    		else if( (p->data).exp == 0 )
	    		{
	    			o << " + " << (p->data).coef;
	    		}
	    	}
	    	else if( (p->data).coef == 1 )
	    	{
	    		if( (p->data).exp >= 2 )
	    		{
	    			o << " + " << "X^" << (p->data).exp;
	    		}
	    		else if( (p->data).exp == 1 )
	    		{
	    			o << " + " << "X";
	    		}
	    		else if( (p->data).exp == 0 )
	    		{
	    			o << " + " << 1;
	    		}
	    	}
	    	else if( (p->data).coef < 0 && (p->data).coef != -1 )
	    	{
	    		if( (p->data).exp >= 2 )
	    		{
	    			o << " - " << -(p->data).coef << "*X^" << (p->data).exp;
	    		}
	    		else if( (p->data).exp == 1 )
	    		{
	    			o << " - " << -(p->data).coef << "*X";
	    		}
	    		else if( (p->data).exp == 0 )
	    		{
	    			o << " - " << -(p->data).coef;
	    		}
	    	}
	    	else if( (p->data).coef == -1 )
	    	{
	    		if( (p->data).exp >= 2 )
	    		{
	    			o << " - " << "X^" << (p->data).exp;
	    		}
	    		else if( (p->data).exp == 1 )
	    		{
	    			o << " - " << "X";
	    		}
	    		else if( (p->data).exp == 0 )
	    		{
	    			o << " - " << 1;
	    		}
	    	}
	    }
	}
    
    return o;  
}

Poly gcd(const Poly& P1, const Poly& P2)
{
	Poly ZERO;
	if(P1.mainCoef() == 0 && P2.mainCoef() != 0)
	{
		return P2;
	}
	if(P2.mainCoef() == 0 && P1.mainCoef() != 0)
	{
		return P1;
	}
	if(P2.mainCoef() == 0 && P1.mainCoef() == 0)
	{
		cout << "[ Error in gcd(Poly P1, Poly P2):" << endl
			 << "  P1 = P2 = 0 is not permitted! ]" << endl;
		exit(-1);
	}
	Poly A, B;
	if( P1.deg() < P2.deg() )
	{
		A = P1;
		B = P2;
	}
	else
	{
		A = P2;
		B = P1;
	}

	Poly A_last, B_last;

	while( B % A != ZERO )
	{
		A_last = A;
		B_last = B;
		
		A = B_last % A_last;
		B = A_last;
	}
	return A/A.mainCoef();
}

Poly lcm(const Poly& P1, const Poly& P2)
{
	Poly ZERO;
	if(P1.mainCoef() == 0 || P2.mainCoef() == 0)
	{
		cout << "[ Error in lcm(Poly P1, Poly P2):" << endl
			 << "  P1 == 0 || P2 == 0 is not permitted! ]" << endl;
		exit(-1);
	}
	
	Poly P_result = P1 * P2 / gcd(P1, P2);
	return P_result/P_result.mainCoef();
}

Poly pow(const Poly& P, int n)
{
	Poly Q = R2P(1);
	for(int i = 0; i < n; i++)
	{
		Q = Q * P;
	}
	return Q;
}

vector<Complex> Poly::roots()
{
	Poly ZERO;
	vector<Complex> rootsArray;
	if( this->mainCoef() == 0 )
	{
		cout << "There are infinite roots because P == 0." << endl;
	}
	else if( this->deg() == 0 )
	{
		cout << "There are no root because P(X) == cte != 0." << endl;
	}
	else if( this->deg() == 1 )
	{
		double a = this->coef(1);
		double b = this->coef(0);

		Complex x1 = - b / a;

		rootsArray.push_back(x1);
	}
	else if( this->deg() == 2 )
	{
		double a = this->coef(2);
		double b = this->coef(1);
		double c = this->coef(0);

		double delta = b * b - 4 * a * c ;

		
		Complex x1 = ( -b + pow(R2C(delta), 1.0/2) ) / (2 * a);
		Complex x2 = ( -b - pow(R2C(delta), 1.0/2) ) / (2 * a);

		rootsArray.push_back(x1);
		rootsArray.push_back(x2);
	}
	else if( this->deg() == 3 )
	{
		double a = this->coef(3);
		double b = this->coef(2);
		double c = this->coef(1);
		double d = this->coef(0);

		double p = (  c - pow(b, 2)  / (3 * a) ) / a;
		double q = ( b / (3 * a) * ( (2 * pow(b, 2)) / (9 * a) - c ) + d )/a;

		double delta = pow( (q/2), 2 ) + pow( (p/3), 3 );

		Complex j(-0.5, sqrt(3) / 2);
		Complex j2(-0.5, -sqrt(3) / 2);
		
		Complex Y1 = - q / 2 + pow(R2C(delta), 1.0/2);
		Complex Y2 = - q / 2 - pow(R2C(delta), 1.0/2);
		Complex E1 = pow(Y1, 1.0/3);
		Complex E2 = pow(Y2, 1.0/3);

		Complex X1 = E1 + E2;
		Complex X2 = j * E1 + j2 * E2;
		Complex X3 = j2 * E1 + j * E2;

		double D = b / (3 * a);
		Complex x1 = X1 - D;
		Complex x2 = X2 - D;
		Complex x3 = X3 - D;

		rootsArray.push_back(x1);
		rootsArray.push_back(x2);
		rootsArray.push_back(x3);
	}
	else
	{
		int n = this->deg();
		double an = this->mainCoef();
		Matrix C(n, n);
		for(int i = 0; i < n-1; i++)
		{
			C.data[i][i+1] = 1;
		}
		for(int j = 0; j < n; j++)
		{
			C.data[n-1][j] = - this->coef(j) / an;
		}
		
		rootsArray = C.eigenvalue();
	}

	return rootsArray;
}

string delete_space(string& P_str)
{
	for(string::iterator it = P_str.begin(); it != P_str.end();)
	{
		if(*it == ' ')
		{
			P_str.erase(it);
		}
		else
		{
			it++;
		}
	}
	return P_str;
}

bool isNumber(char ch)
{
	return (ch >= '0' && ch <= '9');
}

void read_error()
{
	cout << "Error for the input of your polinormial!" << endl;
	exit(-1);
}

string::iterator it_num_begin(string& P_str, string::iterator it)
{
	if( !isNumber(*it) )
	{
		cout << "[ Error in \"string::iterator it_number_begin(string P_str, string::iterator it)\":" << endl
			 << "  *it must be a number! ]" << endl;
		exit(-1);
	}

	while( isNumber(*it) )
	{
		it--;
	}
	if(*it == '.')
	{
		it--;
		if( isNumber(*it) )
		{
			while( isNumber(*it) )
			{
				it--;
			}
		}
		else
		{
			read_error();
		}
	}
	it++;
	return it;
}

double num_from_end(string& P_str, string::iterator it)
{
	double number;
	string::iterator it_begin = it_num_begin(P_str, it);
	string number_str = P_str.substr( it_begin - P_str.begin(), it - P_str.begin() + 1 );
	stringstream ss;
	ss << number_str;
	ss >> number;
	return number;
}

double coef_befor_X(string& P_str, string::iterator it_X)
{
	double Coef;

	string::iterator it = it_X;
	if(*it != 'X')
	{
		cout << "[ Error in \"double deal_befor_X(string P_str, string::iterator it_X)\":" << endl
			 << "  *it_X must be 'X'! ]" << endl;
		exit(-1);
	}

	it--;
	if(*it == '*')
	{
		it--;
		if(isNumber(*it))
		{
			Coef = num_from_end(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else if(*it == '+')
	{
		Coef = 1;
	}
	else if(*it == '-')
	{
		Coef = -1;
	}
	else if(*it == '\0')
	{
		Coef = 1;
	}
	else
	{
		read_error();
	}

	return Coef;
}

Term term_before_plus(string& P_str, string::iterator it_plus)
{

	double Coef;
	int Exp;

	string::iterator it = it_plus;
	if(*it != '+' && *it != '-')
	{
		cout << "[ Error in \"Term term_before_plus(string::it)\":" << endl
			 << "  *it must be '+' or '-' ! ]" << endl;
		exit(-1);
	}
	it--;
	if( isNumber(*it) )
	{
		double num = num_from_end(P_str, it);
		it = it_num_begin(P_str, it);
		it--;
		if(*it == '^')
		{
			Exp = (int)num;
			it--;
			if(*it == 'X')
			{
				Coef = coef_befor_X(P_str, it);
			}
			else
			{
				read_error();
			}
		}
		else if(*it == '+')
		{
			Exp = 0;
			Coef = num;
		}
		else if(*it == '-')
		{
			Exp = 0;
			Coef = -num;
		}
		else if(*it == '\0')
		{
			Exp = 0;
			Coef = num;
		}
		else
		{
			read_error();
		}
	}
	else if(*it == 'X')
	{
		Exp = 1;
		Coef = coef_befor_X(P_str, it);
	}
	else if(*it == '\0')
	{
		Coef = 0;
		Exp = 0;
	}

	return Term(Coef, Exp);
}

string::iterator it_num_end(string& P_str, string::iterator it)
{
	string::iterator it_end = it;
	if( !isNumber(*it_end) )
	{
		cout << "[ Error in \"string::iterator it_num_end(string P_str, string::iterator it)\":" << endl
			 << "  *it must be a number! ]" << endl;
		exit(-1);
	}

	while( isNumber(*it_end) )
	{
		it_end++;
	}
	if(*it_end == '.')
	{
		it_end++;
		if( isNumber(*it_end) )
		{
			while( isNumber(*it_end) )
			{
				it_end++;
			}
		}
		else
		{
			read_error();
		}
	}
	it_end--;

	return it_end;
}

double num_from_begin(string& P_str, string::iterator it_begin)
{
	double number;

	string::iterator it_end = it_num_end(P_str, it_begin);
	string number_str = P_str.substr( it_begin - P_str.begin(), it_end - P_str.begin() );
	
	stringstream ss;
	ss << number_str;
	ss >> number;
	return number;
}

int exp_after_X(string& P_str, string::iterator it_X)
{
	int Exp;

	string::iterator it = it_X;
	if(*it != 'X')
	{
		cout << "[ Error in \"int exp_after_X(string P_str, string::iterator it_X)\":" << endl
			 << "  *it_X must be 'X' ! ]" << endl;
		exit(-1);
	}
	it++;
	if(*it == '^')
	{
		it++;
		if( isNumber(*it) )
		{
			Exp = (int)num_from_begin(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else if(*it == '+' || *it == '-' || *it == '\0')
	{
		Exp = 1;
	}
	else
	{
		read_error();
	}

	return Exp;
}

Term term_after_plus(string& P_str, string::iterator it_plus)
{
	double Coef;
	int Exp;

	string::iterator it = it_plus;
	if(*it == '+')
	{
		it++;
		if( isNumber(*it) )
		{
			Coef = num_from_begin(P_str, it);
			it = it_num_end(P_str, it);
			it++;
			if(*it == '*')
			{
				it++;
				if(*it == 'X')
				{
					Exp = exp_after_X(P_str, it);
				}
				else
				{
					read_error();
				}
			}
			else if(*it == '+' || *it == '-')
			{
				Exp = 0;
			}
			else if(*it == '\0')
			{
				Exp = 0;
			}
			else
			{
				read_error();
			}
		}
		else if(*it == 'X')
		{
			Coef = 1;
			Exp = exp_after_X(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else if(*it == '-')
	{
		it++;
		if( isNumber(*it) )
		{
			Coef = -num_from_begin(P_str, it);
			
			it = it_num_end(P_str, it);
			it++;
			if(*it == '*')
			{
				it++;
				if(*it == 'X')
				{

					Exp = exp_after_X(P_str, it);

				}
				else
				{
					read_error();
				}
			}
			else if(*it == '+' || *it == '-')
			{
				Exp = 0;
			}
			else if(*it == '\0')
			{
				Exp = 0;
			}
			else
			{
				read_error();
			}
		}
		else if(*it == 'X')
		{
			Coef = -1;
			Exp = exp_after_X(P_str, it);
		}
		else
		{
			read_error();
		}
	}
	else
	{
		cout << "[ Error in \"Term term_after_plus(string P_str, string::iterator it_plus)\":" << endl
			 << "  *it_plus must be '+' or '-' ! ]" << endl;
		exit(-1);
	}

	return Term(Coef, Exp);
}

Poly Poly::read(string& P_str)
{
	this->clear();
	delete_space(P_str);
	
	int n_plus = 0;
	int Exp, Coef;
	for(string::iterator it = P_str.begin(); it != P_str.end(); it++)
	{
		if(*it == '+' || *it == '-')
		{
			n_plus++;
			if(n_plus == 1)
			{
				Term term1 = term_before_plus(P_str, it);
				Term term2 = term_after_plus(P_str, it);
				this->newTerm(term1.coef, term1.exp);
				this->newTerm(term2.coef, term2.exp);
			}
			else
			{
				Term term = term_after_plus(P_str, it);
				this->newTerm(term.coef, term.exp);
			}
		}
	}
	
	if(n_plus == 0)
	{
		P_str = "+" + P_str;
		this->read(P_str);
	}
	return *this;
}

Poly Poly::diff()const
{
	Poly Result = *this;
	LinkNode<Term>* p = (Result.termArray).begin();
	for(; p->link != NULL; p = p->link)
	{
		(p->data).coef = (p->data).coef * (p->data).exp;
		(p->data).exp  = (p->data).exp - 1;
	}
	(Result.termArray).erase(p);
	return Result;
}