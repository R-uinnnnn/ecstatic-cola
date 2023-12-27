#pragma once
#include <iostream>
#include <list>
#include <algorithm>
using namespace std;
namespace annn
{

    template <class T>
    struct Node//Ĭ���ǹ��У����Է���
    {
        Node<T>* next;
        //Node�����������������ͣ���������ģ��ʵ������Ҫд�ϲ���<T>
        Node<T>* prev;
        T _data;
        Node(const T& data=T())
            :next(nullptr),
            prev(nullptr),
            _data(data){
        }

    };


    //    typedef list_iterator<T,T&,T*> list_iterator;
    //    typedef list_iterator<T,const T&,const T*> const_list_iterator;
    template <class T, class ref, class ptr>
    struct List_iterator
    {
        Node<T>* node;
        //typedef T& ref;
        //typedef T* ptr;
    //��������Ϳ���ֻ��һ����������list_iterator<int>
        typedef List_iterator<T, T&, T*> iterator;
        typedef List_iterator<T, const T&, const T*> const_iterator;
        typedef List_iterator<T, ref, ptr> self;
        typedef List_iterator<T, ref, ptr>& dst;

        List_iterator()
        {

        }
        List_iterator(const iterator& it)
            :node(it.node)
        {

        }
        List_iterator(iterator& it)
            :node(it.node)
        {

        }
        List_iterator(Node<T>* Node)
            :node(Node)
        {

        }
        ~List_iterator()
        {

        }

        ref operator*()// T
        {
            return node->_data;
        }

        ptr operator->()// T*
        {
            return &(node->_data);
        }

        dst operator++()
        {
            node = node->next;//�ռ䲻���������ÿ++һ�Σ����ߵ���һ���ڵ�
            return *this;
        }
        self operator++(T)
        {
            List_iterator tmp(*this);
            node = node->next;//�ռ䲻���������ÿ++һ�Σ����ߵ���һ���ڵ�
            return tmp;
        }
        dst operator--()
        {
            node=node->prev;
            return *this;
        }
        self operator--(T)
        {
            List_iterator tmp(*this);
            node = node->prev;
            return tmp;
        }
        bool operator!=(iterator it)
        {
            return node != it.node;
        }
       
        bool operator==(iterator it)
        {
            return node == it.node;
        }

    };

    template <class T>
    class List
    {
    public:
        //typedef T& ref;
        //typedef T* ptr;
        typedef List_iterator<T, T&, T*> iterator;
        typedef List_iterator<T, const T&, const T*> const_iterator;
        List()
        {
            node = new Node<T>;//ֻ�д��ϲ�����ģ��ʵ�����˲������ͣ�Node<T>�������ͣ�Nodeֻ������
            node->next = node;
            node->prev = node;
            //����ͷ���(�ڱ���)
        }
        ~List()
        {
            //ʵ��
        }

        List(const List<T>& lt)//��������
        {
            iterator it = lt.begin();
            while (it != lt.end())
            {
                push_back(*it);
                ++it;
            }

        }
        List<T>& operator=(const list<T> it)
        {
            //List<T> tmp(it);
            /*swap(tmp);*/
            node = it.node;
            return *this;
        }
        iterator begin()
        {
            return iterator(node->next);
        }
        iterator end()
        {
            return iterator(node);
        }
        const_iterator begin()
        {
            return const_iterator(node->next);
        }
        const_iterator end()
        {
            return const_iterator(node);
        }
        void push_back(T val)
        {
            insert(end(), val);

        }
        void insert(iterator it, T val)
        {
            Node<T>* newnode = new Node<T>(val);
            Node<T>* cur = it.node;
            Node<T>* prev = cur->prev;
            prev->next = newnode;
            newnode->prev = prev;
            newnode->next = cur;
            cur->prev = newnode;
        }

    public:
        Node<T>* node;
    };



}


//namespace annn
//{
//    template <class T>
//    struct Node//Ĭ���ǹ��У����Է���
//    {
//        Node<T>* next;
//        //Node�����������������ͣ���������ģ��ʵ������Ҫд�ϲ���<T>
//        Node<T>* prev;
//        T _data;
//        Node(const T& data = T())
//            :next(nullptr),
//            prev(nullptr),
//            _data(data)
//        {
//
//        }
//
//    };
//
//
//    //    typedef list_iterator<T,T&,T*> list_iterator;
//    //    typedef list_iterator<T,const T&,const T*> const_list_iterator;
//    template <class T, class ref, class ptr>
//    struct List_iterator
//    {
//        //typedef T& ref;
//        //typedef T* ptr;
//    //��������Ϳ���ֻ��һ����������list_iterator<int>
//        typedef List_iterator<T, ref, ptr> iterator;
//        typedef List_iterator<T, const ref, const ptr> const_iterator;
//        typedef List_iterator<T, ref, ptr> self;
//        typedef List_iterator<T, ref, ptr>& dst;
//
//        List_iterator()
//        {
//
//        }
//
//        List_iterator(Node<T>* pNode) : node(pNode) {}
//
//        List_iterator(const_iterator& it)
//            :node(it.node)
//        {
//
//        }
//        ~List_iterator()
//        {
//
//        }
//
//        ref operator*()
//        {
//            return node->_data;
//        }
//
//        ptr operator->()
//        {
//            return &(node->_data);
//        }
//
//        dst operator++()
//        {
//            ++(node->_data);
//            return *this;
//        }
//        dst operator++(T)
//        {
//            List_iterator tmp(*this);
//            ++(node->_data);
//            return tmp;
//        }
//        dst operator--()
//        {
//            --(node->_data);
//            return *this;
//        }
//        dst operator--(T)
//        {
//            List_iterator tmp(*this);
//            --(node->_data);
//            return tmp;
//        }
//        bool operator!=(const iterator& it)
//        {
//            return node == it.node;
//        }
//        Node<T>* node;
//
//    };
//
//
//    template <class T>
//    class List
//    {
//    public:
//        typedef T& ref;
//        typedef T* ptr;
//        typedef List_iterator<T, , ptr> iterator;
//        typedef List_iterator<T, const ref, const ptr> const_iterator;
//        List()
//        {
//            node = new Node<T>();//ֻ�д��ϲ�����ģ��ʵ�����˲������ͣ�Node<T>�������ͣ�Nodeֻ������
//            node->next = node;
//            node->prev = node;
//            //����ͷ���(�ڱ���)
//        }
//        ~List()
//        {
//            //ʵ��
//        }
//        iterator begin()
//        {
//            return iterator(node->next);
//        }
//        iterator end()
//        {
//            return iterator(node);
//        }
//        void push_back(T val)
//        {
//            insert(end(), val);
//
//        }
//        void insert(iterator it, T val)
//        {
//            Node<T>* newnode = new Node<T>(val);
//            Node<T>* cur = it.node;
//            Node<T>* prev = cur->prev;
//
//            prev->next = newnode;
//            newnode->prev = prev;
//
//            newnode->next = cur;
//            cur->prev = newnode;
//        }
//
//    public:
//        Node<T>* node;
//    };
//
//
//    void test1()
//    {
//        List<int> lt1;
//        lt1.push_back(1);
//        lt1.push_back(2);
//        lt1.push_back(3);
//        lt1.push_back(4);
//        lt1.push_back(5);
//        lt1.push_back(6);
//        lt1.push_back(7);
//
//        List<int>::iterator it = lt1.begin();
//        while (it != lt1.end())
//        {
//            cout << *it << " ";
//        }
//
//    }
//}