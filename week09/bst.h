/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"
#include "stack.h"

using namespace std;

//predefine BSTIterator class
template <class T>
class BSTIterator;

/**************************************************
 * BST Template Class
 *************************************************/
 template <class T>
 class BST
 {
     public:
        //default constructor
        BST() : myRoot(NULL) {}

        //non-default constructor
        /*  I'm not sure if this is correct or not
             I don't think this is used correctly...need to reference
             week09.cpp to see if it's ever called or if we need
             something for the copy constructor
        */
        BST(const BST<T> &rhs)
        {
            *this = rhs;
        }

        //desctructor
        ~BST() { clear(); } 

        //copy constructor

        //assignemnt operator
        BST<T> operator= (const BST<T> &rhs) throw (const char *)
        {

            clear();
            if (rhs.myRoot != NULL)
            {
                try
                {
                    this->myRoot = new BinaryNode<T> (rhs.myRoot->data);
                    copyBinaryTree(rhs.myRoot, this->myRoot);
                }
                catch (...)
                {
                    throw "ERRORL: Unable to allocate a node";
                }
            }

            return *this;
        }

        bool empty() const {return (myRoot == NULL);}

        //size function
        int size() const
        {
            return empty() ? 0 : myRoot->size();
        }
        
        //insert function
        void insert(const T &item) throw (const char *);

        //remove function;
        void remove(BSTIterator<T> &it);

        //delete binarytree, used by clear
        //void deleteBinaryTree(BinaryNode<T> * &pParent);

        //clear
        void clear() 
        {
            if(myRoot)
                deleteBinaryTree(myRoot);
            assert(empty());
         }

        // find
        BSTIterator<T> find(const T &item);       
        
        //begin and rbegin functions, returns iterators
        BSTIterator<T> begin()
        {
            Stack <BinaryNode<T> *> nodes;

            nodes.push(NULL);
            nodes.push(myRoot);
            while (nodes.top() != NULL && nodes.top()->pLeft)
                nodes.push(nodes.top()->pLeft);
            
            return BSTIterator<T>(nodes);
        }

        BSTIterator<T> rbegin()
        {
            Stack <BinaryNode<T> *> nodes;

            nodes.push(NULL);
            nodes.push(myRoot);
            while (nodes.top() != NULL && nodes.top()->pRight)
                nodes.push(nodes.top()->pRight);
            
            return BSTIterator<T>(nodes);
        }

        //end and rend iterators
        BSTIterator<T> end() { return BSTIterator<T>(NULL); }

        BSTIterator<T> rend() { return BSTIterator<T>(NULL); }

    private:
        void deleteNode(BinaryNode<T> * &pDelete, bool toRight);
        //data elements
        BinaryNode<T> * myRoot;
 };

/***************************************
 * BST Iterator class
 *****************************************/
template <class T>
class BSTIterator
{

  public:
   // constructors
   BSTIterator(BinaryNode<T> * p = NULL)    { nodes.push(NULL);  }
   BSTIterator(Stack <BinaryNode<T> *> & s) { nodes = s;         }
   BSTIterator(const BSTIterator<T> & rhs)  { nodes = rhs.nodes; }

   // assignment
   BSTIterator<T> & operator = (const BSTIterator<T> &rhs)
      throw (const char *)
   {
      // need an assignment operator for the Stack class.
      
      nodes = rhs.nodes;
      return *this; 
   }

   // compare
   bool operator == (const BSTIterator<T> &rhs) const
   {
      // only need to compare the leaf node
      return rhs.nodes.top() == nodes.top();
   }
   bool operator != (const BSTIterator<T> &rhs) const
   {
      // only need to compare the leaf node
      return rhs.nodes.top() != nodes.top();
   }

   // de-reference
   T & operator * ()
   {
      return nodes.top()->data;
   }

