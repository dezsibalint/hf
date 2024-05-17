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
#include "halozat.h"

///Teszthálózat osztály, csak a heterogén tároló bemutatása miatt.
///@tparam halozat: Heterogén tároló, amely az áramköri elemeket tárolja.
class teszthalozat {
    halozatitarolo halozat[9];
public:
    ///konstruktor
    teszthalozat();

    ///Felépíti a teszt hálózatot
    void felepit();

    ///Előre megadott értékkel helyezi be a forrásokat
    ///@param e: első változó
    ///@param d: második változó
    ///@param c: harmadik változó
    ///@param b: negyedik változó
    ///@param a: ötödik változó
    teszthalozat(int e,int d,int c,int b,int a);

    ///Kiírja a kimenetet
    void start();

    ///Visszaadja a hálózat kimenetét(utolsó hálózati elem kimenete)
    bool kimenet();

    ///A hálózatban lévő források értékének utólagos beállítása.
    ///@param e: első változó
    ///@param d: második változó
    ///@param c: harmadik változó
    ///@param b: negyedik változó
    ///@param a: ötödik változó
    void setin(int e,int d,int c,int b,int a);

};

#endif //ARAMKOR_TESZTHALOZAT_H
