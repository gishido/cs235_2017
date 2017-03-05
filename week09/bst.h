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
        BST(const T &item)
        {
            cout << "debug: non-default constructor - newNode create\n";
            //decided to try and insert here since it creates a new node for us
            insert(item);
            //myRoot = newNode;

            // cout << "debug: non-default constructor - new node, myRoot->data is - "
            //     << *myRoot->data << endl;
        }

        //desctructor
        ~BST() { clear(); } 

        //copy constructor

        //assignemnt operator
        BST<T> operator= (BST<T> &rhs)
        {

            BSTIterator<T> it;
            BinaryNode<T> * newNode = rhs.myRoot;
            myRoot = NULL;
            int count = 0;

            for (it = rhs.begin(); it != rhs.end(); ++it)
            {
                //cout << "debug: BST<T> operator= *it - " << *it << endl;
                insert(*it);
                //count++;
                //cout << "debug: BST<T> operator= insert(*it) " << count
                    //<< endl;
            }

            //cout << "debug: BST<T> operator= \n";

            return *this;
        }

        bool empty() const {return (myRoot == NULL);}

        //size function
        //int size() const {return numItems;}
        int size() const
        {
            if (myRoot == NULL)
                return 0;
            else
            {
                return 1 +
                (myRoot->pLeft== NULL? 0 : myRoot->pLeft->size()) +
                (myRoot->pRight == NULL ? 0 : myRoot->pRight->size());
            }
        }
        
        //insert function
        void insert(const T &item);

        //remove function;
        void remove(const BSTIterator<T> &it);

        //delete binarytree, used by clear
        void deleteBinaryTree(BinaryNode<T> * &pParent);

        //clear
        void clear() { deleteBinaryTree(myRoot); }

        // find
        BSTIterator<T> find(const T &item);       
        
        //begin and rbegin functions, returns iterators
        BSTIterator<T> begin()
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

        BSTIterator<T> rbegin()
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

        //end and rend iterators
        BSTIterator<T> end()
        {
            BSTIterator<T> it;
            BSTIterator<T> temp(NULL);
            it = temp;
            return it;
        }

         BSTIterator<T> rend()
        {
            BSTIterator<T> it;
            BSTIterator<T> temp(NULL);
            it = temp;
            return it;
        }

    private:
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

   // get the node pointer
   BinaryNode <T> * getNode() { return nodes.top(); }

  private:
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
//        cout << "Item already in the tree\n";
    }

}

/**************************************************
* BST REMOVE :: remove Function
*    I'm referenceing page 685 in the book
*    for 12.4 Binary Search Trees
*************************************************/
template <class T>
void BST<T>::remove(const BSTIterator <T> &it)
{
    bool found;
    BinaryNode<T> * x;
    BinaryNode<T> * parent;

    //will need a working search for this to be enabled
    //search2(item, found, x, parent);

    if (!found)
    {
        cout << "Item not in the BST\n";
//        return;
    }

    //else
    if (x->pLeft != NULL && x->pRight != NULL)
    {   //node has 2 children
        //Find x's inorder successor and its parent
        BinaryNode<T> * xSucc = x->pRight;
        parent = x;

        while (xSucc->pLeft != NULL)  //descend left
        {
            parent = xSucc;
            xSucc = xSucc->pLeft;
        }

        //move contents of xSucc to x and change xSucc
        //to point to successor, which will be removed.
        x->data = xSucc->data;
        x = xSucc;
    } //end if node has 2 children

    //now proceed with case where there are 0 or 1 children
    BinaryNode<T> * subtree = x->pLeft; //pointer to a subtree of x
    if (subtree == NULL)
        subtree = x->pRight;
    if (parent == NULL)     //root being removed
        myRoot = subtree;    
    else if (parent->pLeft == x) //left child of parent
        parent->pLeft = subtree;
    else                            //right child of parent
        parent->pRight = subtree;
    
    delete x;
}

/*************************************************
* BinaryNode delete
*************************************************/
template <class T>
void BST<T>::deleteBinaryTree(BinaryNode<T> * &pParent)
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

// /**************************************************
// * BST CLEAR :: set size to 0 and delete memory
// *************************************************/
// template <class T>
// void BST<T>::clear()
// {
   
// }

/**************************************************
* BST CLEAR :: set size to 0 and delete memory
*************************************************/
template <class T>
BSTIterator<T> BST<T>::find(const T &item)
{
    BinaryNode<T> * locptr = myRoot;     
    BinaryNode<T> * parent = NULL;   //pointer to parent of current node.

    while (locptr != NULL)
    {
        //cout << "debug: insert - inside whileloop\n";
        //cout << "debug: insert - whileloop - locptr->data " << locptr->data << endl;
        parent = locptr;
        if (item < locptr->data)  //descend left
            locptr = locptr->pLeft;
        else if (locptr->data < item) //desend right
            locptr = locptr->pRight;
        else                            //item found
            return BSTIterator<T>(locptr);
    }

    return end();

}



#endif // BST_H

