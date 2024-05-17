//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_VEZETEK_H
#define ARAMKOR_VEZETEK_H
#include "aramkorielem.h"

///Vezeték osztály
///Egyszerű a működése 1 bemenet 1 kimenet, ami a bemenetén van azt továbbítja a kimenetére.
class vezetek: public aramkorielem{
public:
    ///Konstruktor
    vezetek(): aramkorielem(1,"Vezetek"){} //Vezetéknek 1 bemenete van.

    ///Connect függvény
    ///@param mit Bemenet állapota
    ///@paragram hova Így overrideolható,nincs jelentősége mert egy vezetéknek csak 1 bemenete van.
   void connect(uzenet &mit,int hova=0)override;///Amint csatlakoztatjuk kiküldi a kimenetére azt ami a bemenetén van.

   ///Print függvény
   ///@param os Hova írjuk ki
   void print(std::ostream &os = std::cout) const override;
};


#endif //ARAMKOR_VEZETEK_H
