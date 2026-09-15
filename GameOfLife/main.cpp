#include <iostream>
#include "board.hpp"
//#include "cell.hpp"


int main() {


	Board board = Board(10, 10, std::vector<std::vector<int>> {
		{
			3, 3
		},
		{
			4, 4
		},
		{
			4, 5
		},
		{
			3, 5
		},
		{
			2, 5
		}
	});
	std::cout << board.display() << "\n----------------\n\n";

	while (true)
	{
		std::cout << "\nPress enter to continue, or type anything then press enter to quit...\n";
		std::string line;
		std::getline(std::cin, line);
		if (line.size() > 0) {
			return 0;
		}

		board = board.do_turn();
		std::cout << board.display() << "\n----------------\n\n";
	}
	
	return 0;
}