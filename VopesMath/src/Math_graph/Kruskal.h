#ifndef Kruskal_h
#define Kruskal_h
#include <iostream>
#include <queue>
#include "UFSets.h"
#include "Graph.h"
using namespace std;

const int DefaultSize = 40; // Ĭ�ϸ���

template <class T, class E>
struct MSTEdgeNode { // ��С�������߽���������
	int head, tail; // ������λ��
	E weight; // ����Ȩֵ
	MSTEdgeNode() :tail(-1), head(-1), weight(0) {}; // ���캯��
};

template <class T, class E>
bool operator<(const MSTEdgeNode<T, E> &a, const MSTEdgeNode<T, E> &b) {
	if (a.weight > b.weight)
		return true;
	return false;
}

template <class T, class E>
class MinSpanTree { // ��С���������ඨ��
public:
	MinSpanTree(int sz = DefaultSize - 1) { // ���캯��
		maxSize = sz;
		currentSize = 0;
		edgeValue = new MSTEdgeNode<T, E>[sz];
	}
	~MinSpanTree() { // ��������
		delete[]edgeValue; // �ͷſռ�
	}
	bool Insert(MSTEdgeNode<T, E> &item); // ����
	bool Kruscal(Graphlnk<T, E> &G); // Kruscal�㷨
	void printMST(Graphlnk<T, E> &G); // ��ӡ��С������
private:
	int maxSize, currentSize; // ��������Ԫ�ظ����͵�ǰ����
	MSTEdgeNode<T, E> *edgeValue; // �ñ�ֵ�����ʾ��
};

// ����
template <class T, class E>
bool MinSpanTree<T, E>::Insert(MSTEdgeNode<T, E> &item) {
	if (currentSize == maxSize - 1) {
		cout << "�ѳ�������Ĵ洢��Χ��" << endl;
		return false;
	}

	edgeValue[currentSize] = item;
	currentSize++;
	return true;
}

// Kruscal�㷨
template <class T, class E>
bool MinSpanTree<T, E>::Kruscal(Graphlnk<T, E> &G) {
	MSTEdgeNode<T, E> ed; // �߽�㸨����Ԫ
	int u, v, count;
	int n = G.numberOfVertices(); // ͼ�Ķ�����
	E weight; // Ȩֵ
	priority_queue<MSTEdgeNode<T, E>> H; // ��С�ѣ��ؼ�������ΪE
	UnionFindSets F(n); // ���鼯


						// 1.�ѱ�ȫ���浽��С����
	for (u = 0; u < n; u++) {
		for (v = u + 1; v < n; v++) {
			weight = G.getWeight(u, v);
			if (weight > 0 && weight < G.maxValue) { // ����������ڱ�
				ed.tail = u;
				ed.head = v;
				ed.weight = weight;
				H.push(ed); // ������С��
			}
		}
	}
	count = 1; // ��С�����������������
	while (count < n && H.empty() == false) { // n�����㣬����ִ�У�ȡn-1����;������С�Ѳ�Ϊ�գ������б�ʱ
		ed = H.top(); // ����С�����˳�����СȨֵ�ı�ed
		H.pop();
		u = F.Find(ed.tail); // ȡ���������ڼ��ϵĸ�u��v
		v = F.Find(ed.head);
		if (u != v) { // ����ͬһ���ϣ�˵������ͨ
			F.Union(u, v); // �ϲ�����ͨ����
			Insert(ed); // �ñߴ�����С������
			count++;
		}
	}
	if (count < n) {
		cout << "������С������" << endl;
		return false;
	}
	return true; // ����С������
}

// ��ӡ��С������
template <class T, class E>
void MinSpanTree<T, E>::printMST(Graphlnk<T, E> &G) {
	int tail, head; // ��������λ��
	T e1, e2; // ������
	E weight; //  Ȩֵ

	for (int i = 0; i < currentSize; i++) {
		tail = edgeValue[i].tail; // ��������λ��
		head = edgeValue[i].head;
		e1 = G.getValue(tail); // ����λ�ã�ȡ�����Ӧ��ֵ
		e2 = G.getValue(head);
		weight = G.getWeight(tail, head); // ȡȨֵ
		cout << "(" << e1 << "," << e2 << "," << weight << ")" << endl;
	}
}
#endif /* Kruskal_h */