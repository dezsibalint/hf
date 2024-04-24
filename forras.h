//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_FORRAS_H
#define ARAMKOR_FORRAS_H

#include "aramkorielem.h"
#include "iostream"
#include "memtrace.h"
#include "stdexcept"
class forras: public aramkorielem{
public:
    forras(std::ostream &os=std::cout,std::istream &is=std::cin): aramkorielem(0,"Forras") { ///A forrásnak nincs áramköri bemenete csak kimenete,mi állítjuk be az értékét
        int be;
        os << "Bemenet:";


        if (be == 0 || be == 1) {
            is>>be;
            uzenet ou;
            ou.setval(be);
            setout(ou);
        } else throw std::invalid_argument("Nem megfelelő bemenet");
    }
    forras(int be):aramkorielem(0,"Forras"){
        if (be == 0 || be == 1) {
            uzenet ou;
            ou.setval(be);
            setout(ou);
        } else throw std::invalid_argument("Nem megfelelő bemenet");
    }
  void print(std::ostream &os = std::cout) const override;
};


#endif //ARAMKOR_FORRAS_H
