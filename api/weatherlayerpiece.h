#ifndef WEATHERLAYERPIECE_H
#define WEATHERLAYERPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class WeatherLayerPiece : public Piece
{
private:
    std::string m_type = "weather_layer";

public:
    WeatherLayerPiece();
    virtual bool canBeCarried(Container::Type containerType) const;
    virtual std::string getType();
};

#endif // WEATHERLAYERPIECE_H
