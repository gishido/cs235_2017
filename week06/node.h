/***********************************************************************
* Header:
*    Node.h header file
* Author:
*    Adam Shumway, Jenaca Willans
* Summary: 
*    Node Template Class Header File
************************************************************************/

#ifndef NODE_H
#define NODE_H

#include <cassert> //for asserts
#include <iostream>

using namespace std;

/*************************************************
* Node
* A Node struct template that holds stuff
*************************************************/
template <class T>
class Node
{
    public:
        Node() : data(NULL), pNext(NULL) {}
        Node(const T &t) : data(t), pNext(NULL) {} 
    

        T data;
        Node<T> * pNext;

};

template <class T>
Node<T> * copy(const Node<T> * pHead)
{

}

template <class T>
Node<T> * insert(T data, Node<T> * pNode, bool head = false)
{

}

template <class T>
void addToHead(Node<T> * & pHead, T data)
{

}

template <class T>
Node<T> * find(Node<T> * pHead, T index)
{

}

template <class T>
void freeData(Node<T> * pHead)
{

}

template <class T>
ostream & operator<<(ostream & out, Node<T> * pHead)
{

}

#endif //NODE_H