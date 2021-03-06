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
    , m_speed(2)
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

    auto& animation_idle = m_animator.createAnimation("idle", m_piece->getType(), sf::seconds(0.2), true);
    animation_idle.addFrames(sf::Vector2i(0, 0), m_size, 1);

    auto& animation_moving = m_animator.createAnimation("moving", m_piece->getType(), sf::seconds(0.2), true);
    animation_moving.addFrames(sf::Vector2i(0, 0), m_size, nbSprites);
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

sf::Vector2f Pawn::getPosition() {
    return m_sprite.getPosition();
}

// updates the pion
void Pawn::update(sf::Time const& deltaTime)
{
    if(m_piece->getCell() != nullptr) {
        if(!m_travelling) {
            sf::Vector2f position = Hexagon::CellToPix(m_piece->getCell()->getX(), m_piece->getCell()->getY());
            m_sprite.setPosition(position.x, position.y);
        }

        if(m_rotating && m_sprite.getRotation() != m_angle) {
            m_sprite.rotate(m_direction * m_speed);
        } else if(m_rotating) {
            m_rotating = false;
            m_moving = true;
            m_animator.switchAnimation("moving");
        } else if(m_moving && m_progress < m_distance) {
            float speed = m_speed;
            if(m_progress + m_speed > m_distance) {
                speed = m_distance - m_progress;
            }
            
            m_sprite.move(cos((90 - m_angle) * M_PI / 180.0) * speed, -sin((90 - m_angle) * M_PI / 180.0) * speed);
            m_progress += speed;
        } else if(m_moving && m_progress == m_distance) {
            m_moving = false;
            m_animator.switchAnimation("idle");
            m_progress = 0;
            m_distance = 0;

            m_travelling = false;
        }

        m_animator.update(deltaTime);
    }
}

// draws the pion
void Pawn::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    if(m_piece->getCell() != nullptr) {
        target.draw(m_sprite, states);
    }
}
