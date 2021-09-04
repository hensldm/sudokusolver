#include <gtest/gtest.h>
#include <vector>
#include <unordered_set>
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

TEST(SudokuGridTest, getValueError) {
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

TEST(SudokuGridTest, toString) {
    SudokuGrid sudokuGrid(TESTGRID);

    ASSERT_EQ(TESTGRIDSTR, sudokuGrid.toString());
    
}

TEST(SudokuGridTest, toGraph) {
    SudokuGrid sudokuGrid(TESTGRID);
    
    Graph sudokuGraph = sudokuGrid.toGraph();

    std::unordered_set<Vertex*> neighbors0 =  {
        sudokuGraph.getVertex(1),
        sudokuGraph.getVertex(2),
        sudokuGraph.getVertex(3),
        sudokuGraph.getVertex(4),
        sudokuGraph.getVertex(5),
        sudokuGraph.getVertex(6),
        sudokuGraph.getVertex(7),
        sudokuGraph.getVertex(8),
        sudokuGraph.getVertex(9),
        sudokuGraph.getVertex(10),
        sudokuGraph.getVertex(11),
        sudokuGraph.getVertex(18),
        sudokuGraph.getVertex(19),
        sudokuGraph.getVertex(20),
        sudokuGraph.getVertex(27),
        sudokuGraph.getVertex(36),
        sudokuGraph.getVertex(45),
        sudokuGraph.getVertex(54),
        sudokuGraph.getVertex(63),
        sudokuGraph.getVertex(72),
    };

    std::unordered_set<Vertex*> neighbors31 =  {
        sudokuGraph.getVertex(4),
        sudokuGraph.getVertex(13),
        sudokuGraph.getVertex(22),
        sudokuGraph.getVertex(27),
        sudokuGraph.getVertex(28),
        sudokuGraph.getVertex(29),
        sudokuGraph.getVertex(30),
        sudokuGraph.getVertex(32),
        sudokuGraph.getVertex(33),
        sudokuGraph.getVertex(34),
        sudokuGraph.getVertex(35),
        sudokuGraph.getVertex(39),
        sudokuGraph.getVertex(40),
        sudokuGraph.getVertex(41),
        sudokuGraph.getVertex(48),
        sudokuGraph.getVertex(49),
        sudokuGraph.getVertex(50),
        sudokuGraph.getVertex(58),
        sudokuGraph.getVertex(67),
        sudokuGraph.getVertex(76),
    };

    std::unordered_set<Vertex*> neighbors79 =  {
        sudokuGraph.getVertex(7),
        sudokuGraph.getVertex(16),
        sudokuGraph.getVertex(25),
        sudokuGraph.getVertex(34),
        sudokuGraph.getVertex(43),
        sudokuGraph.getVertex(52),
        sudokuGraph.getVertex(60),
        sudokuGraph.getVertex(61),
        sudokuGraph.getVertex(62),
        sudokuGraph.getVertex(69),
        sudokuGraph.getVertex(70),
        sudokuGraph.getVertex(71),
        sudokuGraph.getVertex(72),
        sudokuGraph.getVertex(73),
        sudokuGraph.getVertex(74),
        sudokuGraph.getVertex(75),
        sudokuGraph.getVertex(76),
        sudokuGraph.getVertex(77),
        sudokuGraph.getVertex(78),
        sudokuGraph.getVertex(80),
    };

    ASSERT_EQ(neighbors0, sudokuGraph.getVertex(0)->getNeighbors());
    ASSERT_EQ(neighbors31, sudokuGraph.getVertex(31)->getNeighbors());
    ASSERT_EQ(neighbors79, sudokuGraph.getVertex(79)->getNeighbors());


}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}