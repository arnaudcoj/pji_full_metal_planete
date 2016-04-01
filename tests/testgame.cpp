#include <catch.hpp>
#include <memory>
#include <list>
#include <game.h>
#include <hexagrid.h>
#include <gamestate.h>
#include <SFML/System/Vector2.hpp>
#include <iostream>

TEST_CASE("test Hexagrid constructor & getHexagrid",
    "tests if the hexagrid returned is the one given at the construction")
{
    Hexagrid h(13, 37);
    Game g(h);

    REQUIRE(g.getHexagrid().getWidth() == h.getWidth());
    REQUIRE(g.getHexagrid().getHeight() == h.getHeight());
}

TEST_CASE("test yaml file constructor & getHexagrid",
    "tests if the hexagrid returned is the one given in the yaml file")
{

    Game g("../../assets/maps/test.yaml");

    REQUIRE(g.getHexagrid().getCell(0, 0)->getArea() == 0);
    REQUIRE(g.getHexagrid().getCell(1, 3)->getArea() == 13);
    REQUIRE(g.getHexagrid().getCell(2, 2)->getArea() == 22);
}

TEST_CASE("test constructor and players", "tests if the constructor creates the correct amount of players")
{
    Game g(3);

    REQUIRE(g.getPlayers().size() == 3);
}

TEST_CASE("test getGameState", "tests if getGameState returns a correct gameState")
{
    Game g;
    GameState gs = g.getGameState();

    REQUIRE(gs.getTurn() == 0);
    REQUIRE(gs.getTides().size() == 9);
}

TEST_CASE("test placeMinerals", "tests if the minerals are properly placed on the grid after game started")
{
    YAML::Node primes = YAML::Load("{name : terrain1, cells : ["
                                   "[[0,0], [0,10], [0,20], [0,30], [0,40], [0,50], [3,60]],"
                                   "[[0,1], [0,11], [0,21], [0,31], [0,41], [0,51], [0,61]],"
                                   "[[0,2], [0,12], [0,22], [1,32], [0,42], [0,52], [0,62]],"
                                   "[[0,3], [0,13], [0,23], [0,33], [0,43], [0,53], [2,63]],"
                                   "[[0,4], [0,14], [0,24], [0,34], [0,44], [0,54], [0,64]],"
                                   "[[0,5], [0,15], [0,25], [4,35], [0,45], [0,55], [0,65]],"
                                   "[[0,6], [0,16], [0,26], [0,36], [0,46], [0,56], [0,66]]"
                                   "]}");

    Game g(Hexagrid(primes), 2);

    //100 = nb mineral, 17 = nb pieces for each player, 2 = player
    REQUIRE(g.getPieceStock().getAllPieces().size() == 100 + 17 * 2);

    g.startGame(sf::Vector2i(0, 0));

    //100 - 7 = nb mineral, 6 * 2 = nbPiece in stock after distribution
    REQUIRE(g.getPieceStock().getAllPieces().size() == 100 - 7 + 6 * 2);

    for(int j = 0; j < g.getHexagrid().getHeight(); j++) {
        for(int i = 0; i < g.getHexagrid().getWidth(); i++) {
            // those are the cells in which minerals should be placed
            if(i == 0 && j == 0 || i == 0 && j == 3 || i == 0 && j == 6 || i == 3 && j == 2  || i == 3 && j == 5 || i == 6 && j == 0 ||
                i == 6 && j == 6)
                REQUIRE(g.getHexagrid().getCell(i, j)->isOccupied());
            else
                REQUIRE_FALSE(g.getHexagrid().getCell(i, j)->isOccupied());
        }
    }
}

TEST_CASE("test populatePieceStock", "tests if the pieceStock is filled at Game construction")
{
    Game g2(2);
    REQUIRE(g2.getPieceStock().getAllPieces().size() == 100 + 17 * 2);

    Game g3(3);
    REQUIRE(g3.getPieceStock().getAllPieces().size() == 100 + 17 * 3);

    Game g4(4);
    REQUIRE(g4.getPieceStock().getAllPieces().size() == 100 + 17 * 4);
}

TEST_CASE("test startGame and distributeArmy",
    "tests if the turn is 1 and if pieces are distributed when starting the game")
{
    Game g2(2);
    g2.passTurn();
    g2.passTurn();
    REQUIRE_FALSE(g2.isStarted());
    REQUIRE(g2.getGameState().getTurn() == 0);
    REQUIRE(g2.getCurrentPlayer().getNumber() == 1);
    int expectedStock = 100 + 17 * 2;
    REQUIRE(g2.getPieceStock().getAllPieces().size() == expectedStock);
    REQUIRE(g2.getCurrentPlayer().getPieceStock().getAllPieces().size() == 0);

    g2.startGame(sf::Vector2i(0, 0));
    
    //we substract the number of minerals used...
    expectedStock -= 14; 
    
    //and the number of distributed pieces
    expectedStock -= 11 * 2;
    
    REQUIRE(g2.isStarted());
    REQUIRE(g2.getGameState().getTurn() == 1);
    REQUIRE(g2.getPieceStock().getAllPieces().size() == expectedStock);
    REQUIRE(g2.getCurrentPlayer().getPieceStock().getAllPieces().size() == 11);
    g2.passTurn();
    REQUIRE(g2.getCurrentPlayer().getPieceStock().getAllPieces().size() == 11);
}

TEST_CASE("test passTurn",
    "tests if all players are iterated over. And if we get the next turn and we start over when "
    "we reach the end of the list")
{
    Game game(3);

    game.startGame();
    REQUIRE(game.getGameState().getTurn() == 1);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);

    game.passTurn();

    REQUIRE(game.getGameState().getTurn() == 1);
    REQUIRE(game.getCurrentPlayer().getNumber() == 2);

    game.passTurn();

    REQUIRE(game.getGameState().getTurn() == 1);
    REQUIRE(game.getCurrentPlayer().getNumber() == 3);

    game.passTurn();

    REQUIRE(game.getGameState().getTurn() == 2);
    REQUIRE(game.getCurrentPlayer().getNumber() == 1);

    game.passTurn();

    REQUIRE(game.getGameState().getTurn() == 2);
    REQUIRE(game.getCurrentPlayer().getNumber() == 2);
}

TEST_CASE("test passTurn when just 1 player",
    "tests if the turn changes and if the player stays the same each time we call passTurn")
{
    Game game(1);

    game.startGame();

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