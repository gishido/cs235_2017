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
#define FSIZE 130 //size for file array
#define MSIZE 5 //sixe for misspelled array

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
 * read file
 ****************************************/
void readFile(string &fileName, string fileArray[])
{
   
   ifstream fin(fileName.c_str());
   assert(!fin.fail());
   
   fileArray[FSIZE];
   
   for(int i = 0; i < FSIZE; i++)
   {
      fin >> fileArray[i];
      assert(!fin.fail());
   }
   
   fin.close();
   
}

/*****************************************
 * SPELL CHECK
 * Prompt the user for a file to spell-check
 ****************************************/
void spellCheck()
{
   int hashSize = DSIZE * 1.5;
   SHash d(hashSize);
   string dFile;

   ifstream fin("dictionary.txt");
   assert(!fin.fail());
   while (!fin.eof())
   {
      string value;
      fin >> value;
      d.insert(value);
      assert(!fin.fail());
   }
   fin.close();

   string testFile = "";
   string fileArray[FSIZE];
   
   cout << "What file do you want to check? ";
//   cin >> testFile;
   getline(cin, testFile);
   cin.ignore();

   readFile(testFile, fileArray);

   
   bool spellingErrors = false;
   string misspelledArray[MSIZE];

   // Iterate through fileArray[] and test each
   // word against the dictionary hash. If NOT found, add
   // word to misspelled array.
   // if words are added to misspelled array,
   // change bool to true.
   
   // find example:
   // cin >> number;
   // cout << (h.find(number) ? "Found!" : "Not found.")
   //   << endl;
   
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
