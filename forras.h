//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_FORRAS_H
#define ARAMKOR_FORRAS_H

#include "aramkorielem.h"
#include "iostream"
#include "memtrace.h"
class forras: public aramkorielem{
public:
    forras(): aramkorielem(0,"forras"){ ///A forrásnak nincs áramköri bemenete csak kimenete,mi állítjuk be az értékét
        std::cout<<"Bemenet:";
        bool be;
        std::cin>>be;
        uzenet ou;
        ou.setval(be);
        setout(ou);
    }
    void print() const override;
};


#endif //ARAMKOR_FORRAS_H
