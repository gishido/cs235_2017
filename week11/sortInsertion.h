/***********************************************************************
 * Module:
 *    Week 11, Sort Insertion
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans 
 * Summary:
 *    This program will implement the Insertion Sort
 ************************************************************************/

#ifndef SORT_INSERTION_H
#define SORT_INSERTION_H

#include <cassert>

/*****************************************************
 * SORT INSERTION
 * Perform the insertion sort
 ****************************************************/
template <class T>
void sortInsertion(T array[], int num)
{
    //declare
    int j;
    int high;
    int low;
    int mid;
    int hop;
    T temp;

    // begin loop
    for (int i = 1; i < num; i++)
    {
        temp = array[i];
        //starting params
        high = i;
        low = 0;
        hop = 1;

        //set low and high using
        do
        {
            //set mid and spread level
            mid = high - hop;
            hop *= 2;

            if (array[mid] > temp)
                high = mid;
            else
                low = mid + 1;
        }
        while (low + hop <= high);

        while (low != high)
        {
            mid = (low + high) / 2;

            if (array[mid] > temp)
                high = mid;
            else
                low = mid + 1;
        }

        //shift values
        for(j = i; j > low; j--)
            array[j] = array[j-1];

        //insert
        array[j] = temp;
    }   

}                                   


#endif // SORT_INSERTION_H
