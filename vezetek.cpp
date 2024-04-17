//
// Created by dezsibalint on 2024.04.09..
//

#include "vezetek.h"

void vezetek::connect(uzenet &mit) {

        this->setout(mit);
}

void vezetek::print() const {
    std::cout<<"A vezeték bememenetének állapota: "<< this->getinput(0)<<" A vezeték kimenetének állapota: "<<this->getout()<<std::endl;

}