// Chess
#include "Chess.h"
#include "ChessGame.h"


int main()

{
	string board = "R#BQKB#R################################################r#bqkb#r";
	//string board = "R######R################################################r######r";
	Chess a(board);
	int codeResponse = 0;
	string res = a.getInput();
    ChessGame game;
	while (res != "exit")
	{
		/*
		codeResponse value :
		Illegal movements :
		11 - there is not piece at the source
		12 - the piece in the source is piece of your opponent
		13 - there one of your pieces at the destination
		21 - illegal movement of that piece
		31 - this movement will cause you checkmate

		legal movements :
		41 - the last movement was legal and cause check
		42 - the last movement was legal, next turn
		*/

		/**/
		{ // put your code here instead that code
            codeResponse = game.movePiece(res);
		}
		/**/

		a.setCodeResponse(codeResponse);
		res = a.getInput();
	}

	cout << endl << "Exiting " << endl;
	return 0;
}