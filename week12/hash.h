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
#include "list.h"

template <class T>
class Hash
{
    public:
    Hash() : buckets(NULL), numBuckets(0), numItems(0) {}
    //I'm messing up this non-default constructor...it's too late in the night 
    //  for me to think clearly
    Hash(const Hash<T> &rhs) : buckets(NULL), numBuckets(0), numItems(0) 
    {
        *this = rhs;
    }

    Hash(int numBuckets) throw (const char *)
    {

    }
    
    ~Hash() { clear(); }

    //I'm just setting these up to compile still need to fill these out
    Hash<T> & operator=(const Hash<T> &rhs) throw(const char *)
    {

    }

    bool empty() {return (numItems == 0);}

    int size() {return numItems;}

    int capacity() const {return numBuckets;}

    void clear()
    {

    }

    bool find(T value)
    {
        bool found = false;

        return found;
    }

    //got from discussion board
    void insert(const T &value)
    {
        assert(hash(value) >= 0 && hash(value) < capacity());
        buckets[hash(value)].push_back(value);
        numItems++;
    }

    virtual int hash(const T &item) const = 0;
    // {
    //     return numBuckets;
    // }

    private:
    List<T> * buckets;
    int numBuckets;
    int numItems;
    T data[];


// /*******************************************************
// * I HASH
// * A simple hash of integers
// *******************************************************/
// class IHash : public Hash <int> 
// {
// public:
//    IHash(int numBuckets)    throw (const char *) : Hash <int> (numBuckets) {}
//    IHash(const IHash & rhs) throw (const char *) : Hash <int> (rhs)		{} 

//    // hash function for integers is simply to take the modulous
//    int hash(const int & value) const
//    {
//       return value % capacity();
//    }
// };

// /*******************************************************
// * F HASH
// * A simple hash of integers
// *******************************************************/
// class FHash : public Hash <float> 
// {
// public:
//    FHash(int numBuckets)    throw (const char *) : Hash <float> (numBuckets) {}
//    FHash(const IHash & rhs) throw (const char *) : Hash <float> (rhs)		{} 

//    // hash function for float is simply to take the modulous
//    float hash(const float & value) const
//    {
//       return value % capacity();
//    }
};

#endif // HASH_H