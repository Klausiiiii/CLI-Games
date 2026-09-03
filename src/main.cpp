#include <ncurses.h>
#include <cstdlib>
#include <ctime>

#include "games/snake/snake.h"

int main() {
	srand(time(nullptr));

	initscr();
	cbreak();
	noecho();
	curs_set(0);

	spieleSnake();

	endwin();

	return 0;
}
