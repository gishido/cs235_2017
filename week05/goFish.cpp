/***********************************************************************
* Program:
*    Assignment 01, Go Fish
*    Brother Helfrich, CS 235
* Author:
*    Adam Shumway, Jenaca Willans
* Summary: 
*    This is all the functions necessary to play Go Fish!
* Time:
*    Estimated:  4.0 hrs   
*    Actual:     3.0 hrs
* Please describe briefly what was the most difficult part.
*      Displaying the remaining cards in the set - I tried to just
*      display the hand Set variable but there was no method to do
*      so. Once I realized the display needed to be formatted anyway,
*      it was easy.  
************************************************************************/

#include <iostream>
#include <fstream>
#include <string>
#include "set.h"
#include "card.h"
#include "goFish.h"
using namespace std;

/**********************************************************************
 * GO FISH
 * The function which starts it all
 ***********************************************************************/
void goFish()
{
   // set hand variables including text file with pre-set hand.
   Set <Card> hand;
   char fileName[] = "/home/cs235/week05/hand.txt";
   Card fileCard;
   
   // open file 
   ifstream fin(fileName);

   // return error if read fails.
   if (fin.fail())
   {
      cout << "Error reading file\n";
   }

   // read file and insert each card into the hand.
   while (!fin.eof())
   {
      fin >> fileCard;
      hand.insert(fileCard);
   }

   // close file
   fin.close();      

   // set game variables
   Card cardRequest;
   int round = 1;
   int match = 0;

   cout << "We will play 5 rounds of Go Fish.  Guess the card in the hand\n";

   // known number of rounds in testBed
   while(round < 6)
   {
      cout << "round " << round << ": ";
      cin >> cardRequest;
      round++;

      // set variables to find requested card in the hand.
      SetIterator <Card> itEmpty = hand.end();
      SetIterator <Card> itFind = hand.find(cardRequest);

      if(itFind != itEmpty)
      {
         cout << "\tYou got a match!\n";
         hand.erase(itFind);
         match++;
      }
      else
      {
         cout << "\tGo Fish!\n";
      }
   }

   cout << "You have " << match << " matches!\n";
   cout << "The remaining cards: ";

   for(int i = 0; i < (hand.size() - 1); i++)
   {
      cout << hand[i] << ", ";
   }

   cout << hand[hand.size() - 1] << endl;
   
   return ;
}
