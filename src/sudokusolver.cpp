#include <iostream>
#include <fstream>
#include <unordered_set>
#include "sudokugrid.h"

bool colorGraph(Graph* graph, Vertex* vertex, int colors[SUDOKUGRID_HEIGHT][SUDOKUGRID_WIDTH]) {
    bool setColor = false;
    int idx = vertex->getIdx();
    std::unordered_set<int> usedColors;
    int color;
    bool brokeOut;

    if(graph->isVertexVisited(idx)) {
        return true;
    }
    graph->setVertexVisited(idx);
    if(vertex->getColor() != 0) {
        colors[idx / SUDOKUGRID_HEIGHT][idx % SUDOKUGRID_WIDTH] = vertex->getColor();
        for (auto neighbor : vertex->getNeighbors()) {
            if(!colorGraph(graph, neighbor, colors)) {
                graph->unsetVertexVisited(idx);
                return false;
            }
        }
    } else {
        for( auto neighbor : vertex->getNeighbors()) {
            usedColors.insert(neighbor->getColor());
        }
        for (color = 1; color < 10; color++) {
            if(usedColors.find(color) == usedColors.end()) {
                if (color > 10) {
                    std::cout << color << "\n";
                }
                colors[idx / SUDOKUGRID_HEIGHT][idx % SUDOKUGRID_WIDTH] = color;
                vertex->setColor(color);
                setColor = true;
                for (auto neighbor : vertex->getNeighbors()) {
                    brokeOut = false;
                    if(!colorGraph(graph, neighbor, colors)) {
                        if(setColor) {
                            vertex->setColor(0);
                        }
                        graph->unsetVertexVisited(idx);
                        brokeOut = true;
                        break;
                    }
                }
                if(!brokeOut) {
                    return true;
                }
            }
        }
        if (color == 10) {
            graph->unsetVertexVisited(idx);
            return false;
        }
    }
    return true;
}

bool solve(Graph* graph, int colors[SUDOKUGRID_HEIGHT][SUDOKUGRID_WIDTH]) {
    graph->clearVisited();
    return colorGraph(graph, graph->getVertex(rand() % graph->getVerticies().size()), colors);
}

int main(int argc, char *argv[]) {
    const char usage[] = "This is the usage statement\n";
    
    if(argc < 2) {
        std::cout << argv[0] << " " << usage;
        return 1;
    }

    std::string filename(argv[1]);
    SudokuGrid sudokuGrid(filename);

    Graph graph = sudokuGrid.toGraph();

    int colors[SUDOKUGRID_HEIGHT][SUDOKUGRID_WIDTH];

    if(solve(&graph, colors)){
        SudokuGrid solution(colors);
        std::cout << solution.toString();
    } else {
        std::cout << "No Solution Found!\n";
    }

    return 0;
}