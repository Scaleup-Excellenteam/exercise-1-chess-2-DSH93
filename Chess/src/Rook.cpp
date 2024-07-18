//
// Created by Dor Shukrun on 18/07/2024.
//

#include "Rook.h"


bool Rook::validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece *>> &board) {
    if (sourceRow != destRow && sourceCol != destCol) {
        return false;
    }
    int xStep;
    if (sourceRow == destRow) {
        xStep = 0;
    } else if (destRow > sourceRow) {
        xStep = 1;
    } else {
        xStep = -1;
    }

    int yStep;
    if (sourceCol == destCol) {
        yStep = 0;
    } else if (destCol > sourceCol) {
        yStep = 1;
    } else {
        yStep = -1;
    }

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
