#include "games/snake/snake.h"
#include "games/snake/snake_logic.h"

#include <ncurses.h>
#include <vector>
#include <chrono>

void spieleSnake() {
    timeout(10);

    int hoehe = 0;
	int breite = 0;
	getmaxyx(stdscr, hoehe, breite);

	SnakeSpiel spiel = starteSpiel(hoehe, breite);

    const auto takt = std::chrono::milliseconds(100);
    auto letzterZug = std::chrono::steady_clock::now();

    while(true) {
		// Eingabe
		int taste = getch();
		if(taste == 'q') {
			break;
		}

		if(taste == 'w') {
			setzeRichtung(spiel, -1, 0);
		}

		if(taste == 'a') {
			setzeRichtung(spiel, 0, -1);
		}

		if(taste == 's') {
			setzeRichtung(spiel, 1, 0);
		}

		if(taste == 'd') {
			setzeRichtung(spiel, 0, 1);
		}

		auto jetzt = std::chrono::steady_clock::now();

        if(jetzt - letzterZug >= takt) {
            letzterZug = jetzt;

            schritt(spiel);
            erase();

            for(Punkt p : spiel.schlange) {
                mvaddch(p.y, p.x, '0');
            }
            mvaddch(spiel.kopf.y, spiel.kopf.x, '#');
            mvaddch(spiel.futter.y, spiel.futter.x, '*');

            refresh();

            if(spiel.verloren) { break; }
        }
	}

	// End programm
	timeout(-1);
	mvprintw(spiel.hoehe / 2, 10, "Game Over! Laenge: %zu", spiel.laenge);
	refresh();
	getch();
}
