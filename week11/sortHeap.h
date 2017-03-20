/***********************************************************************
 * Module:
 *    Week 11, Sort Heap
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    This program will implement the Heap Sort
 ************************************************************************/

#ifndef SORT_HEAP_H
#define SORT_HEAP_H


/*************************************************
 * Heap
 * A Heap template that holds stuff
 * from pseudocode Data Structures p 289
 *************************************************/
template <class T>
class Heap
{
  public:
  Heap() : array(0), num(NULL), maxElement(NULL) {}
  Heap(const T &t) : array(t), num(NULL), maxElement(NULL) {}

   Heap(const Heap<T> &rhs) throw(const char *) :
   array(0), num(NULL), maxElement(NULL) { *this = rhs;}

   ~Heap()
   {
      clear();
   }

   // is the container currently empty
   bool empty() const { return (num == 0); }

   // remove all the items from the container
   void clear();

   // how many items are currently in the container?
   int getMax() { return maxElement; }

   void deleteMax(); //remove maxElement

   void heapify();

   void sort();

//   void sortHeap(T array[], int num);

   void percolateDown(int index);

   void swap(int &rhs, int &lhs);
   

   T array;
   Heap<T> * maxElement;
   Heap<T> * num;
};

/*****************************************************
 * SORT HEAP
 * Perform the heap sort
 ****************************************************/
template <class T>
//void Heap<T>:: sortHeap(T array[], int num)
void sortHeap(T array[], int num)
{
   //Heap h(array, num);
   //h.sort();
}

/**************************************************
 * Heap Clear
 * remove every element from a heap
 *************************************************/
template <class T>
void Heap<T>::clear()
{
   // delete array template / Heap
   
   //null out the heap
   num = maxElement = NULL;
}

/**************************************************
 * Heap percolateDown
 * remove every element from a heap
 *************************************************/
template <class T>
void Heap<T>::percolateDown(int index)
{
   int indexLeft = index * 2;
   int indexRight = indexLeft + 1;

   if(indexRight <= num && array[indexRight] > array[indexLeft]
      && array[indexRight] > array[index])
   {
      swap(index, indexRight);
      percolateDown(indexRight);
   }
   else if (array[indexLeft] > array[index])
   {
      swap(index, indexLeft);
      percolateDown(indexLeft);
   }
      
}

/**************************************************
 * Heap swap
 *************************************************/
template <class T>
void Heap<T>::swap(int &lhs, int &rhs)
{
   int temp;
   temp = lhs;
   lhs = rhs;
   rhs = temp;
}

/**************************************************
 * Heap heapify - turn array into heap
 *************************************************/
template <class T>
void Heap<T>::heapify()
{
   for(int i = num/2; i > 1; i--)
   {
      percolateDown(i);
   }
}

/**************************************************
 * Heap sort - not to be confused with sortHeap
 *************************************************/
template <class T>
void Heap<T>::sort()
{
   while(num > 1)
   {
      swap(1, num);
      num--;
      percolateDown(1);
   }
}

#endif // SORT_HEAP_H
