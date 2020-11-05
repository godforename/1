// Math_basic_test.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include<iostream>
#include<string>
#include"MATH_basic.h"
//#include"Math_graph.h"
#include"polynml.h"
using namespace std;
int main()
{
	cout << csc(1.5) << endl;
	term *t=NULL;
	new_term(t, 1, 2);
	cout << t->coef << endl;
	system("pause");
    return 0;
}