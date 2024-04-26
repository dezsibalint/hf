//
// Created by dezsibalint on 2024.03.30..
//

#include "aramkorielem.h"
#include "stdexcept"
void aramkorielem::setout(uzenet &to_out) {
    kimenet=to_out;
}

uzenet &aramkorielem::out() {
    return kimenet;
}

void aramkorielem::connect(uzenet &mit, int hova) {
    //Létezik-e a láb
    if(hova>bemenetekszama) throw std::invalid_argument("Nincs ilyen bemenet!");
    bemenetek[hova]=mit;//Bemenet beállítása
}

uzenet aramkorielem::getinput(int hanyas)const {
        return bemenetek[hanyas];
}
