//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef BISHOP_H
#define BISHOP_H

#include "Piece.h"
#include "Point.h"

class Bishop : public Piece {
public:
    Bishop(char c) : Piece(c) {}
    bool validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece*>>& board) const override;
    char getPieceSymbol() const override { return getColor() == 'w' ? 'B' : 'b'; }
};

#endif // BISHOP_H
