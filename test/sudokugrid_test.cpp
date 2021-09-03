#include <gtest/gtest.h>
#include "sudokugrid.h"

int TESTGRID[9][9] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9},
    {2, 3, 4, 5, 6, 7, 8, 9, 1},
    {3, 4, 5, 6, 7, 8, 9, 1, 2},
    {4, 5, 6, 7, 8, 9, 1, 2, 3},
    {5, 6, 7, 8, 9, 1, 2, 3, 4},
    {6, 7, 8, 9, 1, 2, 3, 4, 5},
    {7, 8, 9, 1, 2, 3, 4, 5, 6},
    {8, 9, 1, 2, 3, 4, 5, 6, 7},
    {9, 1, 2, 3, 4, 5, 6, 7, 8},

};

const std::string TESTGRIDSTR = "1,2,3,4,5,6,7,8,9\n2,3,4,5,6,7,8,9,1\n3,4,5,6,7,8,9,1,2\n4,5,6,7,8,9,1,2,3\n5,6,7,8,9,1,2,3,4\n6,7,8,9,1,2,3,4,5\n7,8,9,1,2,3,4,5,6\n8,9,1,2,3,4,5,6,7\n9,1,2,3,4,5,6,7,8\n";

std::string TESTFILE = "test/testgrid.csv";

TEST(SudokuGridTest, GetValueError) {
    SudokuGrid sudokuGrid(TESTGRID);
    
    ASSERT_EQ(OUTOFBOUNDS_ERROR, sudokuGrid.getGridValue(9, 9));
    ASSERT_EQ(OUTOFBOUNDS_ERROR, sudokuGrid.getGridValue(9, 1));
    ASSERT_EQ(OUTOFBOUNDS_ERROR, sudokuGrid.getGridValue(2, 9));
    ASSERT_EQ(OUTOFBOUNDS_ERROR, sudokuGrid.getGridValue(-1, -1));
    ASSERT_EQ(OUTOFBOUNDS_ERROR, sudokuGrid.getGridValue(-1, 1));
    ASSERT_EQ(OUTOFBOUNDS_ERROR, sudokuGrid.getGridValue(2, -1));

}

TEST(SudokuGridTest, GridConstructor) {
    SudokuGrid sudokuGrid(TESTGRID);
    int row, col;

    for(row = 0; row < SUDOKUGRID_HEIGHT; row++) {
        for(col = 0; col < SUDOKUGRID_WIDTH; col++) {
            ASSERT_EQ(TESTGRID[row][col], sudokuGrid.getGridValue(row, col));
        }
    }
}

TEST(SudokuGridTest, FileConstructor) {
    SudokuGrid sudokuGrid(TESTFILE);
    int row, col;

    for(row = 0; row < SUDOKUGRID_HEIGHT; row++) {
        for(col = 0; col < SUDOKUGRID_WIDTH; col++) {
            ASSERT_EQ(TESTGRID[row][col], sudokuGrid.getGridValue(row, col));
        }
    }
}

TEST(SudokuGridTest, ToString) {
    SudokuGrid sudokuGrid(TESTGRID);

    ASSERT_EQ(TESTGRIDSTR, sudokuGrid.toString());
    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}