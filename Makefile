.PHONY: clean test

sudokusolver: build/sudokusolver.o build/sudokugrid.o build/vertex.o build/graph.o
	g++ -g -Wall -o sudokusolver build/sudokusolver.o build/sudokugrid.o build/vertex.o build/graph.o

build/sudokusolver.o: src/sudokusolver.cpp include/sudokugrid.h
	g++ -g -Iinclude -c src/sudokusolver.cpp -o build/sudokusolver.o

build/sudokugrid.o: src/sudokugrid.cpp include/sudokugrid.h
	g++ -g -Iinclude -c src/sudokugrid.cpp -o build/sudokugrid.o

build/vertex.o: src/vertex.cpp include/vertex.h
	g++ -g -Iinclude -c src/vertex.cpp -o build/vertex.o

build/graph.o: src/graph.cpp include/graph.h
	g++ -g -Iinclude -c src/graph.cpp -o build/graph.o

clean:
	rm sudokusolver *_test build/*.o

test: sudokugrid_test vertex_test graph_test
	./vertex_test
	./graph_test
	./sudokugrid_test

vertex_test: test/vertex_test.cpp build/vertex.o
	g++ -Iinclude -o vertex_test test/vertex_test.cpp build/vertex.o -lgtest -lpthread
	
graph_test: test/graph_test.cpp build/graph.o build/vertex.o
	g++ -Iinclude -o graph_test test/graph_test.cpp build/graph.o build/vertex.o -lgtest -lpthread

sudokugrid_test: test/sudokugrid_test.cpp build/sudokugrid.o
	g++ -Iinclude -o sudokugrid_test test/sudokugrid_test.cpp build/sudokugrid.o build/graph.o build/vertex.o -lgtest -lpthread

