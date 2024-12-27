#include "Engine.h"

using std::cout;
using std::endl;
using std::string;


int main()
{
	char msgToGraphics[1024];
	string input;

	strcpy_s(msgToGraphics, "rnbqkbnrpppppppp################################PPPPPPPPRNBQKBNR0");
	Engine e(msgToGraphics);

	std::cout << "\n" << (e.getCurrPlayer() == 'w' ? "White" : "Black") << " to move." << std::endl;
	std::cout << "Enter move (e.g. e2e4): ";
	std::cin >> input;

	while (input != "quit")
	{
		system("cls");
		e.getCode(input);

		std::cout << "\n" << (e.getCurrPlayer() == 'w' ? "White" : "Black") << " to move." << std::endl;
		std::cout << "Enter move (e.g. e2e4): ";
		std::cin >> input;
	}
	return 0;
}