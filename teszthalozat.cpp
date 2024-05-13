//
// Created by dezsibalint on 2024.04.10..
//

#include "teszthalozat.h"

teszthalozat::teszthalozat() {

    for (int i = 0; i < 3  ; ++i) {
        halozat[i].add(new invereter());     //3db inverter hozzáadása
    }
    for (int i = 3; i <8 ; ++i) {
        halozat[i].add(new forras());       //5db forrás hozzáadása
    }
    halozat[8].add(new norgate(5));         //1db norgate hozzáadása
}

teszthalozat::teszthalozat(int e, int d, int c, int b, int a) {
    for (int i = 0; i < 3  ; ++i) {
        halozat[i].add(new invereter());     //3db inverter hozzáadása
    }
    halozat[3].add(new forras(e));
    halozat[4].add(new forras(d));
    halozat[5].add(new forras(c));
    halozat[6].add(new forras(b));
    halozat[7].add(new forras(a));

    halozat[8].add(new norgate(5));         //1db norgate hozzáadása
}

///Csatlakoztatjuk az elemeket
void teszthalozat::felepit() {
    halozat[0].conn(halozat[7].get(),0);
    halozat[1].conn(halozat[5].get(),0);
    halozat[8].conn(halozat[3].get(),0);
    halozat[8].conn(halozat[4].get(),1);
    halozat[8].conn(halozat[0].get(),2);
    halozat[8].conn(halozat[6].get(),3);
    halozat[8].conn(halozat[1].get(),4);
    halozat[2].conn(halozat[8].get(),0);
}
///Lefut a teszthálózat, és kiírja a kimenetet
void teszthalozat::start() {
    felepit();
    halozat[2].print();}

bool teszthalozat::kimenet() {
    return halozat[2].get()->out().getval();    //A kimeneti inverter második helyen van a tárolónkban,így az ő kimenete kell.
}

void teszthalozat::setin(int e, int d, int c, int b, int a) {
halozat[3].set(e);
halozat[4].set(d);
halozat[5].set(c);
halozat[6].set(b);
halozat[7].set(a);
felepit();//Ha beállítottuk az új bemeneteket újra flépítjük.
}