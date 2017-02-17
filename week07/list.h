/***********************************************************************
*Header : *Node.h header file
*Author : *Adam Shumway, Jenaca Willans
*Summary : *Node Template Class Header File
************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <cassert> //for asserts
#include <iostream>
#include <string>
//#include <iomanip>

using namespace std;

//forward declaration for ListIterator
template <class T>
class ListIterator;

//forward declaration for ListConstIterator
template <class T>
class ListConstIterator;

/*************************************************
* List
* A List clas template that holds stuff, like nodes
*************************************************/
template <class T>
class List
{
public:
  List() : numItems(0), first(NULL) {}

  //List(const T &t) : data(t), pNext(NULL) {}

  ~List()
  {
    //     while (pHead != NULL)
    //   {
    // pNext = pHead->pNext;
    // delete pHead;
    // pHead = pNext;
    //}
  }

  // is the container currently empty
  bool empty() const { return (numItems == 0); }

  // remove all the items from the container
  void clear();

  // how many items are currently in the container?
  int size() { return numItems; }

  //void remove(List<T> * &pHead) {};
  void remove() {}

  // push items to the back of the list
  void push_back(const T &value) throw(const char *)
  {
    int newBack;
    try
    {
      Node *tempNode = new Node(value);
    }
    catch (std::bad_alloc)
    {
      throw "ERROR: Unable to allocate a new node for a list";
    }
  }

  // push items to the front of the List
  void push_front(const T &value) throw(const char *)
  {
    int newFront;

    try
    {
      Node *tempNode = new Node(value);
    }
    catch (std::bad_alloc)
    {
      throw "ERROR: Unable to allocate a new node for a list";
    }
  }

  // front
  T &front() throw(const char *)
  {
    if (!empty())
    {
      //return myArray[myFront];
    }
    else
    {
      throw "ERROR: unable to access data from an empty list";
    }
  }

  // back
  T &back() throw(const char *)
  {
    if (!empty())
    {
      //      return myArray[myBack];
    }
    else
    {
      throw "ERROR: unable to access data from an empty list";
    }
  }

  // ostream & operator<<(ostream & out, const List<T> * pHead);

  // return an iterator to the beginning of the list
  // ListIterator<T> begin() { return ListIterator<T>(data); }
  // ListIterator<T> begin() { }

  // // return an iterator to the end of the list
  // // ListIterator<T> end() { return ListIterator<T>(data + numItems); }
  // ListIterator<T> end() { }

  // // return the const iterator to the beginning of the list
  // // ListConstIterator<T> rbegin() const { return ListConstIterator<T>(data); }
  // ListConstIterator<T> rbegin() const {}

  // // return the const iterator to the end of the list
  // // ListConstIterator<T> rend() const
  // // { return ListConstIterator<T>(data + numItems); }
  // ListConstIterator<T> rend() const { }

  operator=(const List<T> &rhs) throw(const char *) {}

private:
  /*************************************************
    * Node
    * A Node template that holds stuff
    *************************************************/
  // template <class T>
  class Node
  {
  public:
    Node() : data(0), pNext(NULL), pPrev(NULL) {}
    Node(const T &t) : data(t), pNext(NULL), pPrev(NULL) {}

    T data;
    Node *pNext;
    Node *pPrev;
  };

  int numItems;
  Node *first;
};

// template <class T>
// List<T> * copy(List<T> * &rhslist)
// {
//    //create new List
//    List<T> * pNew = new List<T>;
//    //point to new List...basially new head of list
//    List<T> * pCopy = pNew;

//    //copy first data item
//    pNew->data = pHead->data;
//    pHead = pHead->pNext;

//    //if more than 1 data item, copy the rest
//    while (pHead != NULL)
//    {
//       //create new List with data
//       pNew->pNext = new List<T>(pHead->data);
//       //advance Lists
//       pHead = pHead->pNext;
//       pNew = pNew->pNext;
//    }

//    //return head of copy
//    return pCopy;
// }

/**************************************************
 * List ITERATOR
 * An iterator through Container
 *************************************************/
