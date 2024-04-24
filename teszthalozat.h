//
// Created by dezsibalint on 2024.04.10..
//

#ifndef ARAMKOR_TESZTHALOZAT_H
#define ARAMKOR_TESZTHALOZAT_H
#include "aramkorielem.h"
#include "vezetek.h"
#include "forras.h"
#include "norgate.h"
#include "invereter.h"
#include "memtrace.h"
#include "halozat.h"
class teszthalozat {
    size_t meret=9;
    halozatitarolo halozat[9];
public:
        teszthalozat()
        {

            for (int i = 0; i < 3  ; ++i) {
                halozat[i].add(new invereter());
            }
            for (int i = 3; i <8 ; ++i) {
                halozat[i].add(new forras());
            }
            halozat[8].add(new norgate(5));
        }

void felepit(){
    halozat[0].conn(halozat[7].get(),0);
    halozat[1].conn(halozat[5].get(),0);
    halozat[8].conn(halozat[3].get(),0);
    halozat[8].conn(halozat[4].get(),1);
    halozat[8].conn(halozat[0].get(),2);
    halozat[8].conn(halozat[6].get(),3);
    halozat[8].conn(halozat[1].get(),4);
    halozat[2].conn(halozat[8].get(),0);
}
void start(){
    felepit();
    halozat[2].print();}



};

#endif //ARAMKOR_TESZTHALOZAT_H
