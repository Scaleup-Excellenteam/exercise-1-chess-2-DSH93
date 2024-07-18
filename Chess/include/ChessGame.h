//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef CHESSGAME_H
#define CHESSGAME_H

#include "Piece.h"
#include "Point.h"
#include <vector>
#include <string>

class ChessGame {
private:
    std::vector<std::vector<Piece *>> board;
    bool isWhiteTurn;
    int whiteKingRow;
    int whiteKingCol;
    int blackKingRow;
    int blackKingCol;

    bool validateMove(const Point& source, const Point& dest);
    bool isClearPath(const Point& source, const Point& dest);
    bool isKingInCheck(char color);

public:
    ChessGame();
    ~ChessGame();
    unsigned int movePiece(const std::string &input);
    void displayBoard() const;
    char whosTurn() const;
};

#endif // CHESSGAME_H
