#pragma once
#include<math.h>
#include<cmath>
struct term
{
	double coef;
	int exp;
	term *next;
};
#ifdef __cplusplus         // 一般用于将C++代码以标准C形式输出（即以C的形式被调用）
extern"C" {                 // 告诉编译器下面大括号括起来的函数是c语言函数（因为c++和c语言对函数的编译转换不一样，主要是c++中存在重载）
#endif

	__declspec(dllexport)void poly_read(term *t, char str0[]);//字符串读取多项式    // __declspec(dllexport)声明导出该函数供外部调用
	__declspec(dllexport)void new_term(term *t, int a, int b);//为多项式添加项，a是系数，b是次数
	__declspec(dllexport)void poly_out(term *t);//输出多项式
	__declspec(dllexport)term *poly_add(term *t1, term *t2);//多项式相加
	__declspec(dllexport)term *poly_subtruct(term *t1, term *t2);//多项式相减
	__declspec(dllexport)term *poly_Multiply(term *t1, term *t2);//多项式相乘
	__declspec(dllexport)term *poly_division(term *t1, term *t2);//多项式相除
	__declspec(dllexport)term *poly_mod(term *t1, term *t2);//多项式取模
	__declspec(dllexport)term *poly_gcd(term *t1, term *t2);//多项式最小公倍式
	__declspec(dllexport)term *poly_lcm(term *t1, term *t2);//多项式最大公约式
	__declspec(dllexport)int poly_deg(term *t);//多项式次数
	__declspec(dllexport)int poly_miancoef(term *t);//多项式主系数
	__declspec(dllexport)int poly_coef(term *t, int a);//多项式系数
	__declspec(dllexport)term *poly_com(term *t1, term *t2);//复合多项式
	__declspec(dllexport)term *poly_diff(term *t);//多项式求导
	__declspec(dllexport)void poly_clear(term *t);//清空多项式
	__declspec(dllexport)void poly_equal(term *t1, term *t2);//多项式赋值


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
	__declspec(dllexport)void poly_read2(double a, double b, const char* str);
#ifdef __cplusplus
}
#endif