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
        Graph(int numNode);

        Graph(const Graph &rhs) : matrix(NULL) { *this = rhs; }

        ~Graph() { clear(); }

        Graph &operator=(const Graph &rhs)
        {
            numNode = rhs.numNode;
        }

        int size() const { return numNode; }

        void clear () 
        {
            if (matrix != NULL)
                delete [] matrix;
        }

        bool isEdge(const Vertex &vFrom, const Vertex &vTo) const
        {
            bool theEdge = false;
            if (matrix[index(vFrom, vTo)] == true)
                theEdge = true;

            cout << "debug: matrix index - " << index(vFrom, vTo) << endl;
            cout << "debug: isEdge - " << theEdge ? "true\n" : "false\n";

            return theEdge;
        }

        Set<Vertex> findEdges(const Vertex &vFrom);
    
        Vector<Vertex> findPath(const Vertex &vFrom, const Vertex &vTo);

        void add(const Vertex &vFrom, const Vertex &vTo);
        void add(const Vertex &vFrom, const Set<Vertex> &vTo);

    private:
        int index(const Vertex &vFrom, const Vertex &vTo) const
        {
            assert(vFrom.index() * numNode + vTo.index() < numNode * numNode);
            return vFrom.index() * numNode + vTo.index();
        }
        bool * matrix;
        int numNode;
};

#endif // GRAPH_H
