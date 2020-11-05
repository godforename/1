// MATH_basic.cpp : 定义 DLL 应用程序的导出函数。
//

#include<iostream>
#include "stdafx.h"
#include "MATH_basic.h"
#include<math.h>
#include<cmath>
#define PI acos(-1)

//加法
int add(int a, int b)
{
	return a + b;
}
double add(double a, double b)
{
	return a + b;
}

//数组元素和
int sum(int a[])
{
	int sum=0;
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
		sum += a[i];
	return sum;
}
double sum(double a[])
{
	double sum = 0;
	for (int i = 0; i < (sizeof(a) / sizeof(a[0])); i++)
		sum += a[i];
	return sum;
}

//减法
int subtruct(int a, int b)
{
	return a - b;
}
double subtruct(double a, double b)
{
	return a - b;
}

//差分和近似导数
int *diff(int a[], int length)
{
	int *diff = new int[length - 1];
	int *r = diff;
	for (int i = 0; i<length - 1; i++) {
		*diff = a[i + 1] - a[i];
		diff++;
	}
	return r;
}
double *diff(double a[],int length)
{
	double *diff = new double[length - 1];
	double *r = diff;
	for (int i = 0; i<length - 1; i++) {
		*diff = a[i + 1] - a[i];
		diff++;
	}
	return r;
}

//左除
double division_left(double a, double b)
{
	return a / b;
}

//右除
double division_right(double a, double b)
{
	return b / a;
}

//幂
int power(int a, int b)
{
	int power = 1;
	for (int i = 0; i < b; i++) {
		power *= a;
	}
	return power;
}
double power(double a, double b)
{
	double power = 1;
	for (int i = 0; i < b; i++) {
		power *= a;
	}
	return power;
}

//取模
int mod(int a, int b)
{
	return a - (a / b*b);
}

//朝零四舍五入
int fix(double a)
{
	int fix = a;
	return fix;
}

//Sign 函数（符号函数）
int sign(double a)
{
	if (a > 0)return 1;
	if (a < 0)return -1;
	if (a = 0)return 0;
}

//输入角的余割（以弧度为单位）
double csc(double a)
{
	return 1 / sin(a);
}

//反余割（以弧度为单位）
double acsc(double a)
{
	return atan(sign(a) / sqrt(a * a - 1));
}

//双曲余割
double csch(double a)
{
	return  2 / (exp(a) - exp(-a));
}

//反双曲余割
double acsch(double a)
{
	return log((sign(a) * sqrt(a * a + 1) + 1) / a);
}

//角的正割（以弧度为单位）
double sec(double a)
{
	return 1 / cos(a);
}

//反正割（以弧度为单位）
double asec(double a)
{
	return 2 * atan(1) - atan(sign(a) / sqrt(a * a - 1));
}

//双曲正割
double sech(double a)
{
	return 2 / (exp(a) + exp(-a));
}

//反双曲正割
double asech(double a)
{
	return log((sqrt(-a * a + 1) + 1) / a);
}

//角的余切（以弧度为单位）
double cot(double a)
{
	return 1 / tan(a);
}

//反余切（以弧度为单位）
double acot(double a)
{
	return 2 * atan(1) - atan(a);
}

//双曲余切
double coth(double a)
{
	return (exp(a) + exp(-a)) / (exp(a) - exp(-a));
}

//反双曲余切
double acoth(double a)
{
	return log((a + 1) / (a - 1)) / 2;
}

//将角从以度为单位转换为以弧度为单位
double deg2rad(double a)
{
	return a / 180 * PI;
}

//将角的单位从弧度转换为度
double rad2deg(double a)
{
	return a / PI * 180;
}

//质因数
int factor(int a, int *c)//输入值，储存质因数的数组，返回质因数的个数
{
	int b[10];
	int n = 0;
	for (int i = 2; i <= a / 2; i++) {
		if (a%i == 0) {
			*(b + n) = i;
			n++;
		}
	}
	for (int i = 0; i < n; i++) {
		c[i] = b[i];
	}
	return n;
}

