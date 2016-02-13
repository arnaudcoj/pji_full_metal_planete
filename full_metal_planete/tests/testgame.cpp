#include <catch.hpp>
#include <memory>
#include <list>
#include <game.h>
#include <hexagrid.h>

TEST_CASE("test Hexagrid constructor & getHexagrid", "tests if the hexagrid returned is the one given at the construction") {
    Hexagrid h(13, 37);
    Game g(h);

    REQUIRE(g.getHexagrid().getWidth() == h.getWidth());
    REQUIRE(g.getHexagrid().getHeight() == h.getHeight());
}

TEST_CASE("test yaml file constructor & getHexagrid", "tests if the hexagrid returned is the one given in the yaml file") {

    Game g("../../media/grids/test.yaml");

    REQUIRE(g.getHexagrid().getCell(0, 0)->getArea() == 0);
    REQUIRE(g.getHexagrid().getCell(1, 3)->getArea() == 13);
    REQUIRE(g.getHexagrid().getCell(2, 2)->getArea() == 22);
}

TEST_CASE("test getNbTurns and getMaxTurns", "tests if the nbTurns is the same as maxTurns when the game is created") {
    Game g;
    REQUIRE(g.getNbTurns() == g.getMaxTurns());
}

TEST_CASE("test nextTurn", "tests if the nbTurns is updated when we call nextTurn") {
    Game g;
    REQUIRE(g.getNbTurns() == g.getMaxTurns());
    g.nextTurn();
    REQUIRE(g.getNbTurns() == g.getMaxTurns() - 1);
    g.nextTurn();
    REQUIRE(g.getNbTurns() == g.getMaxTurns() - 2);
}

TEST_CASE("test getTideList()", "tests if we can retrieve globally the tideList and if there are enough tide for the game") {
    Game g;
    REQUIRE(g.getTideList() == Game::getTideList());
    REQUIRE(Game::getTideList().size() == g.getNbTurns() / 5);
}
