#include <iostream>
#include <array>
#include "map.h"
#include "tile.h"
#include "treasure.h"
// :D

int main()
{
	std::array<Tile, kRowSize* kColSize> map{};

	for (int idx = 0; idx < kRowSize * kColSize; ++idx)
	{
		map[idx].state_ = TileState::kNotDig;
	}

	int treasureIndex = random_number();

	while (true)
	{
		std::cout << "Enter a row between 1 and " << kColSize << " :";
		int row;
		while (!(std::cin >> row) || row < 1 || row > 5)
		{
			std::cout << "Invalid row. Please enter a value between 1 and 5 :";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		std::cout << "Enter a column between 1 and " << kColSize << " :";
		int col;
		while (!(std::cin >> col) || col < 1 || col > 5)
		{
			std::cout << "Invalid column. Please enter a value between 1 and 5 :";
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		}

		int idx = (row - 1) * kColSize + (col - 1);

		if (idx == treasureIndex)
		{
			map[idx].state_ = TileState::kTreasure;
			std::cout << "You found the treasure!" << '\n';

			displayMap(map);

			return EXIT_SUCCESS;

		}
		else
		{
			map[idx].state_ = TileState::kEmpty;
			std::cout << "Try again :)" << '\n';

			displayMap(map);

		}


		char playAgain;
		std::cout << "Play again ? (y/n): ";
		std::cin >> playAgain;

		if (playAgain == 'n')
		{
			break;
		}

	}

	return 0;
}
//voir rejouabilité :)