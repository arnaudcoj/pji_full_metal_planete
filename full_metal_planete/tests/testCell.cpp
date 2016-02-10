#include <cell.h>
#include <piece.h>
#include <catch.hpp>

#include <SFML/System/Vector2.hpp>

TEST_CASE( "test cell.getCoord", "tests if the coordinates returned are given to the constructor" ) {
    Cell cell1(sf::Vector2i(2, 3));
    Cell cell2(sf::Vector2i(4, 2));
    Cell cell3(1, 5);

    sf::Vector2i coord1 = cell1.getCoord();
    REQUIRE(coord1.x == 2);
    REQUIRE(coord1.y == 3);

    sf::Vector2i coord2 = cell2.getCoord();
    REQUIRE(coord2.x == 4);
    REQUIRE(coord2.y == 2);

    sf::Vector2i coord3 = cell3.getCoord();
    REQUIRE(coord3.x == 1);
    REQUIRE(coord3.y == 5);
}

TEST_CASE("test cell.isHalfCell", "tests if the created cells are halfCells or not") {
    Cell cell1(1, 2, false);
    Cell cell2(3, 4, true);
    Cell cell3(5, 6);

    REQUIRE_FALSE(cell1.isHalfCell());
    REQUIRE(cell2.isHalfCell());
    REQUIRE_FALSE(cell3.isHalfCell());
}

TEST_CASE("test getArea", "tests if the area returned is the one given at construction ") {
    Cell c1(1,2, false, 2);
    Cell c2(3, 2, false, 32);

    REQUIRE(c1.getArea() == 2);
    REQUIRE(c2.getArea() == 32);

}

//TODO TEST DEPLACEMENT SUR AUTRE CASE
//TODO TESTS FUITE MEMOIRE
