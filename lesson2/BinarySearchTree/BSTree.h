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
		:_root(nullptr)//初始化
	{

	}
	//BSTree(T val)
	//	:_root(new Node(T val))//初始化
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
		else//找到了要删除的元素位置
		{
			Node* dele = root;
			if (root->_left == nullptr)//左为空
			{
				root = root->_right;
			}
			else if (root->_right == nullptr)//右为空
			{
				root = root->_left;
			}
			else//左右都不为空
			{
				Node* leftMax = root->_left;
				while (leftMax->_right != nullptr)//找左子树最大节点（最右节点）/右子树最小节点（最左节点）
				{
					leftMax = leftMax->_right;
				}
				swap(leftMax->_key, root->_key);

				return Erase(root->_left, key);
				//不能是Erase(leftMax,key);
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
