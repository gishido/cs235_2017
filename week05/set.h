/***********************************************************************
* Header:
*    Set.h header file
* Author:
*    Adam Shumway
* Summary: 
*    Set Template Class Header File
************************************************************************/

#ifndef SET_H
#define SET_H

#include <cassert> //for asserts
#include <iostream>

using namespace std;

//forward declaration for SetIterator
template <class T>
class SetIterator;

//forward declaration for SetConstIterator
template <class T>
class SetConstIterator;

/*************************************************
* Set
* A Set class template that holds stuff
*************************************************/
template <class T>
class Set
{
  public:
    // default constructor : empty and kinda useless
    Set() : numItems(0), theCapacity(0), data(NULL) {}

    // copy constructor : copy it
    Set(const Set &rhs) throw(const char *);

    // non-default constructor : pre-allocate
    Set(int capacity) throw(const char *);

    // destructor : free everything
    ~Set()
    {
        if (theCapacity)
            delete[] data;
    }

    //assignment operator
    Set<T> &operator=(const Set<T> &rhs) throw(const char *);

    // Set<T> operator&&(const Set<T> rhs) const;
    // Set<T> operator||(const Set<T> rhs) const;

    //bracket [] operator
    T &operator[](int index) throw(const char *);
    const T &operator[](int index) const throw(const char *);

    // is the container currently empty
    bool empty() const { return numItems == 0; }

    // returns capacity count
    int capacity() const { return theCapacity; }

    // remove all the items from the container
    void clear() { numItems = 0; } //may need to change this one

    // how many items are currently in the container?
    int size() const { return numItems; }

    //Help help please fix me
    SetIterator<T> find(const T &t); //takes template item, returns iterator
    // void erase(SetIterator<T> &t){};//takes iterator item, returns nothing...will need to work on this one a bit
    void sort(); //used for sorting
    void swap(T &lhs, T &rhs);  //used for sorting

    // add an item to the container
    void insert(const T &t); //there's a bunch of work needed for this one
    //void push_back(const T &t) throw(const char *);
    //SetIterator<T> binSearch(const T &t); //used by both find and insert...and erase, I think

    // return an iterator to the beginning of the list
    SetIterator<T> begin() { return SetIterator<T>(data); }

    // return an iterator to the end of the list
    SetIterator<T> end() { return SetIterator<T>(data + numItems); }

    // return the const iterator to the beginning of the list
    SetConstIterator<T> cbegin() const { return SetConstIterator<T>(data); }

    // return the const iterator to the end of the list
    SetConstIterator<T> cend() const { return SetConstIterator<T>(data + numItems); }

  private:
    T *data;         // dynamically allocated array of T
    int numItems;    // how many items are currently in the Container?
    int theCapacity; // how many items can I put on the Container before full?
};

/**************************************************
 * Set ITERATOR
 * An iterator through Container
 *************************************************/
template <class T>
class SetIterator
{
  public:
    //default constructor
    SetIterator() : p(NULL) {}

    //initialize to direct p to some item
    SetIterator(T *p) : p(p) {}

    //copy contructor
    SetIterator(const SetIterator &rhs) { *this = rhs; }

    //assignment operator
    SetIterator &operator=(const SetIterator &rhs)
    {
        this->p = rhs.p;
        return *this;
    }

    //not equals operator
    bool operator!=(const SetIterator &rhs) const
    {
        return rhs.p != this->p;
    }

    //de-reference operator
    T &operator*() { return *p; }

    //prefix increment
    SetIterator<T> &operator++()
    {
        p++;
        return *this;
    }

    //postfix increment
    SetIterator<T> operator++(int postfix)
    {
        SetIterator tmp(*this);
        p++;
        return tmp;
    }

    //pre-decrement
    SetIterator<T> &operator--()
    {
        p--;
        return *this;
    }

    //post-decrement
    SetIterator<T> &operator--(int decrement)
    {
        SetIterator tmp(*this);
        p--;
        return tmp;
    }

  private:
    T *p;
};

/**************************************************
 * Set Const ITERATOR
 * A const iterator through Container
 *************************************************/
template <class T>
class SetConstIterator
{
  public:
    //default constructor
    SetConstIterator() : p(NULL) {}

