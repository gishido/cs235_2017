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

}

 /******************************************
 * GRAPH: add
 * Add and edge, accept one vertex and a set
 *   of vertices
 ******************************************/
void Graph::add(const Vertex &vFrom, const Set<Vertex> &vTo)
{

}
 