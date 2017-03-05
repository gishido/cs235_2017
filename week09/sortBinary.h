/***********************************************************************
 * Module:
 *    Week 09, Sort Binary
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the Binary Tree Sort
 ************************************************************************/

#ifndef SORT_BINARY_H
#define SORT_BINARY_H

#include "bst.h"

/*****************************************************
 * SORT BINARY
 * Perform the binary tree sort
 ****************************************************/
template <class T>
void sortBinary(T array[], int num)
{
  
   BST<T> sorted;
   
   for (int i = 0; i < num; i++)
   {
      sorted.insert(array[i]);
   }

   BSTIterator<T> it;
   it = sorted.begin();
   
   //set new values to array
   while (it != sorted.end())
   {
      for (int i = 0; i < num; i++)
      {  
         array[i] = *it;
         it++;
      }

   }
   
   sorted.clear();
 
}

#endif // SORT_BINARY_H
