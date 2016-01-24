#include <SFML/Graphics.hpp>
#include <Hexagrid.h>

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }

    Hexagrid grid(8, 6);

    grid.printAdjacents(9, 9);
    std::cout << std::endl;
    grid.printAdjacents(1, 1);
    std::cout << std::endl;
    grid.printAdjacents(2, 1);
    std::cout << std::endl;
    grid.printAdjacents(3, 1);
    std::cout << std::endl;
    grid.printAdjacents(3, 2);

    grid.toString();
    grid.toStringCoord();

    return 0;
}
