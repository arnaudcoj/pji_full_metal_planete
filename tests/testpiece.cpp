#include <catch.hpp>
#include <piece.h>
#include <tankpiece.h>
#include <cell.h>
#include <plaincell.h>
#include <memory>

TEST_CASE("test setCell & getCell ", "tests if we can set a cell and retrieve it from the piece") {
    std::shared_ptr<Cell> c = std::make_shared<PlainCell>(1,2, false, 2);
    std::shared_ptr<Piece> p = std::make_shared<TankPiece>();

    REQUIRE_FALSE(p->isOnCell());
    p->setCell(c);
    REQUIRE(p->isOnCell());

    std::shared_ptr<Cell> c2 = p->getCell();
    REQUIRE(c2 == c);
}

TEST_CASE("tests setCell & removeCell", "tests if we can set a cell and remove it from the piece") {
    std::shared_ptr<Cell> c = std::make_shared<PlainCell>(1,2, false, 2);
    std::shared_ptr<Cell> c2 = std::make_shared<PlainCell>(2,2, false, 2);
    std::shared_ptr<Piece> p = std::make_shared<TankPiece>();
    std::shared_ptr<Cell> cc;

    REQUIRE_FALSE(p->isOnCell());
    p->setCell(c);
    REQUIRE(p->isOnCell());

    p->removeCell();
    REQUIRE_FALSE(p->isOnCell());

    cc = p->getCell();
    REQUIRE(cc == nullptr);

    p->setCell(c2);
    REQUIRE(p->isOnCell());

    cc = p->getCell();
    REQUIRE(cc == c2);

    p->removeCell();
    REQUIRE_FALSE(p->isOnCell());
}
