/***********************************************************************
 * Header:
 *    QUEUE.H
 * Summary:
 *
 * Author
 *    Adam Shumway, Jenaca Willans
 ************************************************************************/

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>    // for ISTREAM and OSTREAM
#include "dollars.h"
#include <cassert>
using namespace std;

/************************************************
 * Queue
 * A class that holds stuff
 ***********************************************/
template <class T>
class Queue
{
    public:
        // default contructor
  Queue() : myFront(0), myBack(0), myCapacity(0), mySize(0)
        {
            allocate(myCapacity);
        }

        // non-default constructor
        Queue(int myCapacity) throw (const char *);

        // copy constructor
        Queue(const Queue & rhs) throw (const char *);

        // deconstructor
        ~Queue() {if (myCapacity) delete [] myArray;}

        // returns if Queue is empty
        bool empty() const {return (mySize == 0);}

        // remove all items from the Queue
        void clear() 
        {
            while(!empty())
                pop();
        }

        //temp getters
        int theFront() const {return myFront;}

        // how many items are in the Queue
        int size() const {return mySize;}

        // return the total number of elements that can be held in the array
        int capacity() {return myCapacity;}

        // assignment Operator
        Queue<T> & operator= (const Queue<T> & rhs)
        {
            clear();
            if (myCapacity < rhs.myCapacity)
            {
                allocate(rhs.myCapacity);
            }
            copy(rhs);
            return *this;
        }

        // push items on the Queue
        void push(const T & value) throw (const char *)
        {
           int newBack;
           
           if (myCapacity == 0)
           {
              myCapacity = 2;
              allocate(myCapacity);
              newBack = (myBack + 1) % myCapacity;
           }
           else if (mySize >= myCapacity)
           {
              int oldCapacity = myCapacity;
              //double capacity
              myCapacity *= 2;
              
              //create tempory object for queue copy
              T * temp;
              
              // try to push
              try
              {
                 temp = new T[myCapacity];
              }
              catch(std::bad_alloc)
              {
                 throw "ERROR: Unable to allocate a new buffer for queue";
              }

              //if(myFront == myBack)
              //{
              //    for (int i = myFront; i <= oldCapacity; i++)
              //    {
              //        temp[(i - 1) % oldCapacity] = myArray[i % oldCapacity];
              //    }
              //    
              //  delete [] myArray;
              //  myArray = temp;
              //  myFront = 0; //reset front after copy
              //  myBack = oldCapacity; //rest back after copy
              //  newBack = oldCapacity + 1; //reset newBack after copy
              //}
              //else
              //{
                  for (int i = 0; i < oldCapacity; i++)
                  {
                         temp[i] = myArray[(myFront + i) % oldCapacity];
                  }

                delete [] myArray;
                myArray = temp;
                myFront = 0; //reset front after copy
                myBack = oldCapacity; //rest back after copy
                newBack = (oldCapacity + 1) % myCapacity;; //reset newBack after copy

              //}
           }
           else
           {
             newBack = (myBack + 1) % myCapacity;
           }
           
           myArray[myBack] = value;
           myBack = newBack;
           mySize++;
        }
        
        // pop from Queue
        void pop() throw (const char *)
        {

            if (!empty())
            {
               myFront = (myFront + 1) % myCapacity;
               mySize--;
             }
            else
            {
                throw "ERROR: attempting to pop from an empty queue";
            }
        }

        // front
        T & front() throw (const char *)
        {
            if (!empty())
            {
                return myArray[myFront];
            }
            else
            {
                throw "ERROR: attempting to access and item in an empty queue";
            }
        }
        
        // back
        T & back() throw (const char *)
        {
            if (!empty())
            {
                return myArray[myBack];
            }
            else
            {
                throw "ERROR: attempting to access and item in an empty queue";
            }
        }
    
    private:
        T * myArray;
        int myFront;
        int myBack;
        int myCapacity;
        int mySize;

        void allocate(int Space) throw (const char *)
        {
            //attempt to allocate
            try
            {
                myArray = new T[Space];
            }
            catch (std::bad_alloc)
            {
                throw "ERROR: Unable to allocate a new buffer for Queue";
            }
        }

        void copy(const Queue<T> & rhs)
        {
            // copy the capacity and size
            assert(rhs.mySize >= 0 && rhs.mySize <= rhs.myCapacity);
            myFront = rhs.myFront;
            myBack = rhs.myBack;
            mySize = rhs.mySize;
            myCapacity = rhs.myCapacity;

            //copy the items
            for (int i = 0; i < myCapacity; i++)
            {
                myArray[i] = rhs.myArray[i];
            }

        }

};

/**********************************************
 * Queue : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Queue to "myCapacity"
 **********************************************/
template <class T>
Queue <T> :: Queue(int myCapacity) throw (const char *)
{
    assert(myCapacity >= 0);

    // do nothing if there's nothing to do
    if (myCapacity == 0)
    {
        this->myCapacity = this->mySize = 0;
        this->myArray = NULL;
        this->myFront = this->myBack = 0;
        return;
    }

    //attempt to allocate
    try
    {
        myArray = new T[myCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate a new buffer for queue";
    }

    //copy over the stuff
    this->myCapacity = myCapacity;
    this->mySize = 0;
    this->myFront = this->myBack = 0;
}

/*******************************************
 * Queue :: COPY CONSTRUCTOR
 *******************************************/
 template <class T>
 Queue <T> :: Queue(const Queue <T> & rhs) throw (const char *)
 {
     assert(rhs.myCapacity >= 0);

     // do nothing if there's nothing to do
     if (rhs.myCapacity == 0)
     {
         myCapacity = mySize = 0;
         myArray = NULL;
         myFront = myBack = 0;
         return;
     }

     // attempt to allocate
     try
    {
        myArray = new T[rhs.myCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate a new buffer for queue";
    }

    // copy over the capacity and size
    assert(rhs.mySize >= 0 && rhs.mySize <= rhs.myCapacity);
    myCapacity = rhs.myCapacity;
    mySize = rhs.mySize;
    myFront = rhs.myFront;
    myBack = rhs.myBack;

    // copy the items over one at a time
    for (int i = 0; i < myCapacity; i++)
    {
        myArray[i] = rhs.myArray[i];
        
    }
}


#endif //QUEUE_H
