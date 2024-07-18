//
// Created by Dor Shukrun on 18/07/2024.
//


#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"
#include "Point.h"

class Queen : public Piece {
private:
    Rook rook;
    Bishop bishop;

public:
    Queen(char color) : Piece(color), rook(color), bishop(color) {}
    Queen(const Queen& other) : Piece(other.color), rook(other.color), bishop(other.color) {}

    bool validateMove(const Point& source, const Point& dest, const std::vector<std::vector<Piece *>> &board) const override {
        return rook.validateMove(source, dest, board) || bishop.validateMove(source, dest, board);
    }

    char getPieceSymbol() const override {
        return getColor() == 'w' ? 'Q' : 'q';
    }
};

#endif //CHESS_QUEEN_H
