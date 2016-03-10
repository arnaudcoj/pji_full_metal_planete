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
    virtual bool canBeCarried(Container::Type containerType) const;
};

#endif // WEATHERLAYERPIECE_H