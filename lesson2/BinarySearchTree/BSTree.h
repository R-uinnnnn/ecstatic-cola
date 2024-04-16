#pragma once
#include <stdio.h>
template<class T>
struct BSTreeNode
{
	//typedef struct BSTreeNode<T> Node;
public:
	BSTreeNode<T>* _left;
	BSTreeNode<T>* _right;
	T _key;

	BSTreeNode()
		:_left(nullptr)
		,_right(nullptr)
	{

	}
	BSTreeNode(T val)
		:_left(nullptr)
		, _right(nullptr)
	{
		_key = val;
	}

};
template<class T>
class BSTree
{
	typedef BSTreeNode<T> Node;
public:
	BSTree()
		:_root(nullptr)//��ʼ��
	{

	}
	//BSTree(T val)
	//	:_root(new Node(T val))//��ʼ��
	//{
	//}
	BSTreeNode<T>* begin()
	{
		return _root;
	} 
	BSTreeNode<T>* end()
	{
		return _root->right;
	}
	void Insert(T val)
	{
		Node* newnode = new Node(val);
		Node* cur = _root;
		if (cur == nullptr)
		{
			_root = newnode;
		}
		while (cur)
		{
			if (cur->_key < val)
			{
				if (cur->_right == nullptr)
				{
					cur->_right = newnode;
				}
				else
				{
					cur = cur->_right;
				}
				
			}
			else if (cur->_key > val)
			{
				if (cur->_left == nullptr)
				{
					cur->_left = newnode;
				}
				else
				{
					cur = cur->_left;
				}
			}
			else
			{
				return;
			}
		}
	}
	bool Erase(Node*& root,T key)
	{
		if (root == nullptr)
		{
			return false;
		}
		if (root->_key > key)
		{
			Erase(root->_left, key);
		}
		else if (root->_key < key)
		{
			Erase(root->_right, key);
		}
		else//�ҵ���Ҫɾ����Ԫ��λ��
		{
			Node* dele = root;
			if (root->_left == nullptr)//��Ϊ��
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)//��Ϊ��
			{
				root = root->_left;
			}
			else//���Ҷ���Ϊ��
			{
				Node* leftMax = root->_left;
				while (leftMax->_right != nullptr)//�����������ڵ㣨���ҽڵ㣩/��������С�ڵ㣨����ڵ㣩
				{
					leftMax = leftMax->_right;
				}
				swap(leftMax->_key, root->_key);

				return Erase(root->_left, key);
				//������Erase(leftMax,key);
				//return Erase(leftMax, key);
			}
		}
	}
	
	void InOrder(Node*& root)
	{
		if (root == nullptr)
		{
			return;
		}

		InOrder(root->_left);
		printf("%d ", root->_key);
		InOrder(root->_right);

	}
	Node* _root;

};
