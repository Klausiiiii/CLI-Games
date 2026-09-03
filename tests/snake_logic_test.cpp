#include "games/snake/snake_logic.h"

#include <cassert>
#include <iostream>

int fehler = 0;

void pruefe(bool bedingung, const char* name) {
    if(!bedingung) {
        std::cout << "FEHLGESCHLAGEN: " << name << "\n";
        fehler = fehler + 1;
    }
}


int main() {
    // Check ob man bei einem schritt nach vorne läuft und die anfangsrichtung richtig ist
    SnakeSpiel spielCheckSchritt = starteSpiel(20, 40);
    spielCheckSchritt.futter.y = -1;
    spielCheckSchritt.futter.x = -1;

    int vorherX = spielCheckSchritt.kopf.x;
    schritt(spielCheckSchritt);

    pruefe(spielCheckSchritt.kopf.x == vorherX + 1, "Startrichtung rechts");
    pruefe(spielCheckSchritt.kopf.y == 10, "Nur nach rechts gelaufen");
    pruefe(spielCheckSchritt.verloren == false, "Nicht direkt verlieren");
    pruefe(spielCheckSchritt.schlange.size() == 1, "Schlange nicht gewachsen");


    // Check ob beim an die wand fahren man stirbt
    SnakeSpiel spielCheckVerloren = starteSpiel(10, 20);
    spielCheckVerloren.futter.y = -1;
    spielCheckVerloren.futter.x = -1;

    spielCheckVerloren.kopf.y = 5;
    spielCheckVerloren.kopf.x = 19;

    schritt(spielCheckVerloren);

    pruefe(spielCheckVerloren.verloren == true, "Spiel verloren wenn gegen wand gefahren");
    pruefe(spielCheckVerloren.kopf.y == 5, "Schlange immernoch auf gleicher hoehe");
    pruefe(spielCheckVerloren.kopf.x == 20, "Schlange nach vorne gegangen");


    // Check ob fressen die schlange wachsen lässt
    SnakeSpiel spielCheckEssen = starteSpiel(20, 40);
    spielCheckEssen.futter.y = 10;
    spielCheckEssen.futter.x = 21;
    spielCheckEssen.kopf.y = 10;
    spielCheckEssen.kopf.x = 20;
    spielCheckEssen.dy = 0;
    spielCheckEssen.dx = 1;

    std::size_t vorherLaenge = spielCheckEssen.laenge;
    schritt(spielCheckEssen);

    pruefe(spielCheckEssen.laenge == vorherLaenge + 1, "Schlange waechst wenn eine frucht gegessen wird");
    pruefe(spielCheckEssen.kopf.y == 10, "Hoehe gleich geblieben bei schritt nach rechts");
    pruefe(spielCheckEssen.kopf.x == 21, "Kopf hat sich auch bewegt");


    // Check ob bei einer schnellen tastenfolge die schlange in den eigenen schwanz fährt
    SnakeSpiel spielCheckQuickClick = starteSpiel(20,20);
    spielCheckQuickClick.futter.y = -1;
    spielCheckQuickClick.futter.x = -1;

    setzeRichtung(spielCheckQuickClick, -1, 0);
    setzeRichtung(spielCheckQuickClick, 0, -1);

    pruefe(spielCheckQuickClick.dy == -1 && spielCheckQuickClick.dx == 0, "Richtung ändert sich nicht ohne schritt zwischen eingabe");


    return fehler;
}
