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
        Queue <int> wrkQ;
        Queue <Dollars> wrkP;
        //cout << "debug: I'm in the 'sell' choice\n";
        cin >> quantity >> price;
        wrkQ.push(quantity);
        wrkP.push(price);
        sellTran++;

        //cout << "debug: sell price is - " << wrkP.front() << endl;
        int sellShares = 0;
        int buyShares = 0;
        //calculate proceeds

        sellShares = wrkQ.front();
        while (sellShares != buyShares)
        {
            //cout << "debug: inside sell while loop\n";
            buyShares = buyQueue.front(); //get share count
            sellShares = wrkQ.front();
            Dollars proceeds = 0; 
            //cout << "debug: buyShares quantity is - " << buyShares << " and while count is: " << i << endl;
            
            if(sellShares < buyShares)
            {
                //cout << "debug: sellshares less than buy shares\n";
                int tempFront = buyQueue.getMyFront(); //get current position
                int tempBack = buyQueue.getMyBack();
                //cout << "debug: old front and back - " << tempFront << ", " << tempBack << endl;
                //cout << "debug: sell price - " << wrkP.front() << " buy price - " 
                //    << buyPriceQueue.front() << " sell shares - " << sellShares << endl;
                proceeds = (wrkP.front() - buyPriceQueue.front()) * sellShares;
                //cout << "debug: proceeds are - " << proceeds << endl;
                //move items from workQ to sell and price queues
                sellQueue.push(wrkQ.front());
                sellPriceQueue.push(wrkP.front());
                wrkQ.pop();
                wrkP.pop();
                //set buy queues properly
                buyQueue.pop();
                buyQueue.setMyBack(tempFront);
                buyShares -= sellShares;
                buyQueue.push(buyShares); //push new share count
                buyQueue.setMyFront(tempFront);
                buyQueue.setMyBack(tempBack);
                buyShares = sellShares;  //setting the same to break the loops
                portfolio.push(proceeds); //pushing proceeds of sale to portfolio queue
                //cout << "debug: new front and back - " << buyQueue.getMyFront() << ", " << buyQueue.getMyBack() << endl;
                //cout << "debug: portfolio amount is - " << portfolio.front() << endl;
            }
            else if (sellShares == buyShares)
            {
                //cout << "debug: sellshares are equal to buyshares\n";
                //buyShares = buyQueue.front();
                //assuming multiple iterations, adding proceds to itself and result of math
                proceeds = ((wrkP.front() - buyPriceQueue.front()) * sellShares);
                sellQueue.push(wrkQ.front());
                sellPriceQueue.push(wrkP.front());
                wrkQ.pop();
                wrkP.pop();
                buyQueue.pop();         //pop all purchased shares at this price
                buyPriceQueue.pop();    //pop all share prices at this quantity
                buyShares = sellShares;  //setting the same to break the loops
                portfolio.push(proceeds); //pushing proceeds of sale to portfolio queue
                buyTran--;
            }
            else
            {
                //cout << "debug: sellshares are greater than buyshares\n";
                int tempFront = wrkQ.getMyFront(); //get current position
                int tempBack = wrkQ.getMyBack();
                //assuming multiple iterations, adding proceds to itself and result of math
                //using buy shares until sellshares are less than buyshares
                proceeds = ((wrkP.front() - buyPriceQueue.front()) * buyShares);
                buyQueue.pop();         //pop all purchased shares at this price
                buyPriceQueue.pop();    //pop all share prices at this quantity
                portfolio.push(proceeds); //pushing proceeds of sale to portfolio queue
                sellShares -= buyShares; //decrements the sell Shares buy the buy share amt.
                sellQueue.push(buyShares);
                sellPriceQueue.push(wrkP.front());
                wrkQ.pop();
                wrkQ.setMyBack(tempFront);
                wrkQ.push(sellShares);
                wrkQ.setMyFront(tempFront);
                wrkQ.setMyBack(tempBack);
                buyTran--;
                sellTran++;
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
         cout << "Currently held:\n";
        //output holdings
         if (buyTran > 0)
         {
             //cout << "debug: inside buy display loop\n";
            for (int i = 0; i < buyTran; i++)
            {
                //cout << "debug: buytran display loop\n";
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
             //cout << "debug: sellTran is - " << sellTran << endl;
             cout << "Sell History:\n";
            for (int i = 0; i < sellTran; i++)
            {
                //cout << "debug: inside sell display loop\n";
                cout << "\tSold " << sQ.front()
                    << " shares at " << sP.front()
                    << " for a profit of " << pList.front() << endl; 
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
