#ifndef SUDOKUGRID_H
#define SUDOKUGRID_H

#include <string>

#define SUDOKUGRID_HEIGHT 9
#define SUDOKUGRID_WIDTH 9
#define OUTOFBOUNDS_ERROR -1

class SudokuGrid {
    private:
        int grid[SUDOKUGRID_HEIGHT][SUDOKUGRID_HEIGHT];

        bool CheckBounds(int row, int col) {
            if((row >= 0 && row < SUDOKUGRID_HEIGHT) && (col >= 0 && col < SUDOKUGRID_WIDTH)) {
                return true;
            } else {
                //! @TODO: Add error message
                return false;
            }
        }
    
    public:
        SudokuGrid(std::string filename);

        SudokuGrid(int grid[SUDOKUGRID_HEIGHT][SUDOKUGRID_HEIGHT]);

        int GetGridValue(int row, int col);

        void SetGridValue(int row, int col, int val);

        std::string ToString();
};

#endif
