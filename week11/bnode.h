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
  BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL),
    data(0) { }
  BinaryNode(const T &t): pLeft(NULL), pRight(NULL), pParent(NULL),
    data(t) {  } 
   
   int size() const
   {
      return 1 +
         (pLeft== NULL? 0 : pLeft->size()) +
         (pRight == NULL ? 0 : pRight->size());
   }

   // add new node with data
   void addLeft(BinaryNode<T> * pParent) throw (const char *);
   void addLeft(const T & data) throw (const char *);

   // insert passed node
   void addRight(BinaryNode<T> * pRight) throw (const char *);
   void addRight(const T & data) throw (const char *);

   // class variables
   T data;
   BinaryNode<T> * pLeft;
   BinaryNode<T> * pRight;
   BinaryNode<T> * pParent;
   
};

/*************************************************
* BinaryNode insert passed node to left
*************************************************/
template <class T>
void BinaryNode<T>::addLeft(BinaryNode<T> * tempLeft)
throw (const char *)
{   
   try
   {
      this->pLeft = tempLeft;
      
      // if we are inserting to the left position
      if(tempLeft != NULL)
      {
         this->pLeft->pParent = this;
      }
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
      
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
      BinaryNode<T> * tempLeft = new BinaryNode<T>(data);
      this->addLeft(tempLeft);
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
}

/*************************************************
* BinaryNode insert passed node to right
*************************************************/
template <class T>
void BinaryNode<T>::addRight(BinaryNode<T> * tempRight)
throw (const char *)
{   
   try
   {
      this->pRight = tempRight;
      
      // if we are inserting to the right position
      if(tempRight != NULL)
      {
         this->pRight->pParent = this;
      }
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
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
       BinaryNode<T> * tempRight = new BinaryNode<T>(data);
       this->addRight(tempRight);
   }
   catch(string pBinaryNode) 
   {
      throw "Error: Unable to allocate a new BinaryNode";
   }
   
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
ostream & operator<<(ostream & out, const BinaryNode<T> * pNode)
{
   // operator overload to display the list
   for (const BinaryNode<T> * p = pNode; p; p = p->pRight)
   {      
     out << p->pLeft;
     out << p->data << " ";
     out << p->pRight;
   }
   
   return out;
}

#endif //BINARYNODE_H
