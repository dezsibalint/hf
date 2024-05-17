//
// Created by dezsibalint on 2024.04.17..
//

#ifndef ARAMKOR_HALOZAT_H
#define ARAMKOR_HALOZAT_H
#include "aramkorielem.h"
///Hálózat tároló osztály
///Heterogén kollekcióhoz,aramkorielem pointert tárol.
///Belőlle lehet tömböt csinálni,közvetlenül aramkorielem-ből nem,mert az absztakt osztály.
class halozatitarolo {
    aramkorielem* elem;
public:
    ///konstruktor alapértelmezetten NULL-ra állítja az elemet
    halozatitarolo():elem(NULL){}

    ///Áramköri elem hozzáadása
    ///@param a: Hozzáadandó áramköri elem
    void add(aramkorielem*a){elem=a;}

    ///Visszaadja az elemet
    ///@return elem
    aramkorielem*get()const{return elem;}

    ///Csatlakoztatja az elemet
    ///@param kit: Csatlakoztatandó elem
    ///@param hova: Hanyas lábra csatlakoztassuk
    void conn(aramkorielem *kit, int hova);

    ///Kiírja az eleme be és kimenet(eit) coutra
    void print()const {std::cout<<"A hálózat kimenete: "<< elem->getout();}

    ///Tárolt elem kimenetének beállítása
    ///@param val:Kimenet értéke.
    void set(int val);

    ///Destruktor
   ~halozatitarolo(){delete elem;}
};



#endif //ARAMKOR_HALOZAT_H
