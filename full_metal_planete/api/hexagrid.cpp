#include "hexagrid.h"

using namespace std;

Hexagrid::Hexagrid(int width, int height) : m_width(width), m_height(height) {
    int i, j;
    m_grid = new bool*[width];

    for(i = 0; i < width; i++) {
        m_grid[i] = new bool[height];
    }

    for(i = 0; i < width; i++) {
        for(j = 1; j < height - 1; j++)
            m_grid[i][j] = true;
    }

    //1ere colonne
    for(j = 0; j < height; j++)
        m_grid[0][j] = false;

    //derniere colonne
    for(j = 0; j < height; j++)
        m_grid[width - 1][j] = false;

    //premiere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][0] = false;
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][0] = true;
    }

    //derniere ligne
    for(i = 1; i < width - 1; i += 2) {
        m_grid[i][height - 1] = true;
    }

    for(i = 2; i < width - 1; i += 2) {
        m_grid[i][height - 1] = false;
    }

}

void Hexagrid::printAdjacents(int x, int y) {
    printCell(x, y - 1);
    printCell(x + 1, y - (x % 2));
    printCell(x + 1, y + (1 - (x % 2)));
    printCell(x, y + 1);
    printCell(x - 1, y + (1 - (x % 2)));
    printCell(x - 1, y - (x % 2));
}

//pour tester les tests...
sf::Vector2i Hexagrid::getTopCellCoord(int x, int y) {
    return sf::Vector2i(x, y - 1);
}

//pour tester les tests...
sf::Vector2i Hexagrid::getBottomCellCoord(int x, int y) {
    return sf::Vector2i(x, y + 1);
}

void Hexagrid::printCell(int x, int y) {
    if(x < 0 || y < 0 || x >= m_width || y >= m_height)
        cout << x << ", " << y << " out of bounds" << endl;
    else {
        cout << x << ", " << y << " : ";
        if(m_grid[x][y])
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }
}

void Hexagrid::toString() {
    for(int y = 0; y < m_height; y++) {
        cout << " ";
        for(int x = 1; x < m_width; x += 2) {
            if(m_grid[x][y])
                cout << "O ";
            else
                cout << "X ";
        }
        cout << endl;
        for(int x = 0; x < m_width; x += 2) {
            if(m_grid[x][y])
                cout << "O ";
            else
                cout << "X ";
        }
        cout << endl;
    }
}

void Hexagrid::toStringCoord() {
    for(int y = 0; y < m_height; y++) {
        cout << "  ";
        for(int x = 1; x < m_width; x += 2) {
            cout << "(" << x << ", " << y << ") ";
        }
        cout << endl;
        for(int x = 0; x < m_width; x += 2) {
            cout << "(" << x << ", " << y << ") ";
        }
        cout << endl;
    }
}
