//
// Created by dezsibalint on 2024.04.10..
//

#include "invereter.h"

void invereter::connect(uzenet &mit, int hova) {
    {
        aramkorielem::connect(mit,0);
        uzenet u;
        u= getinput(0);
        u.setval(!u.getval());
        setout(u);
    }
}

void invereter::print() const {
   std::cout<<"Az inverter bememenetének állapota: "<< this->getinput(0)<<" Az inverter kimenetének állapota: "<<this->getout()<<std::endl;
}

