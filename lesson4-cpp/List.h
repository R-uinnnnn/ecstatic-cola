#pragma once

/*
namespace annn
{
template <class T>
struct Node//默认是公有，可以访问
{
    Node<T>* next;
    //Node是类名，而不是类型，不能忘记模板实例化，要写上参数<T>
    Node<T>* prev;
    T _data;
    Node()
    {

    }
    Node(const T& data)
    :next(nullptr),
    prev(nullptr),
    _data(data)
    {

    }

};


//    typedef list_iterator<T,T&,T*> list_iterator;
//    typedef list_iterator<T,const T&,const T*> const_list_iterator;
template <class T,class ref,class ptr>
struct List_iterator
{
    //typedef T& ref;
    //typedef T* ptr;
//这种情况就可以只传一个参数，如list_iterator<int>
    typedef List_iterator<T,T&,T*> iterator;
    typedef List_iterator<T,const T&,const T*> const_iterator;
    typedef List_iterator<T,ref,ptr> self;
    typedef List_iterator<T,ref,ptr>& dst;

    List_iterator()
    {

    }
    List_iterator(const_iterator& it)
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

    ref operator*()
    {
        return node->_data;
    }

    ptr operator->()
    {
        return &(node->_data);
    }

    dst operator++()
    {
        ++(node->_data);
        return *this;
    }
    self operator++(T)
    {
        List_iterator tmp(*this);
        ++(node->_data);
        return tmp;
    }
    dst operator--()
    {
        --(node->_data);
        return *this;
    }
    self operator--(T)
    {
        List_iterator tmp(*this);
        --(node->_data);
        return tmp;
    }
    bool operator!=(const iterator& it)
    {
        return node==it.node;
    }

    Node<T>* node;

};



template <class T>
class List
{
public:
    typedef T& ref;
    typedef T* ptr;
    typedef List_iterator<T,T&,T*> iterator;
    typedef List_iterator<T,const T&,const T*> const_iterator;
    List()
    {
        node=new Node<T>();//只有带上参数，模板实例化了才是类型；Node<T>才是类型，Node只是类名
        node->next=node->prev=nullptr;
        //建立头结点(哨兵卫)
    }
    ~List()
    {
        //实现
    }
    iterator begin()
    {
        return iterator(node->next);
    }
    iterator end()
    {
        return iterator(node);
    }
    void push_back(T val)
    {
        insert(end(),val);
        
    }
    void insert(iterator it,T val)
    {
        Node<T>* newnode=new Node<T>(val);
        Node<T>* cur=it.node;
        Node<T>* prev=cur->prev;

        prev->next=newnode;
        newnode->prev=prev;

        newnode->next=cur;
        cur->prev=newnode;
    }

public:
    Node<T>* node;
};


void test1()
{
    List<int> lt1;
    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_back(3);
    lt1.push_back(4);
    lt1.push_back(5);
    lt1.push_back(6);
    lt1.push_back(7);

    List<int>::iterator it=lt1.begin();
    while(it!=lt1.end())
    {
        cout<<*it<<" ";
    }

}
*/



namespace annn
{
    template <class T>
    struct Node//默认是公有，可以访问
    {
        Node<T>* next;
        //Node是类名，而不是类型，不能忘记模板实例化，要写上参数<T>
        Node<T>* prev;
        T _data;
        Node(const T& data = T())
            :next(nullptr),
            prev(nullptr),
            _data(data)
        {

        }

    };


    //    typedef list_iterator<T,T&,T*> list_iterator;
    //    typedef list_iterator<T,const T&,const T*> const_list_iterator;
    template <class T, class ref, class ptr>
    struct List_iterator
    {
        //typedef T& ref;
        //typedef T* ptr;
    //这种情况就可以只传一个参数，如list_iterator<int>
        typedef List_iterator<T, ref, ptr> iterator;
        typedef List_iterator<T, const ref, const ptr> const_iterator;
        typedef List_iterator<T, ref, ptr> self;
        typedef List_iterator<T, ref, ptr>& dst;

        List_iterator()
        {

        }

        List_iterator(Node<T>* pNode) : node(pNode) {}

        List_iterator(const_iterator& it)
            :node(it.node)
        {

        }
        ~List_iterator()
        {

        }

        ref operator*()
        {
            return node->_data;
        }

        ptr operator->()
        {
            return &(node->_data);
        }

        dst operator++()
        {
            ++(node->_data);
            return *this;
        }
        dst operator++(T)
        {
            List_iterator tmp(*this);
            ++(node->_data);
            return tmp;
        }
        dst operator--()
        {
            --(node->_data);
            return *this;
        }
        dst operator--(T)
        {
            List_iterator tmp(*this);
            --(node->_data);
            return tmp;
        }
        bool operator!=(const iterator& it)
        {
            return node == it.node;
        }
        Node<T>* node;

    };


    template <class T>
    class List
    {
    public:
        typedef T& ref;
        typedef T* ptr;
        typedef List_iterator<T, ref, ptr> iterator;
        typedef List_iterator<T, const ref, const ptr> const_iterator;
        List()
        {
            node = new Node<T>();//只有带上参数，模板实例化了才是类型；Node<T>才是类型，Node只是类名
            node->next = node->prev = nullptr;
            //建立头结点(哨兵卫)
        }
        ~List()
        {
            //实现
        }
        iterator begin()
        {
            return iterator(node->next);
        }
        iterator end()
        {
            return iterator(node);
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


    void test1()
    {
        List<int> lt1;
        lt1.push_back(1);
        lt1.push_back(2);
        lt1.push_back(3);
        lt1.push_back(4);
        lt1.push_back(5);
        lt1.push_back(6);
        lt1.push_back(7);

        List<int>::iterator it = lt1.begin();
        while (it != lt1.end())
        {
            cout << *it << " ";
        }

    }
}