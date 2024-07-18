//
// Created by Dor Shukrun on 18/07/2024.
//

#include "Rook.h"

bool Rook::validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece*>>& board) const {
    if (source.getRow() == dest.getRow() || source.getCol() == dest.getCol()) {
        int rowStep = (source.getRow() == dest.getRow()) ? 0 : (dest.getRow() > source.getRow() ? 1 : -1);
        int colStep = (source.getCol() == dest.getCol()) ? 0 : (dest.getCol() > source.getCol() ? 1 : -1);

        int currentRow = source.getRow() + rowStep;
        int currentCol = source.getCol() + colStep;

        while (currentRow != dest.getRow() || currentCol != dest.getCol()) {
            if (board[currentRow][currentCol] != nullptr) {
                return false;
            }
            currentRow += rowStep;
            currentCol += colStep;
        }

        if (board[dest.getRow()][dest.getCol()] == nullptr || board[dest.getRow()][dest.getCol()]->getColor() != getColor()) {
            return true;
        }
    }
    return false;
}
