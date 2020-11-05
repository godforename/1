// Math_graph.cpp : ���� DLL Ӧ�ó���ĵ���������
//

#include "stdafx.h"
#include "Graph.h"
#include"Dijkstra.h"
#include"Kruskal.h"

const int maxSize = 40;
void out_put_graph(Graphlnk<char, int> G)// �������ͼ�е����ж���ͱ���Ϣ
{
	G.outputGraph();
}
void get_value(Graphlnk<char, int> G,char e1)// ȡλ��Ϊi�Ķ����е�ֵ
{
	G.getValue(G.getFirstNeighbor(G.getVertexPos(e1)));
}
void get_weight(Graphlnk<char, int> G, int v1, int v2)//���رߣ�v1�� v2���ϵ�Ȩֵ
{
	G.getWeight(v1, v2);
}
template <class T, class E>
void insert_Vertex(Graphlnk<char, int> G, const T& vertex)// ���붥��
{
	G.insertVertex(vertex);
}
template <class T, class E>
void insert_Edge(Graphlnk<char, int> G, int v1, int v2, E weight)// �����
{
	G.insertEdge(v1, v2, weight);
}
template <class T, class E>
void remove_Vertex(Graphlnk<char, int> G, int v)// ����ͼɾ������
{
	G.removeVertex(v);
}
template <class T, class E>
void remove_Edge(Graphlnk<char, int> G, int v1, int v2)// ɾ����
{
	G.removeEdge(v1, v2);
}
template <class T, class E>
void get_FirstNeighbor(Graphlnk<char, int> G, int v)// ȡ����v�ĵ�һ���ڽӶ���
{
	G.getFirstNeighbor(v);
}
template <class T, class E>
void get_NextNeighbor(Graphlnk<char, int> G, int v, int w)// ȡ����v���ڽӶ���w����һ�ڽӶ���
{
	G.getNextNeighbor(v, w);
}
template <class T, class E>
void get_VertexPos(Graphlnk<char, int> G, const T vertex)// ��������vertex��ͼ�е�λ��
{
	G.getVertexPos(vertex);
}
void number_Of_Vertices(Graphlnk<char, int> G)// ��ǰ������
{
	G.numberOfVertices();
}
template <class T, class E>
void DFS_(Graphlnk<char, int> G, const T& v)// �����������
{
	G.DFS(v);
}
template <class T, class E>
void BFS_(Graphlnk<char, int> G, const T& v)// �����������
{
	G.BFS(v);
}
void Kruscal_(Graphlnk<char, int> G, MinSpanTree<char, int> MST)//����Kruscal����������С������
{
	MST.Kruscal(G);
}
void print_MST(Graphlnk<char, int> G, MinSpanTree<char, int> MST)//��ӡ��С������
{
	MST.printMST(G);
}
void Shortest_Path(Graphlnk<char, int> G, int dist[maxSize],int path[maxSize])//�����ж���֮������·��
{
	ShortestPath(G, dist, path);
}