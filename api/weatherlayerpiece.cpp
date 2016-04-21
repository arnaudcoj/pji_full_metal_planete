#include "weatherlayerpiece.h"

WeatherLayerPiece::WeatherLayerPiece() : Piece(Engine::Type::TERRESTRIAL_ENGINE, Weapon::Type::NO_WEAPON, Container::Type::MINERAL_CONTAINER, 2)
{
}

bool WeatherLayerPiece::canBeCarried(Container container) const
{
    Container::Type containerType = container.getType();
    switch(containerType) {
        case Container::Type::BIG_CONTAINER:
            return true;
        default:
            return false;
    }
}

std::string WeatherLayerPiece::getType() {
    return "weather_layer";
}
