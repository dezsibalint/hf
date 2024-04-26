//
// Created by dezsibalint on 2024.04.10..
//

#include "invereter.h"

void invereter::connect(uzenet &mit, int hova) {
    {
        if(hova!=0) throw std::invalid_argument("Inverternek csak egy bemenete van!");//Ha nem 0ás bemenetre akarunk kötni akkor kivételt dobunk. ű
                                                                                     // Mivel az inverternek csak egy bemenete van.
        aramkorielem::connect(mit,0);
        uzenet u;
        u= getinput(0);
        u.setval(!u.getval()); //Negáljuk a bemenetet
        setout(u);
    }
}

void invereter::print(std::ostream&os) const {
   os<<"Az inverter bememenetének állapota: "
   << this->getinput(0)
   <<" Az inverter kimenetének állapota: "<<this->getout()<<std::endl;
}

