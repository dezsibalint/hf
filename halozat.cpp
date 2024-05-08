//
// Created by dezsibalint on 2024.04.17..
//

#include "halozat.h"

void halozatitarolo::conn(aramkorielem *kit, int hova) {
    if(elem!=NULL&& elem->inputdb()>0) elem->connect(kit->out(),hova);//Ha nem 0 és van bemenete csatlakoztatunk a bemenetére.
}