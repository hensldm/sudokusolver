#include <iostream>
#include "sudokugrid.h"


int main(int argc, char *argv[]) {
    const char usage[] = "This is the usage statement\n";
    
    if(argc < 2) {
        std::cout << argv[0] << " " << usage;
        return 1;
    }

    std::string filename(argv[1]);
    SudokuGrid sudokuGrid(filename);
    std::cout << sudokuGrid.ToString();

    return 0;
}