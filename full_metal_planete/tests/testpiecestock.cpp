#include <catch.hpp>
#include <piecestock.h>

TEST_CASE("test pieceStock Construction and size", "tests if the stock contains the given amount of Pieces after construction") {
    PieceStock stock1(5);
    PieceStock stock2;

    REQUIRE(stock1.size() == 5);
    REQUIRE(stock2.size() == 0);
}

TEST_CASE("test addPiece ", "tests if the stock is correctly updated when adding a piece") {
    PieceStock stock;
    Piece piece;
    Piece piece2;

    stock.addPiece(piece);
    REQUIRE(stock.size() == 1);
    stock.addPiece(piece2);
    REQUIRE(stock.size() == 2);
}

TEST_CASE("test takePiece", "tests if the stock is correctly updated when taking a piece") {
    PieceStock stock(2);

    stock.takePiece();
    REQUIRE(stock.size() == 1);

    stock.takePiece();
    REQUIRE(stock.size() == 0);

    REQUIRE_THROWS_AS(stock.takePiece(), std::logic_error);
    REQUIRE(stock.size() == 0);
}
