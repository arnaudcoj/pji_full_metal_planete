#include <memory>
#include <cell.h>
#include <plaincell.h>
#include <piece.h>
#include <tankpiece.h>
#include <player.h>
#include <catch.hpp>
#include <tide.h>

TEST_CASE("tests player.move and cell.isOccupied", "tests if we can move a Piece, if the cell is occupied when the Piece is placed and checks that we can't add more piece to the cell") {
    std::shared_ptr<Cell> cell = std::make_shared<PlainCell>(1,2);
    std::shared_ptr<Piece> piece = std::make_shared<TankPiece>();
    Player player(1);    

    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell));
    REQUIRE(cell->isOccupied());
    REQUIRE(piece->getCell()->isOccupied()); 
    REQUIRE(piece->isOnCell()); 
    REQUIRE(cell->getPiece()->isOnCell()); 

    REQUIRE_FALSE(player.move(piece, cell));

    player.removePiece(piece);
    REQUIRE_FALSE(piece->isOnCell());
    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell));

    player.useActionPoints(15);

    REQUIRE_FALSE(player.move(piece, cell));
}

TEST_CASE("tests cell.move and cell.removePiece","tests if we can move a Piece and remove it") {
    std::shared_ptr<Cell> cell = std::make_shared<PlainCell>(1,2);
    std::shared_ptr<Piece> piece = std::make_shared<TankPiece>();
    Player player(1);

    player.move(piece, cell);
    player.removePiece(piece);

    REQUIRE_FALSE(cell->isOccupied());

    REQUIRE(player.move(piece, cell));
    REQUIRE(cell->isOccupied());
}

TEST_CASE("tests player.useActionPoints","test if a player uses action points when he tries to move") {
    Player player(1);

    REQUIRE(player.useActionPoints());
    REQUIRE(player.getActionPoints() == 14);
    REQUIRE(player.useActionPoints(14));
    REQUIRE(player.getActionPoints() == 0);
    REQUIRE_FALSE(player.useActionPoints(1));
    REQUIRE(player.getActionPoints() == 0);
}