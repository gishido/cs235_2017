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

template <class T>
void QuickSort(T* array, int startIndex, int endIndex);

template <class T>
int SplitArray(T* array, T pivot, int startIndex, int endIndex);

void swap(int &a, int &b);

/*****************************************************
 * SORT QUICK
 * Perform the quick sort
 * Pseudocode from p 284 of Data Structures
 ****************************************************/
template <class T>
void sortQuick(T array[], int num)
{
    int start = 0;
    int end = num - 1;

    QuickSort(array, start, end);

//   if(num <= 1)
   //    return;

//   int iUp = 0;
//   int iEnd = num - 1;
//   int iDown = iEnd;

//   T pivotValue = array[iEnd / 2];

//   while(iUp <= iDown)
//   {
//       while(iUp <= iEnd && pivotValue > array[iUp])
//      {
//         iUp++;
//      }

//      while(iDown >= 0 && array[iDown] > pivotValue)
//      {
//         iDown--;
//      }

//      if(iUp <= iDown) //< vs >
//      {
//         std::cout << "Made it to swap \n";
         //swap
//         T temp;
//         temp = array[iUp];
//         array[iUp] = array[iDown];
//         array[iDown] = temp;
//      }
//   }

//   sortQuick(array, iUp);
//   sortQuick(array + iUp, iEnd - iUp + 1);
}

void swap(int &a, int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

template <class T>
void QuickSort(T* array, int startIndex, int endIndex)
{
    T pivot = array[startIndex];
    int splitPoint;
    
    if (endIndex > startIndex)
    {
        splitPoint = SplitArray(array, pivot, startIndex, endIndex);
        array[splitPoint] = pivot;
        QuickSort(array, startIndex, splitPoint - 1);
        QuickSort(array, splitPoint + 1, endIndex);
    }
    cout << "debug: array[splitPoint] - " << array[splitPoint] << endl;
}

template <class T>
int SplitArray(T* array, T pivot, int startIndex, int endIndex)
{
    cout << "debug: SplitArray \n";
    int start = startIndex;
    int end = endIndex;
    
    while (start < end)
    {
        cout << "debug: SplitArray - whileLoop - start < end\n";
        cout << "debug: SplitArray - array[end] " << array[end] << endl;
        cout << "debug: SplitArray - array[start] " << array[start] << endl;
        cout << "debug: SplitArray - pivot " << pivot << endl;
        cout << "debug: SplitArray - start " << start << endl;
        cout << "debug: SplitArray - end " << end << endl;
        
        while (array[end] > pivot && end > start)
            end--;
        swap(array[start], array[end]);
        // cout << "debug: SplitArray - whileLoop - end--\n";

        while (pivot == array[start] && start < end)
            start++;
        swap(array[end], array[start]);
            // cout << "debug: SplitArray - whileLoop (=) - end++\n";

        while (pivot > array[start] && start < end)
            start++;
        swap(array[end], array[start]);
            // cout << "debug: SplitArray - whileLoop - end++\n";

        cout << "debug: SplitArray - endWhile\n";
    }
    
    return start;
}

#endif // SORT_QUICK_H
