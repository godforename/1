#ifndef UFSets_h
#define UFSets_h
struct Node { // 并查集结点类
	int data; // 保存数据
	int parent; // 保存父结点
};

class UnionFindSets {
public:
	UnionFindSets(int n); // 构造函数
	~UnionFindSets(); // 析构函数
	void Union(int a, int b); // 并
	int Find(int x); // 查找x，并返回x的根结点
private:
	Node *s; // 数组
	int currentSize; // 实际存储的个数
};

// 构造函数
UnionFindSets::UnionFindSets(int n) {
	// 初始化
	currentSize = n;
	s = new Node[n];
	for (int i = 0; i < n; i++) {
		s[i].data = i;
		s[i].parent = -1;
	}
}

// 析构函数
UnionFindSets::~UnionFindSets() {
	delete[]s; // 释放空间
}

// 并
void UnionFindSets::Union(int a, int b) {
	int root1, root2;

	root1 = Find(a); // 找到a的根结点
	root2 = Find(b); // 找到b的根结点
	if (root1 == root2 || root1 == -1 || root2 == -1) // 根结点相同,或者其中一个数不在集合中
		return;
	if (s[root1].parent < s[root2].parent) // 说明root1的树高比root2的树高大
		s[root2].parent = root1;
	else if (s[root1].parent == s[root2].parent) { // 树高相等
		s[root2].parent = root1;
		s[root1].parent = s[root1].parent - 1; // root1的树高变高，因为是负数，所以减1
	}
	else { // root2的树高比root1的树高大
		s[root1].parent = root2;
	}
}

// 查找x，并返回x的根结点
int UnionFindSets::Find(int x) {
	int i;

	for (i = 0; i < currentSize && s[i].data != x; i++); // 在数组中查找
	if (i >= currentSize) // 没找到
		return -1;
	for (; s[i].parent >= 0; i = s[i].parent); //  找根结点
	return i;
}
#endif /* UFSets_h */