//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef CHESS_PAWN_H
#define CHESS_PAWN_H

#include "Piece.h"


class Pawn : public Piece {

public:
    Pawn(char c) : Piece(c) {}

    Pawn(const Pawn &other) : Piece(other.color) {}

    bool validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece*>>& board)  override;

    char getPieceSymbol() const override { return getColor() == 'w' ? 'P' : 'p'; }
};

#endif //CHESS_PAWN_H


