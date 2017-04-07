/***********************************************************************
 * Component:
 *    Week 13, Maze
 *    Brother Helfrich, CS 235
 * Author:
 *    Adam Shumway, Jenaca Willans
 * Summary:
 *    Graph Class, graph.h
 ************************************************************************/

#ifndef GRAPH_H
#define GRAPH_H

#include "vector.h"
#include "set.h"
//#include "list.h"
#include "vertex.h"

//Create Graph Class
class Graph
{
  public:
   Graph(int numNode);
   
  Graph(const Graph &rhs) : matrix(NULL) { *this = rhs; }
   
//   Graph(const Graph &rhs) : matrix(NULL)
//   {
   //numNode = rhs.numNode;
//      edges = rhs.edges;
   //matrix = rhs.matrix;
   //}
   
   ~Graph() { clear(); }
   
   Graph &operator=(const Graph &rhs)
      {
         clear();
         numNode = rhs.numNode;
         this->matrix = new bool[numNode * numNode];
         
         int mSize = numNode * numNode;
         for (int i = 0; i < mSize; i++)
         {
           this->matrix[i] = rhs.matrix[i];
         }
      }
   
   // number of edges
   int size() const { return numNode; }
   
   // number of possible edges
   int capacity() const { return numNode * numNode; }
   
   bool empty() const { return size() == 0; }
   
   void clear () 
   {
      if (matrix != NULL)
         delete [] matrix;
   }
   
   bool isEdge(const Vertex &vFrom, const Vertex &vTo) const
   {
      return matrix[index(vFrom, vTo)];
   }
   
   Set<Vertex> findEdges(const Vertex &vFrom);
   
   Vector<Vertex> findPath(const Vertex &vFrom, const Vertex &vTo);
   
   void add(const Vertex &vFrom, const Vertex &vTo);
   void add(const Vertex &vFrom, const Set<Vertex> &sTo);
   
  private:
   
   // find the index into the array of nodes for a given edge
   int index(const Vertex & vFrom, const Vertex & vTo) const
   {
      assert(vFrom.index() * numNode + vTo.index() < numNode * numNode);
      return vFrom.index() * numNode + vTo.index();
   }

//   int index(const Vertex & vFrom, const Set<Vertex> & sTo) const
   //  {
   //  assert(vFrom.index() * numNode + sTo.index() < numNode * numNode);
   //  return vFrom.index() * numNode + sTo.index();
   // }

   bool * matrix;
   int numNode;
};

#endif // GRAPH_H
