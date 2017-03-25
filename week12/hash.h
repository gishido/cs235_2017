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
#include <iostream>
#include "list.h"

using namespace std;

template <class T>
class Hash
{
    public:
    Hash() : buckets(NULL), numBuckets(0), numItems(0) {}

    Hash(const Hash<T> &rhs) : buckets(NULL), numBuckets(0), numItems(0) 
    {
        *this = rhs;
    }

    Hash(int data) throw (const char *)
    {
        numBuckets = data;
        numItems = 0;
        buckets = new List<T>[numBuckets];
    }
    
    ~Hash() { clear(); }

    //I'm just setting these up to compile still need to fill these out
    Hash<T> & operator=(const Hash<T> &rhs) throw(const char *)
    {
        clear();
        buckets = rhs.buckets;
        numBuckets = rhs.numBuckets;
        numItems = rhs.numItems;
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

        // cout << "debug: hash(value) - " << hash(value) << endl;
        assert(hash(value) >= 0 && hash(value) < capacity());
        // int slot = hash(value);
        // List<T> bucket = data[slot];        
        // bucket.push_back(value);
        int slot = hash(value);
        buckets[slot].push_back(value);
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

};

#endif // HASH_H