   // iterators
   BSTIterator <T> & operator ++ ();
   BSTIterator <T>   operator ++ (int postfix)
   {
      BSTIterator <T> itReturn = *this;
      ++(*this);
      return itReturn;
   }
   BSTIterator <T> & operator -- ();
   BSTIterator <T>   operator -- (int postfix)
   {
      BSTIterator <T> itReturn = *this;
      --(*this);
      return itReturn;
   }

   //made friend so can call getNode()
   friend void BST<T>::remove(BSTIterator<T> &it);

  private:
   // get the node pointer
   BinaryNode<T> * getNode() { return nodes.top(); }

   // the stack of nodes
   Stack < BinaryNode <T> * > nodes;
   
};

/**************************************************
* BST ITERATOR :: DECREMENT PREFIX
*     advance by one. Note that this implementation uses
*     a stack of nodes to remember where we are. This stack
*     is called "nodes".
* Author:      Br. Helfrich
* Performance: O(log n) though O(1) in the common case
*************************************************/
//I'm not sure this is correct.  I'm commenting out the iterator for now
template <class T>
//BSTIterator<T> & BSTIterator<T>::operator-- (const Stack<T> &rhs)
BSTIterator<T> & BSTIterator<T>::operator-- ()
{
//   cout << "Debug: called decrement prefix\n";
   // do nothing if we have nothing
    if (nodes.top() == NULL)
        return *this;

    // if there is a left node, take it
      if (nodes.top()->pLeft != NULL)
   {
      nodes.push(nodes.top()->pLeft);

        // there might be more right-most children
      while (nodes.top()->pRight)
          nodes.push(nodes.top()->pRight);
      return *this;
   }

    // there are no left children, the right are done
    assert(nodes.top()->pLeft == NULL);
    BinaryNode<T> * pSave = nodes.top();
    nodes.pop();

    // if the parent is the NULL, we are done!
    if (NULL == nodes.top())
       return *this;

    // if we are the right-child, got to the parent.
   if (pSave == nodes.top()->pRight)
     return *this;

    // we are the left-child, go up as long as we are the left child!
    while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   {
      pSave = nodes.top();
      nodes.pop();
   }

    return *this;
}

/**************************************************
* BST ITERATOR :: INCREMENT PREFIX
*     advance by one. Note that this implementation uses
*     a stack of nodes to remember where we are. This stack
*     is called "nodes".
* Author:      Adam and Jenaca, modified from operator--
* Performance: O(log n) though O(1) in the common case
*************************************************/
//this needs some work... it is basically a copy of operator-- right now
template <class T>
//BSTIterator<T> & BSTIterator<T>::operator++ (const Stack<T> &rhs)
BSTIterator<T> & BSTIterator<T>::operator++ ()
{
//   cout << "Debug: in increment prefix\n";
   
    // do nothing if we have nothing
     if (nodes.top() == NULL)
      return *this;

    // if there is a right node, take it
     if (nodes.top()->pRight != NULL)
    {
        nodes.push(nodes.top()->pRight);

        // there might be more left-most children
      while (nodes.top()->pLeft)
          nodes.push(nodes.top()->pLeft);
      return *this;
   }

    // there are no right children, the left is done
     assert(nodes.top()->pRight == NULL);
      BinaryNode<T> * pSave = nodes.top();
     nodes.pop();

    // if the parent is the NULL, we are done!
    if (NULL == nodes.top())
      return *this;

    // if we are the left-child, got to the parent.
   if (pSave == nodes.top()->pLeft)
     return *this;

    // we are the right-child, go up as long as we are the right child!
   while (nodes.top() != NULL && pSave == nodes.top()->pRight)
   {
        pSave = nodes.top();
        nodes.pop();
   }

    return *this;
}

