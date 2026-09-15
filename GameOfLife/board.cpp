#include <iostream>
#include "board.hpp"


Board::Board(int width, int height, std::vector<std::vector<int>> start_living)
{
	for (int y = 0; y < height; y++)
	{
		cells.push_back(std::vector<Cell>());
		for (int x = 0; x < width; x++)
		{
			cells[y].push_back(Cell(Cell::DEAD));
		}
	}

	for (std::vector<int> coord : start_living)
	{
		Cell* live_me = get_cell(coord[0], coord[1]);
		live_me->revive();
	}
}

Board Board::do_turn()
{
	std::vector<std::vector<int>> updated_living = {};
	for (int y = 0; y < cells.size(); y++)
	{
		for (int x = 0; x < cells[0].size(); x++) {
			int living = count_living_neighbors(x, y);
			Cell* cur_cell = get_cell(x, y);
			switch (cur_cell->state)
			{
				case Cell::DEAD:
					if (living == 3)
					{
						updated_living.push_back({ x, y });
					}
					break;
				case Cell::ALIVE:
					if (living >= 2 && living <= 3)
					{
						updated_living.push_back({ x, y });
					}
					break;
				default:
					break;
			}
		}
	}

	return Board(static_cast<int>(cells[0].size()), static_cast<int>(cells.size()), updated_living);
}

int Board::count_living_neighbors(int x, int y)
{
	Cell* cur_cell = get_cell(x, y);
	std::vector<Cell*> cur_neighbors = get_neighbors(x, y);

	int alive_neighbors = 0;
	for (Cell* neighbor : cur_neighbors)
	{
		if (neighbor->state == Cell::ALIVE)
		{
			alive_neighbors++;
		}
	}
	return alive_neighbors;
}

std::string Board::display()
{
	std::string show_me = "";
	for (std::vector<Cell> row : cells)
	{
		for (Cell cell : row)
		{
			show_me += " " + cell.display();
		}
		show_me += "\n";
	}
	
	return show_me;
}

Cell* Board::get_cell(int x, int y)
{
	return &cells[y][x];
}

std::vector<Cell*> Board::get_neighbors(int x, int y)
{
	if (
		x < 0 ||
		y < 0 ||
		x >= cells[0].size() ||
		y >= cells.size()
	) {
		return {};
	}

	std::vector<std::vector<int>> neighbor_coords = {
		{x + 1, y + 1},
		{x, y + 1},
		{x - 1, y + 1},
		{x + 1, y},
		{x - 1, y},
		{x + 1, y - 1},
		{x, y - 1},
		{x - 1, y - 1},
	};

	std::vector<Cell*> neighbor_list = {};
	for (std::vector<int> coord : neighbor_coords)
	{
		if
		(
			coord[0] < 0 ||
			coord[1] < 0 ||
			coord[0] >= cells[0].size() ||
			coord[1] >= cells.size()
		)
		{
			continue;
		}
		neighbor_list.push_back(get_cell(coord[0], coord[1]));
	}


	return neighbor_list;
}

