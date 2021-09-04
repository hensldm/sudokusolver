#include "graph.h"

bool Graph::checkBounds(int idx) {
    if(idx >= 0 && idx < vertices.size()) {
        return true;
    } else {
        return false;
    }
}

Graph::Graph() {
    nextIdx = 0;
}

Graph::~Graph() {
    int i;
    
    for(i=0; i < vertices.size(); i++) {
        delete vertices[i];
    }
}

void Graph::addVertex() {
    vertices.push_back(new Vertex(nextIdx));
    visited.push_back(false);
    nextIdx++;
}

void Graph::addVertex(int color) {
    vertices.push_back(new Vertex(nextIdx, color));
    visited.push_back(false);
    nextIdx++;
}

Vertex* Graph::getVertex(int idx) {
    if(checkBounds(idx)) {
        return vertices[idx];
    } else {
        return NULL;
    }
}

void Graph::addEdge(int src, int dst, bool directed) {
    if(checkBounds(src) && checkBounds(dst)) {
        vertices[src]->addNeighbor(vertices[dst]);
        if(!directed) {
            vertices[dst]->addNeighbor(vertices[src]);
        }
    }
}

void Graph::clearVisited() {
    int i;

    for(i = 0; i < visited.size(); i++) {
        visited[i] = false;
    }
}

void Graph::setVertexVisited(int idx) {
    if(checkBounds(idx)) {
        visited[idx] = true;
    }
    //! @TODO: Print error message to stderr on error
}

void Graph::unsetVertexVisited(int idx) {
    if(checkBounds(idx)) {
        visited[idx] = false;
    }
    //! @TODO: Print error message to stderr on error
}

bool Graph::isVertexVisited(int idx) {
    if(checkBounds(idx)) {
        return visited[idx];
    } else {
        //! @TODO: Print error message to stderr
        return false;
    }
}