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
#include <string>
#include <iomanip>

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
Node<T> * insert(const T & data, Node<T> * &pHead, bool head = false)
throw (const char *)
{   
   try
   {
      Node<T> * pNew = new Node<T>(data);
      //    Node<T> * pFind = find(pHead, data);

      if(head || pHead == NULL)
      {
         pNew->pNext = pHead;
         pHead = pNew;
      }
      else
      {
         pNew->pNext = pHead->pNext;
         pHead->pNext = pNew;
        
//         pNew->pNext = pFind->pNext;
//         pFind->pNext = pNew;
      }
   }
   catch(string pNode) 
   {
      throw "Error: Unable to allocate a new Node";
   }

   return pHead;
   
}

template <class T>
Node<T> * find(Node<T> * pHead, const T &t)
{
   if (NULL == pHead || t < pHead->data)
      return NULL;

//   cout << "Debug: value of data" << pHead->data << endl;
   
   while (pHead->pNext && pHead->pNext->data < t)
   {
      pHead = pHead->pNext;
      return pHead;
   }
}

template <class T>
void freeData(Node<T> * & pHead)
{
    //delete items from the list
    while (pHead != NULL)
    {
        Node<T> * p = pHead->pNext;
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
