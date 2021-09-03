#ifndef GRAPH_H
#define GRAPH_H

#include <vector>
#include "vertex.h"

class Graph {
    private:
        int nextIdx;
        std::vector<Vertex*> vertices;
        std::vector<bool> visited;

        bool checkBounds(int idx);
    public:
        Graph();
        ~Graph();

        std::vector<Vertex*> getVerticies() { return vertices; }

        void addVertex();
        void addVertex(int color);
        Vertex* getVertex(int idx);

        void addEdge(int src, int dst, bool directed);

        void clearVisited();
        void setVertexVisited(int idx);
        bool isVertexVisited(int idx);
};


#endif