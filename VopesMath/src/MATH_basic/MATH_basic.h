#pragma once
#ifdef __cplusplus         // 一般用于将C++代码以标准C形式输出（即以C的形式被调用）
extern"C" {                 // 告诉编译器下面大括号括起来的函数是c语言函数（因为c++和c语言对函数的编译转换不一样，主要是c++中存在重载）
#endif

	__declspec(dllexport)double add(double a, double b);      // __declspec(dllexport)声明导出该函数供外部调用

	__declspec(dllexport) double subtruct(double a, double b); // __stdcall是Windows API默认的函数调用协议，函数采用从右到左的压栈方式，自己在退出时清空堆栈，也可以不使用

	__declspec(dllexport)double sum(double a[]);
	__declspec(dllexport)double *diff(double a[], int length);
	__declspec(dllexport)double division_left(double a, double b);
	__declspec(dllexport)double division_right(double a, double b);
	__declspec(dllexport)double power(double a, double b);
	__declspec(dllexport)int mod(int a, int b);
	__declspec(dllexport)int fix(double a);
	__declspec(dllexport)int sign(double a);
	__declspec(dllexport)double csc(double a);
	__declspec(dllexport)double acsc(double a);
	__declspec(dllexport)double csch(double a);
	__declspec(dllexport)double acsch(double a);
	__declspec(dllexport)double sec(double a);
	__declspec(dllexport)double asec(double a);
	__declspec(dllexport)double sech(double a);
	__declspec(dllexport)double asech(double a);
	__declspec(dllexport)double cot(double a);
	__declspec(dllexport)double acot(double a);
	__declspec(dllexport)double coth(double a);
	__declspec(dllexport)double acoth(double a);
	__declspec(dllexport)double deg2rad(double a);
	__declspec(dllexport)double rad2deg(double a);
	__declspec(dllexport)int factor(int a, int *c);//输入值，储存质因数的数组，返回质因数的个数
	__declspec(dllexport)int factorial(int n, int *re);//返回结果的位数，输入需要阶乘的数和保存结果的数组
	__declspec(dllexport)int gcd(int m, int n);
	__declspec(dllexport)int isprime(int num);
	__declspec(dllexport)int lcm(int m, int n);
	__declspec(dllexport)int nchoosek(int x, int y);
	__declspec(dllexport)int primes(int n, int *res);//输入值，储存质数的数组，输出质数的个数
	__declspec(dllexport)double randn(double i, double j);
	__declspec(dllexport)double integral(double(*f)(double), double min, double max); //输入函数（c编写），最小值，最大值
#ifdef __cplusplus
}
#endif