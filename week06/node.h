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
        Node() : data(0), pNext(NULL) {}
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
    if(head)
        addToHead(data, pNode);
    
    //1. create a new Node
    Node<T> * pNew = new Node<T>;
    pNew->data = data;

    //2. fix the next pointer
    pNew->pNext = pNode->pNext;

    //3. get pNode->pNext to point to new
    pNode->pNext = pNew;

    return pNode;
}

template <class T>
void addToHead(T data, Node<T> * & pHead)
{
  //1. create a new Node
    Node<T> * pNew = new Node<T>;
    pNew->data = data;

    //2. fix the next pointer
    pNew->pNext = pHead;

    //3. get pNode->pNext to point to new
    pHead = pNew;
}

template <class T>
Node<T> * find(Node<T> * pHead, T index)
{

}

template <class T>
void freeData(Node<T> * pHead)
{
    for (Node<T> * p = pHead; p; p->pNext)
        delete p;
    pHead = NULL;
}

template <class T>
ostream & operator<<(ostream & out, const Node<T> * pHead)
{
    for (const Node<T> * p = pHead; p; p->pNext)
        out << p->data << ' ';
    return out;
}

#endif //NODE_H