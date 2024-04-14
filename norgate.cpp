//
// Created by dezsibalint on 2024.04.10..
//

#include "norgate.h"

void norgate::connect(uzenet &mit, int hova) {
    aramkorielem::connect(mit,hova);
    uzenet u;
    u.setval(true);
    setout(u);
    for (int i = 0; i < getlab(); ++i) {
        if(getlaball(i).isdefined()&& getlaball(i).getval()) {
            uzenet out;
            out.setval(false);
            setout(out);
            return;
        }
    }


}
