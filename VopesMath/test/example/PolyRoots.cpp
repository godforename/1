#include "poly.h"

int main()
{
	Poly P;
	cout << endl;
	cout << "Please input your polynormial P:" << endl
		 << "P(X) = ";
	string P_str;
	getline(cin, P_str);
	P.read(P_str);
	cout << endl << "The polynormial that you input is:" << endl
		 << "P(X) = " << P << endl << endl;

//-----------------------------------------------------------------

	vector<Complex> Roots = P.roots();

	if(P.deg() != 0)
	{
		cout << "The roots of polynormial P(X) are:" << endl;
	}

	int n = Roots.size();
	for(int i = 0; i < n; i++)
	{
		cout << "X[" << i+1 << "] = " << Roots[i] << endl;
	}
	cout << endl;

	return 0;
}