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
#include "stack.h" //if we use <stack>, make the Stack lower-case

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
        BST(const T &item)
        {
            BinaryNode<T> * newNode = new BinaryNode<T>(item);
            myRoot = newNode;

            //numItems++;
        }

        //desctructor
        ~BST() { clear(); } 

        //copy constructor

        //assignemnt operator

        //empty function
        bool empty() const {return (myRoot == NULL);}

        //size function
        //int size() const {return numItems;}
        int size() const
        {
            return 1 +
            (myRoot->pLeft== NULL? 0 : myRoot->pLeft->size()) +
            (myRoot->pRight == NULL ? 0 : myRoot->pRight->size());
        }
        
        //insert function
        void insert(const T &item);

        //clear
        void clear();

        // find
        BSTIterator<T> find();       
        
        //begin and end functions, returns iterators
        // not sure if this needs to be in this class or the iterator class
        BSTIterator<T>& begin()
        {
            BSTIterator<T> it;
            BinaryNode<T> * n = myRoot;
            Stack<BinaryNode<T>*> nodes;
            nodes.push(NULL);
            
            while (n != NULL)
            {
                nodes.push(n);
                n = n->pLeft;
            }
            
            BSTIterator<T> temp(nodes);
            it = temp;
            
            return it;
        }
        
        BSTIterator<T>& end()
        {
           BSTIterator<T> it;
           BSTIterator<T> temp(NULL);
           it = temp;
           return it;
        }

    private:
        //data elements
        BinaryNode<T> * myRoot;
        //int numItems;
 };

/***************************************
 * BST Iterator class
 *****************************************/
template <class T>
class BSTIterator
{

  public:
   // constructors
   BSTIterator(BinaryNode <T> * p = NULL)    { nodes.push(NULL);  }
   BSTIterator(Stack <BinaryNode <T> *> & s) { nodes = s;         }
   BSTIterator(const BSTIterator <T> & rhs)  { nodes = rhs.nodes; }

   // assignment
   BSTIterator <T> & operator = (const BSTIterator <T> & rhs)
   {
      // need an assignment operator for the Stack class.
      nodes = rhs.nodes;
   }

   // compare
   bool operator == (const BSTIterator <T> & rhs) const
   {
      // only need to compare the leaf node
      return rhs.nodes.top() == nodes.top();
   }
   bool operator != (const BSTIterator <T> & rhs) const
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

   // get the node pointer
   BinaryNode <T> * getNode() { return nodes.top(); }

  private:
   // the stack of nodes
   Stack < BinaryNode <T> * > nodes;
   
//    public:
        //default constructor
   //      BSTIterator() {}

        //non-default constructor

        //operator=
   //   BSTIterator<T> & operator= (const Stack<T> &rhs)
   //   {
            /*need create a new stack of binary nodes, iterate through
                rhs and return a BSTIterator
            */
   //   }

        /* These will need a stack called nodes, but I haven't 
        done this part yet, so it won't compile */
        //operator--
   //   BSTIterator<T> & operator-- (const Stack<T> &rhs);
        //operator++
   //   BSTIterator<T> & operator++ (const Stack<T> &rhs);

   // private:
   //   Stack<BinaryNode<T>> nodes;

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
    // do nothing if we have nothing
   //  if (nodes.top() == NULL)
   //   return *this;

    // if there is a left node, take it
   //  if (nodes.top()->pLeft != NULL)
   // {
   //   nodes.push(nodes.top()->pLeft);

        // there might be more right-most children
   //   while (nodes.top()->pRight)
   //       nodes.push(nodes.top()->pRight);
   //   return *this;
   //}

    // there are no left children, the right are done
   //  assert(nodes.top()->pLeft == NULL);
   // BinaryNode<T> * pSave = nodes.top();
   //  nodes.pop();

    // if the parent is the NULL, we are done!
   // if (NULL == nodes.top())
   //   return *this;

    // if we are the right-child, got to the parent.
   // if (pSave == nodes.top()->pRight)
   //   return *this;

    // we are the left-child, go up as long as we are the left child!
   // while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
   // {
   //   pSave = nodes.top();
   //   nodes.pop();
   //}

    return *this;
}

/**************************************************
* BST INSERT :: Insert Function
*    I'm referenceing pages 679 and 680 in the book
*    for 12.4 Binary Search Trees
*************************************************/
template <class T>
void BST<T>::insert(const T &item)
{
    //cout << "debug: Inside insert\n";
    bool found = false;     //indicates if item already in BST
    //search pointer (ref. book pg. 679 - still need to 
    //  understand a couple things about how this works
    BinaryNode<T> * locptr = myRoot;     
    BinaryNode<T> * parent = NULL;   //pointer to parent of current node.
    
    while (!found && locptr != NULL)
    {
        //cout << "debug: insert - inside whileloop\n";
        //cout << "debug: insert - whileloop - locptr->data " << locptr->data << endl;
        parent = locptr;
        if (item < locptr->data)  //descend left
            locptr = locptr->pLeft;
        else if (locptr->data < item) //desend right
            locptr = locptr->pRight;
        else                            //item found
            found = true;
    }
    if (!found)
    {   
        //cout << "debug: insert - inside not found\n";                            //construct node containing item
        locptr = new BinaryNode<T>(item); //need to fix/create
                                //non-default constructor for this case
        if (parent == NULL)           //empty tree
            myRoot = locptr;
        else if (item < parent->data) //insert to left of parent
            parent->pLeft = locptr;
        else                        //insert to right of parent
            parent->pRight = locptr;      

        //numItems++;  
    }
    else
    {
        cout << "Item already in the tree\n";
    }

}

/**************************************************
* BST CLEAR :: set size to 0 and delete memory
*************************************************/
template <class T>
void BST<T>::clear()
{
   
}

/**************************************************
* BST CLEAR :: set size to 0 and delete memory
*************************************************/
template <class T>
BSTIterator<T> BST<T>::find()
{
    BSTIterator<T> it;
    return it;
}



#endif // BST_H

