//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef CHESS_ROOK_H
#define CHESS_ROOK_H

#include "Piece.h"

class Rook : public Piece {
public:
    Rook(char c) : Piece(c) {} // Constructor

    Rook(const Rook& other) : Piece(other.color) {} // Copy constructor

    bool validateMove(int sourceRow, int sourceCol, int destRow, int destCol, const std::vector<std::vector<Piece*>>& board) override; // checking if the move is valid

    char getPieceSymbol() const override { return getColor() == 'w' ? 'R' : 'r'; } // symbol of the piece (R for white, r for black)
};



#endif //CHESS_ROOK_H
