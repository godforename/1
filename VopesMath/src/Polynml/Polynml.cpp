// Polynml.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include<math.h>
#include<cmath>
#include"poly.h"
struct term
{
	double coef;
	int exp;
	term *next;
};
Poly term_2_Poly(term *t)
{
	Poly P;
	while (t != NULL)
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
void poly_read(term *t, char str0[])//�ַ�����ȡ����ʽ
{
	string str = str0;
	Poly p = term_2_Poly(t);
	p.read(str);
}
void new_term(term *t, int a, int b)//Ϊ����ʽ����a��ϵ����b�Ǵ���
{
	Poly p = term_2_Poly(t);
	p.newTerm(a, b);
}
void poly_out(term *t)//�������ʽ
{
	Poly p = term_2_Poly(t);
	cout << p;
}
term *poly_add(term *t1, term *t2)//����ʽ���
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1 + p2);
}
term *poly_subtruct(term *t1, term *t2)//����ʽ���
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1 - p2);
}
term *poly_Multiply(term *t1, term *t2)//����ʽ���
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1*p2);
}
term *poly_division(term *t1, term *t2)//����ʽ���
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1 / p2);
}
term *poly_mod(term *t1, term *t2)//����ʽȡģ
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1%p2);
}
term *poly_gcd(term *t1, term *t2)//����ʽ��С����ʽ
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(gcd(p1, p2));
}
term *poly_lcm(term *t1, term *t2)//����ʽ���Լʽ
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(lcm(p1, p2));
}
int poly_deg(term *t)//����ʽ����
{
	Poly p1 = term_2_Poly(t);
	return p1.deg();
}
int poly_miancoef(term *t)//����ʽ��ϵ��
{
	Poly p = term_2_Poly(t);
	return p.mainCoef();
}
int poly_coef(term *t, int a)//����ʽϵ��
{
	Poly p = term_2_Poly(t);
	return p.coef(a);
}
Complex poly_eval(term *t, Complex a)//����ʽ��ĳһ���ֵ
{
	Poly p = term_2_Poly(t);
	return p.eval(a);
}
Complex poly_eval(term *t, double a)
{
	Poly p = term_2_Poly(t);
	return p.eval(a);
}
term *poly_com(term *t1, term *t2)//���϶���ʽ
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1.com(p2));
}
term *poly_diff(term *t)//����ʽ��
{
	Poly p = term_2_Poly(t);
	return Poly_2_term(p.diff());
}
void poly_clear(term *t)//��ն���ʽ
{
	Poly p = term_2_Poly(t);
	p.clear();
}
void poly_equal(term *t1, term *t2)//����ʽ��ֵ
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	p1 = p2;
}

//����
/*
* ��������poly_read2
* ���ܣ�ʵ�ָ����Ķ������
* ������aΪ������ʵ��
*       bΪ�������鲿
*       strΪ����...
* ����ֵ����
* ����
*       (1)...
*       (2)...
*/
void poly_read2(double a, double b, const char* str) {
	//....
}