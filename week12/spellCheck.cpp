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
#include <algorithm>
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
   // this does well against the three metrics:
   // Fast, Systematic, and Uniform.
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
            
      // per the new Data Structures text p 312
      // the hash should be approximately 1.5 times
      // larger than the number of elements to be stored
      // in the hash. Dictionary.txt has approx 2000 words.
      // We made our hash capacity 3000.

   }

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
   }
   fin.close();

   string testFile = "";
   string fileArray[FSIZE];
   
   cout << "What file do you want to check? ";
   cin >> testFile;

   readFile(testFile, fileArray);
   
   bool spellingErrors = false;
   int errorCounter = 0;
   string misspelledArray[MSIZE];

   // Iterate through fileArray[] and test each
   // word against the dictionary hash. If NOT found, add
   // word to misspelled array.
   // if words are added to misspelled array,
   // change bool to true.

   for(int i = 0; fileArray[i] != "\0"; i++)
   {
      string search = fileArray[i];
      transform(search.begin(), search.end(), search.begin(), ::tolower);

      if(!(d.find(search)))
      {
         misspelledArray[errorCounter] = fileArray[i];
         errorCounter++;
         spellingErrors = true;
      }
   }
   
   if(spellingErrors)
   {
      for (int i = 0; i < errorCounter - 1; i++)
      {
         cout << "Misspelled: " << misspelledArray[i] << ", ";
      }

      cout << misspelledArray[errorCounter - 1] << endl;
      
   }
   else if(!spellingErrors)
   {
      cout << "File contains no spelling errors\n";
   }
}
