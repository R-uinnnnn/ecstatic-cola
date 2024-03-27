#pragma once
enum color
{
    red,
    black
};
template<class T>
struct RBNode          //建立节点
{
    RBTree()
    :_left(nullptr),
    _right(nullptr),
    _parent(nullptr),
    _data(0),
    _col(red)
    {

    }
private:
    RBNode<T>* _left;
    RBNode<T>* _right;
    RBNode<T>* _parent;
    T _data;
    color col;
};
template<class K,class T>
struct RBTree
{
    typedef struct RBNode Node;
    RBTree()
    :_data(nullptr)
    {

    }
    RBTree(T data)
    :_data(data)
    {

    }
    //Find()

private:
    Node* _node;//数据

};