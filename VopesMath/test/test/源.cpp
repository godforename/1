
#include<math.h>
#include<cmath>
#include"poly.h"
using namespace std;
#define PI acos(-1)
struct term
{
	double coef;
	int exp;
	term *next;
};
Poly term_2_Poly(term *t)
{
	Poly P;
	while (t!=NULL)
	{
		P.newTerm(t->coef, t->exp);
		t = t->next;
	}
	return P;
}
term *Poly_2_term(const Poly & P)
{
	term *head, *t;
	head = new term;
	t = head;
	LinkNode<Term>* p = (P.getTerms()).begin();
	for (; p != (P.getTerms()).end(); p = p->link) {
		term *s = new term;
		s->coef = p->data.coef;
		cout << s->coef << "	";
		s->exp = p->data.exp;
		t->next = s;
		t = s;
	}
	head = head->next;
	t->next = NULL;
	cout << endl;
	return head;
}
int main()
{
	Poly P1, P2;

	//�ɴ��ն�ֱ���������ʽ��
	// string P1_str;
	// getline(cin, P1_str);

	// P1.read(P1_str);
	//--------------------

	//�����������ķ�ʽ��������ʽ��
	P1.newTerm(1, 4);
	P1.newTerm(2, 3);
	P1.newTerm(-7, 2);
	P1.newTerm(-8, 1);
	P1.newTerm(3, 0);

	P2.newTerm(-2, 3);
	P2.newTerm(2, 2);
	P2.newTerm(3, 1);
	P2.newTerm(5, 0);
	//------------------------

	term *a = Poly_2_term(P1);
	term *b = Poly_2_term(P1);
	while (a!=NULL)
	{
		cout << a->coef << endl;
		a = a->next;
	}
	Poly P3 = term_2_Poly(b);
	cout << P3 << endl;
	//����ֱ�� cout �������ʽ��
	cout << "P1 = " << P1 << endl;
	cout << "P2 = " << P2 << endl;
	//-----------------------------

	cout << endl;

	//��ֱ���� + - * / % ���㣺
	cout << "P1 + P2 = " << P1 + P2 << endl;
	cout << "P1 - P2 = " << P1 - P2 << endl;
	cout << "P1 * P2 = " << P1 * P2 << endl;
	cout << "P1 / P2 = " << P1 / P2 << endl;
	cout << "P1 % P2 = " << P1 % P2 << endl;
	//--------------------------------------

	cout << endl;

	//��������������ʽ����С����ʽ�� �����ʽ��
	cout << "gcd(P1, P2) = " << gcd(P1, P2) << endl;
	cout << "lcm(P1, P2) = " << lcm(P1, P2) << endl;
	//----------------------------------------------

	cout << endl;

	//���Ի�ȡ����ʽ�ĸ�����Ϣ��
	cout << "P1 �Ĵ���Ϊ:\t\t\t" << P1.deg() << endl;
	cout << "P1 ����ϵ��Ϊ:\t\t\t" << P1.mainCoef() << endl;
	cout << "P1 �� 4 ����ϵ��Ϊ:\t\t" << P1.coef(4) << endl;
	cout << "P1 �� x = 3 + i*2 ����ȡֵΪ:\t" << P1.eval(Complex(3, 2)) << endl;
	cout << "P1 �� x = -2 ����ȡֵΪ:\t" << P1.eval(-2) << endl;
	cout << "P1 �� P2 �ĸ��϶���ʽ:" << endl << "P1(P2) = " << P1.com(P2) << endl;
	cout << "P1 �ĵ�����ʽΪ:" << endl << "P1\'(X) = " << P1.diff() << endl;
	//--------------------------------------------------------------------------

	//������ clear() ��ն���ʽ:
	P1.clear();
	//------------------------

	P1.newTerm(-3.75, 10);
	P1.newTerm(2.73, 9);
	P1.newTerm(-6.28, 8);
	P1.newTerm(4.57, 7);
	P1.newTerm(-7.62, 6);
	P1.newTerm(9.62, 5);
	P1.newTerm(9.12, 4);
	P1.newTerm(0.28, 3);
	P1.newTerm(3.45, 2);
	P1.newTerm(2.54, 1);
	P1.newTerm(-7.78, 0);

	cout << endl;

	//��ֱ�ӵȺŸ�ֵ:
	P2 = P1;
	cout << "���ڣ�P2 ��Ϊ:" << endl
		<< "P2 = " << P2 << endl;
	//-----------------------------

	cout << endl;

	//���������ʽ�ĸ�:
	vector<Complex> Roots = P2.roots();
	if (P2.deg() != 0)
	{
		cout << "����ʽ P2 �����и�Ϊ:" << endl << endl;
	}
	for (int i = 0; i < Roots.size(); i++)
	{
		cout << "X[" << i + 1 << "] = " << Roots[i] << endl;
	}

	system("pause");
	return 0;
}