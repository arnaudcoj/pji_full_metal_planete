#include <catch.hpp>
#include <hexagrid.h>
#include <string>

/* Test of constructors*/

TEST_CASE( "test the hexagrid size", "proves Hexagrid(10, 10) creates a 10 * 10 Hexagrid" ) {
        Hexagrid grid = Hexagrid(10, 10);
        REQUIRE(grid.getWidth() == 10);
        REQUIRE(grid.getHeight() == 10);
}

TEST_CASE( "test of half cells placement", "proves half cells are well placed for different grids" ) {
        //Tests for a 8 * 6 grid
        Hexagrid grid = Hexagrid(8, 6);

        REQUIRE(grid.getCell(0, 0)->isHalfCell());
        REQUIRE(grid.getCell(1, 0)->isHalfCell());
        REQUIRE_FALSE(grid.getCell(2, 0)->isHalfCell());

        REQUIRE(grid.getCell(grid.getWidth() - 3, 0)->isHalfCell());
        REQUIRE_FALSE(grid.getCell(grid.getWidth() - 2, 0)->isHalfCell());
        REQUIRE(grid.getCell(grid.getWidth() - 1, 0)->isHalfCell());

        REQUIRE(grid.getCell(0, grid.getHeight() - 1)->isHalfCell());
        REQUIRE_FALSE(grid.getCell(1, grid.getHeight() - 1)->isHalfCell());
        REQUIRE(grid.getCell(2, grid.getHeight() - 1)->isHalfCell());

        REQUIRE_FALSE(grid.getCell(grid.getWidth() - 3, grid.getHeight() - 1)->isHalfCell());
        REQUIRE(grid.getCell(grid.getWidth() - 2, grid.getHeight() - 1)->isHalfCell());
        REQUIRE(grid.getCell(grid.getWidth() - 1, grid.getHeight() - 1)->isHalfCell());

        REQUIRE_FALSE(grid.getCell(3, 3)->isHalfCell());

        //Tests for a 7 * 5 grid
        grid = Hexagrid(7, 5);

        REQUIRE(grid.getCell(0, 0)->isHalfCell());
        REQUIRE(grid.getCell(1, 0)->isHalfCell());
        REQUIRE_FALSE(grid.getCell(2, 0)->isHalfCell());

        REQUIRE_FALSE(grid.getCell(grid.getWidth() - 3, 0)->isHalfCell());
        REQUIRE(grid.getCell(grid.getWidth() - 2, 0)->isHalfCell());
        REQUIRE(grid.getCell(grid.getWidth() - 1, 0)->isHalfCell());

        REQUIRE(grid.getCell(0, grid.getHeight() - 1)->isHalfCell());
        REQUIRE_FALSE(grid.getCell(1, grid.getHeight() - 1)->isHalfCell());
        REQUIRE(grid.getCell(2, grid.getHeight() - 1)->isHalfCell());

        REQUIRE(grid.getCell(grid.getWidth() - 3, grid.getHeight() - 1)->isHalfCell());
        REQUIRE_FALSE(grid.getCell(grid.getWidth() - 2, grid.getHeight() - 1)->isHalfCell());
        REQUIRE(grid.getCell(grid.getWidth() - 1, grid.getHeight() - 1)->isHalfCell());

        REQUIRE_FALSE(grid.getCell(3, 3)->isHalfCell());
}

/* Test of neighbors */

TEST_CASE( "test up cell", "proves that top cell of (1, 1) is (1, 0)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getTopCell(1, 1);
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 0);
}

TEST_CASE( "test bottom cell", "proves that bottom cell of (1, 1) is (1, 2)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getBottomCell(1, 1);
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 2);
}

TEST_CASE( "test left top cell", "proves that left top cell of (1, 1) is (0, 0) and the one of (2, 1) is (1, 1)" ) {
        Hexagrid grid = Hexagrid(10, 10);

        std::shared_ptr<Cell> cell = grid.getLeftTopCell(1, 1);
        REQUIRE(cell->getCoord().x == 0);
        REQUIRE(cell->getCoord().y == 0);

        cell = grid.getLeftTopCell(2, 1);
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 1);
}

TEST_CASE( "test left bottom cell", "proves that left bottom cell of (1, 1) is (0, 1) and the one of (2, 1) is (1, 2)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getLeftBottomCell(1, 1);
        REQUIRE(cell->getCoord().x == 0);
        REQUIRE(cell->getCoord().y == 1);

        cell = grid.getLeftBottomCell(2, 1);
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 2);
}

TEST_CASE( "test right top cell", "proves that right top cell of (1, 1) is (2, 0) and the one of (2, 1) is (3, 1)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getRightTopCell(1, 1);
        REQUIRE(cell->getCoord().x == 2);
        REQUIRE(cell->getCoord().y == 0);

        cell = grid.getRightTopCell(2, 1);
        REQUIRE(cell->getCoord().x == 3);
        REQUIRE(cell->getCoord().y == 1);
}

TEST_CASE( "test right bottom cell", "proves that right bottom cell of (1, 1) is (2, 1) and the one of (2, 1) is (3, 2)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getRightBottomCell(1, 1);
        REQUIRE(cell->getCoord().x == 2);
        REQUIRE(cell->getCoord().y == 1);

        cell = grid.getRightBottomCell(2, 1);
        REQUIRE(cell->getCoord().x == 3);
        REQUIRE(cell->getCoord().y == 2);
}

TEST_CASE("tests yaml construction", "tests if we can load a grid from a yaml file") {
    YAML::Node primes = YAML::Load("{name : terrain1, cells : [[[0,1], [0,1], [0,2], [0,3]],[[0,1], [0,1], [0,2], [0,3]],[[0,1], [0,2], [0,2], [0,3]], [[0,1], [0,2], [0,2], [0,3]]]}");
    REQUIRE(primes["name"].as<std::string>() == "terrain1");
}