template <class T>
class ListIterator
{
public:
  //default constructor
  ListIterator() : p(NULL) {}

  //initialize to direct p to some item
  ListIterator(T *p) : p(p) {}

  //copy contructor
  ListIterator(const ListIterator &rhs) { *this = rhs; }

  //assignment operator
  ListIterator &operator=(const ListIterator &rhs)
  {
    this->p = rhs.p;
    return *this;
  }

  //not equals operator
  bool operator!=(const ListIterator &rhs) const
  {
    return rhs.p != this->p;
  }

  //de-reference operator
  T &operator*() { return *p; }

  //prefix increment
  ListIterator<T> &operator++()
  {
    p++;
    return *this;
  }

  //postfix increment
  ListIterator<T> operator++(int postfix)
  {
    ListIterator tmp(*this);
    p++;
    return tmp;
  }

  //pre-decrement
  ListIterator<T> &operator--()
  {
    p--;
    return *this;
  }

  //post-decrement
  ListIterator<T> &operator--(int decrement)
  {
    ListIterator tmp(*this);
    p--;
    return tmp;
  }

private:
  T *p;
};

/**************************************************
 * List Const ITERATOR
 * A const iterator through Container
 *************************************************/
template <class T>
class ListConstIterator
{
public:
  //default constructor
  ListConstIterator() : p(NULL) {}

  //initialize to direct p to some item
  ListConstIterator(T *p) : p(p) {}

  //copy contructor
  ListConstIterator(const ListConstIterator &rhs) { *this = rhs; }

  //assignment operator
  ListConstIterator &operator=(const ListConstIterator &rhs)
  {
    this->p = rhs.p;
    return *this;
  }

  //not equals operator
  bool operator!=(const ListConstIterator &rhs) const
  {
    return rhs.p != this->p;
  }

  //de-reference operator
  T &operator*() { return *p; }

  //prefix increment
  ListConstIterator<T> &operator++()
  {
    p++;
    return *this;
  }

  //postfix increment
  ListConstIterator<T> operator++(int postfix)
  {
    ListConstIterator tmp(*this);
    p++;
    return tmp;
  }

  //pre-decrement
  ListConstIterator<T> &operator--()
  {
    p--;
    return *this;
  }

  //post-decrement
  ListConstIterator<T> &operator--(int decrement)
  {
    ListConstIterator tmp(*this);
    p--;
    return tmp;
  }

private:
  T *p;
};

// template <class T>
// List<T> * insert(const T & data, List<T> * &pHead, bool head = false)
// throw (const char *)
// {   
//    try
//    {
//       // allocate a new List
//       List<T> * pNew = new List<T>(data);
      
//       // if we are inserting to the head position
//       if(head || pHead == NULL)
//       {
//          pNew->pNext = pHead;
//          pHead = pNew;
//       }
//       else
//       {
//          pNew->pNext = pHead->pNext;
//          pHead->pNext = pNew;
         
//       }
//    }
//    catch(string pList) 
//    {
//       throw "Error: Unable to allocate a new List";
//    }
   
//    return pHead;
   
// }

// template <class T>
// List<T> * find(List<T> * pHead, const T &t)
// {
//    // iterate through list and compare value to data
//    for (List<T> * p = pHead; p; p = p->pNext)
//    {
//       if (p->data == t)
//          return pHead;
//    }
   
//    pHead = NULL;
//    return pHead;
// }

// template <class T>
// void freeData(List<T> * & pHead)
// {
//    //delete items from the list
//    while (pHead != NULL)
//    {
//       List<T> * p = pHead->pNext;
//       delete pHead;
//       pHead = p;
//    }
   
//    pHead = NULL;
// }

// template <class T>
// ostream & List<T>::operator<<(ostream & out, const List<T> * pHead)
// {
//   //  // operator overload to display the list
//   //  for (const List<T> * p = pHead; p; p = p->pNext)
//   //  {
//   //     if(p->pNext != NULL)
//   //     {
//   //        out << p->data << ", ";
//   //     }
//   //     else
//   //     {
//   //        out << p->data;
//   //     }
//   //  }
//    return out;
// }

#endif //LIST_H
