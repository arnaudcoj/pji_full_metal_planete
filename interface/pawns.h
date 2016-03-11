#ifndef PAWNS_H
#define PAWNS_H

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#include "piecestock.h"
#include "pawn.h"

class Pawns : public sf::Drawable
{
private:
    std::vector<std::shared_ptr<Pawn>> m_stock;


public:
    Pawns(PieceStock const& stock);
    void update(sf::Time const& deltaTime);
    void draw(sf::RenderTarget& target, sf::RenderStates states) const;
};

#endif // PAWNS_H