//输入的阶乘
int factorial(int n, int *re)//返回结果的位数，输入需要阶乘的数和保存结果的数组
{
	int a[20001];
	int temp, digit, i, j = 0;//temp每次的得数   digit每次得数的位数  
	a[0] = 1;//从1开始乘 
	digit = 1;//位数从第一位开始 
	for (i = 2; i <= n; i++)
	{
		int num = 0;
		for (j = 0; j < digit; j++)
		{
			temp = a[j] * i + num;//将一个数的每一位数都分别乘以i， 
			a[j] = temp % 10;//将一个数的每一位数利用数组进行储存
			num = temp / 10;
		}
		while (num)//判断退出循环后，num的值是否为0 
		{
			a[digit] = num % 10;//继续储存 
			num = num / 10;
			digit++;
		}
	}
	for (i = digit - 1; i >= 0; i--) {//倒序输出每一位 
		*re = a[i];
		re++;
	}
	return digit;
}

//最大公约数
int gcd(int m,int n)
{
	return n == 0 ? m : gcd(n, m % n);
}

//确定为质数
int isprime(int num)
{
	if (num <= 3) {
		return num > 1;
	}
	// 不在6的倍数两侧的一定不是质数
	if (num % 6 != 1 && num % 6 != 5) {
		return false;
	}
	int a = sqrt(num);
	for (int i = 5; i <= a; i += 6) {
		if (num % i == 0 || num % (i + 2) == 0) {
			return false;
		}
	}
	return true;
}

//最小公倍数
int lcm(int m, int n)
{
	int a, b, c;
	a = m;
	b = n;
	c = a%b;
	while (c != 0)
	{ 
		a = b; b = c; c = a%b;
	} 
	return m*n / b;
}

//二项式系数或所有组合
int nchoosek(int x, int y)
{
	int a = y;
	int b = x%y;
	int tmp;
	while (b != 0) {
		tmp = a;
		a = b;
		b = tmp%a;
	}
	return a;
}

//小于等于输入值的质数
int primes(int n, int *res)//输入值，储存质数的数组，输出质数的个数
{
	//int num;
	bool m; //因为只有两种状态，改为bool类型 

			//考虑把下面的功能以函数形式实现 
	int count = 0;
	int len = 0;
	//cout<<"2"<<endl;
	++count;// "2" 直接算一个 
	res[0] = 2;
	//找出所有小于N的质数；
	for (int i = 3; i < n; i++) {
		m = true;
		for (int j = 0; j < count; j++) { //只用判断到sqrt(i)即可，时间快了很多 
			if (i % res[j] == 0) { //比i小的质数都不能整除即可，不用2~sqrt(i)所有的数；
								   //因为合数都能分解成质数 
								   //cout<<"count；"<<count<<endl; 
				m = false;
				break; //注意 这里当有一个可以整除就代表
					   //不是质数了，这时就可以结束循环，判断下一个i了 
			}
		}
		if (m) {
			res[count] = i; //将满足条件的质数保存起来 
			count++;
			//cout<<i<<endl;
		}
	}
	return count;
}

//正态分布的随机数
double randn(double i, double j)
{
	double u1 = double(rand() % 1000) / 1000, u2 = double(rand() % 1000) / 1000, r;
	static unsigned int seed = 0;
	r = i + sqrt(j)*sqrt(-2.0*(log(u1) / log(exp(1.0))))*cos(2 * PI*u2);
	return r;	
}

//多项式积分
double integral(double(*f)(double), double min, double max) //输入函数（c编写），最小值，最大值
{
	double result = 0;
	const int N = 1000;
	double delta = (max - min) / N;
	for (double i = min + delta; i < max; i += delta)
	{
		result += f(min + i)*delta;
	}
	return result;
}