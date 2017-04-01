/***********************************************************************
 * Component:
 *    Week 13, Maze
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    Graph Class, graph.cpp
 ************************************************************************/

 #include <iostream>
 #include "graph.h"

 /******************************************
 * GRAPH: Main Constructor
 * Allocate a 2-d array of bools
 ******************************************/
 Graph::Graph(int numNode)
 {
     assert(numNode > 0);
     try
     {
         this->matrix = new bool[numNode * numNode];
         
         int mSize = numNode * numNode;
         for (int i = 0; i < mSize; i++)
            matrix[i] = false;
        
         this->numNode = numNode;
     }
     catch(...)
     {
         this->matrix = NULL;
         this->numNode = 0;
         throw "ERROR: unable to allocate space for the graph";
     }
 }

 /******************************************
 * GRAPH: findEdges
 * find the edge and returns a set
 ******************************************/
Set<Vertex> Graph::findEdges(const Vertex &vFrom)
{

}
 
 /******************************************
 * GRAPH: findPath
 * finds a path and returns a vector
 ******************************************/
Vector<Vertex> Graph::findPath(const Vertex &vFrom, const Vertex &vTo)
{

}

 /******************************************
 * GRAPH: add
 * Adds an edge, accepting two vertices
 ******************************************/
void Graph::add(const Vertex &vFrom, const Vertex &vTo)
{
    cout << "debug: add...index value is - " << index(vFrom, vTo)
        << endl;
    matrix[index(vFrom, vTo)] = true;
    cout << "debug: add...matrix bool is - " 
        << (matrix[index(vFrom, vTo)]) ? "True!\n" : "False!\n";
}

 /******************************************
 * GRAPH: add
 * Add and edge, accept one vertex and a set
 *   of vertices
 ******************************************/
void Graph::add(const Vertex &vFrom, const Set<Vertex> &vTo)
{


}
 