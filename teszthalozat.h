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
///Teszthálózat osztály, csak a heterogén tároló bemutatása miatt.
///@tparam meret: Tároló mérete,azaz hány db áramköri elemet tárolhat.
///@tparam halozat: Heterogén tároló, amely az áramköri elemeket tárolja.
class teszthalozat {
    size_t meret=9;
    halozatitarolo halozat[9];
public:
    ///konstruktor
    teszthalozat();

    ///Felépíti a teszt hálózatot
    void felepit();

    ///Kiírja a kimenetet
    void start();



};

#endif //ARAMKOR_TESZTHALOZAT_H