    //initialize to direct p to some item
    SetConstIterator(T *p) : p(p) {}

    //copy contructor
    SetConstIterator(const SetConstIterator &rhs) { *this = rhs; }

    //assignment operator
    SetConstIterator &operator=(const SetConstIterator &rhs)
    {
        this->p = rhs.p;
        return *this;
    }

    //not equals operator
    bool operator!=(const SetConstIterator &rhs) const
    {
        return rhs.p != this->p;
    }

    //de-reference operator
    T &operator*() { return *p; }

    //prefix increment
    SetConstIterator<T> &operator++()
    {
        p++;
        return *this;
    }

    //postfix increment
    SetConstIterator<T> operator++(int postfix)
    {
        SetConstIterator tmp(*this);
        p++;
        return tmp;
    }

    //pre-decrement
    SetConstIterator<T> &operator--()
    {
        p--;
        return *this;
    }

    //post-decrement
    SetConstIterator<T> &operator--(int decrement)
    {
        SetConstIterator tmp(*this);
        p--;
        return tmp;
    }

  private:
    T *p;
};

/*******************************************
 * Set :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Set<T>::Set(const Set<T> &rhs) throw(const char *)
{
    assert(rhs.theCapacity >= 0);

    // do nothing if there is nothing to do
    if (rhs.theCapacity == 0)
    {
        theCapacity = numItems = 0;
        data = NULL;
        return;
    }

    // attempt to allocate
    try
    {
        data = new T[rhs.theCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate buffer";
    }

    // copy over the capacity and size
    assert(rhs.numItems >= 0 && rhs.numItems <= rhs.theCapacity);
    theCapacity = rhs.theCapacity;
    numItems = rhs.numItems;

    // copy the items over one at a time using the assignment operator
    for (int i = 0; i < numItems; i++)
        data[i] = rhs.data[i];

    // the rest needs to be filled with the default value for T
    for (int i = numItems; i < theCapacity; i++)
        data[i] = T();
}

/**********************************************
 * Set : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "theCapacity"
 **********************************************/
