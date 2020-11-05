// Math_graph.cpp : 定义 DLL 应用程序的导出函数。
//

#include "stdafx.h"
#include "Graph.h"
#include"Dijkstra.h"
#include"Kruskal.h"

const int maxSize = 40;
void out_put_graph(Graphlnk<char, int> G)// 输出有向图中的所有顶点和边信息
{
	G.outputGraph();
}
void get_value(Graphlnk<char, int> G,char e1)// 取位置为i的顶点中的值
{
	G.getValue(G.getFirstNeighbor(G.getVertexPos(e1)));
}
void get_weight(Graphlnk<char, int> G, int v1, int v2)//返回边（v1， v2）上的权值
{
	G.getWeight(v1, v2);
}
template <class T, class E>
void insert_Vertex(Graphlnk<char, int> G, const T& vertex)// 插入顶点
{
	G.insertVertex(vertex);
}
template <class T, class E>
void insert_Edge(Graphlnk<char, int> G, int v1, int v2, E weight)// 插入边
{
	G.insertEdge(v1, v2, weight);
}
template <class T, class E>
void remove_Vertex(Graphlnk<char, int> G, int v)// 有向图删除顶点
{
	G.removeVertex(v);
}
template <class T, class E>
void remove_Edge(Graphlnk<char, int> G, int v1, int v2)// 删除边
{
	G.removeEdge(v1, v2);
}
template <class T, class E>
void get_FirstNeighbor(Graphlnk<char, int> G, int v)// 取顶点v的第一个邻接顶点
{
	G.getFirstNeighbor(v);
}
template <class T, class E>
void get_NextNeighbor(Graphlnk<char, int> G, int v, int w)// 取顶点v的邻接顶点w的下一邻接顶点
{
	G.getNextNeighbor(v, w);
}
template <class T, class E>
void get_VertexPos(Graphlnk<char, int> G, const T vertex)// 给出顶点vertex在图中的位置
{
	G.getVertexPos(vertex);
}
void number_Of_Vertices(Graphlnk<char, int> G)// 当前顶点数
{
	G.numberOfVertices();
}
template <class T, class E>
void DFS_(Graphlnk<char, int> G, const T& v)// 深度优先搜索
{
	G.DFS(v);
}
template <class T, class E>
void BFS_(Graphlnk<char, int> G, const T& v)// 广度优先搜索
{
	G.BFS(v);
}
void Kruscal_(Graphlnk<char, int> G, MinSpanTree<char, int> MST)//调用Kruscal函数进行最小生成树
{
	MST.Kruscal(G);
}
void print_MST(Graphlnk<char, int> G, MinSpanTree<char, int> MST)//打印最小生成树
{
	MST.printMST(G);
}
void Shortest_Path(Graphlnk<char, int> G, int dist[maxSize],int path[maxSize])//求所有顶点之间的最短路径
{
	ShortestPath(G, dist, path);
}