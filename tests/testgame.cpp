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

TEST_CASE("test constructor and players", "tests if the constructor creates the correct amount of players") {
    Game g(3);
    
    REQUIRE(g.getPlayers().size() == 3);
}

TEST_CASE("test getGameState", "tests if getGameState returns a correct gameState") {
    Game g;
    GameState gs = g.getGameState();

    REQUIRE(gs.getTurn() == 0);
    REQUIRE(gs.getTides().size() == 9);
}


TEST_CASE("test passTurn", "tests if all players are iterated over. And if we get the next turn and we start over when we reach the end of the list") {
    Game game(3);

    REQUIRE(game.getGameState().getTurn() == 0);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 0);
    REQUIRE(game.getCurrentPlayer().getNumber() == 2);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 0);
    REQUIRE(game.getCurrentPlayer().getNumber() == 3);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 1);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 1);
    REQUIRE(game.getCurrentPlayer().getNumber() == 2);
    
}

TEST_CASE("test passTurn when just 1 player", "tests if the turn changes and if the player stays the same each time we call passTurn") {
    Game game(1);
    
    REQUIRE(game.getGameState().getTurn() == 0);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 1);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 2);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 3);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);
    
    game.passTurn();
    
    REQUIRE(game.getGameState().getTurn() == 4);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);
    
}