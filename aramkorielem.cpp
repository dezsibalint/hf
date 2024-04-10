//
// Created by dezsibalint on 2024.03.30..
//

#include "aramkorielem.h"

void aramkorielem::connect(aramkorielem&mit, int hova) {
    if(hova>=labakszama) throw "Nem létező láb";
    allapot[hova]=mit.allapot[mit.labakszama-1];
}