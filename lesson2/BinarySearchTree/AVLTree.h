#pragma once
#include <stdio.h>

template<class T>
struct AVLNode
{
	AVLNode<T>* _left;
	AVLNode<T>* _right;
	AVLNode<T>* _parent;
	T _key;
	AVLTree()
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _key(0)
	{

	}
};

template<class T>
class AVLTree
{
	typedef AVLNode<T> Node;
private:
	Node* _root;
public:
	AVLTree()
		:_root(nullptr)
	{

	}

};