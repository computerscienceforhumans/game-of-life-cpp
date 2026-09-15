#include "cell.hpp"

Cell::Cell(States starting_state)
{
	state = starting_state;
}

std::string Cell::display()
{
	return state_icons[state];
}

void Cell::kill()
{
	state = DEAD;
}

void Cell::revive()
{
	state = ALIVE;
}
