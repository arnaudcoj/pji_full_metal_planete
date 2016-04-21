#ifndef WEATHERLAYERPIECE_H
#define WEATHERLAYERPIECE_H

#include "piece.h"
#include "engine.h"
#include "weapon.h"
#include "container.h"

class WeatherLayerPiece : public Piece
{

public:
    WeatherLayerPiece();
    virtual bool canBeCarried(Container container) const;
    virtual std::string getType();
};

#endif // WEATHERLAYERPIECE_H
