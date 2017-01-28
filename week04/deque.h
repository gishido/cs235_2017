/***********************************************************************
 * Header:
 *    DEQUE.H
 * Summary:
 *    A class to hold a deque of values that we can access
 *    from either end.
 * Author
 *    Adam Shumway, Jenaca Willans
 ************************************************************************/

#ifndef DEQUE_H
#define DEQUE_H

#include <iostream> // for ISTREAM and OSTREAM
#include <cassert>
using namespace std;

/************************************************
 * DEQUE
 * A class that holds stuff
 ***********************************************/
template <class T>
class Deque
{
  public:
    // default contructor
    Deque() : myFront(0), myBack(-1), myCapacity(0), mySize(0)
    {
        allocate(myCapacity);
    }

    // non-default constructor
    Deque(int myCapacity) throw(const char *);

    // copy constructor
    Deque(const Deque &rhs) throw(const char *);

    // deconstructor
    ~Deque()
    {
        if (myCapacity)
            delete[] myArray;
    }

    // returns if Deque is empty
    bool empty() const { return (mySize == 0); }

    // remove all items from the Deque
    void clear()
    {
        myFront = 0;
        myBack = -1;
        // while (!empty())
        //     pop_front();
    }

    //set and get
    void setMyFront(int value) { myFront = value; }
    void setMyBack(int value) { myBack = value; }
    int getMyFront() { return myFront; }
    int getMyBack() { return myBack; }

    // how many items are in the Deque
    int size() const { return mySize; }

    // return the total number of elements that can be held in the array
    int capacity() { return myCapacity; }

    // assignment Operator
    Deque<T> &operator=(const Deque<T> &rhs)
    {
        clear();
        if (myCapacity < rhs.myCapacity)
        {
            allocate(rhs.myCapacity);
        }
        copy(rhs);
        return *this;
    }

    // push items to the back of the Deque
    void push_back(const T &value) throw(const char *)
    {
        int newBack;

        if (myCapacity == 0)
        {
            myCapacity = 2;
            allocate(myCapacity);
            newBack = iFind(myBack + 1);
        }
        else if (mySize >= myCapacity)
        {
            int newCapacity = myCapacity;
            //double capacity
            newCapacity *= 2;

            //create tempory object for deque copy
            T *temp;

            // try to push to the back of the deque
            try
            {
                temp = new T[newCapacity];
            }
            catch (std::bad_alloc)
            {
                throw "ERROR: Unable to allocate a new buffer for deque";
            }

            for (int i = 0; i < myCapacity; i++)
            {
                myFront = iFind(myFront + i);
                temp[i] = myArray[myFront];
            }

            delete[] myArray;
            myArray = temp;
            myFront = 0;          //reset front after copy
            myBack = myCapacity; //rest back after copy
            newBack = (myCapacity + 1);
            myCapacity = newCapacity;
            //reset newBack after copy
        }
        else
        {
            newBack = iFind(myBack + 1);
        }

        myArray[myBack] = value;
        myBack = newBack;
        mySize++;
    }

    // push items to the front of the Deque
    void push_front(const T &value) throw(const char *)
    {
        int newFront;

        if (myCapacity == 0)
        {
            myCapacity = 2;
            allocate(myCapacity);
            newFront = iFind(myFront - 1);
        }
        else if (mySize >= myCapacity)
        {
            int newCapacity = myCapacity;
            //double capacity
            newCapacity *= 2;

            //create tempory object for deque copy
            T *temp;

            // try to push to the back of the deque
            try
            {
                temp = new T[newCapacity];
            }
            catch (std::bad_alloc)
            {
                throw "ERROR: Unable to allocate a new buffer for deque";
            }

            for (int i = 0; i < myCapacity; i++)
            {
                myFront = iFind(myFront + i);
                temp[i] = myArray[myFront];
            }

            delete[] myArray;
            myArray = temp;
            myFront = iFind(myFront -1); //reset front after copy
            myFront = myCapacity; //rest back after copy
            newBack = (myCapacity - 1);
            myCapacity = newCapacity;
            //reset newBack after copy
        }
        else
        {
            newFront = iFind(myFront - 1);
        }

        myFront = newFront;
        myArray[myFront] = value;
        mySize++;
    }

    // pop from the back of the deque
    void pop_back() throw(const char *)
    {
        if (!empty())
        {
            myBack = iFind(myBack - 1);
            mySize--;
        }
        else
        {
            throw "ERROR: attempting to pop from an empty deque";
        }
    }

    // pop_front from Deque
    void pop_front() throw(const char *)
    {

        if (!empty())
        {
            myFront = iFind(myFront + 1);
            mySize--;
        }
        else
        {
            throw "ERROR: attempting to pop from an empty deque";
        }
    }

    // front
    T &front() throw(const char *)
    {
        if (!empty())
        {
            return myArray[myFront];
        }
        else
        {
            throw "ERROR: attempting to access an item in an empty deque";
        }
    }

    // back
    T &back() throw(const char *)
    {
        if (!empty())
        {
            return myArray[myBack];
        }
        else
        {
            throw "ERROR: attempting to access an item in an empty deque";
        }
    }

  private:
    T *myArray;
    int myFront;
    int myBack;
    int myCapacity;
    int mySize;

    int iFind(int i) const
    {
        //evaluates if i is greater than 1, if so return mod, if not, recurse
        return (i >= 0) ? (i % myCapacity) : (myCapacity - (-1 - i) - 1);
    }

    void allocate(int Space) throw(const char *)
    {
        //attempt to allocate
        try
        {
            myArray = new T[Space];
        }
        catch (std::bad_alloc)
        {
            throw "ERROR: Unable to allocate a new buffer for Deque";
        }
    }

    void copy(const Deque<T> &rhs)
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
 * Deque : NON-DEFAULT CONSTRUCTOR
 * Preallocate the Deque to "myCapacity"
 **********************************************/
template <class T>
Deque<T>::Deque(int myCapacity) throw(const char *)
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
        throw "ERROR: Unable to allocate a new buffer for deque";
    }

    //copy over the stuff
    this->myCapacity = myCapacity;
    this->mySize = 0;
    this->myFront = this->myBack = 0;
}

/*******************************************
 * Deque :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Deque<T>::Deque(const Deque<T> &rhs) throw(const char *)
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
        throw "ERROR: Unable to allocate a new buffer for deque";
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

#endif //DEQUE_H
