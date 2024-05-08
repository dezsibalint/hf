//
// Created by dezsibalint on 2024.04.10..
//

#ifndef ARAMKOR_INVERETER_H
#define ARAMKOR_INVERETER_H
#include "aramkorielem.h"

///Inverter osztály
///Egy db bemenete van,kimenetén a bemenet negált értékét adja vissza.
class invereter: public aramkorielem{

public:
    ///Konstruktor
    invereter(): aramkorielem(1,"Inverter"){} //Inverternek csak 1 bemenete van

    ///Connect függvény
    ///@param mit Bemeneten lévő jel
    ///@param hova Inverternek csak egy bemenete van így meg se kell adni,mert alapértelmezetten a 0ás bemenetre kötjük.
    void connect(uzenet &mit, int hova=0) override;

    ///Kiírás
    ///@param os Kimenet stream
    void print(std::ostream &os = std::cout) const override;
};

#endif //ARAMKOR_INVERETER_H
