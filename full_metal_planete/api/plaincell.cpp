#include "plaincell.h"

PlainCell::PlainCell() : Cell() {
    m_texture = AssetManager::GetTexture("../../media/textures/plain.png");
    initSprite();
}

PlainCell::PlainCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) {
    m_texture = AssetManager::GetTexture("../../media/textures/plain.png");
    initSprite();
}

PlainCell::PlainCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) {
    m_texture = AssetManager::GetTexture("../../media/textures/plain.png");
    initSprite();
}

bool PlainCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->isTerrestrial();
}
