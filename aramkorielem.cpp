//
// Created by dezsibalint on 2024.03.30..
//

#include "aramkorielem.h"

void aramkorielem::setout(uzenet &to_out) {
    kimenet=to_out;
}

uzenet &aramkorielem::out() {
    return kimenet;
}

void aramkorielem::connect(uzenet &mit, int hova) {
    if(hova>=labakszama) throw "Nem létező láb";
    bemenetek[hova]=mit;
}

uzenet aramkorielem::getlaball(int hanyas)const {
        return bemenetek[hanyas];
}