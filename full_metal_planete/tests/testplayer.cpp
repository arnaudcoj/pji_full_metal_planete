#include <cell.h>
#include <piece.h>
#include <player.h>
#include <catch.hpp>

TEST_CASE("tests player.move and cell.isOccupied", "tests if we can move a Piece, if the cell is occupied when the Piece is placed and checks that we can't add more piece to the cell") {
    Cell cell(1,2);
    Piece piece;
    Player player;

    REQUIRE_FALSE(cell.isOccupied());

    REQUIRE(player.move(piece, cell));
    REQUIRE(cell.isOccupied()); //correct
    REQUIRE(piece.getCell().isOccupied()); //segfault
    REQUIRE(piece.isOnCell()); // piece pas sur une cell
    REQUIRE(cell.getPiece().isOnCell()); // piece pas sur une cell

    REQUIRE_FALSE(player.move(piece, cell));

    piece.removeCell();
    REQUIRE_FALSE(piece.isOnCell());
    REQUIRE_FALSE(cell.isOccupied());
}


TEST_CASE("tests cell.move and cell.removePiece","tests if we can move a Piece and remove it") {
    Cell cell = Cell(Cell(1,2));
    Piece piece = Piece(Piece());
    Player player;

    player.move(piece, cell);
    cell.removePiece();

    REQUIRE_FALSE(cell.isOccupied());

    REQUIRE(player.move(piece, cell));
    REQUIRE(cell.isOccupied());
}
