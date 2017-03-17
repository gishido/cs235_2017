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

/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
   int pivot = array[startIndex];
   int splitPoint;

   if (endIndex > startIndex)
   {
      splitPoint = SplitArray(array, pivot, startIndex, endIndex);
      array[splitPoint] = pivot;
      QuickSort(array, startIndex, splitPoint - 1);
      QuickSort(array, splitPoint + 1, endIndex);
   }   
}

void swap(int &a, int &b)
{
   int temp;
   temp = a;
   a = b;
   b = temp;
}


int SplitArray(int* array, int pivot, int startIndex, int endIndex)
{
   int leftBoundary = startIndex;
   int rightBoundary = endIndex;

   while (leftBoundary < rightBoundary)
   {
      while (pivot < array[rightBoundary] && rightBoundary > leftBoundary)
         rightBoundary--;
      swap(array[leftBoundary], array[rightBoundary]);

      while (pivot >= array[leftBoundary] && leftBoundary < rightBoundary)
         leftBoundary++;
      swap(array[rightBoundary], array[leftBoundary]);
   }
   return leftBoundary;
}

#endif // SORT_QUICK_H
