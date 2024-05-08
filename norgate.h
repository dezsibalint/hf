//
// Created by dezsibalint on 2024.04.10..
//

#ifndef ARAMKOR_NORGATE_H
#define ARAMKOR_NORGATE_H
#include "aramkorielem.h"
///Norgate osztály
///Nemvagy kapcsolatot valósít meg, felhasználó által megadott számú bemenettel.
class norgate:public aramkorielem {

public:
    ///Konstruktor
    ///@param bemenetek: a bemenetek száma
    norgate(int bemenetek): aramkorielem(bemenetek,"Norgate"){}

    ///Connect függvény
    ///@param mit: Bemenet beállítása
    ///@param hova: Bemenet sorszáma
    void connect(uzenet &mit, int hova) override;

    //Kiíró függvény
    void print(std::ostream &os = std::cout) const override;
};


#endif //ARAMKOR_NORGATE_H
