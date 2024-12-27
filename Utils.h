#pragma once
#include <string>
using std::string;

class Utils
{
public:
	
	static int* fetchMove(string data)
	{
		int* coords = new int[4];
		int sourceX = 8 - (data[1] - '0');
		int sourceY = data[0] - 'a';
		int destinationX = 8 - (data[3] - '0');
		int destinationY = data[2] - 'a';
		coords[0] = sourceX;
		coords[1] = sourceY;
		coords[2] = destinationX;
		coords[3] = destinationY;
		return coords;
	}
};