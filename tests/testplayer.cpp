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

TEST_CASE("getAccessibleCells",
    "checks if cells are accessibles or not according for the piece, with an amount of 2 action points")
{
    YAML::Node primes = YAML::Load("{name : terrain1, cells : ["
                                   "[[0,0], [0,10], [0,20], [0,30]],"
                                   "[[0,1], [0,11], [0,21], [0,31]],"
                                   "[[0,2], [2,12], [0,22], [0,32]],"
                                   "[[0,3], [0,13], [0,23], [0,33]]]}");

    Hexagrid grid(primes);

    Player player(1);
    player.useActionPoints(13); // we want the player to have 2 action points

    std::shared_ptr<Piece> piece = std::make_shared<TankPiece>();
    player.move(piece, grid.getCell(1, 1));

    std::unordered_set<std::shared_ptr<Cell> > accessibleCells = player.getAccessibleCells(grid, piece);

    // il doit y avoir 20 21 et 22
    REQUIRE(accessibleCells.size() == 3);
    REQUIRE(accessibleCells.count(grid.getCell(2, 0)));
    REQUIRE(accessibleCells.count(grid.getCell(2, 1)));
    REQUIRE(accessibleCells.count(grid.getCell(2, 2)));

    REQUIRE_FALSE(accessibleCells.count(grid.getCell(1, 1)));
    REQUIRE_FALSE(accessibleCells.count(grid.getCell(1, 2)));
    REQUIRE_FALSE(accessibleCells.count(grid.getCell(1, 3)));
}

TEST_CASE("getAccessibleCells with piece stuck",
    "checks if getAccessibleCells returns an empty list when the piece is stuck")
{
    YAML::Node primes = YAML::Load("{name : terrain1, cells : ["
                                   "[[0,0], [0,10], [0,20], [0,30]],"
                                   "[[0,1], [0,11], [0,21], [0,31]],"
                                   "[[0,2], [3,12], [0,22], [0,32]],"
                                   "[[0,3], [0,13], [0,23], [0,33]]]}");

    Hexagrid grid(primes);

    Player player(1);

    std::shared_ptr<Piece> piece = std::make_shared<TankPiece>();
    player.move(piece, grid.getCell(1, 2));

    //the piece can move
    std::unordered_set<std::shared_ptr<Cell> > accessibleCells = player.getAccessibleCells(grid, piece);
    REQUIRE_FALSE(accessibleCells.empty());

    grid.update(Tide::HIGH_TIDE);
    //now the piece is stuck
    accessibleCells = player.getAccessibleCells(grid, piece);
    REQUIRE(accessibleCells.empty());
}