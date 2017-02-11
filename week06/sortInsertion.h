/***********************************************************************
 * Header:
 *    INSERTION SORT
 * Summary:
 *    This will contain just the prototype for insertionSortTest(). You may
 *    want to put other class definitions here as well.
 * Author
 *    <your names here>
 ************************************************************************/

#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H

#include "node.h"

/***********************************************
 * INSERTION SORT
 * Sort the items in the array
 **********************************************/
template <class T>
void sortInsertion(T array[], int num)
{
    Node<T> * unsorted = NULL;
    Node<T> * sorted = NULL;

    for (int i = 0; i < num; i++)
        insert(array[i], unsorted);
    
    Node<T> * current = unsorted;

    while (current != NULL)
    {
        Node<T> * next = current->pNext;
        insertSort(&sorted, current);
        current = next;
    }

    int i = 0;

    while (sorted != NULL)
    {
        array[i] = sorted->data;
        sorted = sorted->pNext;
        i++;
    }

    freeData(sorted);
    freeData(unsorted);
}

template <class T>
void insertSort(Node<T> ** list, Node<T> * pNode)
{
    Node<T> * current;

    if (*list == NULL || (*list)->data >= pNode->data)
    {
        pNode->pNext = *list;
        *list = pNode;
    }
    else
    {
        current = *list;
        while (current->pNext != NULL && current->pNext->data < pNode->data)
            current = current->pNext;
        
        pNode->pNext = current->pNext;
        current->pNext = pNode;
    }
}

#endif // INSERTION_SORT_H

