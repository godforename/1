#pragma once
#ifdef __cplusplus         // һ�����ڽ�C++�����Ա�׼C��ʽ���������C����ʽ�����ã�
extern"C" {                 // ���߱���������������������ĺ�����c���Ժ�������Ϊc++��c���ԶԺ����ı���ת����һ������Ҫ��c++�д������أ�
#endif

	__declspec(dllexport)double add(double a, double b);      // __declspec(dllexport)���������ú������ⲿ����

	__declspec(dllexport) double subtruct(double a, double b); // __stdcall��Windows APIĬ�ϵĺ�������Э�飬�������ô��ҵ����ѹջ��ʽ���Լ����˳�ʱ��ն�ջ��Ҳ���Բ�ʹ��

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
	__declspec(dllexport)int factor(int a, int *c);//����ֵ�����������������飬�����������ĸ���
	__declspec(dllexport)int factorial(int n, int *re);//���ؽ����λ����������Ҫ�׳˵����ͱ�����������
	__declspec(dllexport)int gcd(int m, int n);
	__declspec(dllexport)int isprime(int num);
	__declspec(dllexport)int lcm(int m, int n);
	__declspec(dllexport)int nchoosek(int x, int y);
	__declspec(dllexport)int primes(int n, int *res);//����ֵ���������������飬��������ĸ���
	__declspec(dllexport)double randn(double i, double j);
	__declspec(dllexport)double integral(double(*f)(double), double min, double max); //���뺯����c��д������Сֵ�����ֵ
#ifdef __cplusplus
}
#endif