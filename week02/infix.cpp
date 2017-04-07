/***********************************************************************
 * Module:
 *    Week 02, Stack
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    This program will implement the testInfixToPostfix()
 *    and testInfixToAssembly() functions
 ************************************************************************/

#include <iostream>    // for ISTREAM and COUT
#include <string>      // for STRING
#include <cassert>     // for ASSERT
#include "stack.h"     // for STACK
using namespace std;

/*****************************************************
 * CONVERT INFIX TO POSTFIX
 * Convert infix equation "5 + 2" into postifx "5 2 +"
 *****************************************************/
string convertInfixToPostfix(const string & infix)
{
   string postfix;

   /**********************************
   Implement code for infix to postfix
   **********************************/
   char token,
         topToken;
   Stack<char> myStack;
   const string BLANK = " ";
   for (int i = 0; i < infix.length(); i++)
   {
      token = infix[i];
      switch(token)
      {
         case ' ' : break;    //do nothing skip blanks
         case '(' : myStack.push(token);
                    break;
         case ')' : for (;;)
            {
               assert (!myStack.empty());
               topToken = myStack.top();
               myStack.pop();
               if (topToken == '(') break;
               postfix.append(BLANK + topToken);
            }
            break;
         case '+' : case '-' :
         case '^' : case '*' : case '/' : case '%':
                    for (;;)
                    {
                        if (myStack.empty() ||
                           myStack.top() == '(' ||
                           ((token == '^' || token == '*' || token == '/' || token == '%') &&
                           (myStack.top() == '*' || myStack.top() == '+' || myStack.top() == '-')))
                        {
                           myStack.push(token);
                           break;
                        }
                        else
                        {
                           topToken = myStack.top();
                           myStack.pop();
                           postfix.append(BLANK + topToken);
                        }
                    }
                    break;
         default : //operand
                  // postfix.append(BLANK + token);
                  if ( isdigit(infix[i-1]) )
                  {
                     postfix.append(1, token);
                  }
                  else
                  {
                     postfix.append(BLANK + token);
                  }

                  for(;;)
                  {
                     if ( !isalnum(infix[i+1]) ) break; //end of identifier
                     i++;
                     token = infix[i];
                     postfix.append(1, token);
                  }
      }
   }
   // pop remaining operators on the stack
   for (;;)
   {
      if (myStack.empty()) break;
      topToken = myStack.top();
      myStack.pop();
      if (topToken != '(')
      {
         postfix.append(BLANK + topToken);
      }
      else
      {
         std::cout << " *** Error in infix expression ***\n";
         break;
      }
   }

   return postfix;
}

/*****************************************************
 * TEST INFIX TO POSTFIX
 * Prompt the user for infix text and display the
 * equivalent postfix expression
 *****************************************************/
void testInfixToPostfix()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";
   
   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);

      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << "\tpostfix: " << postfix << endl << endl;
      }
   }
   while (input != "quit");
}

/**********************************************
 * CONVERT POSTFIX TO ASSEMBLY
 * Convert postfix "5 2 +" to assembly:
 *     LOAD 5
 *     ADD 2
 *     STORE VALUE1
 **********************************************/
string convertPostfixToAssembly(const string & postfix)
{
   string assembly;

   /**********************************
   Implement code for infix to assembly
   **********************************/
   //create char variables for input
   char token,
         tOperator; //for the math
   //create working stack...still determining if we need a char or a string
   Stack<char> myStack;
   //add spaces to output
   const string BLANK = " ";

   //begin looping through string
   for (int i = 0; i < postfix.length(); i++)
   {
      token = postfix[i];
      switch(token)
      {
         case ' ' : break;    //do nothing skip blanks
//commented out portion that we may not need for infixtoassembly
/*         case '(' : myStack.push(token);
                    break;
         case ')' : for (;;)
            {
               assert (!myStack.empty());
               topToken = myStack.top();
               myStack.pop();
               if (topToken == '(') break;
               assembly.append(BLANK + topToken);
            }
            break;*/
         case '+' : case '-' :
         case '^' : case '*' : case '/' : case '%':
                    for (;;)
                    {
                        string wrkString;

                        switch(token)
                        {
                            case '+' :
                            {
                                wrkString = "LOAD " + myStack.top()-1 + '\n';
                                assembly.append(wrkString);

                                wrkString = "ADD " + myStack.top() + '\n';
                                assembly.append(wrkString);

                                int value = myStack.top()-1 + myStack.top();
                                wrkString = "STORE VALUE" + i + BLANK + (char)value;
                                assembly.append(wrkString);
                                break;
                            }
                        }
                        /*if (myStack.empty() ||
                           myStack.top() == '(' ||
                           ((token == '^' || token == '*' || token == '/' || token == '%') &&
                           (myStack.top() == '*' || myStack.top() == '+' || myStack.top() == '-')))
                        {
                           myStack.push(token);
                           break;
                        }
                        else
                        {
                           topToken = myStack.top();
                           myStack.pop();
                           assembly.append(BLANK + topToken);
                        }*/
                    }
                    break;
         default : //operand
                  // assembly.append(BLANK + token);
                  if ( isdigit(postfix[i-1]) )
                  {
                     myStack.push(token); //add number to the stack
                     //assembly.append(1, token);
                  }
                  else
                  {
                     //I don't yet want to build my output string
                     //assembly.append(BLANK + token);
                  }

//not sure I need this yet either
/*                  for(;;)
                  {
                     if ( !isalnum(postfix[i+1]) ) break; //end of identifier
                     i++;
                     token = postfix[i];
                     assembly.append(1, token);
                  }*/
      }
   }
   //not sure I need this yet
   // pop remaining operators on the stack
   for (;;)
   {
      if (myStack.empty()) break;
      //topToken = myStack.top();
      myStack.pop();
/*      if (topToken != '(')
      {
         assembly.append(BLANK + topToken);
      }
      else
      {
         std::cout << " *** Error in postfix expression ***\n";
         break;
      }*/
   }


   return assembly;
}

/*****************************************************
 * TEST INFIX TO ASSEMBLY
 * Prompt the user for infix text and display the
 * resulting assembly instructions
 *****************************************************/
void testInfixToAssembly()
{
   string input;
   cout << "Enter an infix equation.  Type \"quit\" when done.\n";

   do
   {
      // handle errors
      if (cin.fail())
      {
         cin.clear();
         cin.ignore(256, '\n');
      }
      
      // prompt for infix
      cout << "infix > ";
      getline(cin, input);
      
      // generate postfix
      if (input != "quit")
      {
         string postfix = convertInfixToPostfix(input);
         cout << convertPostfixToAssembly(postfix);
      }
   }
   while (input != "quit");
      
}
