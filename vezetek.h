//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_VEZETEK_H
#define ARAMKOR_VEZETEK_H
#include "aramkorielem.h"
#include "memtrace.h"

///Vezeték osztály
///Egyszerű a működése 1 bemenet 1 kimenet, ami a bemenetén van azt továbbítja a kimenetére.
class vezetek: public aramkorielem{
public:
    ///Konstruktor
    vezetek(): aramkorielem(1,"Vezetek"){} //Vezetéknek 1 bemenete van.

    ///Connect függvény
    ///@param mit Bemenet állapota
   void connect(uzenet &mit);///Amint csatlakoztatjuk kiküldi a kimenetére azt ami a bemenetén van.

   ///Print függvény
   ///@param os Hova írjuk ki
   void print(std::ostream &os = std::cout) const override;
};


#endif //ARAMKOR_VEZETEK_H
