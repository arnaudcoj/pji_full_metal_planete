#include "hexagon.h"

const float Hexagon::SIZE = { 100 };
const float Hexagon::WIDTH = { SIZE * 2 };
const float Hexagon::HEIGHT = { (float)sqrt(3) / 2 * WIDTH };

// returns a point of the hexagon thanks to its center, its size and the point's identifier
sf::Vector2f hex_corner(float x, float y, float size, int i)
{
    int angle_deg = 60 * i;
    float angle_rad = M_PI / 180 * angle_deg;
    return sf::Vector2f(x + size * cos(angle_rad), y + size * sin(angle_rad));
}

Hexagon::Hexagon(std::shared_ptr<Cell> cell)
    : m_cell(cell)
    , m_sprite()
    , m_selected(false)
    , m_focused(false)
    , m_accessible(false)
    , m_path(false)
{
    m_sprite.setPointCount(6); // the number of points

    // creating each point of the hexagon
    for(int i = 0; i < 6; ++i) {
        m_sprite.setPoint(i, hex_corner(0, 0, SIZE, i));
    }

    // setting the color of the hexagon depending of if it's a half cell or not
    if(m_cell->isHalfCell())
        m_sprite.setFillColor(sf::Color(150, 150, 150));

    m_sprite.setOutlineColor(sf::Color::Black);
    m_sprite.setOutlineThickness(-SIZE / 25);

    sf::Vector2f position = CellToPix(m_cell->getX(), m_cell->getY());
    m_sprite.setPosition(position.x, position.y);
}

sf::Vector2f Hexagon::CellToPix(int xCell, int yCell)
{
    float x;
    float y;

    // setting the position of the hexagon
    if(xCell % 2 == 0) {
        x = xCell * WIDTH * 3 / 4;
        y = yCell * HEIGHT;
    } else {
        x = xCell * WIDTH * 3 / 4;
        y = (yCell - 0.5) * HEIGHT; // above the previous one
    }

    y += HEIGHT / 2;

    return sf::Vector2f(x, y);
}

void Hexagon::setSelected(bool selected)
{
    m_selected = selected;
}

void Hexagon::setFocused(bool focused)
{
    m_focused = focused;
}

void Hexagon::setAccessible(bool accessible)
{
    m_accessible = accessible;
}

void Hexagon::setInPath(bool path)
{
    m_path = path;
}

// updates the hexagon
void Hexagon::update()
{
    m_sprite.setTexture(&AssetManager::getTexture(m_cell->getType()));

    if(!m_cell->isHalfCell()) {
        if(m_path) {
            m_sprite.setFillColor(sf::Color(206, 153, 255));
        } else if(m_accessible) {
            m_sprite.setFillColor(sf::Color(175, 255, 175));
        } else {
            m_sprite.setFillColor(sf::Color::White);
        }
    }

    if(!m_selected) {
        if(m_focused) {
            if(m_accessible) {
                m_sprite.setOutlineColor(sf::Color(0, 128, 0));
            } else {
                m_sprite.setOutlineColor(sf::Color(128, 0, 0));
            }
            m_sprite.setOutlineThickness(-Hexagon::SIZE / 10);
        } else {
            m_sprite.setOutlineColor(sf::Color::Black);
            m_sprite.setOutlineThickness(-Hexagon::SIZE / 25);
        }
    } else {
        m_sprite.setOutlineColor(sf::Color(0, 128, 128));
        m_sprite.setOutlineThickness(-Hexagon::SIZE / 10);
    }
}

// draws the hexagon the the entities inside of it
void Hexagon::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    // drawing the hexagon on the target
    target.draw(m_sprite, states);
}
