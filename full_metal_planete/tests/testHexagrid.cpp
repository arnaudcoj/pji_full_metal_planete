#include <Hexagrid.h>
#include <catch.hpp>

TEST_CASE( "test up cell coord", "proves that top cell of (1, 1) is (1, 0)" ) {
        Hexagrid grid;
        sf::Vector2i top = grid.getTopCellCoord(1, 1);
        REQUIRE(top.x == 1);
        REQUIRE(top.y == 0);

}

TEST_CASE( "test bottom cell coord", "proves that bottom cell of (1, 1) is (1, 2)" ) {
        Hexagrid grid;
        sf::Vector2i top = grid.getBottomCellCoord(1, 1);
        REQUIRE(top.x == 1);
        REQUIRE(top.y == 2);

}
