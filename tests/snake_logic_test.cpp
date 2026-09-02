#include "games/snake/snake_logic.h"

#include <cassert>

int main() {
    SnakeSpiel spiel = starteSpiel(20, 40);
    spiel.futter.y = -1;
    spiel.futter.x = -1;

    int vorherX = spiel.kopf.x;
    schritt(spiel);

    assert(spiel.kopf.x == vorherX + 1);
    assert(spiel.kopf.y == 10);
    assert(spiel.verloren == false);
    assert(spiel.schlange.size() == 1);

    return 0;
}
