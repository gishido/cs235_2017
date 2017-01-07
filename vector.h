/***********************************************************************
* Header:
*    vector.h header file
* Author:
*    Adam Shumway
* Summary: 
*    Vector Template Class Header File
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert> //for asserts
#include <iostream>

//forward declaration for VectorIterator
template <class T>
class VectorIterator;

//forward declaration for VectorConstIterator
template <class T>
class VectorConstIterator;

/*************************************************
* VECTOR
* A vector class template that holds stuff
*************************************************/
template <class T>
class Vector
{
public:
   // default constructor : empty and kinda useless
   Vector() : numItems(0), theCapacity(0), data(NULL) {}

   // copy constructor : copy it
   Vector(const Vector & rhs) throw (const char *);
   
   // non-default constructor : pre-allocate
   Vector(int capacity) throw (const char *);
   
   // destructor : free everything
   ~Vector()        {if (theCapacity) delete [] data;  }

   //assignment operator
   Vector<T>& operator= (const Vector<T> &rhs) throw (const char *);

   //bracket [] operator
   T& operator [](int index) throw (const char *);
   const T& operator [](int index) const throw (const char *);

   // is the container currently empty
   bool empty() const  { return numItems == 0;         }

   // returns capacity count
   int capacity() const { return theCapacity;          }

   // remove all the items from the container
   void clear()        { numItems = 0;                 }

   // how many items are currently in the container?
   int size() const    { return numItems;              }

   // add an item to the container
   void insert(const T & t) throw (const char *);
   void push_back(const T & t) throw (const char *);

   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}

   // return the const iterator to the beginning of the list
   VectorConstIterator <T> cbegin() const { return VectorConstIterator<T>(data); }

   // return the const iterator to the end of the list
   VectorConstIterator <T> cend() const { return VectorConstIterator<T>(data + numItems);}
   
private:
   T * data;          // dynamically allocated array of T
   int numItems;      // how many items are currently in the Container?
   int theCapacity;      // how many items can I put on the Container before full?
};

/**************************************************
 * Vector ITERATOR
 * An iterator through Container
 *************************************************/
 template <class T>
 class VectorIterator
 {
    public:
    //default constructor
    VectorIterator() : p(NULL) {}

    //initialize to direct p to some item
    VectorIterator(T * p) : p(p) {}

    //copy contructor
    VectorIterator(const VectorIterator & rhs) {*this = rhs;}

    //assignment operator
    VectorIterator & operator= (const VectorIterator & rhs)
    {
        this->p = rhs.p;
        return *this;
    }

    //not equals operator
    bool operator != (const VectorIterator & rhs) const
    {
        return rhs.p != this->p;
    }

    //de-reference operator
    T & operator * () {return *p;}

    //prefix increment
    VectorIterator <T> & operator++ ()
    {
        p++;
        return *this;
    }

    //postfix increment
    VectorIterator <T> operator++ (int postfix)
    {
        VectorIterator tmp(*this);
        p++;
        return tmp;
    }

    //pre-decrement
    VectorIterator <T> & operator-- ()
    {
        p--;
        return *this;
    }

    //post-decrement
    VectorIterator <T> & operator-- (int decrement)
    {
        VectorIterator tmp(*this);
        p--;
        return tmp;
    }

    private:
    T * p;
 };

 /**************************************************
 * Vector Const ITERATOR
 * A const iterator through Container
 *************************************************/
 template <class T>
 class VectorConstIterator
 {
    public:
    //default constructor
    VectorConstIterator() : p(NULL) {}

    //initialize to direct p to some item
    VectorConstIterator(T * p) : p(p) {}

    //copy contructor
    VectorConstIterator(const VectorConstIterator & rhs) {*this = rhs;}

    //assignment operator
    VectorConstIterator & operator= (const VectorConstIterator & rhs)
    {
        this->p = rhs.p;
        return *this;
    }

    //not equals operator
    bool operator != (const VectorConstIterator & rhs) const
    {
        return rhs.p != this->p;
    }

    //de-reference operator
    T & operator * () {return *p;}

    //prefix increment
    VectorConstIterator <T> & operator++ ()
    {
        p++;
        return *this;
    }

    //postfix increment
    VectorConstIterator <T> operator++ (int postfix)
    {
        VectorConstIterator tmp(*this);
        p++;
        return tmp;
    }

    //pre-decrement
    VectorConstIterator <T> & operator-- ()
    {
        p--;
        return *this;
    }

    //post-decrement
    VectorConstIterator <T> & operator-- (int decrement)
    {
        VectorConstIterator tmp(*this);
        p--;
        return tmp;
    }

    private:
    T * p;
 };

/*******************************************
 * Vector :: COPY CONSTRUCTOR
 *******************************************/
template <class T>
Vector <T> :: Vector(const Vector <T> & rhs) throw (const char *)
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
 * Vector : NON-DEFAULT CONSTRUCTOR
 * Preallocate the container to "theCapacity"
 **********************************************/
template <class T>
Vector <T> :: Vector(int theCapacity) throw (const char *)
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
 * Vector :: operator=
 **************************************************/
 template <class T>
 Vector <T>& Vector<T> :: operator=(const Vector<T> &rhs) throw (const char *)
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
         throw "ERROR: unable to allocate buffer";
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
 * Vector :: operator []
 **************************************************/
 template <class T>
 T& Vector<T> :: operator [](int index) throw (const char *)
 {
     if (index < 0 || index > numItems)
     {
         throw "ERROR: index out of bounds";
     }

     return data[index];
 }

 template <class T>
 const T& Vector<T> :: operator [](int index) const throw (const char *)
 {
     if (index < 0 || index > numItems)
     {
         throw "ERROR: index out of bounds";
     }

     return data[index];
 }

/***************************************************
 * Vector :: INSERT
 * Insert an item on the end of the container
 **************************************************/
template <class T>
void Vector <T> :: insert(const T & t) throw (const char *)
{
   // do we have space?
   if (theCapacity == 0 || theCapacity == numItems)
      throw "ERROR: Insufficient space";
   
   // add an item to the end
   data[numItems++] = t;
}

/***************************************************
 * Vector :: PUSH_BACK
 * Extends the array size prior to an insert
 **************************************************/
template <class T>
void Vector<T> :: push_back(const T & t) throw (const char *)
{
    //create a new, temp empty array
    T* moreData;

    if (numItems >= theCapacity)
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

        delete [] data;
        data = moreData;
    }

    insert(t);
}

#endif //VECTOR_H