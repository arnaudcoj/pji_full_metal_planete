#include <catch.hpp>
#include <memory>
#include <list>
#include <game.h>
#include <hexagrid.h>
#include <gamestate.h>

TEST_CASE("test Hexagrid constructor & getHexagrid", "tests if the hexagrid returned is the one given at the construction") {
    Hexagrid h(13, 37);
    Game g(h);

    REQUIRE(g.getHexagrid().getWidth() == h.getWidth());
    REQUIRE(g.getHexagrid().getHeight() == h.getHeight());
}

TEST_CASE("test yaml file constructor & getHexagrid", "tests if the hexagrid returned is the one given in the yaml file") {

    Game g("../../assets/maps/test.yaml");

    REQUIRE(g.getHexagrid().getCell(0, 0)->getArea() == 0);
    REQUIRE(g.getHexagrid().getCell(1, 3)->getArea() == 13);
    REQUIRE(g.getHexagrid().getCell(2, 2)->getArea() == 22);
}

TEST_CASE("test getGameState", "tests if getGameState returns a correct gameState") {
    Game g;
    GameState gs = g.getGameState();

    REQUIRE(gs.getNbTurns() == gs.getMaxTurns());
    REQUIRE(gs.getTides().size() == 9);

}
