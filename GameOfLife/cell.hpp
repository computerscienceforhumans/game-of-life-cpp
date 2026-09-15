#pragma once
#include <string>
#include <vector>

class Cell {
public:
	enum States {
		DEAD,
		ALIVE
	};

	States state = DEAD;
	std::vector<std::string> state_icons = { "-", "O" };

	Cell(States starting_state);
	std::string display();

	void kill();
	void revive();
};