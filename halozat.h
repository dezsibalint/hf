//
// Created by dezsibalint on 2024.04.17..
//

#ifndef ARAMKOR_HALOZAT_H
#define ARAMKOR_HALOZAT_H
#include "aramkorielem.h"

class halozatitarolo {
    aramkorielem* elem;
public:
    halozatitarolo():elem(NULL){}
    void add(aramkorielem*a){elem=a;}
    aramkorielem*get()const{return elem;}
    void conn(aramkorielem *kit, int hova){
        if(elem!=NULL&& elem->inputdb()>0) elem->connect(kit->out(),hova);
    }

    void print()const {elem->print();}
~halozatitarolo(){if(elem!=NULL)delete elem;}
};



#endif //ARAMKOR_HALOZAT_H
