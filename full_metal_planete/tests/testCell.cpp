#include <memory>
#include <cell.h>
#include <piece.h>
#include <catch.hpp>

#include <SFML/System/Vector2.hpp>

TEST_CASE( "test cell.getCoord", "tests if the coordinates returned are the ones given to the constructor" ) {
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

TEST_CASE("tests setPiece & getPiece", "tests if we can set a piece and retrieve it from the cell") {
    std::shared_ptr<Cell> c = std::make_shared<Cell>(1,2, false, 2);
    std::shared_ptr<Piece> p = std::make_shared<Piece>();

    REQUIRE_FALSE(c->isOccupied());
    c->setPiece(p);
    REQUIRE(c->isOccupied());

    std::shared_ptr<Piece> p2 = c->getPiece();
    REQUIRE(p2 == p);
}

TEST_CASE("tests setPiece & removePiece", "tests if we can set a piece and remove it from the cell") {
    std::shared_ptr<Cell> c = std::make_shared<Cell>(1,2, false, 2);
    std::shared_ptr<Piece> p = std::make_shared<Piece>();
    std::shared_ptr<Piece> p2 = std::make_shared<Piece>();
    std::shared_ptr<Piece> pp;

    REQUIRE_FALSE(c->isOccupied());
    c->setPiece(p);
    REQUIRE(c->isOccupied());

    c->removePiece();
    REQUIRE_FALSE(c->isOccupied());

    pp = c->getPiece();
    REQUIRE(pp == nullptr);

    c->setPiece(p2);
    REQUIRE(c->isOccupied());

    pp = c->getPiece();
    REQUIRE(pp == p2);

    c->removePiece();
    REQUIRE_FALSE(c->isOccupied());
}

//TODO TEST DEPLACEMENT SUR AUTRE CASE
//TODO TESTS FUITE MEMOIRE
