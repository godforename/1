#pragma once
#include<math.h>
#include<cmath>
struct term
{
	double coef;
	int exp;
	term *next;
};
#ifdef __cplusplus         // һ�����ڽ�C++�����Ա�׼C��ʽ���������C����ʽ�����ã�
extern"C" {                 // ���߱���������������������ĺ�����c���Ժ�������Ϊc++��c���ԶԺ����ı���ת����һ������Ҫ��c++�д������أ�
#endif

	__declspec(dllexport)void poly_read(term *t, char str0[]);//�ַ�����ȡ����ʽ    // __declspec(dllexport)���������ú������ⲿ����
	__declspec(dllexport)void new_term(term *t, int a, int b);//Ϊ����ʽ����a��ϵ����b�Ǵ���
	__declspec(dllexport)void poly_out(term *t);//�������ʽ
	__declspec(dllexport)term *poly_add(term *t1, term *t2);//����ʽ���
	__declspec(dllexport)term *poly_subtruct(term *t1, term *t2);//����ʽ���
	__declspec(dllexport)term *poly_Multiply(term *t1, term *t2);//����ʽ���
	__declspec(dllexport)term *poly_division(term *t1, term *t2);//����ʽ���
	__declspec(dllexport)term *poly_mod(term *t1, term *t2);//����ʽȡģ
	__declspec(dllexport)term *poly_gcd(term *t1, term *t2);//����ʽ��С����ʽ
	__declspec(dllexport)term *poly_lcm(term *t1, term *t2);//����ʽ���Լʽ
	__declspec(dllexport)int poly_deg(term *t);//����ʽ����
	__declspec(dllexport)int poly_miancoef(term *t);//����ʽ��ϵ��
	__declspec(dllexport)int poly_coef(term *t, int a);//����ʽϵ��
	__declspec(dllexport)term *poly_com(term *t1, term *t2);//���϶���ʽ
	__declspec(dllexport)term *poly_diff(term *t);//����ʽ��
	__declspec(dllexport)void poly_clear(term *t);//��ն���ʽ
	__declspec(dllexport)void poly_equal(term *t1, term *t2);//����ʽ��ֵ


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
	__declspec(dllexport)void poly_read2(double a, double b, const char* str);
#ifdef __cplusplus
}
#endif