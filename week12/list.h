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
  ListIterator<T> remove(ListIterator<T> &it) throw(const char *);

  //void insert and item in the list
  ListIterator<T> insert(ListIterator<T> &it, const T &value)
     throw(const char *);

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
      pNode->pNext = first;

      //connect current head to new node
      if (first != NULL)
        first->pPrev = pNode;
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
  ListIterator<T> rbegin() { return ListIterator<T>(last); }

  // return the const iterator to the end of the list
  ListConstIterator<T> crend() const { return ListConstIterator<T>(NULL); }
  ListIterator<T> rend() { return ListIterator<T>(NULL); }

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

/*************************************************
 * LIST ITERATOR
 * Iterate through a List, non-constant version
 ************************************************/
template <class T>
class ListIterator
{
  public:
    // default constructor: not pointing to anything
    ListIterator() : p(NULL) { }
    // non-default constrictor taking a pointer as a parameter
    ListIterator(Node<T> *p) : p(p) { }
    // copy constructor
    ListIterator(const ListIterator<T> &rhs) : p(rhs.p) { }
    // assignment operator
    ListIterator<T> &operator=(const ListIterator<T> &rhs) 
    { 
      p = rhs.p;
      return *this;
    } 
    // dereference operator, fetch a node
    T &operator*() throw(const char *)
    {
      if (p)
        return p->data;
      else
        throw "ERROR: Trying to dereference a NULL pointer";
    }
    // equals operator: are the iterators the same?
    bool operator==(const ListIterator<T> &rhs) const
    {
      return rhs.p == this->p;
    }
    // not-equals operator: are the iterators different?
    bool operator!=(const ListIterator<T> &rhs) const
    {
      return rhs.p != this->p;
    }
    // postfix increment
    ListIterator<T> operator++(int postfix)
    {
      ListIterator<T> old(*this);
      assert(p);
      p = p->pNext;
      return old;
    }
    // prefix increment
    ListIterator<T> &operator++()
    {
      assert(p);
      p = p->pNext;
      return *this;
    }
    
    // postfix decrement
    ListIterator<T> operator--(int postfix)
    {
      ListIterator<T> old(*this);
      assert(p);
      p = p->pPrev;
      return old;
    }
    // prefix decrement
    ListIterator<T> &operator--()
    {
      assert(p);
      p = p->pPrev;
      return *this;
    }
    
    // two friends who need to access p directly
    friend ListIterator<T> List<T>::insert(ListIterator<T> &it, const T &data)
      throw(const char *);
    friend ListIterator<T> List<T>::remove(ListIterator<T> &it) throw(const char *);
  private:
    Node<T> *p;
};

/*************************************************
 * LIST CONST ITERATOR
 * Iterate through a List, the constant version
 ************************************************/
template <class T>
class ListConstIterator
{
  public:
    // default constructor: not pointing to anything
    ListConstIterator() : p(NULL) { }
    // non-default constrictor taking a pointer as a parameter
    ListConstIterator(const Node<T> *p) : p(p) { }
    // copy constructor
    ListConstIterator(const ListConstIterator<T> &rhs) : p(rhs.p) { }
    // assignment operator
    ListConstIterator<T> &operator=(const ListConstIterator<T> &rhs)
    {
      p = rhs.p;
      return *this;
    }
    // dereference operator, fetch a node
    // this is the only real difference between ListConstIterator and the other
    T operator*() const
    {
      return p->data;
    }
    // equals operator: are the iterators the same?
    bool operator==(const ListConstIterator<T> &rhs) const
    {
      return rhs.p == this->p;
    }
    // not-equals operator: are the iterators different?
    bool operator!=(const ListConstIterator<T> &rhs) const
    {
      return rhs.p != this->p;
    }
    // postfix increment
    ListConstIterator<T> operator++(int postfix)
    {
      ListConstIterator<T> old(*this);
      assert(p);
      p = p->pNext;
      return old;
    }
    // prefix increment
    ListConstIterator<T> &operator++()
    {
      assert(p);
      p = p->pNext;
      return *this;
    }
    
    // postfix decrement
    ListConstIterator<T> operator--(int postfix)
    {
      ListConstIterator<T> old(*this);
      assert(p);
      p = p->pPrev;
      return old;
    }
    // prefix decrement
    ListConstIterator<T> &operator--()
    {
      assert(p);
      p = p->pPrev;
      return *this;
    }
  private:
    const Node<T> *p;
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
  for (Node<T> * p = first; p; p =p->pNext)
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
    Node<T> * pNode = new Node<T>(value);

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
 * remove a single node from the list
 *************************************************/
template <class T>
ListIterator<T> List<T>::remove(ListIterator<T> &it) throw(const char *)
{
  ListIterator<T> itNext = end();

  //invalid iterator
  if (it == end())
    throw "ERROR: enable to remove from an invalid locaton in a list";

  assert(first && last);

  //prep nodes after current node (from iterator)
  if (it.p->pNext)
  {
    it.p->pNext->pPrev = it.p->pPrev;
    itNext = it.p->pNext;
  }
  else
  {
    //already last node
    last = last->pPrev;
  }

  //not the first node
  if (it.p->pPrev)
  {
    it.p->pPrev->pNext = it.p->pNext;
  }
  else
  {
    first = first->pNext;
  }

  //self cleanup
  delete it.p;
  numItems--;

  return itNext;

}

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
