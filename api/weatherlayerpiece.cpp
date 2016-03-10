#include "weatherlayerpiece.h"

WeatherLayerPiece::WeatherLayerPiece() : Piece(Engine::Type::TERRESTRIAL_ENGINE, Weapon::Type::NO_WEAPON, Container::Type::MINERAL_CONTAINER, 2)
{
}

bool WeatherLayerPiece::canBeCarried(Container::Type containerType) const
{
    switch(containerType) {
        case Container::Type::BIG_CONTAINER:
            return true;
        default:
            return false;
    }
}
