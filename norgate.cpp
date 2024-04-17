//
// Created by dezsibalint on 2024.04.10..
//

#include "norgate.h"

void norgate::connect(uzenet &mit, int hova) {
    aramkorielem::connect(mit,hova);
    uzenet u;
    u.setval(true);
    setout(u);
    for (int i = 0; i < inputdb(); ++i) {
        if(getinput(i).isdefined()&& getinput(i).getval()) {
            uzenet out;
            out.setval(false);
            setout(out);
            return;
        }
    }

}

void norgate::print() const {
    for (int i = 0; i < inputdb(); ++i) {
        std::cout<<"A norkapu"<<i+1<< ".bememenetének állapota: "<< this->getinput(i)<<std::endl;
    }
    std::cout<<"A norkpu kimenetének állapota: "<<this->getout()<<std::endl;

}
