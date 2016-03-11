#include "pawns.h"

Pawns::Pawns(PieceStock const& stock)
{
    std::cout << "Stock" << std::endl;

    for(int i = 0; i < stock.size(); i++) {
        m_stock.push_back(std::make_shared<Pawn>(stock.getPiece(i)));
    }
}

// updates the grid
void Pawns::update(sf::Time const& deltaTime)
{
    for(std::shared_ptr<Pawn> pawn : m_stock) {
        pawn->update(deltaTime);
    }
}

// calls the draw function of each hexagon of the grid
void Pawns::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    for(std::shared_ptr<Pawn> pawn : m_stock) {
        pawn->draw(target, states);
    }
}
