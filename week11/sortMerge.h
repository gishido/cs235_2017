/***********************************************************************
 * Module:
 *    Week 11, Sort Merge
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans 
 * Summary:
 *    This program will implement the Merge Sort
 ************************************************************************/

#ifndef SORT_MERGE_H
#define SORT_MERGE_H

// merge(destination, iBegin1, iBegin2, iEnd2, source)

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
   T source = array[num - 1];
   int numMerges = 0;
   int iBegin1 = 0;

   do
   {
      int numIterations = 0;

      while(iBegin1 < num)
      {
         numIterations++;

//         for(int iEnd = iBegin1 + 1; iEnd != num; iEnd--)
      }
   }
   while(numMerges > 1);
   
}


#endif // SORT_MERGE_H
