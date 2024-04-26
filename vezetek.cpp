//
// Created by dezsibalint on 2024.04.09..
//

#include "vezetek.h"

///Vezeték kimenetének beállítása
void vezetek::connect(uzenet &mit) {
    this->setout(mit);//Csatlakoztatáskor a kimenet értékét beállítjuk a bemenet értékére.
}

void vezetek::print(std::ostream&os) const {
    os<<"A vezeték bememenetének állapota: "
    << this->getinput(0)<<" A vezeték kimenetének állapota: "
    <<this->getout()<<std::endl;
}