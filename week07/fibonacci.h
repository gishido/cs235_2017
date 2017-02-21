/***********************************************************************
 * Header:
 *    FIBONACCI
 * Summary:
 *    This will contain just the prototype for fibonacci(). You may
 *    want to put other class definitions here as well.
 * Author
 *    Adam Shumway, Jenaca Willans
 ************************************************************************/

#ifndef FIBONACCI_H
#define FIBONACCI_H

#include "list.h"

// the interactive fibonacci program
void fibonacci();

/********************************************
 * Declare LARGENUM class.
 ********************************************/
class LargeNum
{
  private:
   List<int> addPrev;
   List<int> addCurr;
   List<int> addNext;

   int numItems;
   Node<int> pFirst;
   Node<int> pLast;

  public:
   // Declare constructors:
   LargeNum();
   LargeNum(int num) throw (const char *);
   LargeNum(const LargeNum &rhs) throw(const char *);
   ~LargeNum();

   // Declare functions:
   void advance();
   void clear();

   // Declare getters:
   List<int> getAddPrev() const { return addPrev; };
   
   // Delcare setters:
   void setAddPrev(List<int> addPrev);

   // operator overloads
   LargeNum &operator=(const List<int> &rhs) throw(const char *)
   {
      //clear existing nodes
      clear();

      //allocate nodes
//      for (List<int> * p = rhs.front(); p; p = p->pNext)
      //           push_back(p->data);

      return *this;
   }

   ostream & operator << (const Node<int> * pHead)
   {
      // operator overload to display the list
      for (const Node<int> * p = pHead; p; p = p->pNext)
      {
         if(p->pNext != NULL)
         {
            cout << p->data << ", ";
         }
         else
         {
            cout << p->data;
         }
      }
      return cout;
   }

//   LargeNum &operator+=(const List<int> rhs) const
   LargeNum &operator+=(const List<int> &rhs) throw(const char *)
   {
      //new dynamic List
//      List<int> rtnData;


//      int iNode1 = 0;
      //    int iNode2 = 0;

      // while (iNode1 < numItems || iNode2 < rhs.numItems)
      // {
      //if (iNode1 == numItems)
        //    return rtnData;
      //else if (iNode2 == rhs.numItems)
      //    rtnData.insert(data[iNode1++]);
      // else if (data[iNode1] == rhs.data[iNode2])
      // {
      //    iNode1++;
      //    iNode2++;
      // }
      // else if (data[iNode1] < rhs.data[iNode2])
      //    rtnData.insert(data[iNode1++]);
      // else if (data[iNode1] > rhs.data[iNode2])
      //    iNode2++;
      // }

      return *this;
//      return rtnData;
   }
};

#endif // FIBONACCI_H

