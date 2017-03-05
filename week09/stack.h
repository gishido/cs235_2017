/***********************************************************************
* Header:
*    INFIX      
* Summary:
*    This will contain just the prototype for the stack class
* Authors
*    Adam Shumway, Jenaca Willans
************************************************************************/

#ifndef STACK_H
#define STACK_H

#include <cassert>
#include <iostream>

using namespace std;
 /************************************************
 * Stack
 * A class that holds stuff
 ***********************************************/
template <class T>
class Stack
{
    public:
        // default contructor
        Stack() : myTop(0), myCapacity(0)
        {
            allocate(myCapacity);
        }

        // non-default constructor
        Stack(int myCapacity) throw (const char *);

        // copy constructor
        Stack(const Stack & rhs) throw (const char *);

        // deconstructor
        ~Stack() {if (myCapacity) delete [] myArray;}

        // returns if Stack is empty
        bool empty() const {return myTop == 0;}

        // remove all items from the stack
        void clear() {myTop = 0;}

        // how many items are in the Stack
        int size() const {return myTop;}

        // return the total number of elements that can be held in the array
        int capacity() {return myCapacity;}

        // assignment Operator
        Stack<T> & operator= (const Stack<T> & rhs)
        {
            clear();
            if (myCapacity < rhs.myCapacity)
            {
                allocate(rhs.myCapacity);
            }
            copy(rhs);
            return *this;
        }

        // push items on the Stack
        void push(const T & value) throw (const char *)
        {
            if (myCapacity == 0)
            {
                myCapacity = 1;
                allocate(myCapacity);
            }
            else if (myTop == myCapacity)
            {
                //double capacity
                myCapacity *= 2;
                //create tempory object for stack copy
                T * temp;

                // try to push
                try
                {
                    temp = new T[myCapacity];
                }
                catch(std::bad_alloc)
                {
                    throw "ERROR: Unable to properly push the stack!";
                }

                for (int i = 0; i < myTop; i++)
                {
                    temp[i] = myArray[i];
                }
                delete [] myArray;
                myArray = temp;
            }

            myArray[myTop] = value;
            myTop++;
        }

        // pop from Stack
        void pop() throw (const char *)
        {
            if (!empty())
            {
                myTop--;
            }
            else
            {
                throw "ERROR: Unable to pop from an empty Stack";
            }
        }

        // top
        T & top() const throw (const char *)
        {
            if (!empty())
            {
                return myArray[myTop-1];
            }
            else
            {
                throw "ERROR: Unable to reference the element from an empty Stack";
            }
        }
    
    private:
        T * myArray;
        int myTop;
        int myCapacity;

        void allocate(int Space) throw (const char *)
        {
            //attempt to allocate
            try
            {
                myArray = new T[Space];
            }
            catch (std::bad_alloc)
            {
                throw "ERROR: Unable to allocate a new buffer for Stack";
            }
        }

        void copy(const Stack<T> & rhs)
        {
            // copy the capacity and size
            assert(rhs.myTop >= 0 && rhs.myTop <= rhs.myCapacity);
            myTop = rhs.myTop;
            myCapacity = rhs.myCapacity;

            //copy the items
            for (int i = 0; i < myTop; i++)
            {
                myArray[i] = rhs.myArray[i];
            }

            //fill remaining stack with default value for TEST1
            for (int i = myTop; i < myCapacity; i++)
            {
                myArray[i] = T();
            }
        }
};

/**********************************************
 * Stack : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Stack to "myCapacity"
 **********************************************/
template <class T>
Stack <T> :: Stack(int myCapacity) throw (const char *)
{
    assert(myCapacity >= 0);

    // do nothing if there's nothing to do
    if (myCapacity == 0)
    {
        this->myCapacity = this->myTop = 0;
        this->myArray = NULL;
        return;
    }

    //attempt to allocate
    try
    {
        myArray = new T[myCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate a new buffer for Stack";
    }

    //copy over the stuff
    this->myCapacity = myCapacity;
    this->myTop = 0;

    //initialize the STack by calling the default constructor
    for (int i = 0; i < myCapacity; i++)
    {
        myArray[i] = T();

    }
}

/*******************************************
 * Stack :: COPY CONSTRUCTOR
 *******************************************/
 template <class T>
 Stack <T> :: Stack(const Stack <T> & rhs) throw (const char *)
 {
     assert(rhs.myCapacity >= 0);

     // do nothing if there's nothing to do
     if (rhs.myCapacity == 0)
     {
         myCapacity = myTop = 0;
         myArray = NULL;
         return;
     }

     // attempt to allocate
     try
    {
        myArray = new T[rhs.myCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate a new buffer for Stack";
    }

    // copy over the capacity and size
    assert(rhs.myTop >= 0 && rhs.myTop <= rhs.myCapacity);
    this->myCapacity = rhs.myCapacity;
    myTop = rhs.myTop;

    // copy the items over one at a time
    for (int i = 0; i < myCapacity; i++)
    {
        myArray[i] = rhs.myArray[i];
    }

    // the rest of the array is filled with the defaul value of TEST1
    for (int i = myTop; i < myCapacity; i++)
    {
        myArray[i] = T();
    }
 }


#endif //STACK_H
