#ifndef UFSets_h
#define UFSets_h
struct Node { // ���鼯�����
	int data; // ��������
	int parent; // ���游���
};

class UnionFindSets {
public:
	UnionFindSets(int n); // ���캯��
	~UnionFindSets(); // ��������
	void Union(int a, int b); // ��
	int Find(int x); // ����x��������x�ĸ����
private:
	Node *s; // ����
	int currentSize; // ʵ�ʴ洢�ĸ���
};

// ���캯��
UnionFindSets::UnionFindSets(int n) {
	// ��ʼ��
	currentSize = n;
	s = new Node[n];
	for (int i = 0; i < n; i++) {
		s[i].data = i;
		s[i].parent = -1;
	}
}

// ��������
UnionFindSets::~UnionFindSets() {
	delete[]s; // �ͷſռ�
}

// ��
void UnionFindSets::Union(int a, int b) {
	int root1, root2;

	root1 = Find(a); // �ҵ�a�ĸ����
	root2 = Find(b); // �ҵ�b�ĸ����
	if (root1 == root2 || root1 == -1 || root2 == -1) // �������ͬ,��������һ�������ڼ�����
		return;
	if (s[root1].parent < s[root2].parent) // ˵��root1�����߱�root2�����ߴ�
		s[root2].parent = root1;
	else if (s[root1].parent == s[root2].parent) { // �������
		s[root2].parent = root1;
		s[root1].parent = s[root1].parent - 1; // root1�����߱�ߣ���Ϊ�Ǹ��������Լ�1
	}
	else { // root2�����߱�root1�����ߴ�
		s[root1].parent = root2;
	}
}

// ����x��������x�ĸ����
int UnionFindSets::Find(int x) {
	int i;

	for (i = 0; i < currentSize && s[i].data != x; i++); // �������в���
	if (i >= currentSize) // û�ҵ�
		return -1;
	for (; s[i].parent >= 0; i = s[i].parent); //  �Ҹ����
	return i;
}
#endif /* UFSets_h */