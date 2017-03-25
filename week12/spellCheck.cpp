/***********************************************************************
 * Module:
 *    Week 12, Spell Check
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    This program will implement the spellCheck() function
 ************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "spellCheck.h"
#include "hash.h"
#include "list.h"
using namespace std;

#define DSIZE 2322 //size for dictionary array
#define FARRAY 130 //size for file array
#define MARRAY 5 //sixe for misspelled array

/****************************************
 * S HASH
 * A hash of string
 ****************************************/
class SHash : public Hash <string>
{
public:
   SHash(int numBuckets) throw (const char *) :
         Hash <string> (numBuckets)  {}
   SHash(const SHash & rhs) throw (const char *) :
         Hash <string> (rhs) {}

   // hash function for strings will add up all the ASCII values
   int hash(const string & value) const
   {
      int index = 0;
      //int newSize = numBuckets + (numBuckets * 1.5);
      for(const char * p = value.c_str(); *p; p++)
      {
         index += *p;
      }
      index %= capacity();
      assert(0 <= index && index < capacity());
      return index;
      //when calling this hash, we'll need to calculate the size
      // before callign the hash since it will affect capacity and other 
      // assert functions that are based on numBuckets
      
      //return index % newSize;
      //old size was static 3000, but I'm calculating a newhash size, although
      // it doesn't match capacity.  May need to think abou that.'
      
      // per the new Data Structures text p 312
      // the hash should be approximately 1.5 times
      // larger than the number of elements to be stored
      // in the hash. Dictionary.txt has approx 2000 words.
      // We made our hash capacity 3000.

   }
private:

};

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   //we should probably defind our static sizes so
   // we can use them in our loops


   string fileName;
   string dictionaryArray[DSIZE];
   string fileArray[FARRAY];

   int hashSize = DSIZE * 1.5;
   SHash d(hashSize);
   
   cout << "What file do you want to check? ";
   cin >> fileName;

//   ifstream fin(fileName);
   // assert(!fin.fail());
   // for (int i = 0; i < 130; i++)
   // {
   // fin >> fileArray[i];
   // assert(!fin.fail());
   // }
   //fin.close();


   // compare file with dictionary.txt
   // add any words not found to array
   // if words are added to array, change bool to true

   bool spellingErrors = false;
   string misspelledArray[5];
   
   if(spellingErrors)
   {
      // testBed only has two misspelled words. If we ever use this
      // for another project, loop through the array to display.
       cout << "Misspelled: " << misspelledArray[0] << ", "
            << misspelledArray[1] << endl;
   }
   else if(!spellingErrors)
   {
      cout << "File contains no spelling errors\n";
   }
}

void readFile(string fileName, SHash d)
{

   ifstream fin("dictionary.txt");
   assert(!fin.fail());
   while (!fin.eof())
   {
      string value;
      fin >> value;
      d.insert(value);
      assert(!fin.fail());
   }
//    for (int i = 0; i < DSIZE; i++)
//    {
//       //insert into the hash here?
//       //fin >> dictionaryArray[i];
//       string value;
//       fin >> value;
//       d.insert(value);
//       assert(!fin.fail());
//    }
   fin.close();

}
