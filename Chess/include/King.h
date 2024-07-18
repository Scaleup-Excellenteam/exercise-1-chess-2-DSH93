//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef CHESS_KING_H
#define CHESS_KING_H

#include "Piece.h"

class King : public Piece {
public:
    King(char c) : Piece(c) {}

    King(const King &other) : Piece(other.color) {}

    bool validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece *>> &board) override;

    char getPieceSymbol() const override { return getColor() == 'w' ? 'K' : 'k'; }
};

#endif //CHESS_KING_H



