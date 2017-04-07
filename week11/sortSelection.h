/***********************************************************************
 * Module:
 *    Week 11, Sort Select
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans 
 * Summary:
 *    This program will implement the Selection Sort
 ************************************************************************/

#ifndef SORT_SELECTION_H
#define SORT_SELECTION_H

#include <iostream>

using namespace std;

/*****************************************************
 * SORT SELECTION
 * Perform the selection sort
 ****************************************************/
template <class T>
void sortSelection(T array[], int num)
{
    int currPos = 0;
    T currVal;
    T switchVal;
    T smallVal;
    int smallPos = 0;
    int switchPos = 0;
    int innerVal;


    for (int i = 0; i < num; i++)
    {
        smallPos = i;
        smallVal = array[smallPos];
        for (int j = i; j < num; j++)
        {

            if (smallVal > array[j])
            {
                smallPos = j;
                smallVal = array[smallPos];
            }

        }
        //switch values
        array[smallPos] = array[i];
        array[i] = smallVal;

    }
    
}


#endif // SORT_SELECTION_H
