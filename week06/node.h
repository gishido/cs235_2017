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
Node<T> * copy(Node<T> * &pHead)
{
    //create new node
    Node<T> * pNew = new Node<T>;
    //point to new node...basially new head of list
    Node<T> * pCopy = pNew;
    
    //copy first data item
    pNew->data = pHead->data;
    pHead = pHead->pNext;

    //if more than 1 data item, copy the rest
    while (pHead != NULL)
    {
        //create new node with data
        pNew->pNext = new Node<T>(pHead->data);
        //advance nodes
        pHead = pHead->pNext;
        pNew = pNew->pNext;
    }

    //return head of copy
    return pCopy;
}

template <class T>
Node<T> * insert(T data, Node<T> * &pNode, bool head = false)
{
    if(head || pNode == NULL)
        addToHead(data, pNode);
    else
    {
        //1. create a new Node
        Node<T> * pNew = new Node<T>;
        pNew->data = data;

        //2. fix the next pointer
        pNew->pNext = pNode->pNext;

        //3. get pNode->pNext to point to new
        pNode->pNext = pNew;
    }
    
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
void freeData(Node<T> * & pHead)
{
    //delete items from the list
    while (pHead != NULL)
    {
        Node<T> * p = pHead;
        p = p->pNext;
        delete pHead;
        pHead = p;
    }

    pHead = NULL;
}

template <class T>
ostream & operator<<(ostream & out, const Node<T> * pHead)
{
    for (const Node<T> * p = pHead; p; p = p->pNext)
    {
       if(p->pNext != NULL)
       {
          out << p->data << ", ";
       }
       else
       {
          out << p->data;
       }
    }
       return out;
}

#endif //NODE_H
