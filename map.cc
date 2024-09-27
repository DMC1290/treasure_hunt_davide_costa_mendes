#include "map.h"

#include <array>


void displayMap
(
	std::array<Tile, kRowSize * kColSize>& map,
	std::array<bool, kRowSize * kColSize>& treasure_map
)

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
			if (treasure_map[idx])
			{
				map[idx].state_ = TileState::kTreasure;
			}

			map[idx].DisplayState();
			std::cout << "\t";
		}
		std::cout << "\n\n";
	}
}
