#ifndef MAP_H 
#define MAP_H 
#include "bnode.h" // for BinaryNode 
#include "stack.h" // for Stack 
#include "pair.h" // for Pair 
#include "bst.h" // for BST 

#include <cassert> // for ASSERT 
#include <iostream> 

// forward declaration for the iterator 
template <class K, class V>
class MapIterator; 

/***************************************************************** 
* MAP CLASS 
* A container for a Map 
******************************************************************/ 
template <class K,class V> 
class Map 
{ 
public: 
   // default constructor
  Map() : pRoot(NULL), numItems(0) {};

   // copy constructor 
   Map(const Map & rhs) : pRoot(NULL), numItems(0)
   {
         pRoot = rhs.pRoot;
   }

   //destructor, call clear() since this does the same thing 
   ~Map() { clear(); } 

   void recursiveCopy(BinaryNode<Pair<K, V> > * &pThis, 
                      BinaryNode<Pair<K, V> > * pRhs) 
      throw (const char*)
      {

      }; 

   // Return the number of nodes in the binary search tree.  
   int size() { return numItems; } 
   void recursiveInsert(const Pair<K,V> & t, BinaryNode <Pair<K,V> > * pNode) 
      throw (const char *)
      {

      }
       

   // Returns whether the current binary search tree is empty. 
   bool empty() const { return (pRoot == NULL); } 

   // delete all the elements in the binary search tree. 
   void clear() 
   { 
      deleteBinaryTree(pRoot); 
      pRoot = NULL; 
   } 
   
   // overloaded assignment operator 
   Map & operator = (const Map<K,V> & rhs) throw (const char *) 
      { 
         recursiveCopy(this->pRoot, rhs.pRoot); 
         return *this; 
      } 

// square bracket [] operator overload 
// array index will be words from file 
// driver program passes both int and string 
      V& operator [] (const K index) throw(const char *)
      {
      //This should all work, but it doesn't, which is lame
// //           //create a pair (with a default value that we will search for 
//           Pair<K,V> pair(index,V());
          
//           BinaryNode< Pair<K,V> > pNode;
          
// //           //find the item 
//          BSTIterator it = bst.find(pair);
// //           BSTIterator it = bst.find(pair);
// // //          BSTIterator < Pair<K,V> > it = bst.find(Pair<K,V>);
          
// //           //if it is not found, create a new node and put it there 
//           if (end() == it)
//           {
//               bst.insert(pair);
//               it = bst.find(pair);
//               assert(end() != it);
//           }
//          //return the second 
//             return (*it).second;
      }
    

//insert an item 
   void insert(const Pair<K,V> & t) throw (const char *)
   {
         numItems++;
   } 

// remove an item 
   void remove(MapIterator <K,V> & it); 

// find a given item 
   MapIterator <K,V> find(const Pair<K,V> & t); 

// iterator methods 
   MapIterator <K,V> begin(); 
   MapIterator <K,V> rbegin(); 

// end -- return value is an iterator referring to no element in the Map. 
// By convention, this is the NULL iterator. 
   MapIterator <K,V> end() { return MapIterator <K,V>(NULL);} 
   MapIterator <K,V> rend() { return MapIterator <K,V>(NULL);} 

   MapIterator<K,V> getRoot() { return pRoot; } 

   
  private: 
   BinaryNode <Pair<K, V> > * pRoot; 
   int numItems;
// INTERNAL FUNCTIONS NEEDED FOR RED-BLACK TREE BALANCING 
// PRIVATE -- FOR INTERNAL CLASS USE ONLY 

// recursive function controls re-coloring & calls rotation functions,  
// as necessary 
   void recolorNodes(BinaryNode <Pair<K, V> > * pThis); 

//Functions for Rotation 
   void rotateRight(BinaryNode <Pair<K, V> > * pThis,
                    BinaryNode <Pair<K, V> > * pPar, 
                    BinaryNode <Pair<K, V> > * pGran,
                    BinaryNode <Pair<K, V> > * pSib, 
                    BinaryNode <Pair<K, V> > * pAunt); 
   void rotateLeft(BinaryNode <Pair<K, V> > * pThis,
                   BinaryNode <Pair<K, V> > * pPar, 
                   BinaryNode <Pair<K, V> > * pGran,
                   BinaryNode <Pair<K, V> > * pSib, 
                   BinaryNode <Pair<K, V> > * pAunt); 
   void rotateDoubleRight(BinaryNode <Pair<K, V> > * pThis,
                          BinaryNode <Pair<K, V> > * pPar, 
                          BinaryNode <Pair<K, V> > * pGran,
                          BinaryNode <Pair<K, V> > * pSib, 
                          BinaryNode <Pair<K, V> > * pAunt); 
   void rotateDoubleLeft(BinaryNode <Pair<K, V> > * pThis,
                         BinaryNode <Pair<K, V> > * pPar, 
                         BinaryNode <Pair<K, V> > * pGran,
                         BinaryNode <Pair<K, V> > * pSib, 
                         BinaryNode <Pair<K, V> > * pAunt); 
};

/***************************************************************** 
* MapIterator CLASS 
* A Iterator for a Map 
******************************************************************/ 
template <class K, class V>
class MapIterator
{

};

#endif //MAP.H
