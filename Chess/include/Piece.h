//
// Created by Dor Shukrun on 18/07/2024.
//


#ifndef PIECE_H
#define PIECE_H

#include <vector>
#include "Point.h"

class Piece {
protected:
    char color; // 'w' for white, 'b' for black

public:
    Piece(char c) : color(c) {}
    virtual ~Piece() {}
    char getColor() const { return color; }
    virtual bool validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece*>>& board) const = 0;
    virtual char getPieceSymbol() const = 0;
};

#endif // PIECE_H
