#include "seacell.h"

SeaCell::SeaCell() : Cell() {
    m_texture = AssetManager::GetTexture("../../media/textures/sea.png");
    initSprite();
}

SeaCell::SeaCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) {
    m_texture = AssetManager::GetTexture("../../media/textures/sea.png");
    initSprite();
}

SeaCell::SeaCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) {
    m_texture = AssetManager::GetTexture("../../media/textures/sea.png");
    initSprite();
}

bool SeaCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->isMarine();
}
