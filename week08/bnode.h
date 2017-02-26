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
  BinaryNode() : data(0), pLeft(NULL), pRight(NULL), pParent(NULL)
   {
      numItems++;
   }
  BinaryNode(const T &t): data(t), pLeft(NULL), pRight(NULL), pParent(NULL)
   {
      numItems++;
   } 
   
   int size() const { return numItems; }
   bool empty() const { return numItems == 0; }

   BinaryNode<T> * copy(BinaryNode<T> * &pParent);
   void addLeft(BinaryNode<T> * pParent) throw (const char *);
   void addLeft(const T & data) throw (const char *);

   void addRight(BinaryNode<T> * pRight) throw (const char *);
   void addRight(const T & data) throw (const char *);

   //void deleteBinaryTree(BinaryNode<T> * &pParent);

   //ostream & operator<<(ostream & out, const BinaryNode<T> * pParent)
   
   T data;
   int numItems;
   // BinaryNode<T> * pNext;
   BinaryNode<T> * pLeft;
   BinaryNode<T> * pRight;
   BinaryNode<T> * pParent;
   
};

/*************************************************
* BinaryNode COPY 
*************************************************/
template <class T>
BinaryNode<T> * BinaryNode<T>::copy(BinaryNode<T> * &pParent)
{
   //create new BinaryNode
   BinaryNode<T> * pNew = new BinaryNode<T>;
   //point to new BinaryNode...basially new head of list
   BinaryNode<T> * pCopy = pNew;
   
   //copy first data item
   pNew->data = pParent->data;
   pParent = pParent->pRight;
   
   //if more than 1 data item, copy the rest
   while (pParent != NULL)
   {
      //create new BinaryNode with data
      pNew->pRight = new BinaryNode<T>(pParent->data);
      //advance BinaryNodes
      pParent = pParent->pRight;
      pNew = pNew->pRight;
   }
   
   //return head of copy
   return pCopy;
}


/*************************************************
* BinaryNode insert passed node to left
*************************************************/
template <class T>
void BinaryNode<T>::addLeft(BinaryNode<T> * pParent)
throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
      BinaryNode<T> * pNew = new BinaryNode<T>(pParent->data);
      
      // if we are inserting to the head position
      if(pParent == NULL)
      {
         pNew->pRight = pParent;
         pParent = pNew;

      }
      else
      {
         pNew->pRight = pParent->pRight;
         pParent->pRight = pNew;

      }
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
   //return pParent;
   
}


/*************************************************
* BinaryNode insert node with new value to left
*************************************************/
template <class T>
void BinaryNode<T>::addLeft(const T &data) throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
      BinaryNode<T> * pNew = new BinaryNode<T>(data);
      
      // if we are inserting to the head position
//      if(pParent == NULL)
      //    {
      // pNew->pRight = pParent;
      // pParent = pNew;
      //}
      //else
      // {
      // pNew->pRight = pParent->pRight;
      // pParent->pRight = pNew;
         
      // }
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
   //return data;
   
}


/*************************************************
* BinaryNode insert node with new value to right
*************************************************/
template <class T>
void BinaryNode<T>::addRight(const T &data) throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
       BinaryNode<T> * pNew = new BinaryNode<T>(data);
      
      // if we are inserting to the head position
       // if(pRight == NULL)
       //{
       //pNew->pRight = pRight;
       //pRight = pNew;
       // }
       //else
       // {
       //pNew->pRight = pRight->pRight;
       //pRight->pRight = pNew;
        
       //}
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
   //return data;
   
}


/*************************************************
* BinaryNode insert passed node to right
*************************************************/
template <class T>
void BinaryNode<T>::addRight(BinaryNode<T> * pRight)
throw (const char *)
{   
   try
   {
      // allocate a new BinaryNode
    BinaryNode<T> * pNew = new BinaryNode<T>(pRight->data);
      
      // if we are inserting to the head position
          if(pRight == NULL)
      {
       pNew->pRight = pRight;
       pRight = pNew;
      }
       else
      {
       pNew->pRight = pRight->pRight;
       pRight->pRight = pNew;
         
      }
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
//   return pRight;
   
}


/*************************************************
* BinaryNode delete
*************************************************/
template <class T>
void deleteBinaryTree(BinaryNode<T> * &pParent)
{
   //delete items from the list
   while (pParent != NULL)
   {
      BinaryNode<T> * p = pParent->pRight;
      delete pParent;
      pParent = p;
   }
   
   pParent = NULL;
}


/*************************************************
* BinaryNode operator <<
*************************************************/
template <class T>
ostream & operator<<(ostream & out, const BinaryNode<T> * pParent)
{
   // operator overload to display the list
   for (const BinaryNode<T> * p = pParent; p; p = p->pRight)
   {
      if(p->pRight != NULL)
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
