#include "Pipe.h"
#include "Engine.h"
#include <iostream>
#include <thread>
#include <windows.h>

using std::cout;
using std::endl;
using std::string;

void main2()
{
	srand(time_t(NULL));

	system("start chessGraphics.exe");
	Sleep(600);

	
	Pipe p;
	bool isConnect = p.connect();
	
	string ans;
	while (!isConnect)
	{
		cout << "Cannot find an instance of ChessGraphics" << endl;
		cout << "Try to connect again or exit? (0-try again, 1-exit)" << endl;
		std::cin >> ans;

		if (ans == "0")
		{
			cout << "Trying to connect again..." << endl;
			Sleep(5000);
			isConnect = p.connect();
		}
		else
		{
			p.close();
			return;
		}
	}
	
	char msgToGraphics[1024];

	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0");
	
	Engine e(msgToGraphics);
	p.sendMessageToGraphics(msgToGraphics);   // send the board string

	// get message from graphics
	string msgFromGraphics = p.getMessageFromGraphics();

	while (msgFromGraphics != "quit")
	{
		char* code = e.getCode(msgFromGraphics);
		strcpy_s(msgToGraphics, code);
		
		if (code[0] == '0' || code[0] == '1' || code[0] == '8')
		{
			e.movePiece(msgFromGraphics);
			e.setCurrPlayer(e.getCurrPlayer() == WHITE ? BLACK : WHITE);
		}
		// return result to graphics
		p.sendMessageToGraphics(msgToGraphics);

		// get message from graphics
		msgFromGraphics = p.getMessageFromGraphics();
	}

	p.close();
}