#include <catch.hpp>
#include <container.h>
#include <memory>
#include <piece.h>
#include <tankpiece.h>
#include <pontoonpiece.h>
#include <bargepiece.h>
#include <crabpiece.h>
#include <iostream>

TEST_CASE("test max capacity", "checks if the maximal capacity is correct") {
    Container no_c(Container::Type::NO_CONTAINER);
    Container min_c(Container::Type::MINERAL_CONTAINER);
    Container cl_c(Container::Type::CLASSIC_CONTAINER);
    Container big_c(Container::Type::BIG_CONTAINER);
    
    REQUIRE(no_c.getMaxCapacity() == 0);
    REQUIRE(min_c.getMaxCapacity() == 1);
    REQUIRE(cl_c.getMaxCapacity() == 2);
    REQUIRE(big_c.getMaxCapacity() == 4);
    
}

TEST_CASE("test getWeight", "tests if the weight returned is correct according to the shipment of the container") {
    Container cl_c(Container::Type::CLASSIC_CONTAINER);
    
    std::shared_ptr<Piece> p1 = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> p2 = std::make_shared<PontoonPiece>();
    
    REQUIRE(cl_c.getWeight() == 0);
    
    cl_c.takePiece(p1);
    REQUIRE(cl_c.getWeight() == 1);
       
    cl_c.takePiece(p2);
    REQUIRE(cl_c.getWeight() == 2);
}

TEST_CASE("test getWeight recursive", "tests if the weight returned is correct according to the weight of the pieces and their own shipments") {

    std::shared_ptr<Piece> barge = std::make_shared<BargePiece>();
    std::shared_ptr<Piece> crab = std::make_shared<CrabPiece>();
    std::shared_ptr<Piece> p1 = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> p2 = std::make_shared<PontoonPiece>();
    
    REQUIRE(crab->getWeight() == 2);
    crab->getContainer().takePiece(p1);
    REQUIRE(crab->getWeight() == 3);
    
    REQUIRE(barge->getWeight() == 2);
    barge->getContainer().takePiece(p2);
    REQUIRE(barge->getWeight() == 3);
    barge->getContainer().takePiece(crab);
    REQUIRE(barge->getWeight() == 6);
}
/*
    std::vector< std::shared_ptr<Piece> > getCarriedPieces() const;
    bool canCarry(std::shared_ptr<Piece> piece) const;
    bool takePiece(std::shared_ptr<Piece> piece);
    bool removePiece(std::shared_ptr<Piece> piece);
    Type getType() const;
    
    */