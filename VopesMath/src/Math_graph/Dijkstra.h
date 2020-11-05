#ifndef Dijkstra_h
#define Dijkstra_h
#include "Graph.h"

template <class T, class E>
void ShortestPath(Graphlnk<T, E> &G, E dist[], int path[]) {
	int n = G.numberOfVertices(); // ������

	for (int i = 0; i < n; i++) {
		Dijkstra(G, i, dist, path); // ����Dijkstra����
		printShortestPath(G, i, dist, path); // ������·��
		cout << endl;
	}
}

// Dijkstra�㷨
template <class T, class E>
void Dijkstra(Graphlnk<T, E> &G, int v, E dist[], int path[]) {
	// Graph��һ����Ȩ����ͼ��dist[]�ǵ�ǰ�󵽵ĴӶ���v������j�����·�����ȣ�ͬʱ������
	// path[]����󵽵����·��
	int n = G.numberOfVertices(); // ������
	bool *s = new bool[n]; // ���·�����㼯
	int i, j, k, u;
	E w, min;

	for (i = 0; i < n; i++) {
		dist[i] = G.getWeight(v, i); // �����ʼ������ȡ(v,i)�ߵ�Ȩֵ
		s[i] = false; // �ö���δ�����ʹ�
		if (i != v && dist[i] < G.maxValue) // ����i��v���ڽӶ���
			path[i] = v; // ��v���Ϊ����i�����·��
		else
			path[i] = -1; // ˵���ö���i�붥��vû�б�����
	}
	s[v] = true; // ���Ϊ���ʹ�������v����s������
	dist[v] = 0;
	for (i = 0; i < n - 1; i++) {
		min = G.maxValue;
		u = v; // ѡ��������������s[]�еĶ���
			   // 1.��v��Ȩֵ��С��δ�����ʹ����ڽӶ���w,<v,w>
		for (j = 0; j < n; j++) {
			if (s[j] == false && dist[j] < min) {
				u = j;
				min = dist[j];
			}
		}
		s[u] = true; // ������u���뵽����s
		for (k = 0; k < n; k++) { // �޸�
			w = G.getWeight(u, k);
			if (s[k] == false && w < G.maxValue && dist[u] + w < dist[k]) {
				// ����kδ�����ʹ����Ҵ�v->u->k��·����v->k��·����
				dist[k] = dist[u] + w;
				path[k] = u; // �޸ĵ�k�����·��
			}
		}
	}
}

// ��path�����ȡ���·�����㷨
template <class T, class E>
void printShortestPath(Graphlnk<T, E> &G, int v, E dist[], int path[]) {
	int i, j, k, n = G.numberOfVertices();
	int *d = new int[n];

	cout << "�Ӷ���" << G.getValue(v) << "����������������·��Ϊ��" << endl;
	for (i = 0; i < n; i++) {
		if (i != v) { // ������Ƕ���v
			j = i;
			k = 0;
			while (j != v) {
				d[k++] = j;
				j = path[j];
			}
			cout << "����" << G.getValue(i) << "�����·��Ϊ��" << G.getValue(v);
			while (k > 0)
				cout << "->" << G.getValue(d[--k]);
			cout << "�����·������Ϊ��" << dist[i] << endl;
		}
	}
}

#endif /* Dijkstra_h */