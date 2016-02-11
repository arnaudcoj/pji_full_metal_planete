#include <cell.h>
#include <piece.h>
#include <player.h>
#include <catch.hpp>

TEST_CASE("tests player.move and cell.isOccupied", "tests if we can move a Piece, if the cell is occupied when the Piece is placed and checks that we can't add more piece to the cell") {
    std::shared_ptr<Cell> cell = std::make_shared<Cell>(1,2);
    std::shared_ptr<Piece> piece = std::make_shared<Piece>();
    Player player;

    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell));
    REQUIRE(cell->isOccupied()); //correct
    REQUIRE(piece->getCell()->isOccupied()); //segfault
    REQUIRE(piece->isOnCell()); // piece pas sur une cell
    REQUIRE(cell->getPiece()->isOnCell()); // piece pas sur une cell

    REQUIRE_FALSE(player.move(piece, cell));

    player.removePiece(piece);
    REQUIRE_FALSE(piece->isOnCell());
    REQUIRE_FALSE(cell->isOccupied());
}

TEST_CASE("tests cell.move and cell.removePiece","tests if we can move a Piece and remove it") {
    std::shared_ptr<Cell> cell = std::make_shared<Cell>(1,2);
    std::shared_ptr<Piece> piece = std::make_shared<Piece>();
    Player player;

    player.move(piece, cell);
    player.removePiece(piece);

    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell));
    REQUIRE(cell->isOccupied());
}
