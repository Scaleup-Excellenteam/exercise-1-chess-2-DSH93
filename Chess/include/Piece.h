//
// Created by Dor Shukrun on 18/07/2024.
//


#ifndef PIECE_H
#define PIECE_H

#include <vector>

class Piece {
protected:
    char color; // 'w' for white, 'b' for black

public:
    Piece(char c) : color(c) {} // Constructor
    virtual ~Piece() {} // Destructor
    char getColor() const {
        return color;
    }


    // Pure virtual function for checking if the move is valid
    virtual bool validateMove(int startX, int startY, int endX, int endY, const std::vector<std::vector<Piece*>>& board) = 0;

    // Pure virtual function for getting the symbol of the piece
    virtual char getPieceSymbol() const = 0;
};

#endif // PIECE_H
