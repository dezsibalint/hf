//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_FORRAS_H
#define ARAMKOR_FORRAS_H

#include "aramkorielem.h"
#include "iostream"
#include "stdexcept"

///Forrás osztály
///Kimenete beállítható 1re vagy 0ra felhasználó által
class forras: public aramkorielem{
public:

    ///Forrás konsturkor, 0 bemenettel,hiszen azt nem egy másik elem adja meg hanem a felhasználó,
    /// alapértelmezetten coutra ír és cin-ről olvas
    ///@param os: ostream referencia, alapértelmezett értéke std::cout
    ///@param is: istream referencia, alapértelmezett értéke std::cin
    forras(std::ostream &os=std::cout,std::istream &is=std::cin): aramkorielem(0,"Forras") {
        int be;
        os << "Bemenet:";
        if (be == 0 || be == 1) {//Typecheck
            is>>be;
            uzenet ou;
            ou.setval(be);
            setout(ou);
        } else throw std::invalid_argument("Nem megfelelő bemenet");//Kivétel dobás,ha nem megfelelő a bemenet
    }

    ///Forrás konstuktor a tesztekhe
    ///@param be: Forrás értékét beállítja.
    forras(int be):aramkorielem(0,"Forras"){
        if (be == 0 || be == 1) { //Typecheck
            uzenet ou;
            ou.setval(be);
            setout(ou);
        } else throw std::invalid_argument("Nem megfelelő bemenet");//Kivétel dobás,ha nem megfelelő a bemenet
    }

    ///Forrás kiírása
    ///@param os: ostream referencia, alapértelmezett értéke std::cout
  void print(std::ostream &os = std::cout) const override;
};


#endif //ARAMKOR_FORRAS_H
