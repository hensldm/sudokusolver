#ifndef VERTEX_H
#define VERTEX_H

#include <unordered_set>

class Vertex {
    private:
        int idx;
        int color;
        std::unordered_set<Vertex*> neighbors;

    public:
        Vertex(int idx);
        Vertex(int idx, int color);

        int getIdx() { return idx; }
        int getColor() { return color; }
        std::unordered_set<Vertex*> getNeighbors() { return neighbors; }

        void setColor(int color);
        void addNeighbor(Vertex* neighbor);
        void removeNeighbor(Vertex* neighbor);
};

#endif