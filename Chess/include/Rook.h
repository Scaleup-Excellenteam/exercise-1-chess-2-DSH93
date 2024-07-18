//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef ROOK_H
#define ROOK_H

#include "Piece.h"
#include "Point.h"

class Rook : public Piece {
public:
    Rook(char c) : Piece(c) {}
    bool validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece*>>& board) const override;
    char getPieceSymbol() const override { return getColor() == 'w' ? 'R' : 'r'; }
};

#endif // ROOK_H
