#include <memory>
#include <list>
#include <game.h>
#include <catch.hpp>

TEST_CASE( "tes", "tests " ) {
    for(std::shared_ptr<Tide> i : Game::getTideList())
        std::cout << i->toString() << std::endl;


}
