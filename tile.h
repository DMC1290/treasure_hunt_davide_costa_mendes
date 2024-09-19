#ifndef TILE_H
#define TILE_H
#include <iostream>

enum class TileState // il est jamais content resharper :(
{
	kNotDig,
	kEmpty,
	kTreasure
};


class Tile
{

public:
	TileState state_;

	void displayState()
	{
		switch (state_)
		{
		case TileState::kNotDig:
			std::cout << " ? "; // Is there something ? :|
			break;
		case TileState::kEmpty:
			std::cout << " x "; // This is empty. :(
			break;
		case TileState::kTreasure:
			std::cout << " $ "; // You found the treasure! :)
			break;
		}
	}
};


#endif