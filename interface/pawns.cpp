#include "pawns.h"

Pawns::Pawns(PieceStock const& stock)
{
    for(int i = 0; i < stock.size(); i++) {
        m_map.insert(std::make_pair(stock.getPiece(i), std::make_shared<Pawn>(stock.getPiece(i))));
    }
}

std::shared_ptr<Pawn> Pawns::getPawn(std::shared_ptr<Piece> piece)
{
    return m_map.find(piece)->second;
}

// updates the grid
void Pawns::update(sf::Time const& deltaTime)
{
    for(auto& pair : m_map) {
        pair.second->update(deltaTime);
    }
}

// calls the draw function of each hexagon of the grid
void Pawns::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(auto& pair : m_map) {
        pair.second->draw(target, states);
    }
}
