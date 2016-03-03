#include "mountaincell.h"

MountainCell::MountainCell() : Cell() {
    m_texture.loadFromFile("../../media/textures/mountain.png");
    initSprite();
}

MountainCell::MountainCell(sf::Vector2i coord, bool halfCell, unsigned int area) : Cell(coord, halfCell, area) {
    m_texture.loadFromFile("../../media/textures/mountain.png");
    initSprite();
}

MountainCell::MountainCell(int x, int y, bool halfCell, unsigned int area) : Cell(x, y, halfCell, area) {
    m_texture.loadFromFile("../../media/textures/mountain.png");
    initSprite();
}

bool MountainCell::isPracticableCurrent(std::shared_ptr<Piece> piece, Tide) {
    return piece->canClimb();
}
