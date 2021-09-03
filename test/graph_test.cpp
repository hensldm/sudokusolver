#include <gtest/gtest.h>
#include "graph.h"

TEST(GraphTest, getVertexError) {
    Graph graph;

    graph.addVertex();

    ASSERT_EQ(NULL, graph.getVertex(1));
}

TEST(GraphTest, addVertex) {
    Graph graph;

    graph.addVertex();
    graph.addVertex();
    graph.addVertex(3);

    ASSERT_EQ(0, graph.getVertex(0)->getIdx());
    ASSERT_EQ(1, graph.getVertex(1)->getIdx());
    ASSERT_EQ(2, graph.getVertex(2)->getIdx());
    ASSERT_EQ(3, graph.getVertex(2)->getColor());
}

TEST(GraphTest, addEdge) {
    Graph graph;

    graph.addVertex();
    graph.addVertex();
    graph.addVertex(3);

    graph.addEdge(0, 1, false);
    graph.addEdge(1, 2, true);
    graph.addEdge(2, 0, false);

    Vertex* vertex0 = graph.getVertex(0);
    Vertex* vertex1 = graph.getVertex(1);
    Vertex* vertex2 = graph.getVertex(2);

    ASSERT_NE(vertex0->getNeighbors().find(vertex1), vertex0->getNeighbors().end());
    ASSERT_NE(vertex0->getNeighbors().find(vertex2), vertex0->getNeighbors().end());
    ASSERT_NE(vertex1->getNeighbors().find(vertex0), vertex1->getNeighbors().end());
    ASSERT_NE(vertex1->getNeighbors().find(vertex2), vertex1->getNeighbors().end());
    ASSERT_NE(vertex2->getNeighbors().find(vertex0), vertex2->getNeighbors().end());
    ASSERT_EQ(vertex2->getNeighbors().find(vertex1), vertex2->getNeighbors().end());
}

TEST(GraphTest, setVertexVisited) {
    Graph graph;

    graph.addVertex();
    graph.addVertex();
    graph.addVertex(3);

    graph.setVertexVisited(2);
    graph.setVertexVisited(0);

    ASSERT_EQ(true, graph.isVertexVisited(0));
    ASSERT_EQ(false, graph.isVertexVisited(1));
    ASSERT_EQ(true, graph.isVertexVisited(2));
    
}

TEST(GraphTest, clearVisited) {
    Graph graph;

    graph.addVertex();
    graph.addVertex();
    graph.addVertex(3);

    graph.setVertexVisited(2);
    graph.setVertexVisited(0);

    graph.clearVisited();

    ASSERT_EQ(false, graph.isVertexVisited(0));
    ASSERT_EQ(false, graph.isVertexVisited(1));
    ASSERT_EQ(false, graph.isVertexVisited(2));
    
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}