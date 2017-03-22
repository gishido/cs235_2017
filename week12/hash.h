/***********************************************************************
 * Module:
 *    Week 12, Hash
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    This program will implement the hash() function
 ************************************************************************/

#ifndef HASH_H
#define HASH_H


#include <cassert>
//will likely include this in this class
//  at least we know our list class works over bst
//  friggin bst
//#include "list.h"


template <class T>
class Hash
{
    public:
    Hash() : numBuckets(0), min(0), max(0) {}
    //I'm messing up this non-default constructor...it's too late in the night 
    //  for me to think clearly
    Hash(const Hash &data) : numBuckets(0), min(0), max(0) {}
    
    ~Hash();

    //I'm just setting these up to compile still need to fill these out
    void operator=(const Hash &rhs) throw(const char *)
    {

    }

    bool empty() {return (numBuckets == 0);}

    int size() {return numBuckets;}

    int capacity() const {return numBuckets;}

    void clear()
    {

    }

    bool find(T value)
    {
        bool found = false;

        return found;
    }

    void insert(T value)
    {

    }

    int hash()
    {
        return numBuckets;
    }

    private:
    int numBuckets;
    int min;
    int max;

};

/*******************************************************
* I HASH
* A simple hash of integers
*******************************************************/
class IHash : public Hash <int> 
{
public:
   IHash(int numBuckets)    throw (const char *) : Hash <int> (numBuckets) {}
   IHash(const IHash & rhs) throw (const char *) : Hash <int> (rhs)		{} 

   // hash function for integers is simply to take the modulous
   int hash(const int & value) const
   {
      return value % capacity();
   }
};

#endif // HASH_H