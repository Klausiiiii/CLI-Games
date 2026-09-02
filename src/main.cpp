#include <ncurses.h>
#include <vector>
#include <cstdlib>
#include <ctime>

#include "games/snake/snake_logic.h"

int main() {
	srand(time(nullptr));


	initscr();
	cbreak();
	noecho();
	curs_set(0);
	timeout(100);

	int hoehe = 0;
	int breite = 0;
	getmaxyx(stdscr, hoehe, breite);

	SnakeSpiel spiel = starteSpiel(hoehe, breite);

	while(true) {

		// Eingabe
		int taste = getch();
		if(taste == 'q') {
			spiel.verloren = true;
		}

		if(taste == 'w' && spiel.dy != 1) {
			setzeRichtung(spiel, -1, 0);
		}

		if(taste == 'a' && spiel.dx != 1) {
			setzeRichtung(spiel, 0, -1);
		}

		if(taste == 's' && spiel.dy != -1) {
			setzeRichtung(spiel, 1, 0);
		}

		if(taste == 'd' && spiel.dx != -1) {
			setzeRichtung(spiel, 0, 1);
		}

		schritt(spiel);

		erase();

		for(Punkt p : spiel.schlange) {
			mvaddch(p.y, p.x, '0');
		}
		mvaddch(spiel.futter.y, spiel.futter.x, '*');

		refresh();


		if(spiel.verloren) { break; }
	}

	// End programm
	timeout(-1);
	mvprintw(spiel.hoehe / 2, 10, "Game Over! Laenge: %zu", spiel.laenge);
	refresh();
	getch();
	endwin();

	return 0;
}
