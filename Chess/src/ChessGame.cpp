//
// Created by Dor Shukrun on 18/07/2024.
//

#include "ChessGame.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"
#include <iostream>

char BLACK = 'b';
char WHITE = 'w';

ChessGame::ChessGame() {
    this->isWhiteTurn = true;

    for (int row = 0; row < 8; row++) {
        std::vector<Piece *> boardRow;
        for (int col = 0; col < 8; col++) {
            boardRow.push_back(nullptr);
        }
        board.push_back(boardRow);
    }
    this->whiteKingRow = 0;
    this->whiteKingCol = 4;
    this->blackKingRow = 7;
    this->blackKingCol = 4;

    board[0][0] = new Rook(WHITE);
    board[0][7] = new Rook(WHITE);
    board[0][2] = new Bishop(WHITE);
    board[0][5] = new Bishop(WHITE);
    board[0][4] = new King(WHITE);
    board[0][3] = new Queen(WHITE);


    board[7][0] = new Rook(BLACK);
    board[7][7] = new Rook(BLACK);
    board[7][2] = new Bishop(BLACK);
    board[7][5] = new Bishop(BLACK);
    board[7][4] = new King(BLACK);
    board[7][3] = new Queen(BLACK);


}

ChessGame::~ChessGame() {
    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            delete board[row][col];
        }
    }
}

bool ChessGame::isClearPath(const Point& source, const Point& dest) {
    int rowStep = (source.getRow() == dest.getRow()) ? 0 : (dest.getRow() > source.getRow() ? 1 : -1);
    int colStep = (source.getCol() == dest.getCol()) ? 0 : (dest.getCol() > source.getCol() ? 1 : -1);

    int currentRow = source.getRow() + rowStep;
    int currentCol = source.getCol() + colStep;

    while (currentRow != dest.getRow() || currentCol != dest.getCol()) {
        if (board[currentRow][currentCol] != nullptr) {
            return false;
        }
        currentRow += rowStep;
        currentCol += colStep;
    }
    return true;
}

bool ChessGame::validateMove(const Point& source, const Point& dest) {
    if (board[source.getRow()][source.getCol()] == nullptr) {
        return false;
    } else if ((board[source.getRow()][source.getCol()]->getColor() == 'w' && !this->isWhiteTurn) ||
               (board[source.getRow()][source.getCol()]->getColor() == 'b' && this->isWhiteTurn)) {
        return false;
    } else if (board[dest.getRow()][dest.getCol()] != nullptr &&
               ((board[dest.getRow()][dest.getCol()]->getColor() == 'w' && this->isWhiteTurn) ||
                (board[dest.getRow()][dest.getCol()]->getColor() == 'b' && !this->isWhiteTurn))) {
        return false;
    } else if (!board[source.getRow()][source.getCol()]->validateMove(source, dest, board)) {
        return false;
    }
    return isClearPath(source, dest);
}

bool ChessGame::isKingInCheck(char color) {
    int kingRow, kingCol;
    if (color == 'w') {
        kingRow = whiteKingRow;
        kingCol = whiteKingCol;
    } else {
        kingRow = blackKingRow;
        kingCol = blackKingCol;
    }
    Point kingPos(kingRow, kingCol);

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row][col] != nullptr && board[row][col]->getColor() != color) {
                Point currentPos(row, col);
                if (board[row][col]->validateMove(currentPos, kingPos, board)) {
                    return true;
                }
            }
        }
    }
    return false;
}

unsigned int ChessGame::movePiece(const std::string &input) {
    Point source(input[0] - 'a', input[1] - '1');
    Point dest(input[2] - 'a', input[3] - '1');

    if (!validateMove(source, dest)) {
        return 21; // Illegal movement of that piece
    }

    Piece *movingPiece = board[source.getRow()][source.getCol()];
    Piece *capturedPiece = board[dest.getRow()][dest.getCol()];
    board[dest.getRow()][dest.getCol()] = movingPiece;
    board[source.getRow()][source.getCol()] = nullptr;

    char currentTurnColor = whosTurn();
    if (isKingInCheck(currentTurnColor)) {
        board[source.getRow()][source.getCol()] = movingPiece;
        board[dest.getRow()][dest.getCol()] = capturedPiece;
        return 31; // This movement will cause checkmate
    }

    delete capturedPiece;
    isWhiteTurn = !isWhiteTurn;
    return 42; // Legal movement
}

void ChessGame::displayBoard() const {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; col < 8; ++col) {
            if (board[row][col] == nullptr) {
                std::cout << ". ";
            } else {
                std::cout << board[row][col]->getPieceSymbol() << " ";
            }
        }
        std::cout << std::endl;
    }
}

char ChessGame::whosTurn() const {
    return this->isWhiteTurn ? 'w' : 'b';
}
