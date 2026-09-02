#pragma once
#include <vector>

struct Punkt {
    int y;
    int x;
};

struct SnakeSpiel {
    std::vector<Punkt> schlange;
    Punkt kopf;
    Punkt futter;
    int dy = 0;
    int dx = 1;
    std::size_t laenge = 5;
    int hoehe = 0;
    int breite = 0;
    bool verloren = false;
};

SnakeSpiel starteSpiel(int hoehe, int breite);
void setzeRichtung(SnakeSpiel& spiel, int dy, int dx);
void schritt(SnakeSpiel& spiel);

bool trifft(Punkt p, const std::vector<Punkt>& liste);
Punkt zufallsPunkt(int hoehe, int breite, const std::vector<Punkt>& liste);
