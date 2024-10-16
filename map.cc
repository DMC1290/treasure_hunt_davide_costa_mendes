#include "map.h"

#include <array>


void displayMap(std::array<Tile, kRowSize* kColSize>& map)

{
	std::cout << "  ";

	for (int j = 0; j < kRowSize; ++j)
	{
		std::cout << " " << j + 1 << "\t";
	}

	std::cout << "\n";

	for (int i = 0; i < kColSize; ++i)
	{
		char RowLetter = 'A' + i;
		std::cout << RowLetter << " ";

		for (int j = 0; j < kColSize; ++j)
		{
			int idx = i * kColSize + j;
			map[idx].DisplayState();
			std::cout << "\t";
		}
		std::cout << "\n\n";
	}
}