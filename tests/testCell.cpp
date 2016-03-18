#include <catch.hpp>
#include <memory>
#include <cell.h>
#include <plaincell.h>
#include <seacell.h>
#include <mountaincell.h>
#include <swampcell.h>
#include <reefcell.h>
#include <piece.h>
#include <tankpiece.h>
#include <bigtankpiece.h>
#include <patrolboatpiece.h>
#include <tide.h>

#include <SFML/System/Vector2.hpp>

TEST_CASE( "test cell.getCoord", "tests if the coordinates returned are the ones given to the constructor" ) {
    PlainCell cell1(sf::Vector2i(2, 3));
    PlainCell cell2(sf::Vector2i(4, 2));
    PlainCell cell3(1, 5);

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
    PlainCell cell1(1, 2, false);
    PlainCell cell2(3, 4, true);
    PlainCell cell3(5, 6);

    REQUIRE_FALSE(cell1.isHalfCell());
    REQUIRE(cell2.isHalfCell());
    REQUIRE_FALSE(cell3.isHalfCell());
}

TEST_CASE("test getArea", "tests if the area returned is the one given at construction ") {
    PlainCell c1(1,2, false, 2);
    PlainCell c2(3, 2, false, 32);

    REQUIRE(c1.getArea() == 2);
    REQUIRE(c2.getArea() == 32);

}

TEST_CASE("tests setPiece & getPiece", "tests if we can set a piece and retrieve it from the cell") {
    std::shared_ptr<Cell> c = std::make_shared<PlainCell>(1,2, false, 2);
    std::shared_ptr<Piece> p = std::make_shared<TankPiece>();

    REQUIRE_FALSE(c->isOccupied());
    c->setPiece(p);
    REQUIRE(c->isOccupied());

    std::shared_ptr<Piece> p2 = c->getPiece();
    REQUIRE(p2 == p);
}

TEST_CASE("tests setPiece & removePiece", "tests if we can set a piece and remove it from the cell") {
    std::shared_ptr<Cell> c = std::make_shared<PlainCell>(1,2, false, 2);
    std::shared_ptr<Piece> p = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> p2 = std::make_shared<TankPiece>();
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

TEST_CASE("tests PlainCell", "tests the behavior of an hill cell") {
    std::shared_ptr<Cell> c = std::make_shared<PlainCell>(1,2, false, 2);
    std::shared_ptr<Piece> h = std::make_shared<BigTankPiece>();
    std::shared_ptr<Piece> t = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> m = std::make_shared<PatrolBoatPiece>();

    SECTION("Low Tide")
    REQUIRE(c->isPracticable(h, Tide::LOW_TIDE));
    REQUIRE(c->isPracticable(t, Tide::LOW_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::LOW_TIDE));

    SECTION("Medium Tide")
    REQUIRE(c->isPracticable(h, Tide::MEDIUM_TIDE));
    REQUIRE(c->isPracticable(t, Tide::MEDIUM_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::MEDIUM_TIDE));

    SECTION("High Tide")
    REQUIRE(c->isPracticable(h, Tide::HIGH_TIDE));
    REQUIRE(c->isPracticable(t, Tide::HIGH_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::HIGH_TIDE));
}

TEST_CASE("tests SeaCell", "tests the behavior of a sea cell") {
    std::shared_ptr<Cell> c = std::make_shared<SeaCell>(1,2, false, 2);
    std::shared_ptr<Piece> h = std::make_shared<BigTankPiece>();
    std::shared_ptr<Piece> t = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> m = std::make_shared<PatrolBoatPiece>();

    SECTION("Low Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::LOW_TIDE));
    REQUIRE_FALSE(c->isPracticable(t, Tide::LOW_TIDE));
    REQUIRE(c->isPracticable(m, Tide::LOW_TIDE));

    SECTION("Medium Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::MEDIUM_TIDE));
    REQUIRE_FALSE(c->isPracticable(t, Tide::MEDIUM_TIDE));
    REQUIRE(c->isPracticable(m, Tide::MEDIUM_TIDE));

    SECTION("High Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::HIGH_TIDE));
    REQUIRE_FALSE(c->isPracticable(t, Tide::HIGH_TIDE));
    REQUIRE(c->isPracticable(m, Tide::HIGH_TIDE));
}

TEST_CASE("tests MountainCell", "tests the behavior of a mountain cell") {
    std::shared_ptr<Cell> c = std::make_shared<MountainCell>(1,2, false, 2);
    std::shared_ptr<Piece> h = std::make_shared<BigTankPiece>();
    std::shared_ptr<Piece> t = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> m = std::make_shared<PatrolBoatPiece>();

    SECTION("Low Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::LOW_TIDE));
    REQUIRE(c->isPracticable(t, Tide::LOW_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::LOW_TIDE));

    SECTION("Medium Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::MEDIUM_TIDE));
    REQUIRE(c->isPracticable(t, Tide::MEDIUM_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::MEDIUM_TIDE));

    SECTION("High Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::HIGH_TIDE));
    REQUIRE(c->isPracticable(t, Tide::HIGH_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::HIGH_TIDE));
}

TEST_CASE("tests SwampCell", "tests the behavior of a swamp cell") {
    std::shared_ptr<Cell> c = std::make_shared<SwampCell>(1,2, false, 2);
    std::shared_ptr<Piece> h = std::make_shared<BigTankPiece>();
    std::shared_ptr<Piece> t = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> m = std::make_shared<PatrolBoatPiece>();


    SECTION("Low Tide")
    REQUIRE(c->isPracticable(h, Tide::LOW_TIDE));
    REQUIRE(c->isPracticable(t, Tide::LOW_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::LOW_TIDE));

    SECTION("Medium Tide")
    REQUIRE(c->isPracticable(h, Tide::MEDIUM_TIDE));
    REQUIRE(c->isPracticable(t, Tide::MEDIUM_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::MEDIUM_TIDE));

    SECTION("High Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::HIGH_TIDE));
    REQUIRE_FALSE(c->isPracticable(t, Tide::HIGH_TIDE));
    REQUIRE(c->isPracticable(m, Tide::HIGH_TIDE));
}

TEST_CASE("tests ReefCell", "tests the behavior of a reef cell") {
    std::shared_ptr<Cell> c = std::make_shared<ReefCell>(1,2, false, 2);
    std::shared_ptr<Piece> h = std::make_shared<BigTankPiece>();
    std::shared_ptr<Piece> t = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> m = std::make_shared<PatrolBoatPiece>();

    SECTION("Low Tide")
    REQUIRE(c->isPracticable(h, Tide::LOW_TIDE));
    REQUIRE(c->isPracticable(t, Tide::LOW_TIDE));
    REQUIRE_FALSE(c->isPracticable(m, Tide::LOW_TIDE));

    SECTION("Medium Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::MEDIUM_TIDE));
    REQUIRE_FALSE(c->isPracticable(t, Tide::MEDIUM_TIDE));
    REQUIRE(c->isPracticable(m, Tide::MEDIUM_TIDE));

    SECTION("High Tide")
    REQUIRE_FALSE(c->isPracticable(h, Tide::HIGH_TIDE));
    REQUIRE_FALSE(c->isPracticable(t, Tide::HIGH_TIDE));
    REQUIRE(c->isPracticable(m, Tide::HIGH_TIDE));
}
