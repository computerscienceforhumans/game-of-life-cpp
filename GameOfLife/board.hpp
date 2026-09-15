#pragma once
#include <vector>
#include <string>
#include "cell.hpp"

class Board {
public:
	std::vector<std::vector<Cell>> cells;

	Board(int width, int height, std::vector<std::vector<int>> start_living);

	std::string display();

	Cell* get_cell(int x, int y);

	std::vector<Cell*> get_neighbors(int x, int y);

	Board do_turn();
	int count_living_neighbors(int x, int y);
};