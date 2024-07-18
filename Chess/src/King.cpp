//
// Created by Dor Shukrun on 18/07/2024.
//
#include "King.h"

bool King::validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece*>>& board) {
    if (abs(sourceRow - destRow) <= 1 && abs(sourceCol - destCol) <= 1) {
        if (board[destRow][destCol] == nullptr || board[destRow][destCol]->getColor() != getColor()) {
            return true;
        }
    }
    return false;
}