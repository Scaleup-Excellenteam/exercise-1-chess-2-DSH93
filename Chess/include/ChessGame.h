//
// Created by Dor Shukrun on 18/07/2024.
//

#ifndef CHESS_CHESSGAME_H
#define CHESS_CHESSGAME_H

#include "Piece.h"
#include <vector>
#include <string>

class ChessGame {
private:
    std::vector<std::vector<Piece *>> board;
    bool isWhiteTurn;
    int blackKingRow, blackKingCol;
    int whiteKingRow, whiteKingCol;

    char whosTurn() const;
    bool validateMove(int sourceRow, int sourceCol, int destRow, int destCol);
    bool isClearPath(int sourceRow, int sourceCol, int destRow, int destCol);
    bool isKingInCheck(char color);

public:
    ChessGame();
    ~ChessGame();
    unsigned int movePiece(const std::string &input);
    void displayBoard() const;
};

#endif // CHESS_CHESSGAME_H
