//
// Created by dezsibalint on 2024.04.10..
//

#ifndef ARAMKOR_KOMBHAL_H
#define ARAMKOR_KOMBHAL_H
#include "aramkorielem.h"
#include "vezetek.h"
#include "forras.h"
#include "norgate.h"
#include "invereter.h"
#include "memtrace.h"
#include "halozat.h"
class kombhal {
    halozatitarolo halozat[9];
public:
        kombhal()
        {
            halozat[0].add(new invereter());
            halozat[1].add(new invereter());
            halozat[2].add(new invereter());
            halozat[3].add(new forras());
            halozat[4].add(new forras());
            halozat[5].add(new forras());
            halozat[6].add(new forras());
            halozat[7].add(new forras());
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

#endif //ARAMKOR_KOMBHAL_H
