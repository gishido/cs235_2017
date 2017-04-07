/***********************************************************************
 * Module:
 *    Week 11, Sort Bubble
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    This program will implement the Bubble Sort
 ************************************************************************/

#ifndef SORT_BUBBLE_H
#define SORT_BUBBLE_H

using namespace std;

/*****************************************************
 * SORT BUBBLE
 * Perform the bubble sort
 * From Bubble sort pseudocode, p265 C++ Data Structures
 ****************************************************/
template <class T>
void sortBubble(T array[], int num)
{
   int iPivot = 0;
   int iCheck = 0;

   for(iPivot = num - 1; iPivot > 0; --iPivot)
   {
      //could increase efficiency with a bool here
//      bool swapped = false;

      for(iCheck = 0; iCheck < iPivot; ++iCheck)
      {
         if(array[iCheck] > array[iCheck + 1])
         {
            // swap
            T temp;
            temp = array[iCheck];
            array[iCheck] = array[iCheck + 1];
            array[iCheck + 1] = temp;

//          swapped = true;
         }

//          if(!swapped)
//          {
               //break
               // more efficient if we can figure this out.
//             return;
//          }
      }

   }
}

#endif // SORT_BUBBLE_H
