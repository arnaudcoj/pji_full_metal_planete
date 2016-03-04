#include "seacell.h"

SeaCell::SeaCell() : Cell() { }

SeaCell::SeaCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) {
    m_texture.loadFromFile("../../media/textures/sea.png");
    initSprite();
}

SeaCell::SeaCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) {
    m_texture.loadFromFile("../../media/textures/sea.png");
    initSprite();
}

bool SeaCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->getEngine().isMarine();
}
