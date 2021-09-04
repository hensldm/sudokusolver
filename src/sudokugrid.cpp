#include <sstream>
#include <fstream>
#include <iostream>
#include "sudokugrid.h"

SudokuGrid::SudokuGrid(std::string filename) {
    std::string line;
    std::string num;
    std::ifstream fs(filename);
    int row = 0;
    int col = 0;

    if(fs.is_open()) {
        while (getline(fs, line)) {
            if (row < SUDOKUGRID_HEIGHT) {
                std::stringstream ls(line);
                while(getline(ls, num, ',')) {
                    if(col < SUDOKUGRID_WIDTH ) {
                        grid[row][col] = stoi(num);
                        col++;
                    } else {
                        std::cerr << "File " << filename << " has to many columns\n";
                        fs.close();
                        exit(1);
                    }
                }
                col = 0;
                row++;
            } else {
                std::cerr << "File " << filename << " has to many rows\n";
                fs.close();
                exit(1);
            }
        }
        fs.close();
    } else {
        std::cerr << "Unable to open file " << filename << "\n";
        exit(1);
    }
}

SudokuGrid::SudokuGrid(int grid[9][9]){
    int row, col;
    for(row = 0; row < SUDOKUGRID_HEIGHT; row++) {
        for (col = 0; col < SUDOKUGRID_HEIGHT; col++) {
            setGridValue(row, col, grid[row][col]);
        }
    }
}

int SudokuGrid::getGridValue(int row, int col) {
    if (checkBounds(row, col)) {
        return grid[row][col];
    }
    return OUTOFBOUNDS_ERROR;
}

void SudokuGrid::setGridValue(int row, int col, int val) {
    if(checkBounds(row, col)) {
        grid[row][col] = val;
    }
}

std::string SudokuGrid::toString() {
    int row, col;
    std::ostringstream os;

    for(row = 0; row < SUDOKUGRID_HEIGHT; row++) {
        for (col = 0; col < SUDOKUGRID_HEIGHT; col++) {
            if(col != 0) {
                os << ',';
            }
            os << grid[row][col];
        }
        os << '\n';
    }
    return os.str();
}

Graph SudokuGrid::toGraph(){
    Graph graph;
    int row, col, blockrow, blockcol, src, dst;
    
    for(row = 0; row < SUDOKUGRID_HEIGHT; row++) {
        for(col = 0; col < SUDOKUGRID_WIDTH; col++) {
            graph.addVertex(grid[row][col]);
        }
    }

    for(row = 0; row < SUDOKUGRID_HEIGHT * SUDOKUGRID_WIDTH; row += SUDOKUGRID_WIDTH) {
        for(src = row; src < row + SUDOKUGRID_WIDTH; src++) {
            for (dst = src + 1; dst < row + SUDOKUGRID_WIDTH; dst++) {
                graph.addEdge(src, dst, false);
            }
        }
    }

    for(col = 0; col < SUDOKUGRID_WIDTH; col++) {
        for(src = col; src < SUDOKUGRID_HEIGHT * SUDOKUGRID_WIDTH; src += SUDOKUGRID_WIDTH) {
            for (dst = src + SUDOKUGRID_WIDTH; dst < SUDOKUGRID_HEIGHT * SUDOKUGRID_WIDTH; dst += SUDOKUGRID_WIDTH) {
                graph.addEdge(src, dst, false);
            }
        }
    }

    for(blockrow = 0; blockrow < BLOCK_HEIGHT; blockrow++) {
        for(blockcol = 0; blockcol < BLOCK_WIDTH; blockcol++) {
            int topleft = blockrow * BLOCK_HEIGHT * SUDOKUGRID_WIDTH + blockcol * BLOCK_WIDTH;
            int nextBlockTopLeft = topleft + BLOCK_HEIGHT * SUDOKUGRID_WIDTH;
            for(src = topleft; src < nextBlockTopLeft; src = moveForwardOneInBlock(src)) {
                for(dst = moveForwardOneInBlock(src); dst < nextBlockTopLeft; dst = moveForwardOneInBlock(dst)) {
                    graph.addEdge(src, dst, false);
                }
            }
        }
    }
    return graph;
}