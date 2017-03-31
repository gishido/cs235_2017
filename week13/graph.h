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
#include "vertex.h"

//Create Graph Class
class Graph
{
    public:
        Graph(int numNode) {}

        Graph(const Graphy &rhs) : matrix(NULL) { *this = rhs; }

        ~Graph() { clear(); }

        Graph &operator=(const Graph &rhs)
        {
            numNode = rhs.numNode;
        }

        int size() { return numNode; }

        void clear () 
        {
            if (matrix != NULL)
                delete [] matrix;
        }

        bool isEdge(const Vertex &vFrom, const Vertex &vTo)
        {
            bool theEdge = false;

            return theEdge;
        }

        Set<Vertex> findEdges(const Vertex &vFrom);
    
        Vertex<Vertex> findPath(const Vertex &vFrom, const Vertex &vTo);

        void add(const Vertex &vFrom, const Vertex &vTo);
        void add(const Vertex &vFrom, const Set<Vertex> &vTo);

    private:
        bool * matrix;
        int numNode;
};

#endif // GRAPH_H
