/***********************************************************************
* Header:
*    BinaryNode.h header file
* Author:
*    Adam Shumway, Jenaca Willans
* Summary: 
*    BinaryNode Template Class Header File
************************************************************************/

#ifndef BINARYNODE_H
#define BINARYNODE_H

#include <cassert> //for asserts
#include <iostream>
#include <string>

using namespace std;

/*************************************************
* BinaryNode
* A BinaryNode struct template that holds stuff
*************************************************/
template <class T>
class BinaryNode
{
  public:
  BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL) {}
  BinaryNode(const T &t) : pLeft(NULL), pRight(NULL), pParent(NULL) {} 
   
   int size() { return numItems; }
   
   T data;
   int numItems;
   BinaryNode<T> * pNext;
   BinaryNode<T> * pLeft;
   BinaryNode<T> * pRight;
   BinaryNode<T> * pParent;
   
};


template <class T>
BinaryNode<T> * copy(BinaryNode<T> * &pHead)
{
   //create new BinaryNode
   BinaryNode<T> * pNew = new BinaryNode<T>;
   //point to new BinaryNode...basially new head of list
   BinaryNode<T> * pCopy = pNew;
   
   //copy first data item
   pNew->data = pHead->data;
   pHead = pHead->pNext;
   
   //if more than 1 data item, copy the rest
   while (pHead != NULL)
   {
      //create new BinaryNode with data
      pNew->pNext = new BinaryNode<T>(pHead->data);
      //advance BinaryNodes
      pHead = pHead->pNext;
      pNew = pNew->pNext;
   }
   
   //return head of copy
   return pCopy;
}


template <class T>
BinaryNode<T> * addLeft(BinaryNode<T> * pHead)
throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
      //     BinaryNode<T> * pNew = new BinaryNode<T>(data);
      
      // if we are inserting to the head position
      // if(head || pHead == NULL)
      //{
      //  pNew->pNext = pHead;
      // pHead = pNew;
      // }
      // else
      //{
      // pNew->pNext = pHead->pNext;
      // pHead->pNext = pNew;
         
      //   }
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
   return pHead;
   
}

template <class T>
BinaryNode<T> * addLeft(const T & data)
throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
      // BinaryNode<T> * pNew = new BinaryNode<T>(data);
      
      // if we are inserting to the head position
      // if(head || pHead == NULL)
      // {
      // pNew->pNext = pHead;
      // pHead = pNew;
      // }
      //else
      // {
      // pNew->pNext = pHead->pNext;
      //  pHead->pNext = pNew;
         
      //   }
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
   return data;
   
}


template <class T>
BinaryNode<T> * addRight(const T & data)
throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
      // BinaryNode<T> * pNew = new BinaryNode<T>(data);
      
      // if we are inserting to the head position
      //if(head || pHead == NULL)
         // {
         // pNew->pNext = pHead;
         // pHead = pNew;
         // }
      // else
         //{
         // pNew->pNext = pHead->pNext;
         // pHead->pNext = pNew;
         
         //}
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
   return data;
   
}

template <class T>
BinaryNode<T> * addRight(BinaryNode<T> * &pHead)
throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
//      BinaryNode<T> * pNew = new BinaryNode<T>(data);
      
      // if we are inserting to the head position
      //    if(head || pHead == NULL)
      //{
      // pNew->pNext = pHead;
      // pHead = pNew;
      //}
      // else
      //{
      // pNew->pNext = pHead->pNext;
      // pHead->pNext = pNew;
         
      //}
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
   return pHead;
   
}


template <class T>
void deleteBinaryTree(BinaryNode<T> * & pHead)
{
   //delete items from the list
   while (pHead != NULL)
   {
      BinaryNode<T> * p = pHead->pNext;
      delete pHead;
      pHead = p;
   }
   
   pHead = NULL;
}

template <class T>
ostream & operator<<(ostream & out, const BinaryNode<T> * pHead)
{
   // operator overload to display the list
   for (const BinaryNode<T> * p = pHead; p; p = p->pNext)
   {
      if(p->pNext != NULL)
      {
         out << p->data << " ";
      }
      else
      {
         out << p->data;
      }
   }
   return out;
}

#endif //BINARYNODE_H
