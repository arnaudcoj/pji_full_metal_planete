#include "tools.h"

using namespace std;

sf::Vector2f Tools::HexToPix(int xCell, int yCell) {
    float x;
    float y;
    float width = Hexagon::WIDTH;
    float height = Hexagon::HEIGHT;

    // setting the position of the hexagon
    if(xCell % 2 == 0) {
        x = xCell * width * 3/4;
        y = yCell * height;
    } else {
        x = xCell * width * 3/4;
        y = (yCell - 0.5) * height; // above the previous one
    }

    x -= width / 2; // adding an offset

    return sf::Vector2f(x, y);
}

sf::Vector2f Tools::PixToHex(int xCursor, int yCursor) {
    int x;
    int y;
    float size = Hexagon::SIZE;
    float width = Hexagon::WIDTH;
    float height = Hexagon::HEIGHT;
    float side = size * 3 / 2;;

    xCursor += width / 2;

    int ci = floor(xCursor / side);
    int cx = xCursor - side * ci;

    int ty = yCursor - (ci % 2) * height / 2;
    int cj = floor(ty / height);
    int cy = ty - height * cj;

    if (cx > std::abs(size / 2 - size * cy / height)) {
        x = ci;
        y = cj;
    } else {
        x = ci - 1;
        y = cj + (ci % 2) - ((cy < height / 2) ? 1 : 0);
    }

    if(x % 2)
        y++;

    // A COMMENTER !

    return sf::Vector2f(x, y);
}
