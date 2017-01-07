/***********************************************************************
* Header:
*    vector.h header file
* Summary: 
*    Vector Template Class Header File
************************************************************************/

#ifndef VECTOR_H
#define VECTOR_H

#include <cassert> //for asserts

//forward declaration for VectorIterator
template <class T>
class VectorIterator;

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
   ~Vector()        {                                  }
   
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

   // return an iterator to the beginning of the list
   VectorIterator <T> begin() { return VectorIterator<T>(data); }

   // return an iterator to the end of the list
   VectorIterator <T> end() { return VectorIterator<T>(data + numItems);}
   
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

#endif //VECTOR_H