//
// Created by Dor Shukrun on 18/07/2024.
//
#include "King.h"
#include <cmath>

bool King::validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece*>>& board) const {
    if (abs(source.getRow() - dest.getRow()) <= 1 && abs(source.getCol() - dest.getCol()) <= 1) {
        if (board[dest.getRow()][dest.getCol()] == nullptr || board[dest.getRow()][dest.getCol()]->getColor() != getColor()) {
            return true;
        }
    }
    return false;
}