/**************************************************
* BST INSERT :: Insert Function
*    I'm referenceing pages 679 and 680 in the book
*    for 12.4 Binary Search Trees
*************************************************/
template <class T>
void BST<T>::insert(const T &item) throw (const char *)
{
    try
    {
        //if empty tree, create new root
        if (myRoot == NULL)
        {
            myRoot = new BinaryNode<T> (item);
            return;
        }

        // search for the correct place to insert
        BinaryNode<T> * node = myRoot;
        bool complete = false;

        while (!complete)
        {
            // if center is larger, go left
            if (node->data > item)
            {
                //follow node to left
                if (node->pLeft)
                    node = node->pLeft;
                //if we're at the bottom, create new node
                else
                {
                    node->addLeft(item);
                    complete = true;
                }
            }
            //if center is smaller, go right
            else
            {
                //follow node to right
                if (node->pRight)
                    node = node->pRight;
                //if we're at the bottom, create new node
                else
                {
                    node->addRight(item);
                    complete = true;
                }
            }
        }
    }
    catch (...)
    {
        throw "ERROR: Unable to allocate a node";
    }
}

/**************************************************
* BST REMOVE :: remove Function
*    I'm referenceing page 685 in the book
*    for 12.4 Binary Search Trees
*************************************************/
template <class T>
void BST<T>::remove(BSTIterator<T> &it)
{
    //find the node
    BinaryNode<T> * pNode = it.getNode();
    
    //if node is NULL, return
    if (pNode == NULL)
        return;
    
    //if there is only one child
    if (pNode->pLeft == NULL)
        deleteNode(pNode, true);

    //if only one child (left)
    else if (pNode->pRight == NULL)
        deleteNode(pNode, false);
    
    //otherwise switch 
    else
    {
        BinaryNode<T> * pNew = pNode->pRight;
        while (pNew->pLeft != NULL)
            pNew = pNew->pLeft;
        
        //copy data
        pNode->data = pNew->data;

        //if there any remaining children, fix them
        assert(pNew->pLeft == NULL);
        deleteNode(pNew, true);

        //delete prep
        pNode = pNew;
    }

    delete pNode;
}

/*************************************************
* BinaryNode delete
*************************************************/
template <class T>
void BST<T>::deleteNode(BinaryNode<T> * &pDelete, bool toRight)
{
   // shift everything up
   BinaryNode <T> * pNext = (toRight ? pDelete->pRight : pDelete->pLeft);

   // if we are not the parent, hook ourselves into the existing tree
   if (pDelete != myRoot)
   {
      if (pDelete->pParent->pLeft == pDelete)
      {
         pDelete->pParent->pLeft = NULL;
         pDelete->pParent->addLeft(pNext);
      }
      else
      {
         pDelete->pParent->pRight = NULL;
         pDelete->pParent->addRight(pNext);
      }

   }

   //other new root
   else
   {
       myRoot = pNext;
       pNext->pParent = NULL;
   }
}

// /*************************************************
// * BinaryNode delete
// *************************************************/
// template <class T>
// void BST<T>::deleteBinaryTree(BinaryNode<T> * &pParent)
// {
//    //delete items from the list
//    while (pParent != NULL)
//    {
//       BinaryNode<T> * p = pParent->pLeft;
      
//       delete pParent;
//       pParent = p;
 
//    }

//    pParent = NULL;
// }

// /**************************************************
// * BST CLEAR :: set size to 0 and delete memory
// *************************************************/
// template <class T>
// void BST<T>::clear()
// {
   
// }

/**************************************************
* BST FIND :: loop through tree to find item
*************************************************/
template <class T>
BSTIterator<T> BST<T>::find(const T &item)
{
    Stack <BinaryNode<T> *> nodesFound;

    nodesFound.push(myRoot);

    while (nodesFound.top() != NULL)
    {
        if (nodesFound.top()->data == item)
            return nodesFound;
        if (nodesFound.top()->data > item)
            nodesFound.push(nodesFound.top()->pLeft);
        else
            nodesFound.push(nodesFound.top()->pRight);
    }

    return BSTIterator<T> ();
}



#endif // BST_H

