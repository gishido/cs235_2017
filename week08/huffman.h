/***********************************************************************
 * Module:
 *    Week 08, Huffman
 *    Brother Helfrich, CS 235
 * Author:
 *    Br. Helfrich
 * Summary:
 *    This program will implement the huffman() function
 ************************************************************************/

#ifndef HUFFMAN_H
#define HUFFMAN_H

#include <string>

using namespace std;

void huffman();

string huffman(string fileName);

class Huffman
{
    public:

    /******************************************************
     * HUFFMAN :: EXTRACT RECURSIVE
     * From a single completed Huffman tree, extract all the
     * data and put it in output
     ******************************************************/
    void extractRecursive(BinaryNode < Pair <string, float> > * tree,
                                   string sPrefix,
                                   const Vector < Pair <string, float > > & input,
                                   Pair <string, string> output [])
    {
       // better have a tree
       assert(tree);

       // if we are a leaf, then save the data
       if (tree->pLeft == NULL && tree->pRight == NULL)
       {
          for (int i = 0; i < input.size(); i++)
             if (input(i).getFirst() == tree->data.getFirst())
             {
                Pair <string, string> pair(sPrefix, input(i).getFirst());
                output[i] = pair;
                return;
             }

          // unable to find something matching our node
          assert(false);
       }

       // handle the left tree
       assert(tree->pRight);
       extractRecursive(tree->pLeft,
                        sPrefix + "0",
                        input,
                        output);
       // handle the right tree
       assert(tree->pLeft);
       extractRecursive(tree->pRight,
                        sPrefix + "1",
                        input,
                        output);
    }
};



#endif // HUFFMAN_h
