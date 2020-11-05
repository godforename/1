#ifndef Kruskal_h
#define Kruskal_h
#include <iostream>
#include <queue>
#include "UFSets.h"
#include "Graph.h"
using namespace std;

const int DefaultSize = 40; // 默认个数

template <class T, class E>
struct MSTEdgeNode { // 最小生成树边结点的类声明
	int head, tail; // 两顶点位置
	E weight; // 边上权值
	MSTEdgeNode() :tail(-1), head(-1), weight(0) {}; // 构造函数
};

template <class T, class E>
bool operator<(const MSTEdgeNode<T, E> &a, const MSTEdgeNode<T, E> &b) {
	if (a.weight > b.weight)
		return true;
	return false;
}

template <class T, class E>
class MinSpanTree { // 最小生成树的类定义
public:
	MinSpanTree(int sz = DefaultSize - 1) { // 构造函数
		maxSize = sz;
		currentSize = 0;
		edgeValue = new MSTEdgeNode<T, E>[sz];
	}
	~MinSpanTree() { // 析构函数
		delete[]edgeValue; // 释放空间
	}
	bool Insert(MSTEdgeNode<T, E> &item); // 插入
	bool Kruscal(Graphlnk<T, E> &G); // Kruscal算法
	void printMST(Graphlnk<T, E> &G); // 打印最小生成树
private:
	int maxSize, currentSize; // 数组的最大元素个数和当前个数
	MSTEdgeNode<T, E> *edgeValue; // 用边值数组表示树
};

// 插入
template <class T, class E>
bool MinSpanTree<T, E>::Insert(MSTEdgeNode<T, E> &item) {
	if (currentSize == maxSize - 1) {
		cout << "已超出数组的存储范围！" << endl;
		return false;
	}

	edgeValue[currentSize] = item;
	currentSize++;
	return true;
}

// Kruscal算法
template <class T, class E>
bool MinSpanTree<T, E>::Kruscal(Graphlnk<T, E> &G) {
	MSTEdgeNode<T, E> ed; // 边结点辅助单元
	int u, v, count;
	int n = G.numberOfVertices(); // 图的顶点数
	E weight; // 权值
	priority_queue<MSTEdgeNode<T, E>> H; // 最小堆，关键码类型为E
	UnionFindSets F(n); // 并查集


						// 1.把边全部存到最小堆中
	for (u = 0; u < n; u++) {
		for (v = u + 1; v < n; v++) {
			weight = G.getWeight(u, v);
			if (weight > 0 && weight < G.maxValue) { // 两个顶点存在边
				ed.tail = u;
				ed.head = v;
				ed.weight = weight;
				H.push(ed); // 插入最小堆
			}
		}
	}
	count = 1; // 最小生成树加入边数计数
	while (count < n && H.empty() == false) { // n个顶点，反复执行，取n-1条边;并且最小堆不为空，即还有边时
		ed = H.top(); // 从最小堆中退出具最小权值的边ed
		H.pop();
		u = F.Find(ed.tail); // 取两顶点所在集合的根u和v
		v = F.Find(ed.head);
		if (u != v) { // 不是同一集合，说明不连通
			F.Union(u, v); // 合并，连通它们
			Insert(ed); // 该边存入最小生成树
			count++;
		}
	}
	if (count < n) {
		cout << "不是最小生成树" << endl;
		return false;
	}
	return true; // 是最小生成树
}

// 打印最小生成树
template <class T, class E>
void MinSpanTree<T, E>::printMST(Graphlnk<T, E> &G) {
	int tail, head; // 顶点所在位置
	T e1, e2; // 两顶点
	E weight; //  权值

	for (int i = 0; i < currentSize; i++) {
		tail = edgeValue[i].tail; // 顶点所在位置
		head = edgeValue[i].head;
		e1 = G.getValue(tail); // 根据位置，取顶点对应的值
		e2 = G.getValue(head);
		weight = G.getWeight(tail, head); // 取权值
		cout << "(" << e1 << "," << e2 << "," << weight << ")" << endl;
	}
}
#endif /* Kruskal_h */