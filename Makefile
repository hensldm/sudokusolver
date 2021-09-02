.PHONY: clean test

sudokusolver: build/sudokusolver.o build/sudokugrid.o
	g++ -g -Wall -o sudokusolver build/sudokusolver.o  build/sudokugrid.o

build/sudokusolver.o: src/sudokusolver.cpp include/sudokugrid.h
	g++ -g -Iinclude -c src/sudokusolver.cpp -o build/sudokusolver.o

build/sudokugrid.o: src/sudokugrid.cpp include/sudokugrid.h
	g++ -g -Iinclude -c src/sudokugrid.cpp -o build/sudokugrid.o

clean:
	rm sudokusolver sudokugrid_test build/*.o

test: sudokugrid_test
	./sudokugrid_test

sudokugrid_test: test/sudokugrid_test.cpp build/sudokugrid.o
	g++ -Iinclude -o sudokugrid_test test/sudokugrid_test.cpp build/sudokugrid.o -lgtest -lpthread