template <class T>
Set<T>::Set(int theCapacity) throw(const char *)
{
    assert(theCapacity >= 0);

    // do nothing if there is nothing to do
    if (theCapacity == 0)
    {
        this->theCapacity = this->numItems = 0;
        this->data = NULL;
        return;
    }

    // attempt to allocate
    try
    {
        data = new T[theCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: Unable to allocate buffer";
    }

    // copy over the stuff
    this->theCapacity = theCapacity;
    this->numItems = 0;

    // initialize the container by calling the default constructor
    for (int i = 0; i < theCapacity; i++)
        data[i] = T();
}

/***************************************************
 * Set :: = Operator
 **************************************************/
template <class T>
Set<T> &Set<T>::operator=(const Set<T> &rhs) throw(const char *)
{
    assert(rhs.theCapacity >= 0);

    //if there's nothing to do, do nothing
    if (rhs.theCapacity == 0)
    {
        this->theCapacity = this->numItems = 0;
        this->data = NULL;

        return *this;
    }

    //attempt to allocate
    try
    {
        this->data = new T[rhs.theCapacity];
    }
    catch (std::bad_alloc)
    {
        throw "ERROR: unable to allocate new buffer for Set";
    }

    //copy size and capacity
    assert(rhs.numItems >= 0 && rhs.numItems <= rhs.theCapacity);
    this->theCapacity = rhs.theCapacity;
    this->numItems = rhs.numItems;

    //copy items
    for (int i = 0; i < this->numItems; i++)
        this->data[i] = rhs.data[i];

    //filling remaining array with default value of T
    for (int i = this->numItems; i < this->theCapacity; i++)
        this->data[i] = T();

    return *this;
}

/***************************************************
 * Set :: find
 * traverses the Set to find an item
 **************************************************/
 template <class T>
 SetIterator<T> Set<T>::find(const T &t)
{ 
    int iBegin = 0;
    int iEnd = numItems - 1;

    while (iBegin <= iEnd)
    {
        int iMiddle = (iBegin + iEnd) / 2;
        if (t == data[iMiddle])
        {
            cout << "debug: find() returning found item\n"; 
            return SetIterator<T>(data + iMiddle);
        }
        else if (t < data[iMiddle])
            iEnd = iMiddle - 1;
        else 
            iBegin = iMiddle + 1;
    }

    cout << "debug: find(); returning end()... which could be 0?\n";
    cout << "debug: data + numItems is - " << data + numItems << endl;
    return end();

}

/***************************************************
 * Set :: operator []
 **************************************************/
template <class T>
T &Set<T>::operator[](int index) throw(const char *)
{
    if (index < 0 || index > numItems)
    {
        throw "ERROR: index out of bounds";
    }

    return data[index];
}

template <class T>
const T &Set<T>::operator[](int index) const throw(const char *)
{
    if (index < 0 || index > numItems)
    {
        throw "ERROR: index out of bounds";
    }

    return data[index];
}

/***************************************************
 * Set :: Sort
 * Sorts the container
 **************************************************/
 template <class T>
 void Set<T>::sort()
 {
    int inner = 0;
    int outter = 0;

    for (int i = 0; i < theCapacity - 1; i++)
    {
        inner = i;

        for (outter = i + 1; outter < theCapacity; outter++)
        {
            if (data[inner] < data[outter])
                inner = outter;
            
            swap(data[i], data[outter]);
        }
    }

 }

/***************************************************
 * Set :: Swap
 * used with sort... switches values
 **************************************************/
template <class T>
void Set<T>::swap(T &lhs, T &rhs)
{
    T temp;
    temp = lhs;
    lhs = rhs;
    rhs = temp;
}

/***************************************************
 * Set :: INSERT
 * Insert an item on the end of the container
 **************************************************/
template <class T>
void Set<T>::insert(const T &t)
{
    //create a new, temp empt array
    T* moreData;

    // do we have space?
    if (theCapacity == 0 || numItems >= theCapacity)
    {
        if (theCapacity == 0)
        {
            //initialize size to at least 1
            theCapacity = 1;    
        }
        else
        {
            //double size
            theCapacity *= 2;
        }
        
        moreData = new T[theCapacity];
        //copy existing items to the new array
        for (int i = 0; i < numItems; ++i)
            moreData[i] = data[i];
        cout << "debug: I just grew\n";

        delete [] data;
        data = moreData;
    }

    if (numItems == 0)
    {
        // add an item to the end
        // cout << "debug: when 0, numItems before = " << numItems << endl;
        // cout << "debug: when 0, data[numItems++] before: " << data[numItems] << endl;
        data[numItems++] = t;  
        // cout << "debug: when 0, data[numItems++] after: " << data[numItems] << endl;
        // cout << "debug: when 0, numItems after = " << numItems << endl;
    }
    else
    {
        // SetIterator<T> result = find(t);
        
        // cout << "{ ";
        // cout << "result : end \n\t";
        // cout << *result << " : " << data + numItems<< endl;
        // cout << '}';

        if(*find(t) != t)
        {
            // T* sortData = new T[theCapacity];
            // int index = 0;

            // cout << "debug: find() *result != t\n";

            // //copy exiting items to the new array
            // for (int i = 0; i < numItems + 1; i++)
            // {
            //     if(t < data[i])
            //     {
            //         sortData[i] = t;
            //         index = i;
            //         cout << "debug: testItem is less than data[i]\n";
            //     }
            //     else
            //     {
            //         sortData[i] = data[i];
            //         cout << "debug: sortData[i] : data[i] \n"
            //             << sortData[i] << " : " << data[i] << endl;
            //     }

            // }
            // cout << "debug: index val is - " << index << endl;
            // cout << "debug: numItems val is - " << numItems << endl;

            // for (index; index < numItems + 1; index++)
            // {
            //     sortData[index] = data[index - 1];
            // }
            data[numItems++] = t; 
            // delete [] data;
            // data = sortData;

            sort();
        }

 
    }

}

// /***************************************************
//  * Set :: && Operator
//  **************************************************/
// template <class T>
// Set<T> Set<T>::operator&&(const Set<T> rhs) const
// {
// }

// /***************************************************
//  * Set :: || Operator|
//  **************************************************/
// template <class T>
// Set<T> Set<T>::operator||(const Set<T> rhs) const
// {
// }

#endif //SET_H