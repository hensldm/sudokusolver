#include <gtest/gtest.h>
#include "vertex.h"

TEST(VertexTest, Constructor) {
    Vertex vertex(2);

    ASSERT_EQ(2, vertex.getIdx());
    ASSERT_EQ(0, vertex.getColor());
}

TEST(VertexTest, ConstructorColor) {
    Vertex vertex(3,4);

    ASSERT_EQ(3, vertex.getIdx());
    ASSERT_EQ(4, vertex.getColor());
}

TEST(VertexTest, setColor) {
    Vertex vertex(3);

    ASSERT_EQ(0, vertex.getColor());
    vertex.setColor(2);
    ASSERT_EQ(2, vertex.getColor());
}

TEST(VertexTest, addNeighbor) {
    Vertex vertex1(3);
    Vertex vertex2(2);
    Vertex vertex3(1);

    vertex1.addNeighbor(&vertex2);
    vertex1.addNeighbor(&vertex3);
    
    ASSERT_NE(vertex1.getNeighbors().find(&vertex2), vertex1.getNeighbors().end());
    ASSERT_NE(vertex1.getNeighbors().find(&vertex3), vertex1.getNeighbors().end());
}

TEST(VertexTest, removeNeighbor) {
    Vertex vertex1(3);
    Vertex vertex2(2);
    Vertex vertex3(1);

    vertex1.addNeighbor(&vertex2);
    vertex1.addNeighbor(&vertex3);

    vertex1.removeNeighbor(&vertex2);

    ASSERT_NE(vertex1.getNeighbors().find(&vertex3), vertex1.getNeighbors().end());
    ASSERT_EQ(vertex1.getNeighbors().find(&vertex2), vertex1.getNeighbors().end());
}

int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}