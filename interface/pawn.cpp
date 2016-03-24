#include "pawn.h"

Pawn::Pawn(std::shared_ptr<Piece> const& piece)
    : m_piece(piece)
    , m_sprite()
    , m_size(0, 0)
    , m_animator(m_sprite)
    , m_travelling(false)
    , m_rotating(false)
    , m_moving(false)
    , m_direction(0)
    , m_speed(1.5)
    , m_angle(0)
    , m_distance(0)
    , m_progress(0)
{
    int nbSprites = 1;

    if(m_piece->getType() == "tank") {
        m_size = sf::Vector2i(30, 38);
        nbSprites = 2;
    } else if(m_piece->getType() == "big_tank") {
        m_size = sf::Vector2i(30, 46);
        nbSprites = 2;
    } else if(m_piece->getType() == "boat") {
        m_size = sf::Vector2i(27, 52);
    } else if(m_piece->getType() == "crab") {
        m_size = sf::Vector2i(54, 52);
        nbSprites = 2;
    } else if(m_piece->getType() == "barge") {
        m_size = sf::Vector2i(20, 50);
    } else if(m_piece->getType() == "pontoon") {
        m_size = sf::Vector2i(32, 52);
    } else if(m_piece->getType() == "weather_layer") {
        m_size = sf::Vector2i(56, 56);
    }

    m_sprite.setOrigin(m_size.x / 2, m_size.y / 2);
    
    float size = 2.8 * Hexagon::SIZE / 100;
    
    m_sprite.setScale(size, size);

    auto& animation_idle = m_animator.CreateAnimation("idle", m_piece->getType(), sf::seconds(0.2), true);
    animation_idle.AddFrames(sf::Vector2i(0, 0), m_size, 1);

    auto& animation_moving = m_animator.CreateAnimation("moving", m_piece->getType(), sf::seconds(0.2), true);
    animation_moving.AddFrames(sf::Vector2i(0, 0), m_size, nbSprites);
}

sf::Vector2f Pawn::PawnToPix(int xCell, int yCell) const
{
    float x;
    float y;

    // setting the position of the pawn
    if(xCell % 2 == 0) {
        x = xCell * Hexagon::WIDTH * 3 / 4;
        y = yCell * Hexagon::HEIGHT;
    } else {
        x = xCell * Hexagon::WIDTH * 3 / 4;
        y = (yCell - 0.5) * Hexagon::HEIGHT; // above the previous one
    }

    y += Hexagon::HEIGHT / 2; // adding an offset

    return sf::Vector2f(x, y);
}

bool Pawn::isTravelling()
{
    return m_travelling;
}

void Pawn::travelTo(std::shared_ptr<Cell> destination)
{
    m_travelling = true;

    sf::Vector2f v1(Hexagon::CellToPix(m_piece->getCell()->getX(), m_piece->getCell()->getY()));
    sf::Vector2f v2(Hexagon::CellToPix(destination->getX(), destination->getY()));

    if(v1.x == v2.x && v1.y == v2.y) {
        m_angle = m_sprite.getRotation();
    } else {
        m_distance = sqrt(pow((v2.x - v1.x), 2) + pow((v2.y - v1.y), 2));

        if(v1.x == v2.x) {
            m_angle = (v1.y > v2.y) ? 0 : 180;
        } else if(v1.x < v2.x) {
            m_angle = (v1.y > v2.y) ? 60 : 120;
        } else {
            m_angle = (v1.y > v2.y) ? 300 : 240;
        }

        if(m_sprite.getRotation() < 180) {
            if(m_angle > m_sprite.getRotation() && m_angle <= m_sprite.getRotation() + 180) {
                m_direction = 1;
            } else {
                m_direction = -1;
            }
        } else {
            if(m_angle > (int)(m_sprite.getRotation()) % 180 && m_angle <= (int)(m_sprite.getRotation()) % 180 + 180) {
                m_direction = -1;
            } else {
                m_direction = 1;
            }
        }
    }

    m_rotating = true;
}

// updates the pion
void Pawn::update(sf::Time const& deltaTime)
{
    if(m_rotating && m_sprite.getRotation() != m_angle) {
        m_sprite.rotate(m_direction * m_speed);
    } else if(m_rotating) {
        m_rotating = false;
        m_moving = true;
        m_animator.SwitchAnimation("moving");
    } else if(m_moving && m_progress < m_distance) {
        if(m_progress + m_speed > m_distance) {
            m_sprite.setPosition(
                cos((90 - m_angle) * M_PI / 180.0) * m_distance, -sin((90 - m_angle) * M_PI / 180.0) * m_distance);
        } else {
            m_sprite.move(cos((90 - m_angle) * M_PI / 180.0) * m_speed, -sin((90 - m_angle) * M_PI / 180.0) * m_speed);
        }
        m_progress += m_speed;
    } else if(m_moving) {
        m_moving = false;
        m_animator.SwitchAnimation("idle");
        m_progress = 0;
        m_distance = 0;

        m_sprite.setPosition(0, 0);

        m_travelling = false;
    }

    m_animator.Update(deltaTime);
}

// draws the pion
void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(m_piece->getCell() != nullptr) {
        states.transform.translate(PawnToPix(m_piece->getCell()->getX(), m_piece->getCell()->getY()));

        target.draw(m_sprite, states);
    }
}
