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
            SetGridValue(row, col, grid[row][col]);
        }
    }
}

int SudokuGrid::GetGridValue(int row, int col) {
    if (CheckBounds(row, col)) {
        return grid[row][col];
    }
    return OUTOFBOUNDS_ERROR;
}

void SudokuGrid::SetGridValue(int row, int col, int val) {
    if(CheckBounds(row, col)) {
        grid[row][col] = val;
    }
}

std::string SudokuGrid::ToString() {
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