#include "Hexagrid.h"

using namespace std;

Hexagrid::Hexagrid(int width, int height) : mwidth(width), mheight(height) {
  int i, j;
  mgrid = new bool*[width];

  for(i = 0; i < width; i++) {
    mgrid[i] = new bool[height];
    for(j = 0; j < height; j++)
      mgrid[i][j] = true;
  }
  
  //1ere colonne
  for(j = 0; j < height; j++)
      mgrid[0][j] = false;

  //derniere colonne
  for(j = 0; j < height; j++)
      mgrid[width - 1][j] = false;

  //premiere ligne
  for(i = 1; i < width; i += 2)
      mgrid[i][0] = false;

  //derniere ligne
  for(i = 0; i < width; i += 2)
      mgrid[i][height - 1] = false;
        
  
}

void Hexagrid::printAdjacents(int x, int y) {
  printCell(x, y - 1);
  printCell(x + 1, y - (x % 2));
  printCell(x + 1, y + (1 - (x % 2)));
  printCell(x, y + 1);
  printCell(x - 1, y + (1 - (x % 2)));
  printCell(x - 1, y - (x % 2));
}

void Hexagrid::printCell(int x, int y) {
  if(x < 0 || y < 0 || x >= mwidth || y >= mheight)
    cout << x << ", " << y << " out of bounds" << endl;
  else {
    cout << x << ", " << y << " : ";
    if(mgrid[x][y])
      cout << "true" << endl;
    else
      cout << "false" << endl;
  }
}

void Hexagrid::toString() {
  for(int y = 0; y < mheight; y++) {
    cout << " ";
    for(int x = 1; x < mwidth; x += 2) {
      if(mgrid[x][y])
	cout << "O ";
      else
	cout << "X ";
    }
    cout << endl;
    for(int x = 0; x < mwidth; x += 2) {
      if(mgrid[x][y])
	cout << "O ";
      else
	cout << "X ";
    }
    cout << endl;
  }
}

void Hexagrid::toStringCoord() {
  for(int y = 0; y < mheight; y++) {
    cout << "  ";
    for(int x = 1; x < mwidth; x += 2) {
      cout << "(" << x << ", " << y << ") ";
    }
    cout << endl;
    for(int x = 0; x < mwidth; x += 2) {
      cout << "(" << x << ", " << y << ") ";
    }
    cout << endl;
  }
}

int main (void) {

  Hexagrid grid(8, 6);
  
  grid.printAdjacents(9, 9);
  cout << endl;
  grid.printAdjacents(1, 1);
  cout << endl;
  grid.printAdjacents(2, 1);
  cout << endl;
  grid.printAdjacents(3, 1);
  cout << endl;
  grid.printAdjacents(3, 2);

  grid.toString();
  grid.toStringCoord();
  
  return 0;
}
