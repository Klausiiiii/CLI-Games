#include "snake_logic.h"
#include <cstdlib>
#include <vector>


bool trifft(Punkt p, const std::vector<Punkt>& liste) {
	for(Punkt s : liste) {
		if(s.y == p.y && s.x == p.x) {
			return true;
		}
	}
	return false;
}

Punkt zufallsPunkt(int hoehe, int breite, const std::vector<Punkt>& liste) {
	Punkt p;
	do {
		p.y = rand() % hoehe;
		p.x = rand() % breite;
	} while (trifft(p, liste));
	return p;
}

SnakeSpiel starteSpiel(int hoehe, int breite) {
    SnakeSpiel spiel;
    spiel.hoehe = hoehe;
    spiel.breite = breite;
    spiel.kopf.y = hoehe / 2;
    spiel.kopf.x = breite / 2;
    spiel.futter = zufallsPunkt(hoehe, breite, spiel.schlange);
    return spiel;
}

void schritt(SnakeSpiel& spiel) {
    spiel.kopf.y = spiel.kopf.y + spiel.dy;
    spiel.kopf.x = spiel.kopf.x + spiel.dx;

    if(spiel.kopf.y < 0 || spiel.kopf.y > spiel.hoehe - 1 ||
       spiel.kopf.x < 0 || spiel.kopf.x > spiel.breite - 1) {
        spiel.verloren = true;
        return;
    }

    if(trifft(spiel.kopf, spiel.schlange)) {
        spiel.verloren = true;
    }

    if(spiel.verloren) { return; }


    // Aktualisierung
    spiel.schlange.insert(spiel.schlange.begin(), spiel.kopf);

    // futter essen check
    if(spiel.kopf.y == spiel.futter.y && spiel.kopf.x == spiel.futter.x) {
        spiel.laenge = spiel.laenge + 1;
        spiel.futter = zufallsPunkt(spiel.hoehe, spiel.breite, spiel.schlange);
    }

    while(spiel.schlange.size() > spiel.laenge) {
        spiel.schlange.pop_back();
    }
}

void setzeRichtung(SnakeSpiel& spiel, int dy, int dx) {
    spiel.dy = dy;
    spiel.dx = dx;
}
