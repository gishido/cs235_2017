/*********************************************************************** 
* Header: 
*    BinaryNode 
* Summary: 
*    Implements Binary Tree 
* 
* Author 
*    
************************************************************************/ 

#ifndef BNODE_H 
#define BNODE_H 

#include <cassert> 
#include <iostream> 
#include <string> 
using namespace std; 

//NOTE: You may have tweak it!

/********************************************************************** 
* BINARYNODE 
* Binary Node Class 
***********************************************************************/ 
template <class T> 
class BinaryNode 
{ 
public: 
   //default constructor 
  BinaryNode() : pLeft(NULL), pRight(NULL), pParent(NULL), data(),  
      isRed(true) {  } 
   //non-default constructor 
  BinaryNode(const T & data) : pLeft(NULL), pRight(NULL), pParent(NULL),  
      data(data), isRed(true) {  } 

   //member variables 
   T data; 
   BinaryNode <T> *pLeft; 
   BinaryNode <T> *pRight; 
   BinaryNode <T> *pParent; 
   bool isRed; 

   //returns count of nodes in tree through recursion 
   int size() 
   { 
      int count = 1; 

      if (pLeft != NULL) 
      { 
         count += pLeft->size(); 
      } 
      if (pRight != NULL) 
      { 
         count += pRight->size(); 
      } 

      return count; 
   } 

   //simple case for adding new node.  data is passed in as param 
   void addLeft(const T & data) 
   { 
      BinaryNode<T> *newNode = new BinaryNode(data); 
      this->pLeft = newNode; 
      newNode->pParent = this; 
   } 
   //when existing node is passed in, we have to link it to the existing tree 
   void addLeft(BinaryNode<T>* newNode); 
    
   //both of these functions mirror the two above 
   void addRight(BinaryNode<T>* newNode); 
   void addRight(const T & data) 
   { 
      BinaryNode<T> *newNode = new BinaryNode(data); 
      this->pRight = newNode; 
      newNode->pParent = this; 
   } 

private: 
   //internal utility functions 
   int findDepth() const; 
   void verifyRedBlack(int depth) const; 
   void verifyBTree() const; 

}; 

/********************************************************************** 
* BINARYNODE :: ADD LEFT 
* Link existing node to left 
***********************************************************************/ 
template <class T> 
void BinaryNode <T> ::addLeft(BinaryNode<T>* newNode) 
{ 
   this->pLeft = newNode; 

   // this may be more complicated than it needs to be,  
   // but i wasn't passing some tests at first 
   if (newNode != NULL) 
   { 
      newNode->pParent = this; 

      if (newNode->pLeft != NULL) 
         newNode->pLeft = newNode->pLeft; 
      else 
         newNode->pLeft = NULL; 

      if (newNode->pRight != NULL) 
         newNode->pRight = newNode->pRight; 
      else 
         newNode->pRight = NULL; 
   } 
} 

/********************************************************************** 
* BINARYNODE :: ADD RIGHT 
* Link existing node to right 
***********************************************************************/ 
template <class T> 
void BinaryNode <T> :: addRight(BinaryNode<T>* newNode) 
{ 
   this->pRight = newNode; 

   if (newNode != NULL) 
   { 
      newNode->pParent = this; 

      if (newNode->pLeft != NULL) 
         newNode->pLeft = newNode->pLeft; 
      else 
         newNode->pLeft = NULL; 

      if (newNode->pRight != NULL) 
         newNode->pRight = newNode->pRight; 
      else 
         newNode->pRight = NULL; 
   } 
} 

/********************************************************************** 
* BINARYNODE :: DELETE BINARY TREE 
* recurses through the tree and deletes everything 
***********************************************************************/ 
template <class T> 
void deleteBinaryTree(BinaryNode <T> * leaf) 
{ 
   if (leaf == NULL) 
      return; 

   if (leaf->pLeft) 
      deleteBinaryTree(leaf->pLeft); 
   if (leaf->pRight) 
      deleteBinaryTree(leaf->pRight); 

   delete leaf; 
   leaf = NULL; 
} 

/********************************************************************** 
* BINARYNODE :: INSERTION OPERATOR  (<<) OVERLOAD 
* prints in LVR format 
***********************************************************************/ 
template <class T> 
std::ostream & operator << (std::ostream & out, BinaryNode<T> * pStart) 
{ 
   if (pStart != NULL) 
   { 
      out << (pStart->pLeft); 
      std::cout << pStart->data << " "; 
      out << (pStart->pRight); 
   } 

   return out; // always return out 
} 

/**************************************************** 
 * BINARY NODE :: FIND DEPTH 
 * Find the depth of the black nodes. This is useful for 
 * verifying that a given red-black tree is valid 
 * Author: Br. Helfrich 
 ****************************************************/ 
template <class T> 
int BinaryNode <T> :: findDepth() const 
{ 
   // if there are no children, the depth is ourselves 
   if (pRight == NULL && pLeft == NULL) 
      return (isRed ? 0 : 1); 

   // if there is a right child, go that way 
   if (pRight != NULL) 
      return (isRed ? 0 : 1) + pRight->findDepth(); 
   else 
      return (isRed ? 0 : 1) + pLeft->findDepth(); 
} 

/**************************************************** 
 * BINARY NODE :: VERIFY RED BLACK 
 * Do all four red-black rules work here? 
 * Author: Br. Helfrich 
 ***************************************************/ 
template <class T> 
void BinaryNode <T> :: verifyRedBlack(int depth) const 
{ 
   depth -= (isRed == false) ? 1 : 0; 

   // Rule a) Every node is either red or black 
   assert(isRed == true || isRed == false); // this feels silly 

   // Rule b) The root is black 
   if (pParent == NULL) 
      assert(isRed == false); 

   // Rule c) Red nodes have black children 
   if (isRed == true) 
   { 
      if (pLeft != NULL) 
         assert(pLeft->isRed == false); 
      if (pRight != NULL) 
         assert(pRight->isRed == false); 
   } 

   // Rule d) Every path from a leaf to the root has the same # of black nodes 
   if (pLeft == NULL && pRight && NULL) 
      assert(depth == 0); 
   if (pLeft != NULL) 
      pLeft->verifyRedBlack(depth); 
   if (pRight != NULL) 
      pRight->verifyRedBlack(depth); 
} 

/****************************************************** 
 * VERIFY B TREE 
 * Verify that the tree is correctly formed 
 * Author: Br. Helfrich 
 ******************************************************/ 
template <class T> 
void BinaryNode <T> :: verifyBTree() const 
{ 
   // check parent 
   if (pParent) 
      assert(pParent->pLeft == this || pParent->pRight == this); 

   // check left 
   if (pLeft) 
   { 
      assert(pLeft->data <= data); 
      assert(pLeft->pParent == this); 
      pLeft->verifyBTree(); 
   } 

   // check right 
   if (pRight) 
   { 
      assert(pRight->data >= data); 
      assert(pRight->pParent == this); 
      pRight->verifyBTree(); 
   } 
} 

#endif  // BNODE_H 