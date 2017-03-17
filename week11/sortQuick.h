/***********************************************************************
 * Module:
 *    Week 11, Sort Quick
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans 
 * Summary:
 *    This program will implement the Quick Sort
 ************************************************************************/

#ifndef SORT_QUICK_H
#define SORT_QUICK_H

//forward declare split
template <class T>
int SplitArray(T* array, T pivot, int startIndex, int endIndex);

/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
   T pivot = array[num];
   int splitPoint;
   int startIndex = 0;
   int endIndex = num;

   if (endIndex > startIndex)
   {
//seg   splitPoint = SplitArray(array, pivot, startIndex, endIndex);
      array[splitPoint] = pivot;
      sortQuick(array, splitPoint - 1);
//    sortQuick(array, splitPoint + 1, endIndex); // passes 2 not 1
      sortQuick(array, splitPoint + 1);
   }

   
}

/*****************************************************
 * SORT QUICK :: swap
 ****************************************************/
void swap(int &a, int &b)
{
   int temp;
   temp = a;
   a = b;
   b = temp;
}

/*****************************************************
 * SORT QUICK :: splitArray
 ****************************************************/
template <class T>
int SplitArray(T* array, T pivot, int startIndex, int endIndex)
{
   int leftBoundary = startIndex;
   int rightBoundary = endIndex;

   while (leftBoundary < rightBoundary)
   {
      while (array[rightBoundary] > pivot && rightBoundary > leftBoundary)
         rightBoundary--;
      swap(array[leftBoundary], array[rightBoundary]);

      while (pivot > array[leftBoundary] && rightBoundary > leftBoundary)
         leftBoundary++;
      swap(array[rightBoundary], array[leftBoundary]);
   }
   return leftBoundary;
}

#endif // SORT_QUICK_H
