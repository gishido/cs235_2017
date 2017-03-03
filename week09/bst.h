/***********************************************************************
 * Component:
 *    Week 09, Binary Search Tree (BST)
 *    Brother Helfrich, CS 235
 * Author:
 *    
 * Summary:
 *    
 ************************************************************************/

#ifndef BST_H
#define BST_H

#include "bnode.h"

//predefine BESTIterator class
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
        BST() : myRoot(NULL), numItems(0) {}

        //non-default constructor
        //  I'm not sure if this is correct or not
        BST(const T * item)
        {
            BinaryNode<T> * newNode = new BinaryNode<T>(item);
            myRoot = newNode;

            numItems++;
        }

        //desctructor
        ~BST() {}

        //empty function
        bool empty() const {return (myRoot == NULL);}

        //size function
        int size() const {return numItems;}

        //insert function
        void insert(const T * item);

        //data elements
        BinaryNode<T> * myRoot;
        int numItems;
 };



/**************************************************
* BST ITERATOR :: DECREMENT PREFIX
*     advance by one. Note that this implementation uses
*     a stack of nodes to remember where we are. This stack
*     is called "nodes".
* Author:      Br. Helfrich
* Performance: O(log n) though O(1) in the common case
*************************************************/

// //I'm not sure this is correct.  I'm commenting out the iterator for now
// template <class T>
// class BSTIterator
// {
//     BSTIterator <T> & operator -- ()
//     {
//     // do nothing if we have nothing
//     if (nodes.top() == NULL)
//         return *this;

//     // if there is a left node, take it
//     if (nodes.top()->pLeft != NULL)
//     {
//         nodes.push(nodes.top()->pLeft);

//         // there might be more right-most children
//         while (nodes.top()->pRight)
//             nodes.push(nodes.top()->pRight);
//         return *this;
//     }

//     // there are no left children, the right are done
//     assert(nodes.top()->pLeft == NULL);
//     BinaryNode <T> * pSave = nodes.top();
//     nodes.pop();

//     // if the parent is the NULL, we are done!
//     if (NULL == nodes.top())
//         return *this;

//     // if we are the right-child, got to the parent.
//     if (pSave == nodes.top()->pRight)
//         return *this;

//     // we are the left-child, go up as long as we are the left child!
//     while (nodes.top() != NULL && pSave == nodes.top()->pLeft)
//     {
//         pSave = nodes.top();
//         nodes.pop();
//     }

//     return *this;
//     }

// };

/**************************************************
* BST INSERT :: Insert Function
*    I'm referenceing pages 679 and 680 in the book
*    for 12.4 Binary Search Trees
*************************************************/
template <class T>
void BST<T>::insert(const T * item)
{
    bool found = false;     //indicates if item already in BST
    //search pointer (ref. book pg. 679 - still need to 
    //  understand a couple things about how this works
    BinaryNode<T> * locptr = myRoot;     
    BinaryNode<T> * parent = NULL;            //pointer to parent of current node.
    
    while (!found && locptr != 0)
    {
        parent = locptr;
        if (item < locptr->data)  //descent left
            locptr = locptr->pLeft;
        else if (item < parent->data) //insert to left of parent
            parent->pLeft = locptr;
        else                            //insert to right of parent
            parent->pRight = locptr;
    }
    if (!found)
    {                               //construct node containing item
        locptr = new BST<T>(item); //need to fix/create non-default constructor for this case
        if (parent == 0)           //empty tree
            myRoot = locptr;
        else if (item < parent->data) //insert to left of parent
            parent->pLeft = locptr;
        else                        //insert to right of parent
            parent->pRight = locptr;        
    }
    else
        parent->pRight = locptr;
}

#endif // BST_H

