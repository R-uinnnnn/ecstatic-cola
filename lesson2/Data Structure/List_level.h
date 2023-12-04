#ifndef LIST_H
#define LIST_H

#include<stdlib.h>

template<class T>
class List
{
	struct Node				//双向结点声明
	{
		T data;
		Node* prev, * next;
		Node(const T& d = T(), Node* p = NULL, Node* n = NULL) :data(d), prev(p), next(n) {}
	};
	int size;				//数据结点个数
	Node* head;				//头结点指针
	Node* tail;				//尾结点指针
	void init()				//初始化函数
	{
		size = 0; head = new Node; tail = new Node; head->next = tail; tail->prev = head;
	}

public:
	class const_iterator
	{
	protected:
		Node* current;
		T& retrieve()const { return current->data; }
		const_iterator(Node* p) :current(p) {}
		friend class List<T>;
	public:
		const_iterator() :current(NULL) {}
		const T& operator*()const { return retrieve(); }//current->data
		const_iterator& operator++()//前++
		{
			current = current->next;
			return *this;
		}
		const_iterator operator++(int)//后++
		{
			const_iterator old = *this;	//old=current;
			++(*this);					//current=current->next;
			return old;
		}
		const_iterator& operator--()//前--
		{
			current = current->prev;
			return *this;
		}
		const_iterator operator--(int)//后--
		{
			const_iterator old = *this;	//old=current;
			--(*this);					//current=current->next;
			return old;
		}
		bool operator==(const const_iterator& rhs)const
		{
			return current == rhs.current;
		}
		bool operator!=(const const_iterator& rhs)const
		{
			return current != rhs.current;
		}

	};
	class iterator :public const_iterator
	{
	protected:
		iterator(Node* p) :const_iterator(p) {}
		friend class List<T>;
	public:
		iterator() {}
		T& operator*() { return retrieve(); }
		const T& operator*()const { return const_iterator::operator*(); }
		iterator& operator++()//前++
		{
			current = current->next;
			return *this;
		}
		iterator operator++(int)//后++
		{
			iterator old = *this;			//old=current;
			++(*this);					//current=current->next;
			return old;
		}
		iterator& operator--()//前--
		{
			current = current->prev;
			return *this;
		}
		iterator operator--(int)//后--
		{
			iterator old = *this;			//old=current;
			--(*this);					//current=current->next;
			return old;
		}
	};
	List() { init(); }								//默认构造函数
	List(const List<T>& l) { init(); operator=(l); }//复制构造函数
	~List() { Clear(); delete head; delete tail; }	//析构函数
	const List<T>& operator=(const List<T>& l);		//复制赋值运算符函数
	int Size()const { return size; }				//求数据个数
	bool Empty()const { return size == 0; }			//判空函数
	void Clear() { while (!Empty())Pop_front(); }	//清表

	iterator begin() { return iterator(head->next); }
	const_iterator begin()const { return const_iterator(head->next); }
	iterator end() { return iterator(tail); }
	const_iterator end()const { return const_iterator(tail); }

	T& Front() { return *begin(); }			//返回首元素的引用
	const T& Front()const { return *begin(); }	//返回首元素的常量型引用
	T& Back() { return *--end(); }				//返回尾元素的引用			
	const T& Back()const { return *--end(); }	//返回尾元素的常量型引用
	void Push_front(const T& item) { Insert(begin(), item); }//首插
	void Push_back(const T& item) { Insert(end(), item); }//尾插
	void Pop_front() { Erase(begin()); }		//删除首结点
	void Pop_back() { Erase(--end()); }		//删除尾结点
	iterator Erase(iterator itr);			//删除指示器位置上的结点
	//iterator Insert(iterator itr, const T& item);//在指示器的位置插入item
	T& RemoveMin();
};
template<class T>//复制赋值成员运算符函数的实现
const List<T>& List<T>::operator=(const List<T>& l)
{
	Clear();					//清为空表
	for (const_iterator itr = l.begin(); itr != l.end(); ++itr) //把表l的结点逐个复制
		Push_back(*itr);
	return *this;
}

template<class T>
List<T>::iterator List<T>::Erase(iterator itr)
{
	Node* p = itr.current;
	iterator re(p->next);
	p->prev->next = p->next;
	p->next->prev = p->prev;
	delete p;
	size--;
	return re;
}

template <class T>
T& List<T>::RemoveMin()
{
	iterator min = begin();
	iterator it = begin();
	while (it != end())
	{
		if (*it < *min)
		{
			min = it;
		}
		++it;
	}
	int Min = *min;
	Erase(min);
	return Min;
}

#endif