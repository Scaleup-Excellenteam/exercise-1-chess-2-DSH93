//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef CHESS_BISHOP_H
#define CHESS_BISHOP_H

#include "Piece.h"

class Bishop : public Piece {
public:
    Bishop(char c) : Piece(c) {}
    Bishop(const Bishop &other) : Piece(other.color) {}
    bool validateMove(int sourceRow, int startY, int destRow, int destCol, const std::vector<std::vector<Piece *>> &board) override;
    char getPieceSymbol() const override { return getColor() == 'w' ? 'B' : 'b'; }
};

#endif //CHESS_BISHOP_H
