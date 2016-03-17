#include <catch.hpp>
#include <container.h>
#include <memory>
#include <piece.h>
#include <tankpiece.h>
#include <pontoonpiece.h>
#include <bargepiece.h>
#include <crabpiece.h>
#include <bigtankpiece.h>
#include <patrolboatpiece.h>
#include <weatherlayerpiece.h>
#include <MineralPiece.h>

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

TEST_CASE("takePiece", "tests if we can take a piece or not depending on the situation") {
    Container cl_c(Container::Type::CLASSIC_CONTAINER);
    
    std::shared_ptr<Piece> p1 = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> p2 = std::make_shared<PontoonPiece>();
    std::shared_ptr<Piece> p3 = std::make_shared<PontoonPiece>();
    
    REQUIRE(cl_c.takePiece(p1));
    
    REQUIRE_FALSE(cl_c.takePiece(p1));
       
    REQUIRE(cl_c.takePiece(p2));
  
    REQUIRE_FALSE(cl_c.takePiece(p3));
}

TEST_CASE("removePiece", "tests if we can remove a piece or not depending on the situation") {
    Container cl_c(Container::Type::CLASSIC_CONTAINER);
    
    std::shared_ptr<Piece> p1 = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> p2 = std::make_shared<PontoonPiece>();
    std::shared_ptr<Piece> p3 = std::make_shared<PontoonPiece>();
    
    REQUIRE_FALSE(cl_c.removePiece(p1));
    REQUIRE(cl_c.takePiece(p1));
    REQUIRE(cl_c.removePiece(p1));
    REQUIRE_FALSE(cl_c.removePiece(p1));
}

