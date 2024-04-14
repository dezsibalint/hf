//
// Created by dezsibalint on 2024.04.10..
//

#include "invereter.h"

void invereter::connect(uzenet &mit, int hova) {
    {
        aramkorielem::connect(mit,0);
        uzenet u;
        u= getlaball(0);
        u.setval(!u.getval());
        setout(u);
    }
}