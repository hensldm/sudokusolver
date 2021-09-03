#include "vertex.h"

Vertex::Vertex(int idx) {
    this->idx = idx;
    this->color = 0;
}

Vertex::Vertex(int idx, int color) {
    this->idx = idx;
    this->color = color;
}

void Vertex::setColor(int color) {
    this->color = color;
}

void Vertex::addNeighbor(Vertex* neighbor) {
    neighbors.insert(neighbor);
}

void Vertex::removeNeighbor(Vertex* neighbor){
    neighbors.erase(neighbor);
}
