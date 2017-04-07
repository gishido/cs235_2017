/***********************************************************************
 * Implementation:
 *    STOCK
 * Summary:
 *    This will contain the implementation for stocksBuySell() as well
 *    as any other function or class implementation you need
 * Author
 *    Adam Shumway, Jenaca Willans
 **********************************************************************/

#include <iostream>    // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>      // for STRING
#include <sstream>     // for STRING STREAM
#include <vector>      // for VECTOR of input
#include <cassert>     // for ASSERT
#include "stock.h"     // for STOCK_TRANSACTION
#include "queue.h"     // for QUEUE
using namespace std;

/************************************************
 * STOCKS BUY SELL
 * The interactive function allowing the user to
 * buy and sell stocks
 ***********************************************/
void stocksBuySell()
{
   // instructions
   cout << "This program will allow you to buy and sell stocks. "
        << "The actions are:\n";
   cout << "  buy 200 $1.57   - Buy 200 shares at $1.57\n";
   cout << "  sell 150 $2.15  - Sell 150 shares at $2.15\n";
   cout << "  display         - Display your current stock portfolio\n";
   cout << "  quit            - Display a final report and quit the program\n";

   // your code here...
   string userInput;
   Dollars proceeds = 0;
   string choice;
   int quantity;
   Queue <int> quantityArray;
   Dollars price;
   Queue <Dollars> priceArray;
   Queue <int> sellQuantityArray;
   Queue <Dollars> sellPriceArray;
   

string parse;
vector<string>inputVector;

   do
   {
      cout << "> ";
//      cin >> choice >> quantity >> price;
      //cin.ignore(255, '\n');
      cin >> userInput;

      cout << "debug: inputVecotr before loop size - " << inputVector.size()<< endl;
      cout << "debug: userInput - " << userInput << endl;

      stringstream ss(userInput);

      while (ss >> parse)
      {
         inputVector.push_back(parse);
      }

      cout << "debug: inputVecotr after loop size - " << inputVector.size() << endl;
      //debug
      for (int i = 0; i < inputVector.size(); i++)
      {
            cout << "debug: inputVector - " << inputVector[i] << endl;
      }
//      cout << "end while " << inputVector[0] << endl;
//      cout << "end while " << inputVector[1] << endl;
//      cout << "end while " << inputVector[2] << endl;
      
      for (int i = 0; i < quantityArray.size(); i++)
      {
            cout << "debug: quantityArray - " << quantityArray.front() << endl;
      }

      for (int i = 0; i < quantityArray.size(); i++)
      {
            cout << "debug: priceArray - " << priceArray.front() << endl;
      }

      choice = inputVector[0];
      quantity = atoi(inputVector[1].c_str());
//      price = static_cast<Dollars>(inputVector[2]);
      
      if (choice == "buy")
      {
      cout << "debug: I'm in the 'buy' choice\n";
         quantityArray.push(quantity);
         //priceArray.push(inputVector[2]);
      }
      else if (choice == "sell")
      {
         sellQuantityArray.push(quantity);
         sellPriceArray.push(price);

      }
      else if (choice == "display")
      {
         cout << "enter display\n";

         if (!priceArray.empty())
         {
            cout << "Currently held:\n";

            while (!priceArray.empty())
            {
               cout << "\tBought " << quantityArray.front()
                    << " shares at " << priceArray.front() << endl;
          
               quantityArray.pop();
               priceArray.pop();
            }
         }
         if (!sellPriceArray.empty())
         {
            cout << "Sell History:\n";

            while (!sellPriceArray.empty())
            {
               cout << "\tBought " << sellQuantityArray.front()
                    << " shares at " << sellPriceArray.front() << endl;
          
               sellQuantityArray.pop();
               sellPriceArray.pop();
            }
         }

         cout << "Proceeds: " << proceeds << endl;
      }
      
   }
   while (choice != "quit");
   
            
}


