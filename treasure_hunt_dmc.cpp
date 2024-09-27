#include <iostream>
#include <array>
#include "map.h"
#include "tile.h"
#include "treasure.h"
// :D

int main()
{
	std::array<Tile, kRowSize* kColSize> map{};
	std::array<bool, kRowSize* kColSize> treasure_map{};

	for (int idx = 0; idx < kRowSize * kColSize; ++idx)
	{
		map[idx].state_ = TileState::kNotDig;
		treasure_map[idx] = false;
	}

	int treasureIndex = random_number();
	treasure_map[treasureIndex] = true;

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

		int idx = (row -1) * kColSize + (col - 1);

		if (treasure_map[idx])
		{
			map[idx].state_ = TileState::kTreasure;
			std::cout << "You found the treasure!" << '\n';
		}
		else
		{
			map[idx].state_ = TileState::kEmpty;
			std::cout << "Try again :)" << '\n';
		}

		std::cout << '\n';
		displayMap(map, treasure_map);

		char playAgain;
		std::cout << "Play again ? (y/n): ";
		std::cin >> playAgain;

		if (playAgain == 'n')
		{
			break;
		}
		else if (playAgain == 'y')
		{
			return main();
		}

		else
		{
			std::cout << "What are you tryng to do?";

			return playAgain;
		}


	}

	std::cout << '\n';
	displayMap(map, treasure_map);

	return 0;
}
//voir rejouabilité :)