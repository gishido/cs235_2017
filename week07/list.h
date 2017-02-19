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
    * Node
    * A Node template that holds stuff
    *************************************************/
  template <class T>
  class Node
  {
   
    public:
      Node() : data(0), pNext(NULL), pPrev(NULL) {}
      Node(const T &t) : data(t), pNext(NULL), pPrev(NULL) {}

      T data;
      Node<T> *pNext;
      Node<T> *pPrev;
  };

/*************************************************
* List
* A List clas template that holds stuff, like nodes
*************************************************/
template <class T>
class List
{
public:
  List() : numItems(0), first(NULL), last(NULL) {}

  List(const List<T> &rhs) throw(const char *) : 
    numItems(0), first(NULL), last(NULL) { *this = rhs;}

  ~List()
  {
    clear();
  }

  // is the container currently empty
  bool empty() const { return (first == 0); }

  // remove all the items from the container
  void clear();

  // how many items are currently in the container?
  int size() { return numItems; }

  //void and item from the list
  void remove();

  //void insert and item in the list
  void insert();

  // push items to the back of the list
  void push_back(const T &value) throw(const char *)
  {
    
    try
    {
      //create new node and add data passed
      Node<T> * pNode = new Node<T>(value);
      
      //point to the previous node
      pNode->pPrev = last;

      //connect current last to new node
      if (last != NULL)
        last->pNext = pNode;
      else
        first = pNode;

      //connect curent to new
      last = pNode;
      numItems++;

    }
    catch (std::bad_alloc)
    {
      throw "ERROR: Unable to allocate a new node for a list";
    }

  }

  // push items to the front of the List
  void push_front(const T &value) throw(const char *)
  {
    try
    {
      //create new node and add data passed
      Node<T> * pNode = new Node<T>(value);
      
      //point to the head node
      pNode->pPrev = first;

      //connect current head to new node
      if (first != NULL)
        first->pNext = pNode;
      else
        last = pNode;

      //connect curent to new
      first = pNode;
      numItems++;

    }
    catch (std::bad_alloc)
    {
      throw "ERROR: Unable to allocate a new node for a list";
    }
  }

  // front
  T &front() throw(const char *)
  {
    if (first != NULL)
    {
      return first->data;
    }
    else
    {
      throw "ERROR: unable to access data from an empty list";
    }
  }

  // back
  T &back() throw(const char *)
  {
    if (first != NULL)
    {
      return last->data;
    }
    else
    {
      throw "ERROR: unable to access data from an empty list";
    }
  }

  // ostream & operator<<(ostream & out, const List<T> * pHead);

  // return an iterator to the beginning of the list
  ListIterator<T> begin() { return ListIterator<T>(first); }

  // // return an iterator to the end of the list
  ListIterator<T> end() { return ListIterator<T>(NULL); }


  // // return the const iterator to the beginning of the list
  ListConstIterator<T> crbegin() const { return ListConstIterator<T>(last); }
  ListConstIterator<T> rbegin() { return ListConstIterator<T>(last); }

  // return the const iterator to the end of the list
  ListConstIterator<T> crend() const { return ListConstIterator<T>(NULL); }
  ListConstIterator<T> rend() { return ListConstIterator<T>(NULL); }

  List<T> &operator=(const List<T> &rhs) throw(const char *) 
  {
    //clear existing nodes
    clear();
    
    //allocate nodes
    for (Node<T> * p = rhs.first; p; p = p->pNext)
      push_back(p->data);
 
    return *this;
  }

  //still trying to work out copy of the list
  void copy(List<T> * &rhs)
  {
    //create new List
    List<T> * newList;

    newList->first = rhs->first;
    newList->last = rhs->last;
    newList->numItems = rhs->numItems;

  }

private:
  int numItems;
  Node<T> * first;
  Node<T> * last;
};

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

/**************************************************
 * List Clear
 * remove every node from a list
 *************************************************/
template <class T>
void List<T>::clear()
{
  //loop through list and remove everything
  Node<T> * pNode;
  for (Node<T> * p = first; p; p = pNext)
  {
    pNode = p->pNext;
    delete p;
  }
  //null out the list
  first = last = NULL;
  numItems = 0;

}

/**************************************************
 * List Insert
 * insert a node in the list
 *************************************************/
template <class T>
ListIterator<T> List<T>::insert(ListIterator<T> &it, const T &value) throw(const char *)
{
  //if the list is empty
  if (first == NULL)
  {
    assert(last == NULL);
    first = last = new Node<T>(value);
    return begin();
  }

  //checking that first and last are set
  assert(last && first);
  assert(first->pPrev == NULL);
  assert(last->pNext == NULL);

  try
  {
    Node<T> * pNode = Node<T>(value);

    //if end of list
    if (it == end())
    {
      //update last
      last->pNext = pNode;
      pNode->pPrev = last;
      last = pNode;

      it = pNode;
    }
    else
    {
      //setting previous and next
      pNode->pPrev = it.p->pPrev;
      pNode->pNext = it.p;

      //update what next and previous point to
      if (pNode->pPrev)
        pNode->pPrev->pNext = pNode;
      else
        first = pNode;
      
      if (pNode->pNext)
        pNode->pNext->pPrev = pNode;
      else
        last = pNode;

      it = pNode;
    }
    //increment numItems
    numItems++;
  }
  catch (...)
  {
    throw "ERROR: unable to allocate a new node for list";
  }

  return it;
}

/**************************************************
 * List Remove
 * remove a single node form the list
 *************************************************/
template <class T>
ListIterator<T> List<T>::remove(ListIterator<T> &it) throw(const char *)
{

}
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
