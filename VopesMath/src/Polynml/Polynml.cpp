// Polynml.cpp : 定义 DLL 应用程序的导出函数。
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
void poly_read(term *t, char str0[])//字符串读取多项式
{
	string str = str0;
	Poly p = term_2_Poly(t);
	p.read(str);
}
void new_term(term *t, int a, int b)//为多项式添加项，a是系数，b是次数
{
	Poly p = term_2_Poly(t);
	p.newTerm(a, b);
}
void poly_out(term *t)//输出多项式
{
	Poly p = term_2_Poly(t);
	cout << p;
}
term *poly_add(term *t1, term *t2)//多项式相加
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1 + p2);
}
term *poly_subtruct(term *t1, term *t2)//多项式相减
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1 - p2);
}
term *poly_Multiply(term *t1, term *t2)//多项式相乘
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1*p2);
}
term *poly_division(term *t1, term *t2)//多项式相除
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1 / p2);
}
term *poly_mod(term *t1, term *t2)//多项式取模
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1%p2);
}
term *poly_gcd(term *t1, term *t2)//多项式最小公倍式
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(gcd(p1, p2));
}
term *poly_lcm(term *t1, term *t2)//多项式最大公约式
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(lcm(p1, p2));
}
int poly_deg(term *t)//多项式次数
{
	Poly p1 = term_2_Poly(t);
	return p1.deg();
}
int poly_miancoef(term *t)//多项式主系数
{
	Poly p = term_2_Poly(t);
	return p.mainCoef();
}
int poly_coef(term *t, int a)//多项式系数
{
	Poly p = term_2_Poly(t);
	return p.coef(a);
}
Complex poly_eval(term *t, Complex a)//多项式在某一点的值
{
	Poly p = term_2_Poly(t);
	return p.eval(a);
}
Complex poly_eval(term *t, double a)
{
	Poly p = term_2_Poly(t);
	return p.eval(a);
}
term *poly_com(term *t1, term *t2)//复合多项式
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	return Poly_2_term(p1.com(p2));
}
term *poly_diff(term *t)//多项式求导
{
	Poly p = term_2_Poly(t);
	return Poly_2_term(p.diff());
}
void poly_clear(term *t)//清空多项式
{
	Poly p = term_2_Poly(t);
	p.clear();
}
void poly_equal(term *t1, term *t2)//多项式赋值
{
	Poly p1 = term_2_Poly(t1);
	Poly p2 = term_2_Poly(t2);
	p1 = p2;
}

//例如
/*
* 函数名：poly_read2
* 功能：实现复数的读入操作
* 参数：a为复数的实部
*       b为复数的虚部
*       str为输入...
* 返回值：无
* 错误：
*       (1)...
*       (2)...
*/
void poly_read2(double a, double b, const char* str) {
	//....
}