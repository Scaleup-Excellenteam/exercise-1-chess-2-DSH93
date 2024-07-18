//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef KING_H
#define KING_H

#include "Piece.h"
#include "Point.h"

class King : public Piece {
public:
    King(char c) : Piece(c) {}
    bool validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece*>>& board) const override;
    char getPieceSymbol() const override { return getColor() == 'w' ? 'K' : 'k'; }
};

#endif // KING_H



