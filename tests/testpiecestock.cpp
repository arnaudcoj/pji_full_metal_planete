#include <catch.hpp>
#include <memory>
#include <piecestock.h>
#include <tankpiece.h>
#include <piece.h>

TEST_CASE("test pieceStock Construction and size", "tests if the stock contains the given amount of Pieces after construction") {
    PieceStock stock1;
    for(int i = 0; i < 5; i++)
        stock1.addPiece(std::make_shared<TankPiece>());
    PieceStock stock2;

    REQUIRE(stock1.getAllPieces().size() == 5);
    REQUIRE(stock2.getAllPieces().size() == 0);
    REQUIRE(stock1.takeTankPiece() != nullptr);
}

TEST_CASE("test addPiece ", "tests if the stock is correctly updated when adding a piece") {
    PieceStock stock;
    std::shared_ptr<Piece> piece = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> piece2 = std::make_shared<TankPiece>();

    stock.addPiece(piece);
    REQUIRE(stock.getAllPieces().size() == 1);
    stock.addPiece(piece2);
    REQUIRE(stock.getAllPieces().size() == 2);
}

TEST_CASE("test takePiece", "tests if the stock is correctly updated when taking a piece") {
    PieceStock stock;
    for(int i = 0; i < 2; i++)
        stock.addPiece(std::make_shared<TankPiece>());

    stock.takeTankPiece();
    REQUIRE(stock.getAllPieces().size() == 1);

    stock.takeTankPiece();
    REQUIRE(stock.getAllPieces().size() == 0);

    REQUIRE_THROWS_AS(stock.takeTankPiece(), std::logic_error);
    REQUIRE(stock.getAllPieces().size() == 0);
}
