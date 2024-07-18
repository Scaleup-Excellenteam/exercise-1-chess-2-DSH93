//
// Created by Dor Shukrun on 18/07/2024.
//

#include "Pawn.h"
#include <vector>
#include <cmath>

bool Pawn::validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece *>> &board) {
    int direction = (getColor() == 'w') ? 1 : -1;
    int startRow = (getColor() == 'w') ? 1 : 6;


    if ((sourceCol == destCol) && (destRow == sourceRow + direction) && (board[destRow][destCol] == nullptr)) {
        return true;
    }


    if (sourceCol == destCol && destRow == sourceRow + 2 * direction && sourceRow == startRow) {
        if (board[destRow][destCol] == nullptr && board[sourceRow + direction][sourceCol] == nullptr) {
            return true;
        }
    }

    if (abs(destCol - sourceCol) == 1 && destRow == sourceRow + direction) {
        if (board[destRow][destCol] != nullptr || board[destRow][destCol]->getColor() != getColor()) {
            return true;
        }
    }

    return false;
}
