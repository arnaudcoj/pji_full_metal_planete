#include "player.h"

Player::Player(int number)
    : m_action_points(15)
    , m_number(number)
    , m_pieceStock()
{
}

int Player::getNumber() const
{
    return m_number;
}

int Player::getActionPoints() const
{
    return m_action_points;
}

bool Player::useActionPoints(int points)
{
    if(points < 0)
        return false;
    if(m_action_points - points < 0)
        return false;
    m_action_points -= points;
    return true;
}

bool Player::canMove(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell)
{
    assert(cell != nullptr);

    return (!(cell->isOccupied() || !cell->isPracticable(piece) ||
        (piece->getCell() != nullptr && !piece->getCell()->isPracticable(piece))));
}

bool Player::canCarry(std::shared_ptr<Piece> transporter, std::shared_ptr<Piece> targetPiece, Hexagrid& grid) {
    assert(transporter != nullptr);
    assert(targetPiece != nullptr);

    return grid.areNeighbours(transporter->getCell(), targetPiece->getCell()) && transporter->getContainer().canCarry(targetPiece) ;
}

bool Player::move(std::shared_ptr<Piece> piece, std::shared_ptr<Cell> cell)
{
    assert(cell != nullptr);

    if(!canMove(piece, cell)) {
        return false;
    }

    cell->setPiece(piece);

    if(piece->isOnCell())
        piece->getCell()->removePiece();

    piece->setCell(cell);

    return true;
}

bool Player::pickPiece(std::shared_ptr<Piece> transporter, std::shared_ptr<Piece> targetPiece, Hexagrid& grid)
{
    assert(transporter != nullptr);
    assert(targetPiece != nullptr);

    if(canCarry(transporter, targetPiece, grid)) {
        return false;
    }

    transporter->getContainer().takePiece(targetPiece);

    if(targetPiece->isOnCell())
        targetPiece->getCell()->removePiece();

    targetPiece->setCell(nullptr);

    return true;
}

bool Player::putPieceDown(std::shared_ptr<Piece> transporter, std::shared_ptr<Piece> targetPiece, std::shared_ptr<Cell> targetCell, Hexagrid& grid) 
{
    assert(transporter);
    //check si est à l'intérieur
    assert(targetPiece);
    
    if(targetCell->isOccupied() || !targetCell->isPracticable(targetPiece))
        return false;
        
    targetPiece->getContainer().removePiece(targetPiece);
    targetCell->setPiece(targetPiece);
        
    return true;
}

bool Player::removePiece(std::shared_ptr<Piece> piece)
{
    if(!piece->isOnCell()) {
        return false;
    }

    piece->getCell()->removePiece();
    piece->removeCell();

    return false;
}

PieceStock& Player::getPieceStock() {
    return m_pieceStock;
}

std::unordered_set<std::shared_ptr<Cell> > Player::getAccessibleCells(Hexagrid& grid, std::shared_ptr<Piece> piece)
{
    assert(piece != nullptr);
    assert(piece->getCell() != nullptr);

    std::unordered_set<std::shared_ptr<Cell> > cells;

    // return an empty set  (range < 1)
    if(!piece->getCell()->isPracticable(piece) || getActionPoints() < 1) {
        return cells;
    }

    std::list<std::list<std::shared_ptr<Cell> > > fringes;

    // add first cell's neighbours (range = 1)
    fringes.emplace_back();
    for(std::shared_ptr<Cell> neighbour : grid.getDirectPracticableNeighbours(piece->getCell(), piece)) {
        if(!cells.count(neighbour)) {
            cells.insert(neighbour);
            fringes.back().push_back(neighbour);
        }
    }

    // flood-fill for the other cells (range > 2)
    for(int k = 1; k < getActionPoints(); k++) {
        fringes.emplace_back();
        for(std::shared_ptr<Cell> cell : fringes.front()) {
            for(std::shared_ptr<Cell> neighbour : grid.getDirectPracticableNeighbours(cell, piece)) {
                if(!cells.count(neighbour)) {
                    cells.insert(neighbour);
                    fringes.back().push_back(neighbour);
                }
            }
        }
        fringes.pop_front();
    }
    
    return cells;
}
