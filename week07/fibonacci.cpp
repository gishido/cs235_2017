/***********************************************************************
 * Implementation:
 *    FIBONACCI
 * Summary:
 *    This will contain the implementation for fibonacci() as well as any
 *    other function or class implementations you may need
 * Author
 *    Adam Shumway, Jenaca Willans
 **********************************************************************/

#include <iostream>
#include "fibonacci.h"   // for fibonacci() prototype
#include "list.h"        // for LIST
using namespace std;


/************************************************
 * FIBONACCI
 * The interactive function allowing the user to
 * display Fibonacci numbers
 ***********************************************/
void fibonacci()
{
   // show the first serveral Fibonacci numbers
   int number;
   cout << "How many Fibonacci numbers would you like to see? ";
   cin  >> number;

   // your code to display the first <number> Fibonacci numbers
   int prev = 0;
   int curr = 1;
   int next = 0;

   cout << "\t" << curr << endl;

   for (int i = 0; i < number - 1; i++)
   {
      if (number == 1)
      {
         next = number;
      }
      else
      {
         next = prev + curr;
         prev = curr;
         curr = next;
      }
      
      cout << "\t" << next << endl;
   }
   
   // prompt for a single large Fibonacci
   cout << "Which Fibonacci number would you like to display? ";
   cin  >> number;

   // your code to display the <number>th Fibonacci number
   // this works until we hit the large numbers.
   // we need to make a class for LargeNumbers that
   // uses a vector to hold large numbers in 3 digit
   // blocks. Then display with commas.
//   LargeNum largePrev = 0;
   // LargeNum largeCurr = 1;
   // LargeNum largeNext = 0;

   // for (int i = 0; i < number - 1; i++)
   // {
//      if (number == 1)
         // {
   //       next = number;
   // }
   // else
   // {
   //    largeNext = largePrev + largeCurr;
   //    largePrev = largeCurr;
   //    largeCurr = largeNext;
   // }
      
   // }
   
   // cout << "\t" << largeNext << endl;

   
}

/************************************************
 * LargeNum :: CONSTRUCTOR
 * Construct an instance of a large number class
 * and initialize member variables.
 ***********************************************/
LargeNum :: LargeNum(): addPrev(), addCurr(), addNext()
{

}

/************************************************
 * LargeNum :: NON-DEFAULT CONSTRUCTOR
 * Construct an instance of a large number class
 * and initialize member variables.
 ***********************************************/
LargeNum :: LargeNum(int num) throw(const char *)
{

}

/************************************************
 * LargeNum :: COPY CONSTRUCTOR
 * Construct an instance of a large number class
 * and initialize member variables.
 ***********************************************/
LargeNum :: LargeNum(const LargeNum &rhs) throw(const char *)
{
   // assert(rhs.theCapacity >= 0);

   // do nothing if there is nothing to do
   // if (rhs.theCapacity == 0)
   // {
   // theCapacity = numItems = 0;
   // data = NULL;
   // return;
   //}

   // attempt to allocate
   // try
   // {
   //    data = new T[rhs.theCapacity];
   // }
   // catch (std::bad_alloc)
   // {
   //    throw "ERROR: Unable to allocate buffer";
   // }
   
     // copy over the capacity and size
   //   assert(rhs.numItems >= 0 && rhs.numItems <= rhs.theCapacity);
   // theCapacity = rhs.theCapacity;
   // numItems = rhs.numItems;

      // copy the items over one at a time using the assignment operator
   // for (int i = 0; i < numItems; i++)
   //    data[i] = rhs.data[i];

      // the rest needs to be filled with the default value for T
   // for (int i = numItems; i < theCapacity; i++)
   //    data[i] = T();
      
   
}

/************************************************
 * LargeNum :: DESTRUCTOR
 ***********************************************/
LargeNum :: ~LargeNum()
{
//   if (theCapacity)
   //    delete[] data;
}

/************************************************
 * LargeNum :: Define advance.
 ***********************************************/
void LargeNum :: advance()
{

}

/************************************************
 * LargeNum :: Define clear.
 ***********************************************/
void LargeNum :: clear()
{
   //loop through list and remove everything
//   Node<int> * pNode;

   // for (Node<int> * p = first; p; p =p->pNext)
   //{
   // pNode = p->pNext;
   // delete p;
   //}
    
   //null out the list
   // first = last = NULL;
   // numItems = 0;
}

/************************************************
 * LargeNum :: set addPrev
 ***********************************************/
void LargeNum :: setAddPrev(List<int> addPrev)
{
   this->addPrev = addPrev;
}

