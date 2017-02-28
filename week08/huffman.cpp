/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#include "huffman.h"       // for HUFFMAN() prototype
#include <string>
#include "vector.h"        //our vector class
#include "pair.h"          //pair class
#include <fstream>        //for reading in a file

using namespace std;

/**********************************************************************
Here's what I need to do.  I need to read in the file into a vector of pairs (pair.h)
and then use that vector to compare weights and build my huffman tree.  Then I need to 
output the tree, using something similar to the one found on huffman.h.

Step 1: read in file to vector of pairs and output the values
Step 2: build huffman tree using the vector pairs as a source
Step 3: output the resulting tree
**********************************************************************/

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
void huffman()
{

   return;
}

/*******************************************
 * HUFFMAN
 * Driver program to exercise the huffman generation code
 *******************************************/
string huffman(string fileName)
{
    Vector <Pair <string, float> > newVector;
    Pair <string, float> newPair;
    string input1;
    float input2;
    
    ifstream infile(fileName);

    if(infile)
    {
        while(infile >> input1 >> input2)
        {
            newPair.first = input1;
            newPair.second = input2;

            newVector.push_back(newPair);

            cout << "debug: input1 and input2 " << input1 << " " << input2 << endl;
        }
    }
    else
    {
        cerr << "Couldn't open " << fileName << " for reading\n";
    }

    return fileName;
}

