//
// Created by Dor Shukrun on 18/07/2024.
//

#include <iostream>
#include "ChessGame.h"
#include "Rook.h"
#include "King.h"
#include "Bishop.h"
#include "Queen.h"

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

bool ChessGame::isClearPath(int sourceRow, int sourceCol, int destRow, int destCol) {
    int rowStep = (sourceRow == destRow) ? 0 : (destRow > sourceRow ? 1 : -1);
    int colStep = (sourceCol == destCol) ? 0 : (destCol > sourceCol ? 1 : -1);

    int currentRow = sourceRow + rowStep;
    int currentCol = sourceCol + colStep;

    while (currentRow != destRow || currentCol != destCol) {
        if (board[currentRow][currentCol] != nullptr) {
            return false;
        }
        currentRow += rowStep;
        currentCol += colStep;
    }
    return true;
}

bool ChessGame::validateMove(int sourceRow, int sourceCol, int destRow, int destCol) {
    if (board[sourceRow][sourceCol] == nullptr) {
        return false;
    } else if ((board[sourceRow][sourceCol]->getColor() == 'w' && !this->isWhiteTurn) ||
               (board[sourceRow][sourceCol]->getColor() == 'b' && this->isWhiteTurn)) {
        return false;
    } else if (board[destRow][destCol] != nullptr &&
               ((board[destRow][destCol]->getColor() == 'w' && this->isWhiteTurn) ||
                (board[destRow][destCol]->getColor() == 'b' && !this->isWhiteTurn))) {
        return false;
    } else if (!board[sourceRow][sourceCol]->validateMove(sourceRow, sourceCol, destRow, destCol, board)) {
        return false;
    }
    return isClearPath(sourceRow, sourceCol, destRow, destCol);
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

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            if (board[row][col] != nullptr && board[row][col]->getColor() != color) {
                if (board[row][col]->validateMove(row, col, kingRow, kingCol, board)) {
                    return true;
                }
            }
        }
    }
    return false;
}

unsigned int ChessGame::movePiece(const std::string &input) {
    int sourceRow = input[0] - 'a';
    int sourceCol = input[1] - '1';
    int destRow = input[2] - 'a';
    int destCol = input[3] - '1';

    if (!validateMove(sourceRow, sourceCol, destRow, destCol)) {
        return 21;
    }

    Piece *movingPiece = board[sourceRow][sourceCol];
    Piece *capturedPiece = board[destRow][destCol];
    board[destRow][destCol] = movingPiece;
    board[sourceRow][sourceCol] = nullptr;

    char currentTurnColor = whosTurn();
    if (isKingInCheck(currentTurnColor)) {
        board[sourceRow][sourceCol] = movingPiece;
        board[destRow][destCol] = capturedPiece;
        return 31;
    }

    delete capturedPiece;
    isWhiteTurn = !isWhiteTurn;
    return 42;
}

void ChessGame::displayBoard() const {
    for (int row = 0; row < 8; ++row) {
        for (int col = 0; ;++col) {
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
