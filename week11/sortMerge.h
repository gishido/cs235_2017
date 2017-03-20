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

// forward delcare merge function
template <class T>
void merge(T destination[], int iBegin1, int iBegin2,
           int iEnd2, T source[]);

/*****************************************************
 * SORT MERGE
 * Perform the merge sort
 * from pseudocode in data structures p 279-280
 ****************************************************/
template <class T>
void sortMerge(T array[], int num)
{
   T source = array[num]; //num only?
   T destination;
   int numMerges = 0;
   int iBegin1 = 0;
   int iBegin2 = 0;
   int iEnd1 = 0;
   int iEnd2 = 0;
   int numIterations = 0;

//   do
//   {
//       while(iBegin1 < num)
//       {
//          numIterations++;

         // next two lines don't compile - source[]
         // for(int iEnd1 = iBegin1 + 1; 
         //  iEnd1 != num || !(source[iEnd1 - 1] > source[iEnd1]);)
//         for(iEnd1 = iBegin1 + 1; iEnd1 < num; iEnd1++)
//         {
//            if (!(array[iEnd1 - 1] > array[iEnd1]))
//            {
//               iBegin2 = iEnd1 +1;
//            }
//         }
//         for(iEnd2 = iBegin2 + 1; iEnd2 < num; iEnd2++)
//         {
//            if (!(array[iEnd1 - 2] > array[iEnd2]))
//            {
//               if(iBegin2 < num)
//               {
                  // merge(T* destination, iBegin1, iBegin2, iEnd2, source);
//               }
//               iBegin1 = iEnd2;
               
//            }
//         }

//         for(int i = 0; i < num; i++)
//         {
            //swap
//            T temp;
//            temp = source[i];
//            source[i] = destination[i];
//            destination[i] = temp;
//         }
//      }
//      std::cout << "debug: numIterations= " << numIterations << endl;
//   }
//   while(numIterations > 1);

//   if(array != source) //can't compare like this
   // {
   // for(int i = 0; i < num - 1; i++)
   // {
   //    array[i] = source[i];
   // }
   // }
}

/*****************************************************
 * SORT MERGE - merge function
 ****************************************************/
template <class T>
void merge(T destination[], int iBegin1, int iBegin2,
           int iEnd2, T source[])
{
   int iEnd1 = iBegin2 - 1;
   int i1 = iBegin1;
   int i2 = iBegin2;

   for(int iDest = 0; iDest < (iEnd2 - iBegin1 + 1); iDest++)
   {
      if(i1 <= iEnd1 && (i2 = iEnd2 || source[i2] > source[i1]))
      {
         destination[iDest] = source[i1++];
      }
      else
      {
         destination[iDest] = source[i2++];
      }
   }
}


#endif // SORT_MERGE_H
