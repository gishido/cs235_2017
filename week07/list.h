/***********************************************************************
* Header:
*    Node.h header file
* Author:
*    Adam Shumway, Jenaca Willans
* Summary: 
*    Node Template Class Header File
************************************************************************/

#ifndef LIST_H
#define LIST_H

#include <cassert> //for asserts
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

/*************************************************
* List
* A List struct template that holds stuff
*************************************************/
template <class T>
class List
{
  public:
  List() : data(0), pNext(NULL) {}
  List(const T &t) : data(t), pNext(NULL) {} 
   
   T data;
   List<T> * pNext;
   
};

template <class T>
List<T> * copy(List<T> * &pHead)
{
   //create new List
   List<T> * pNew = new List<T>;
   //point to new List...basially new head of list
   List<T> * pCopy = pNew;
   
   //copy first data item
   pNew->data = pHead->data;
   pHead = pHead->pNext;
   
   //if more than 1 data item, copy the rest
   while (pHead != NULL)
   {
      //create new List with data
      pNew->pNext = new List<T>(pHead->data);
      //advance Lists
      pHead = pHead->pNext;
      pNew = pNew->pNext;
   }
   
   //return head of copy
   return pCopy;
}

template <class T>
List<T> * insert(const T & data, List<T> * &pHead, bool head = false)
throw (const char *)
{   
   try
   {
      // allocate a new List
      List<T> * pNew = new List<T>(data);
      
      // if we are inserting to the head position
      if(head || pHead == NULL)
      {
         pNew->pNext = pHead;
         pHead = pNew;
      }
      else
      {
         pNew->pNext = pHead->pNext;
         pHead->pNext = pNew;
         
      }
   }
   catch(string pList) 
   {
      throw "Error: Unable to allocate a new List";
   }
   
   return pHead;
   
}

template <class T>
List<T> * find(List<T> * pHead, const T &t)
{
   // iterate through list and compare value to data
   for (List<T> * p = pHead; p; p = p->pNext)
   {
      if (p->data == t)
         return pHead;
   }
   
   pHead = NULL;
   return pHead;
}

template <class T>
void freeData(List<T> * & pHead)
{
   //delete items from the list
   while (pHead != NULL)
   {
      List<T> * p = pHead->pNext;
      delete pHead;
      pHead = p;
   }
   
   pHead = NULL;
}

template <class T>
ostream & operator<<(ostream & out, const List<T> * pHead)
{
   // operator overload to display the list
   for (const List<T> * p = pHead; p; p = p->pNext)
   {
      if(p->pNext != NULL)
      {
         out << p->data << ", ";
      }
      else
      {
         out << p->data;
      }
   }
   return out;
}

#endif //LIST_H
