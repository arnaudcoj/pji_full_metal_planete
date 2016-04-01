#include <catch.hpp>
#include <memory>
#include <gamestate.h>

TEST_CASE("test getTurn and getMaxTurns", "tests if the nbTurns is the same as maxTurns when the game is created") {
    GameState gs;

    REQUIRE(gs.getTurn() == 0);
}

TEST_CASE("test nextTurn", "tests if the nbTurns is updated when we call nextTurn") {
    GameState gs;

    REQUIRE(gs.getTurn() == 0);
    gs.nextTurn();
    REQUIRE(gs.getTurn() == 1);
    gs.nextTurn();
    REQUIRE(gs.getTurn() == 2);
}

TEST_CASE("test getTides() and nextTide", "tests the amount of cells at init and when we use nextTide") {
    GameState gs;

    REQUIRE(gs.getTides().size() == 9);
    gs.nextTide();
    REQUIRE(gs.getTides().size() == 8);

    for(int i = 8; i > 0 ; i--) {
        REQUIRE(gs.getTides().size() == i);
        gs.nextTide();
    }
    REQUIRE(gs.getTides().size() == 9);

}
