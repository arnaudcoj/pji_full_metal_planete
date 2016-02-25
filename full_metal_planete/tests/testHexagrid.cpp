#include <catch.hpp>
#include <hexagrid.h>
#include <cell.h>

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

TEST_CASE( "test getCell when cell out of bounds", "tests if getCell returns nullptr if we give coordinates out of the grid") {
    Hexagrid grid = Hexagrid(10, 10);
    REQUIRE(grid.getCell(3, 3) != nullptr);
    REQUIRE(grid.getCell(-1, 3) == nullptr);
    REQUIRE(grid.getCell(12, 3) == nullptr);
    REQUIRE(grid.getCell(3, -1) == nullptr);
    REQUIRE(grid.getCell(3, 12) == nullptr);
    REQUIRE(grid.getCell(-1, -1) == nullptr);
    REQUIRE(grid.getCell(12, 12) == nullptr);
    }

TEST_CASE( "test up cell", "proves that top cell of (1, 1) is (1, 0)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getTopCell(grid.getCell(1,1));
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 0);
}

TEST_CASE( "test bottom cell", "proves that bottom cell of (1, 1) is (1, 2)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getBottomCell(grid.getCell(1, 1));
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 2);
}

TEST_CASE( "test left top cell", "proves that left top cell of (1, 1) is (0, 0) and the one of (2, 1) is (1, 1)" ) {
        Hexagrid grid = Hexagrid(10, 10);

        std::shared_ptr<Cell> cell = grid.getLeftTopCell(grid.getCell(1, 1));
        REQUIRE(cell->getCoord().x == 0);
        REQUIRE(cell->getCoord().y == 0);

        cell = grid.getLeftTopCell(grid.getCell(2, 1));
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 1);
}

TEST_CASE( "test left bottom cell", "proves that left bottom cell of (1, 1) is (0, 1) and the one of (2, 1) is (1, 2)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getLeftBottomCell(grid.getCell(1, 1));
        REQUIRE(cell->getCoord().x == 0);
        REQUIRE(cell->getCoord().y == 1);

        cell = grid.getLeftBottomCell(grid.getCell(2, 1));
        REQUIRE(cell->getCoord().x == 1);
        REQUIRE(cell->getCoord().y == 2);
}

TEST_CASE( "test right top cell", "proves that right top cell of (1, 1) is (2, 0) and the one of (2, 1) is (3, 1)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getRightTopCell(grid.getCell(1, 1));
        REQUIRE(cell->getCoord().x == 2);
        REQUIRE(cell->getCoord().y == 0);

        cell = grid.getRightTopCell(grid.getCell(2, 1));
        REQUIRE(cell->getCoord().x == 3);
        REQUIRE(cell->getCoord().y == 1);
}

TEST_CASE( "test right bottom cell", "proves that right bottom cell of (1, 1) is (2, 1) and the one of (2, 1) is (3, 2)" ) {
        Hexagrid grid = Hexagrid(10, 10);
        std::shared_ptr<Cell> cell = grid.getRightBottomCell(grid.getCell(1, 1));
        REQUIRE(cell->getCoord().x == 2);
        REQUIRE(cell->getCoord().y == 1);

        cell = grid.getRightBottomCell(grid.getCell(2, 1));
        REQUIRE(cell->getCoord().x == 3);
        REQUIRE(cell->getCoord().y == 2);
}

TEST_CASE("tests construction with yaml", "tests if we can create a grid from a (correct) yaml node") {
    YAML::Node primes = YAML::Load("{name : terrain1, cells : ["
                                   "[[0,0], [0,10], [0,20], [0,30]],"
                                   "[[0,1], [0,11], [0,21], [0,31]],"
                                   "[[0,2], [0,12], [0,22], [0,32]],"
                                   "[[0,3], [0,13], [0,23], [0,33]]]}");

    Hexagrid grid(primes);

    REQUIRE(primes["name"].as<std::string>() == "terrain1");

    REQUIRE(grid.getCell(0, 0)->getArea() == 0);
    REQUIRE(grid.getCell(1, 3)->getArea() == 13);
    REQUIRE(grid.getCell(2, 2)->getArea() == 22);

    REQUIRE(grid.getCell(0,0)->isHalfCell());
    REQUIRE(grid.getCell(1,0)->isHalfCell());
    REQUIRE_FALSE(grid.getCell(2,0)->isHalfCell());
    REQUIRE_FALSE(grid.getCell(2,1)->isHalfCell());
    REQUIRE(grid.getCell(2,3)->isHalfCell());
    REQUIRE_FALSE(grid.getCell(1,3)->isHalfCell());

}

TEST_CASE("tests construction from yaml file", "tests if we can create a grid from a (correct) yaml file") {

    YAML::Node primes = YAML::LoadFile("../../media/grids/test.yaml");

    Hexagrid grid(primes);

    REQUIRE(primes["name"].as<std::string>() == "terrain1");

    REQUIRE(grid.getCell(0, 0)->getArea() == 0);
    REQUIRE(grid.getCell(1, 3)->getArea() == 13);
    REQUIRE(grid.getCell(2, 2)->getArea() == 22);

    REQUIRE(grid.getCell(0,0)->isHalfCell());
    REQUIRE(grid.getCell(1,0)->isHalfCell());
    REQUIRE_FALSE(grid.getCell(2,0)->isHalfCell());
    REQUIRE_FALSE(grid.getCell(2,1)->isHalfCell());
    REQUIRE(grid.getCell(2,3)->isHalfCell());
    REQUIRE_FALSE(grid.getCell(1,3)->isHalfCell());

}
