// MATH_basic.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include<iostream>
#include "stdafx.h"
#include "MATH_basic.h"
#include<math.h>
#include<cmath>
#define PI acos(-1)

//�ӷ�
int add(int a, int b)
{
	return a + b;
}
double add(double a, double b)
{
	return a + b;
}

//����Ԫ�غ�
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

//����
int subtruct(int a, int b)
{
	return a - b;
}
double subtruct(double a, double b)
{
	return a - b;
}

//��ֺͽ��Ƶ���
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

//���
double division_left(double a, double b)
{
	return a / b;
}

//�ҳ�
double division_right(double a, double b)
{
	return b / a;
}

//��
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

//ȡģ
int mod(int a, int b)
{
	return a - (a / b*b);
}

//������������
int fix(double a)
{
	int fix = a;
	return fix;
}

//Sign ���������ź�����
int sign(double a)
{
	if (a > 0)return 1;
	if (a < 0)return -1;
	if (a = 0)return 0;
}

//����ǵ����Ի���Ϊ��λ��
double csc(double a)
{
	return 1 / sin(a);
}

//�����Ի���Ϊ��λ��
double acsc(double a)
{
	return atan(sign(a) / sqrt(a * a - 1));
}

//˫�����
double csch(double a)
{
	return  2 / (exp(a) - exp(-a));
}

//��˫�����
double acsch(double a)
{
	return log((sign(a) * sqrt(a * a + 1) + 1) / a);
}

//�ǵ�����Ի���Ϊ��λ��
double sec(double a)
{
	return 1 / cos(a);
}

//������Ի���Ϊ��λ��
double asec(double a)
{
	return 2 * atan(1) - atan(sign(a) / sqrt(a * a - 1));
}

//˫������
double sech(double a)
{
	return 2 / (exp(a) + exp(-a));
}

//��˫������
double asech(double a)
{
	return log((sqrt(-a * a + 1) + 1) / a);
}

//�ǵ����У��Ի���Ϊ��λ��
double cot(double a)
{
	return 1 / tan(a);
}

//�����У��Ի���Ϊ��λ��
double acot(double a)
{
	return 2 * atan(1) - atan(a);
}

//˫������
double coth(double a)
{
	return (exp(a) + exp(-a)) / (exp(a) - exp(-a));
}

//��˫������
double acoth(double a)
{
	return log((a + 1) / (a - 1)) / 2;
}

//���Ǵ��Զ�Ϊ��λת��Ϊ�Ի���Ϊ��λ
double deg2rad(double a)
{
	return a / 180 * PI;
}

//���ǵĵ�λ�ӻ���ת��Ϊ��
double rad2deg(double a)
{
	return a / PI * 180;
}

//������
int factor(int a, int *c)//����ֵ�����������������飬�����������ĸ���
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

//����Ľ׳�
int factorial(int n, int *re)//���ؽ����λ����������Ҫ�׳˵����ͱ�����������
{
	int a[20001];
	int temp, digit, i, j = 0;//tempÿ�εĵ���   digitÿ�ε�����λ��  
	a[0] = 1;//��1��ʼ�� 
	digit = 1;//λ���ӵ�һλ��ʼ 
	for (i = 2; i <= n; i++)
	{
		int num = 0;
		for (j = 0; j < digit; j++)
		{
			temp = a[j] * i + num;//��һ������ÿһλ�����ֱ����i�� 
			a[j] = temp % 10;//��һ������ÿһλ������������д���
			num = temp / 10;
		}
		while (num)//�ж��˳�ѭ����num��ֵ�Ƿ�Ϊ0 
		{
			a[digit] = num % 10;//�������� 
			num = num / 10;
			digit++;
		}
	}
	for (i = digit - 1; i >= 0; i--) {//�������ÿһλ 
		*re = a[i];
		re++;
	}
	return digit;
}

//���Լ��
int gcd(int m,int n)
{
	return n == 0 ? m : gcd(n, m % n);
}

//ȷ��Ϊ����
int isprime(int num)
{
	if (num <= 3) {
		return num > 1;
	}
	// ����6�ı��������һ����������
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

//��С������
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

//����ʽϵ�����������
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

//С�ڵ�������ֵ������
int primes(int n, int *res)//����ֵ���������������飬��������ĸ���
{
	//int num;
	bool m; //��Ϊֻ������״̬����Ϊbool���� 

			//���ǰ�����Ĺ����Ժ�����ʽʵ�� 
	int count = 0;
	int len = 0;
	//cout<<"2"<<endl;
	++count;// "2" ֱ����һ�� 
	res[0] = 2;
	//�ҳ�����С��N��������
	for (int i = 3; i < n; i++) {
		m = true;
		for (int j = 0; j < count; j++) { //ֻ���жϵ�sqrt(i)���ɣ�ʱ����˺ܶ� 
			if (i % res[j] == 0) { //��iС�������������������ɣ�����2~sqrt(i)���е�����
								   //��Ϊ�������ֽܷ������ 
								   //cout<<"count��"<<count<<endl; 
				m = false;
				break; //ע�� ���ﵱ��һ�����������ʹ���
					   //���������ˣ���ʱ�Ϳ��Խ���ѭ�����ж���һ��i�� 
			}
		}
		if (m) {
			res[count] = i; //������������������������ 
			count++;
			//cout<<i<<endl;
		}
	}
	return count;
}

//��̬�ֲ��������
double randn(double i, double j)
{
	double u1 = double(rand() % 1000) / 1000, u2 = double(rand() % 1000) / 1000, r;
	static unsigned int seed = 0;
	r = i + sqrt(j)*sqrt(-2.0*(log(u1) / log(exp(1.0))))*cos(2 * PI*u2);
	return r;	
}

//����ʽ����
double integral(double(*f)(double), double min, double max) //���뺯����c��д������Сֵ�����ֵ
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