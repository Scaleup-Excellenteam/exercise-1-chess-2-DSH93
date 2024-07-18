//
// Created by Dor Shukrun on 18/07/2024.
//

#include "Bishop.h"

bool Bishop::validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece *>> &board) {
    if (abs(sourceRow - destRow) != abs(sourceCol - destCol)) {
        return false;
    }
    int xStep = (destRow > sourceRow) ? 1 : -1;
    int yStep = (destCol > sourceCol) ? 1 : -1;
    int x = sourceRow + xStep;

    int y = sourceCol + yStep;
    while (x != destRow || y != destCol) {
        if (board[x][y] != nullptr) {
            return false;
        }
        x += xStep;
        y += yStep;
    }
    if (board[destRow][destCol] == nullptr || board[destRow][destCol]->getColor() != getColor()) {
        return true;
    }
    return false;
}
