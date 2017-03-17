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
    int currVal;
    int switchVal;
    int switchPos = 0;
    int innerVal;

    //outter loop
    for (int i = 1; i < num; i++)
    {
        //currVal = array[i];
        //cout << "debug: currVal - " << currVal << endl;
        //inner loop
        for (int j = i + 1; j < num; j++)
        {
            //innerVal = array[j];
            //cout << "debug: innerVal - " << innerVal << endl;
            if (array[j] > array[i])
            {
                cout << "debug: sortSelect - well, POOP!  I think you did it!\n";
                // switchVal = array[i];
                // switchPos = j;
            }
        }
        //switch values
        // array[switchPos] = array[i];
        // array[i] = switchVal;
    }


}


#endif // SORT_SELECTION_H
