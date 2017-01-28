/***********************************************************************
 * Implementation:
 *    NOW SERVING
 * Summary:
 *    This will contain the implementation for nowServing() as well as any
 *    other function or class implementations you may need
 * Author
 *    Adam Shumway, Jenaca Willans
 **********************************************************************/

#include <iostream>     // for ISTREAM, OSTREAM, CIN, and COUT
#include <string>       // for STRING
#include <cassert>      // for ASSERT
#include "nowServing.h" // for nowServing() prototype
#include "deque.h"      // for DEQUE
using namespace std;

/************************************************
 * NOW SERVING
 * The interactive function allowing the user to
 * handle help requests in the Linux lab
 ***********************************************/
void nowServing()
{
   // instructions
   cout << "Every prompt is one minute.  The following input is accepted:\n";
   cout << "\t<class> <name> <#minutes>    : a normal help request\n";
   cout << "\t!! <class> <name> <#minutes> : an emergency help request\n";
   cout << "\tnone                         : no new request this minute\n";
   cout << "\tfinished                     : end simulation\n";
   
   // your code here
   Deque <string> choiceDeque;
   Deque <string> nameDeque;
   string choice;
   string name;
   int minutes = 0;
   int request = 0;
   int timeLeft = 0;
   int emergency = 0;
   
   do
   {
      cout << "<" << request << "> ";
      request++;
      
      cin >> choice;
      
      if(choice == "cs124" || choice == "cs165")
      {
         cin >> name >> minutes;
         
         if(!timeLeft)
         {
            choiceDeque.push_front(choice);
            nameDeque.push_front(name);
            
            cout << "\tCurrently serving " << nameDeque.front()
                 << " for class " << choiceDeque.front()
                 << ". Time left: " << minutes << endl;

         }
         else
         {
            choiceDeque.push_back(choice);
            nameDeque.push_back(name);
            
            cout << "\tCurrently serving " << nameDeque.front()
                 << " for class " << choiceDeque.front()
                 << ". Time left: " << timeLeft << endl;
         }

//         timeLeft = minutes;
         timeLeft--;
         
         if(!timeLeft)
         {
            nameDeque.pop_front();
            choiceDeque.pop_front();
         }

         timeLeft += minutes;
         
         
      }
      else if(choice == "!!")
      {
         cin >> choice >> name >> minutes;
         emergency = 1;
         
         if(timeLeft)
         {
            cout << "\tCurrently serving " << nameDeque.front()
                 << " for class " << choiceDeque.front()
                 << ". Time left: " << minutes << endl;
            
            timeLeft--;

            if(!timeLeft)
            {
               nameDeque.pop_front();
               choiceDeque.pop_front();
            }
            
            timeLeft += minutes;
            
            choiceDeque.push_front(choice);
            nameDeque.push_front(name);         
            
         }
         else
         {
            timeLeft += minutes;
            choiceDeque.push_front(choice);
            nameDeque.push_front(name);         
            
            cout << "\tEmergency for " << nameDeque.front()
                 << " for class " << choiceDeque.front()
                 << ". Time left: " << timeLeft << endl;
            
            emergency = 0;
            
            
            timeLeft--;
            
            if(!timeLeft)
            {
               nameDeque.pop_front();
               choiceDeque.pop_front();
            }
            
            timeLeft += minutes;

            
         }
         
         
      }
      else if(choice == "none")
      {
         if(timeLeft)
         {
            if(!emergency)
            {
            cout << "\tCurrently serving " << nameDeque.front()
                 << " for class " << choiceDeque.front()
                 << ". Time left: " << minutes << endl;
            }
            else
            {
               cout << "\tEmergency for " << nameDeque.front()
                    << " for class " << choiceDeque.front()
                    << ". Time left: " << minutes << endl;

               emergency = 0;

               minutes--;
            
               if(!minutes)
               {
                  nameDeque.pop_front();
                  choiceDeque.pop_front();
               }
               
            }

            timeLeft--;
            
            if(!timeLeft)
            {
               nameDeque.pop_front();
               choiceDeque.pop_front();
            }
            
         }
         
      }
   }
   while(choice != "finished");
   
   if(choice == "finished")
   {
      // end
      cout << "End of simulation\n";
   }
   

}


