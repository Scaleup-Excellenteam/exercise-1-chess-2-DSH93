//
// Created by Dor Shukrun on 18/07/2024.
//


#include "Piece.h"
#include "Rook.h"
#include "Bishop.h"


#ifndef CHESS_QUEEN_H
#define CHESS_QUEEN_H

class Queen : public Piece {
private:
    Rook rook;
    Bishop bishop;

public:
    Queen(char color) : Piece(color), rook(color), bishop(color) {}
    Queen(const Queen& other) : Piece(other.color), rook(other.color), bishop(other.color) {}

    bool validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece *>> &board) override{
        return rook.validateMove(sourceRow, sourceCol, destRow, destCol, board) || bishop.validateMove(sourceRow, sourceCol, destRow, destCol, board);
    }
    char getPieceSymbol() const override { return getColor() == 'w' ? 'Q' : 'q'; }


};

#endif //CHESS_QUEEN_H
