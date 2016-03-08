#include "hexagon.h"

const float Hexagon::SIZE = { 75 };
const float Hexagon::WIDTH = { SIZE * 2 };
const float Hexagon::HEIGHT = { (float)sqrt(3)/2 * WIDTH };

// returns a point of the hexagon thanks to its center, its size and the point's identifier
sf::Vector2f hex_corner(float x, float y, float size, int i) {
    int angle_deg = 60 * i;
    float angle_rad = M_PI / 180 * angle_deg;
    return sf::Vector2f(x + size * cos(angle_rad), y + size * sin(angle_rad));
}

Hexagon::Hexagon(std::shared_ptr<Cell> cell) {
    m_cell = cell;
    initSprite();
}

sf::Vector2f Hexagon::CellToPix(int xCell, int yCell) const {
    float x;
    float y;

    // setting the position of the hexagon
    if(xCell % 2 == 0) {
        x = xCell * WIDTH * 3/4;
        y = yCell * HEIGHT;
    } else {
        x = xCell * WIDTH * 3/4;
        y = (yCell - 0.5) * HEIGHT; // above the previous one
    }

    y += HEIGHT / 2; // adding an offset

    return sf::Vector2f(x, y);
}

void Hexagon::initSprite() {
    m_sprite.setPointCount(6); // the number of points

    // creating each point of the hexagon
    for (int i = 0; i < 6; ++i) {
        m_sprite.setPoint(i, hex_corner(0, 0, SIZE, i));
    }

    m_sprite.setTexture(&AssetManager::GetTexture(m_cell->getType()));

    // setting the color of the hexagon depending of if it's a half cell or not
    if(m_cell->isHalfCell())
        m_sprite.setFillColor(sf::Color(150, 150, 150, 255));
}

// updates the hexagon
void Hexagon::update() {
    if (m_cell->isOccupied()) {
        m_sprite.setOutlineColor(sf::Color::Red);
        m_sprite.setOutlineThickness(-SIZE/10);
    } else {
        m_sprite.setOutlineColor(sf::Color::Black);
        m_sprite.setOutlineThickness(-SIZE/25);
    }
}

// draws the hexagon the the entities inside of it
void Hexagon::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform.translate(CellToPix(m_cell->getX(), m_cell->getY()));

    // drawing the hexagon on the target
    target.draw(m_sprite, states);

    // if the cell is occupied
    if (m_cell->isOccupied()) {
        // drawing the pawn on the target
        Pawn pawn;
        pawn.draw(target, states);
    }
}
