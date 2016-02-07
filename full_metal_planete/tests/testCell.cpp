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

TEST_CASE("tests cell.placePiece and cell.isOccupied", "tests if we can place a Piece and if the cell is occupied when the Piece is placed") {
    std::shared_ptr<Cell> cell = std::make_shared<Cell>(Cell(1,2));
    std::shared_ptr<Piece> piece = std::make_shared<Piece>(Piece());

    REQUIRE_FALSE(cell->isOccupied());
    REQUIRE_FALSE(cell->placePiece(nullptr, nullptr));

    REQUIRE(cell->placePiece(cell, piece));
    REQUIRE(cell->isOccupied());

    REQUIRE_FALSE(cell->placePiece(cell, piece));
}

TEST_CASE("tests cell.placePiece and cell.getPiece", "tests if we can place a Piece and if we can get a pointer to it") {
    std::shared_ptr<Cell> cell = std::make_shared<Cell>(Cell(1,2));
    std::shared_ptr<Piece> piece = std::make_shared<Piece>(Piece());
    std::shared_ptr<Piece> p2;

    cell->placePiece(cell, piece);

    p2 = cell->getPiece();

    REQUIRE(p2 == piece);
}

TEST_CASE("tests cell.placePiece and cell.removePiece","tests if we can place a Piece and remove it") {
    std::shared_ptr<Cell> cell = std::make_shared<Cell>(Cell(1,2));
    std::shared_ptr<Piece> piece = std::make_shared<Piece>(Piece());

    cell->placePiece(cell, piece);
    cell->removePiece();

    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(cell->placePiece(cell, piece));
    REQUIRE(cell->isOccupied());
}

TEST_CASE("test getArea", "tests if the area returned is the one given at construction ") {
    Cell c1(1,2, false, 2);
    Cell c2(3, 2, false, 32);

    REQUIRE(c1.getArea() == 2);
    REQUIRE(c2.getArea() == 32);

}

//TODO TEST DEPLACEMENT SUR AUTRE CASE
//TODO TESTS FUITE MEMOIRE
