#ifndef MAP_H
#define MAP_H
#include <iostream>
#include "tile.h"


constexpr int kRowSize = 5;
constexpr int kColSize = 5;


void displayMap
(
	std::array<Tile, kRowSize * kColSize >& map,
	std::array<bool, kRowSize * kColSize >& treasure_map
);



#endif