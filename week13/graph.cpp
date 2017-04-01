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

         int mSize = numNode * numNode;
         for (int i = 0; i < mSize; i++)
         {
           this->matrix[i] = false;
         }

//         clear();
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
   Set <Vertex> s;
   
   for(int v2 = 0; v2 < size(); v2++)
   {
      if(matrix[index(vFrom, v2)] == true)
      {
         s.insert(v2);
      }
   }

   return s;
}
 
 /******************************************
 * GRAPH: findPath
 * finds a path and returns a vector
 ******************************************/
Vector<Vertex> Graph::findPath(const Vertex &vFrom, const Vertex &vTo)
{
//   cout << "Debug: arrived in findPath \n";

   int distance = 0;
   Vector<Vertex> distances;
   List<Vertex> predecessor;
   Vertex v;
   Set <Vertex> s;
   Vector <Vertex> path;
   List <Vertex> toVisit;
   
   
   toVisit.push_back(vFrom);

   for(int i = 0; i < size(); i++)
   {
      distances[i] = -1;
   }
   
   while(!toVisit.empty())// && distances[vTo] = -1)
   {
      v = toVisit.front();
//      toVisit.pop_front();
      
//      if(distances[v] > distance)
//      {
//         distance++;
//      }
      
      s = findEdges(v);

      for(SetIterator<Vertex> it = s.begin(); it != s.end(); ++it)
      {
//         if(distances[it] = -1)
//         {
//            distances[it] = distance + 1;
//            predecessor[it] = v;
//            toVisit.push_back(it);
//         }
      }
   }
   
   distance++;
   
//   if(distances[vTo] = -1)
//   {
//      return -1;
//   }
   
   
   path.push_back(vTo);
   for(int i = 1; i < distance; i++)
   {
//      path.push_back(predecessor[path[i - 1]]);
   }
   
   return path;
}

 /******************************************
 * GRAPH: add
 * Adds an edge, accepting two vertices
 ******************************************/
void Graph::add(const Vertex &vFrom, const Vertex &vTo)
{
   this->matrix[index(vFrom, vTo)] = true;
}

 /******************************************
 * GRAPH: add
 * Add and edge, accept one vertex and a set
 *   of vertices
 ******************************************/
void Graph::add(const Vertex &vFrom, const Set<Vertex> &sTo)
{
//   this->matrix[index(vFrom, sTo)] = true;
}
 
