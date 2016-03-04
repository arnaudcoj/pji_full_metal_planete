#include "cell.h"

const float Cell::SIZE = { 50 };
const float Cell::WIDTH = { SIZE * 2 };
const float Cell::HEIGHT = { (float)sqrt(3)/2 * WIDTH };

Cell::Cell() : m_halfCell(false), m_coord(sf::Vector2i(-1, -1)), m_area(0) {
    m_piece = nullptr;
}

Cell::Cell(sf::Vector2i coord, bool halfCell, unsigned int area) : m_halfCell(halfCell), m_coord(coord), m_area(area) {
    m_piece = nullptr;
}

Cell::Cell(int x, int y, bool halfCell, unsigned int area) : m_halfCell(halfCell), m_coord(x, y), m_area(area) {
    m_piece = nullptr;
}

bool Cell::isHalfCell() {
    return m_halfCell;
}

std::shared_ptr<Piece> Cell::getPiece() {
    return m_piece;
}

void Cell::setPiece(std::shared_ptr<Piece> piece) {
    assert(piece != nullptr);
    m_piece = piece;
}

bool Cell::isOccupied() const {
    return m_piece != nullptr;
}

bool Cell::removePiece() {
    if(m_piece == nullptr)
        return false;

    m_piece = nullptr;
    return true;
}

sf::Vector2i Cell::getCoord() {
    return m_coord;
}

int Cell::getX() const {
    return m_coord.x;
}

int Cell::getY() const {
    return m_coord.y;
}

unsigned int Cell::getArea() {
    return m_area;
}

bool Cell::isPracticable(std::shared_ptr<Piece> piece, Tide tide) {
    assert(piece != nullptr);
    return (piece != nullptr) && !isHalfCell() && isPracticableCurrent(piece, tide);
}

// returns a point of the hexagon thanks to its center, its size and the point's identifier
sf::Vector2f hex_corner(float x, float y, float size, int i) {
    int angle_deg = 60 * i;
    float angle_rad = M_PI / 180 * angle_deg;
    return sf::Vector2f(x + size * cos(angle_rad), y + size * sin(angle_rad));
}

sf::Vector2f Cell::CellToPix(int xCell, int yCell) const {
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

void Cell::initSprite() {
    m_sprite.setPointCount(6); // the number of points

    // creating each point of the hexagon
    for (int i = 0; i < 6; ++i) {
        m_sprite.setPoint(i, hex_corner(0, 0, SIZE, i));
    }

    m_sprite.setTexture(&m_texture);

    // creating a black border inside the hexagon
    m_sprite.setOutlineThickness(-2);
    m_sprite.setOutlineColor(sf::Color(0, 0, 0, 255));

    // setting the color of the hexagon depending of if it's a half cell or not
    if(isHalfCell())
        m_sprite.setFillColor(sf::Color(150, 150, 150, 255));
}

// updates the hexagon
void Cell::update() {
    if (isOccupied()) {
        m_sprite.setOutlineColor(sf::Color::Red);
        m_sprite.setOutlineThickness(-5);
    } else {
        m_sprite.setOutlineColor(sf::Color::Black);
        m_sprite.setOutlineThickness(-2);
    }
}

// draws the hexagon the the entities inside of it
void Cell::draw(sf::RenderTarget& target, sf::RenderStates states) const {
    states.transform.translate(CellToPix(getX(), getY()));

    // drawing the hexagon on the target
    target.draw(m_sprite, states);

    // if the cell is occupied
    if (isOccupied()) {
        // drawing the pawn on the target
        m_piece->draw(target, states);
    }
}