//INCORRECT car retourne toujours 2 car contient les nullptr
TEST_CASE("getCarriedPieces", "tests if getCarriedPieces returns the pieces stored in the container") {
    Container cl_c(Container::Type::CLASSIC_CONTAINER);
    
    std::shared_ptr<Piece> p1 = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> p2 = std::make_shared<PontoonPiece>();
    std::shared_ptr<Piece> p3 = std::make_shared<PontoonPiece>();
    
    REQUIRE(cl_c.getNbCarriedPieces() == 0);
    
    cl_c.takePiece(p1);
    
    REQUIRE(cl_c.getNbCarriedPieces() == 1);
       
    cl_c.takePiece(p2);
  
    REQUIRE(cl_c.getNbCarriedPieces() == 2);
    
    cl_c.removePiece(p2);
    
    REQUIRE(cl_c.getNbCarriedPieces() == 1);
    
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

TEST_CASE("test getWeight recursive", "tests if the weight returned is correct according to the weight of a piece and its own shipments") {

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

TEST_CASE("test canCarry", "tests if pieces can contain other pieces or not") {
    
    std::shared_ptr<Piece> tank = std::make_shared<TankPiece>();
    std::shared_ptr<Piece> bigtank = std::make_shared<BigTankPiece>();
    std::shared_ptr<Piece> crab = std::make_shared<CrabPiece>();
    std::shared_ptr<Piece> weather = std::make_shared<WeatherLayerPiece>();
    std::shared_ptr<Piece> patrol = std::make_shared<PatrolBoatPiece>();
    std::shared_ptr<Piece> barge = std::make_shared<BargePiece>();
    std::shared_ptr<Piece> pontoon = std::make_shared<PontoonPiece>();
    std::shared_ptr<Piece> mineral = std::make_shared<MineralPiece>();
    
    SECTION("Tank canCarry")    
    REQUIRE_FALSE(tank->getContainer().canCarry(tank));
    REQUIRE_FALSE(tank->getContainer().canCarry(bigtank));
    REQUIRE_FALSE(tank->getContainer().canCarry(crab));
    REQUIRE_FALSE(tank->getContainer().canCarry(weather));
    REQUIRE_FALSE(tank->getContainer().canCarry(patrol));
    REQUIRE_FALSE(tank->getContainer().canCarry(barge));
    REQUIRE_FALSE(tank->getContainer().canCarry(pontoon));
    REQUIRE_FALSE(tank->getContainer().canCarry(mineral));
    
    SECTION("Big Tank canCarry")
    REQUIRE_FALSE(bigtank->getContainer().canCarry(tank));
    REQUIRE_FALSE(bigtank->getContainer().canCarry(bigtank));
    REQUIRE_FALSE(bigtank->getContainer().canCarry(crab));
    REQUIRE_FALSE(bigtank->getContainer().canCarry(weather));
    REQUIRE_FALSE(bigtank->getContainer().canCarry(patrol));
    REQUIRE_FALSE(bigtank->getContainer().canCarry(barge));
    REQUIRE_FALSE(bigtank->getContainer().canCarry(pontoon));
    REQUIRE_FALSE(bigtank->getContainer().canCarry(mineral));

    SECTION("Crab canCarry")
    REQUIRE(crab->getContainer().canCarry(tank));
    REQUIRE(crab->getContainer().canCarry(bigtank));
    REQUIRE_FALSE(crab->getContainer().canCarry(crab));
    REQUIRE_FALSE(crab->getContainer().canCarry(weather));
    REQUIRE_FALSE(crab->getContainer().canCarry(patrol));
    REQUIRE_FALSE(crab->getContainer().canCarry(barge));
    REQUIRE(crab->getContainer().canCarry(pontoon));
    REQUIRE(crab->getContainer().canCarry(mineral));
    
    SECTION("Weather Layer canCarry")
    REQUIRE_FALSE(weather->getContainer().canCarry(tank));
    REQUIRE_FALSE(weather->getContainer().canCarry(bigtank));
    REQUIRE_FALSE(weather->getContainer().canCarry(crab));
    REQUIRE_FALSE(weather->getContainer().canCarry(weather));
    REQUIRE_FALSE(weather->getContainer().canCarry(patrol));
    REQUIRE_FALSE(weather->getContainer().canCarry(barge));
    REQUIRE_FALSE(weather->getContainer().canCarry(pontoon));
    REQUIRE(weather->getContainer().canCarry(mineral));
    
    SECTION("Patrol Boat canCarry")
    REQUIRE_FALSE(patrol->getContainer().canCarry(tank));
    REQUIRE_FALSE(patrol->getContainer().canCarry(bigtank));
    REQUIRE_FALSE(patrol->getContainer().canCarry(crab));
    REQUIRE_FALSE(patrol->getContainer().canCarry(weather));
    REQUIRE_FALSE(patrol->getContainer().canCarry(patrol));
    REQUIRE_FALSE(patrol->getContainer().canCarry(barge));
    REQUIRE_FALSE(patrol->getContainer().canCarry(pontoon));
    REQUIRE_FALSE(patrol->getContainer().canCarry(mineral));
    
    SECTION("Barge canCarry")
    REQUIRE(barge->getContainer().canCarry(tank));
    REQUIRE(barge->getContainer().canCarry(bigtank));
    REQUIRE(barge->getContainer().canCarry(crab));
    REQUIRE(barge->getContainer().canCarry(weather));
    REQUIRE_FALSE(barge->getContainer().canCarry(patrol));
    REQUIRE_FALSE(barge->getContainer().canCarry(barge));
    REQUIRE(barge->getContainer().canCarry(pontoon));
    REQUIRE(barge->getContainer().canCarry(mineral));
    
    SECTION("Pontoon canCarry")
    REQUIRE_FALSE(pontoon->getContainer().canCarry(tank));
    REQUIRE_FALSE(pontoon->getContainer().canCarry(bigtank));
    REQUIRE_FALSE(pontoon->getContainer().canCarry(crab));
    REQUIRE_FALSE(pontoon->getContainer().canCarry(weather));
    REQUIRE_FALSE(pontoon->getContainer().canCarry(patrol));
    REQUIRE_FALSE(pontoon->getContainer().canCarry(barge));
    REQUIRE_FALSE(pontoon->getContainer().canCarry(pontoon));
    REQUIRE_FALSE(pontoon->getContainer().canCarry(mineral));
    
    SECTION("Mineral canCarry")
    REQUIRE_FALSE(mineral->getContainer().canCarry(tank));
    REQUIRE_FALSE(mineral->getContainer().canCarry(bigtank));
    REQUIRE_FALSE(mineral->getContainer().canCarry(crab));
    REQUIRE_FALSE(mineral->getContainer().canCarry(weather));
    REQUIRE_FALSE(mineral->getContainer().canCarry(patrol));
    REQUIRE_FALSE(mineral->getContainer().canCarry(barge));
    REQUIRE_FALSE(mineral->getContainer().canCarry(pontoon));
    REQUIRE_FALSE(mineral->getContainer().canCarry(mineral));
}
