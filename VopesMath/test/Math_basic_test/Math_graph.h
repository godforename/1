#pragma once
#include "stdafx.h"
#include "Graph.h"
#include"Dijkstra.h"
#include"Kruskal.h"
const int maxSize = 40;
#ifdef __cplusplus         // 一般用于将C++代码以标准C形式输出（即以C的形式被调用）
extern"C" {                 // 告诉编译器下面大括号括起来的函数是c语言函数（因为c++和c语言对函数的编译转换不一样，主要是c++中存在重载）
#endif
	__declspec(dllexport)void out_put_graph(Graphlnk<char, int> G);      // __declspec(dllexport)声明导出该函数供外部调用
	__declspec(dllexport)void get_value(Graphlnk<char, int> G, char e1);
	__declspec(dllexport)void get_weight(Graphlnk<char, int> G, int v1, int v2);
	__declspec(dllexport)void insert_Vertex(Graphlnk<char, int> G, const class T& vertex);
	__declspec(dllexport)void insert_Edge(Graphlnk<char, int> G, int v1, int v2, class E weight);
	__declspec(dllexport)void remove_Vertex(Graphlnk<char, int> G, int v);
	__declspec(dllexport)void remove_Edge(Graphlnk<char, int> G, int v1, int v2);
	__declspec(dllexport)void get_FirstNeighbor(Graphlnk<char, int> G, int v);
	__declspec(dllexport)void get_NextNeighbor(Graphlnk<char, int> G, int v, int w);
	__declspec(dllexport)void get_VertexPos(Graphlnk<char, int> G, const class T vertex);
	__declspec(dllexport)void number_Of_Vertices(Graphlnk<char, int> G);
	__declspec(dllexport)void DFS_(Graphlnk<char, int> G, const class T& v);
	__declspec(dllexport)void BFS_(Graphlnk<char, int> G, const class T& v);
	__declspec(dllexport)void Kruscal_(Graphlnk<char, int> G, MinSpanTree<char, int> MST);
	__declspec(dllexport)void print_MST(Graphlnk<char, int> G, MinSpanTree<char, int> MST);
	__declspec(dllexport)void Shortest_Path(Graphlnk<char, int> G, int dist[maxSize], int path[maxSize]);

#ifdef __cplusplus
}
#endif