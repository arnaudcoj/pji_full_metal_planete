#include <cell.h>
#include <plaincell.h>
#include <piece.h>
#include <player.h>
#include <catch.hpp>
#include <tide.h>

TEST_CASE("tests player.move and cell.isOccupied", "tests if we can move a Piece, if the cell is occupied when the Piece is placed and checks that we can't add more piece to the cell") {
    std::shared_ptr<Cell> cell = std::make_shared<PlainCell>(1,2);
    std::shared_ptr<Piece> piece = std::make_shared<Piece>();
    Player player;    

    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell, Tide::MEDIUM_TIDE));
    REQUIRE(cell->isOccupied()); //correct
    REQUIRE(piece->getCell()->isOccupied()); //segfault
    REQUIRE(piece->isOnCell()); // piece pas sur une cell
    REQUIRE(cell->getPiece()->isOnCell()); // piece pas sur une cell

    REQUIRE_FALSE(player.move(piece, cell, Tide::MEDIUM_TIDE));

    player.removePiece(piece);
    REQUIRE_FALSE(piece->isOnCell());
    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell, Tide::MEDIUM_TIDE));

    player.useActionPoints(99);

    REQUIRE_FALSE(player.move(piece, cell, Tide::MEDIUM_TIDE));
}

TEST_CASE("tests cell.move and cell.removePiece","tests if we can move a Piece and remove it") {
    std::shared_ptr<Cell> cell = std::make_shared<PlainCell>(1,2);
    std::shared_ptr<Piece> piece = std::make_shared<Piece>();
    Player player;

    player.move(piece, cell, Tide::MEDIUM_TIDE);
    player.removePiece(piece);

    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell, Tide::MEDIUM_TIDE));
    REQUIRE(cell->isOccupied());
}

TEST_CASE("tests player.useActionPoints","test if a player uses action points when he tries to move") {
    PlainCell cell(1,2);
    Piece piece;
    Player player;

    REQUIRE(player.useActionPoints());
    REQUIRE(player.getActionPoints() == 99);
    REQUIRE(player.useActionPoints(99));
    REQUIRE(player.getActionPoints() == 0);
    REQUIRE_FALSE(player.useActionPoints(1));
    REQUIRE(player.getActionPoints() == 0);
}
