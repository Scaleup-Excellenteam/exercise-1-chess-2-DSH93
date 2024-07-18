//
// Created by Dor Shukrun on 18/07/2024.
//

#include "Bishop.h"
#include <cmath>

bool Bishop::validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece*>>& board) const {
    int rowDiff = abs(source.getRow() - dest.getRow());
    int colDiff = abs(source.getCol() - dest.getCol());
    if (rowDiff == colDiff) {
        int rowStep = (dest.getRow() > source.getRow()) ? 1 : -1;
        int colStep = (dest.getCol() > source.getCol()) ? 1 : -1;

        int currentRow = source.getRow() + rowStep;
        int currentCol = source.getCol() + colStep;

        while (currentRow != dest.getRow() && currentCol != dest.getCol()) {
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
