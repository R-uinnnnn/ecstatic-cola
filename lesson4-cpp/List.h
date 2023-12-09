#pragma once

namespace abl
{
template <class T>
struct Node//默认是公有，可以访问
{
    Node<T>* next;
    //Node是类名，而不是类型，不能忘记模板实例化，要写上参数<T>
    Node<T>* prev;
    T date;
};

template <class T>
class List
{
    List()
    {
        node=new Node<T>;//只有带上参数，模板实例化了才是类型；Node<T>才是类型，Node只是类名
        node->next=node->prev=nullptr;
    }
    ~List()
    {

    }


public:
    Node<T>* node;
};

}