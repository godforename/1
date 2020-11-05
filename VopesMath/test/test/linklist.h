#ifndef _LINKLIST_H
#define _LINKLIST_H

#include <iostream>
#include <stdlib.h>
#include <vector>

using namespace std;

template<typename DataType>
class LinkNode
{
public:
	DataType  data;
	LinkNode<DataType>* link;
};

template<typename DataType>
class LinkList
{
private:
	LinkNode<DataType>*  head;
public:
	void init();
	LinkList<DataType>()
	{
		this->init();
	}
	LinkList<DataType>& operator =(const LinkList<DataType>& X);
	void clear();
	LinkNode<DataType>* getHead();
	LinkNode<DataType>* begin()const;
	LinkNode<DataType>* end()const;
	void insert(DataType x);
	void erase(LinkNode<DataType>* q);
	void erase(int i);
	int  length();
	int  isEmpty();
	LinkNode<DataType>* find(DataType x)const;
	LinkNode<DataType>* locate(int i);
	int locate(LinkNode<DataType>*);
	LinkList<DataType> cat(LinkList<DataType> X);
	void print();
};

template<typename DataType>
void LinkList<DataType>::init()
{
	this->head  = new LinkNode<DataType>;
	(this->head)->link = NULL;
}

template<typename DataType>
LinkList<DataType>& LinkList<DataType>::operator =(const LinkList<DataType>& X)
{
	this->clear();
	LinkNode<DataType>* p = X.head;
	while(p->link != NULL)
	{
		DataType value = (p->link)->data;
		(*this).insert(value);
		p = p->link;
	}
	return (*this);
}

template<typename DataType>
void LinkList<DataType>::clear()
{
	LinkNode<DataType>* p;
	while( (this->head)->link != NULL )
	{
		p = (this->head)->link;
		(this->head)->link = p->link;
		delete p;
	}
}

template<typename DataType>
LinkNode<DataType>* LinkList<DataType>::getHead()
{
	return this->head;
}

template<typename DataType>
LinkNode<DataType>* LinkList<DataType>::begin()const
{
	return (this->head)->link;
}

template<typename DataType>
LinkNode<DataType>* LinkList<DataType>::end()const
{
	LinkNode<DataType>* p = this->head;
	while( p->link != NULL )
	{
		p = p->link;
	}
	return p->link;
}

template<typename DataType>
void LinkList<DataType>::insert(DataType x)
{
	LinkNode<DataType>* newNode = new LinkNode<DataType>;
	newNode->data = x;
	LinkNode<DataType>* p;
	p = this->head;
	while( p->link != NULL && (p->link)->data > x )
	{
		p = p->link;
	}
	newNode->link = p->link;
	p->link = newNode;
}

template<typename DataType>
void LinkList<DataType>::erase(int i)
{
	if( i < 0 || i > this->length() )
	{
		cout << "Error in LinkList::delete ! there is no element on position i" << endl;
		exit(-1);
	}
	LinkNode<DataType>* p = this->head;
	for(int index = 1; index < i; index++)
	{
		p = p->link;
	}
	delete p->link;
	p->link = (p->link)->link;
}

template<typename DataType>
void LinkList<DataType>::erase(LinkNode<DataType>* q)
{
	LinkNode<DataType>* p = this->head;
	while( p->link != NULL && p->link != q )
	{
		p = p->link;
	}

	if(p->link == q)
	{
		p->link = q->link;
		delete q;
	}
	else
	{
		cout << "Error in LinkList::delete(LinkNode*)! the adress you input is not in this list!" << endl;
		exit(-1);
	}
}

template<typename DataType>
int LinkList<DataType>::length()
{
	int n = 0;
	LinkNode<DataType>* p = this->head;
	while(p->link != NULL)
	{
		p = p->link;
		n++;
	}
	return n;
}

template<typename DataType>
int LinkList<DataType>::isEmpty()
{
	if( (this->head)->link == NULL )
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

template<typename DataType>
LinkNode<DataType>* LinkList<DataType>::find(DataType x)const
{
	LinkNode<DataType>* index = NULL;
	LinkNode<DataType>* p = this->begin();
	while(p != NULL)
	{
		if(p->data == x)
		{
			index = p;
			break;
		}
		p = p->link;
	}
	return index;
}

template<typename DataType>
LinkNode<DataType>* LinkList<DataType>::locate(int i)
{
	if( i < 0 || i > this->length() )
	{
		cout << "Error in locate(int i) ! there is no element on position i" << endl;
		exit(-1);
	}
	LinkNode<DataType>* p = this->head;
	for(int index = 1; index <= i; index++)
	{
		p = p->link;
	}
	return p;
}

template<typename DataType>
int LinkList<DataType>::locate(LinkNode<DataType>* q)
{
	int i = 0;
	LinkNode<DataType>* p = this->head;
	while( p->link != NULL && p != q )
	{
		p = p->link;
		i++;
	}

	if(p != q)
	{
		cout << "Error in locate(LinkNode<DataType>*)! the adress you input is not in this list!" << endl;
		exit(-1);
	}
	else
	{
		return i;
	}
}

template<typename DataType>
LinkList<DataType> LinkList<DataType>::cat(LinkList<DataType> X)
{
	LinkNode<DataType>* p = X.begin();
	while( p != X.end() )
	{
		DataType value = p->data;
		this->insert(value);
		p = p->link;
	}
	return (*this);
}

template<typename DataType>
void LinkList<DataType>::print()
{
	LinkNode<DataType>* p = this->head;
	while( p->link != NULL )
	{
		cout << (p->link)->data << endl;
		p = p->link;
	}
}

#endif