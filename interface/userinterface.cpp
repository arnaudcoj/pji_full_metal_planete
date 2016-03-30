#include "userinterface.h"

UserInterface::UserInterface(Game& game, sf::RenderWindow& window)
    : m_window(window)
    , m_view(sf::FloatRect(0, 0, window.getSize().x, window.getSize().y))
    , m_game(game)
    , m_turn()
    , m_player()
    , m_actions()
    , m_tide()
{
    m_window.setView(m_view);

    m_turn.setFont(AssetManager::getFont("game_over.ttf"));
    m_turn.setCharacterSize(Hexagon::SIZE);
    m_turn.setColor(sf::Color::White);
    m_turn.setStyle(sf::Text::Bold);

    m_player.setFont(AssetManager::getFont("game_over.ttf"));
    m_player.setCharacterSize(Hexagon::SIZE);
    m_player.setColor(sf::Color::White);
    m_player.setStyle(sf::Text::Bold);

    m_actions.setFont(AssetManager::getFont("game_over.ttf"));
    m_actions.setCharacterSize(Hexagon::SIZE);
    m_actions.setColor(sf::Color::White);
    m_actions.setStyle(sf::Text::Bold);

    m_tide.setFont(AssetManager::getFont("game_over.ttf"));
    m_tide.setCharacterSize(Hexagon::SIZE);
    m_tide.setColor(sf::Color::White);
    m_tide.setStyle(sf::Text::Bold);

    m_turn.setPosition(Hexagon::SIZE / 2, -Hexagon::SIZE / 2);
    m_player.setPosition(Hexagon::SIZE * 3, -Hexagon::SIZE / 2);
    m_actions.setPosition(Hexagon::SIZE * 5.6, -Hexagon::SIZE / 2);
    m_tide.setPosition(window.getSize().x - Hexagon::SIZE * 3, -Hexagon::SIZE / 2);
}

void UserInterface::update()
{
    sf::String turn;
    sf::String player;
    sf::String actions;
    sf::String tide;

    turn = std::to_string(m_game.getGameState().getNbTurns());
    player = std::to_string(m_game.getCurrentPlayer().getNumber());
    actions = std::to_string(m_game.getCurrentPlayer().getActionPoints());

        switch(m_game.getGameState().getTide())
    {
    case Tide::LOW_TIDE:
        tide = "Low";
        break;
    case Tide::MEDIUM_TIDE:
        tide = "Medium";
        break;
    case Tide::HIGH_TIDE:
        tide = "High";
        break;
    default:
        break;
    }

    m_turn.setString("Turn: " + turn);
    m_player.setString("Player: " + player);
    m_actions.setString("Actions: " + actions);
    m_tide.setString("Tide: " + tide);
}

void UserInterface::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
    target.setView(m_view);
    target.draw(m_turn);
    target.draw(m_player);
    target.draw(m_actions);
    target.draw(m_tide);
}
