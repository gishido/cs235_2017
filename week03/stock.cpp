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

//pre-define display
void display(Queue <int>, Queue <Dollars>, Queue <int>, Queue <Dollars>);

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
   string choice;
   int quantity;
   Queue <int> buyQueue;
   Dollars price;
   Queue <Dollars> buyPriceQueue;
   Queue <int> sellQueue;
   Queue <Dollars> sellPriceQueue;
   Queue <Dollars> portfolio; //holds profit/loss
   int buyTran = 0; //buy transaction counter
   int sellTran = 0; //sell transaction counter

   do
   {
      cout << "> ";
//      cin >> choice >> quantity >> price;
      //cin.ignore(255, '\n');
      cin >> choice;

     //cout << "debug: choice - " << choice << endl;
      
      if (choice == "buy")
      {
      //cout << "debug: I'm in the 'buy' choice\n";
        cin >> quantity >> price;
        buyQueue.push(quantity);
        buyPriceQueue.push(price);
        buyTran++;
  
      }
      else if (choice == "sell")
      {
         
        //cout << "debug: I'm in the 'sell' choice\n";
        cin >> quantity >> price;
        sellQueue.push(quantity);
        sellPriceQueue.push(price);
        sellTran++;

        int sellShares = 0;
        int buyShares = 0;
        //calculate proceeds

        if (sellTran > 0)
            sellShares = sellQueue.front();


        while (sellShares != buyShares)
        {
            //cout << "debug: inside sell while loop\n";
            buyShares = buyQueue.front(); //get share count
            Dollars proceeds = 0; 
            
            if(sellShares < buyShares)
            {
                //cout << "debug: sellshares less than buy shares\n";
                int tempFront = buyQueue.getMyFront(); //get current position
                proceeds = (sellPriceQueue.front() - buyPriceQueue.front()) * sellShares;
                buyQueue.pop();
                buyQueue.setMyFront(tempFront);
                buyQueue.push(buyShares - sellShares); //push new share count
                buyShares = sellShares;  //setting the same to break the loops
                portfolio.push(proceeds); //pushing proceeds of sale to portfolio queue
            }
            else if (sellShares == buyShares)
            {
                //cout << "debug: sellshares are equal to buyshares\n";
                //buyShares = buyQueue.front();
                //assuming multiple iterations, adding proceds to itself and result of math
                proceeds = ((sellPriceQueue.front() - buyPriceQueue.front()) * sellShares);
                buyQueue.pop();         //pop all purchased shares at this price
                buyPriceQueue.pop();    //pop all share prices at this quantity
                buyShares = sellShares;  //setting the same to break the loops
                portfolio.push(proceeds); //pushing proceeds of sale to portfolio queue
            }
            else
            {
                //cout << "debug: sellshares are greater than buyshares\n";
                //assuming multiple iterations, adding proceds to itself and result of math
                //using buy shares until sellshares are less than buyshares
                proceeds = ((sellPriceQueue.front() - buyPriceQueue.front()) * buyShares);
                buyQueue.pop();         //pop all purchased shares at this price
                buyPriceQueue.pop();    //pop all share prices at this quantity
                portfolio.push(proceeds); //pushing proceeds of sale to portfolio queue
            }
        }

      }
      else if (choice == "display")
      {
 
         //cout << "debug: I'm in the 'display' choice\n";
        Dollars portSum = 0; //for use with the proceeds (portfolio summary)

         Queue <int> bQ(buyQueue); //buyQueue
         Queue <Dollars> bP(buyPriceQueue); //buyPriceQueue
         Queue <int> sQ(sellQueue); //sellQueue
         Queue <Dollars> sP(sellPriceQueue); //sellPriceQueue
         Queue <Dollars> pList(portfolio); //portfolio queue
         
         //display(bQ, bP, sQ, sP);
         cout << "Currently Held:\n";
        //output holdings
         if (buyTran > 0)
         {
            for (int i = 0; i < buyTran; i++)
            {
                cout << "\tBought " << bQ.front()
                    << " shares at " << bP.front()
                    << endl;
                bQ.pop();
                bP.pop();
            }
         }

         //output sell history
         if (sellTran > 0)
         {
             cout << "Sell History:\n";
            for (int i = 0; i < sellTran; i++)
            {
                cout << "\tSold " << sQ.front()
                    << " shares at " << sP.front()
                    << " for a profit of " << pList.front() << endl; //still have to work out the profit piece
                portSum += pList.front();
                sQ.pop();
                sP.pop();
                pList.pop();
            }
         }
         
         //display proceeds
         cout << "Proceeds: "; 
         if (portfolio.empty())
         {
             cout << "$0.00\n";
         }
         else
         {
             cout << portSum << endl;
         }
      
      }
    }
   while (choice != "quit");
   
             
}
