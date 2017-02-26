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
      numItems = 0;
      numItems++;
   }
  BinaryNode(const T &t): data(t), pLeft(NULL), pRight(NULL), pParent(NULL)
   {
      numItems = 0;
      numItems++;
   } 
   
   int size() const { return numItems; }
   bool empty() const { return numItems == 0; }

   BinaryNode<T> * copy(BinaryNode<T> * &pParent);
   void addLeft(BinaryNode<T> * pParent) throw (const char *);
   void addLeft(const T & data) throw (const char *);

   void addRight(BinaryNode<T> * pRight) throw (const char *);
   void addRight(const T & data) throw (const char *);

//   void deleteBinaryTree(BinaryNode<T> * &pParent);

   //ostream & operator<<(ostream & out, const BinaryNode<T> * pParent)
   
   T data;
   int numItems;
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
void BinaryNode<T>::addLeft(BinaryNode<T> * tempLeft)
throw (const char *)
{   
//  cout << "debug: currently in addLeft(BinaryNode<T> * pParent)\n";
   try
   {
      // allocate a new BinaryNode
//      BinaryNode<T> * pNew = new BinaryNode<T>(pParent->data);

      this->pLeft = tempLeft;
      
      // if we are inserting to the head position
      if(tempLeft != NULL)
      {
         this->pLeft->pParent = this;
         numItems += 2;
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
   //cout << "debug: currently in addLeft(const T &data)\n";
   try
   {
      // allocate a new BinaryNode
      BinaryNode<T> * tempLeft = new BinaryNode<T>(data);
      this->addLeft(tempLeft);

      numItems++;

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
   // cout << "debug: currently in addRight(const T &data)\n";
   try
   {
      // allocate a new BinaryNode
       BinaryNode<T> * tempRight = new BinaryNode<T>(data);
       this->addRight(tempRight);

       numItems++;

       
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
void BinaryNode<T>::addRight(BinaryNode<T> * tempRight)
throw (const char *)
{   
   //cout << "debug: currently in addRight(BinaryNode<T> *pRight)\n";
   try
   {
      // allocate a new BinaryNode
//    BinaryNode<T> * pNew = new BinaryNode<T>(pRight->data);

      this->pRight = tempRight;
      
      // if we are inserting to the head position
      if(tempRight != NULL)
      {
         this->pRight->pParent = this;
         numItems += 2;
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
//      cout << "DeBug: entered delete loop.\n";
      BinaryNode<T> * p = pParent->pLeft;
      
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
//  out << "debug: currently in operator<<\n";
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
