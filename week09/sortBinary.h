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
//   cout << "Debug: passed num value: " << num << endl;

   // BST<T> * unsorted = NULL;
   //BST<T> * sorted = NULL;

   BST<T> sorted;
   
   for (int i = 0; i < num; i++)
   {
      sorted.insert(array[i]);
//      sorted->insert(array[i]);
//      cout << "Debug: able to insert: " << i << endl;
   }

   //create working current node pointer
   // BST<T> * current = unsorted;

   //process current node and call insertSort
   //while (current != NULL)
   //{
   // BST<T> * next = current->pNext;
   // insertSort(&sorted, current);
   // current = next;
   //}
   
   //int i = 0;

   //set new values to array
   //while (sorted != NULL)
   //{
   // array[i] = sorted->data;
   // sorted = sorted->pNext;
   // i++;
   // }

   //clear the lists
   //sorted->clear();
   //unsorted->clear();
      
}

//template <class T>
//void insertSort(BST<T> ** list, BST<T> * pNode)
//{
   //create current node pointer
// BST<T> * current;

   //walk node and compare values
// if (*list == NULL || (*list)->data >= pNode->data)
//  {
//    pNode->pNext = *list;
//    *list = pNode;
// }
// else
// {
//    current = *list;
//    while (current->pNext != NULL && current->pNext->data < pNode->data)
//       current = current->pNext;

//    pNode->pNext = current->pNext;
//      current->pNext = pNode;
// }
//}


#endif // SORT_BINARY_H
