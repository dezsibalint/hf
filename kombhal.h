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
    //halozatitarolo halozat[9];
    invereter i1,i2,i3;
    forras a,b,c,d,e;
    norgate n;
public:
    kombhal(): n(5){

        i1.connect(e.out(),0);
        i2.connect(c.out(),0);
        n.connect(a.out(),0);
        n.connect(b.out(),1);
        n.connect(i1.out(),2);
        n.connect(d.out(),3);
        n.connect(i2.out(),4);
        i3.connect(n.out(),0);
    }
    void start(){
i3.out().kiir();
    }

};
/*invereter i1,i2,i3;
halozat[0].add(&i1);
halozat[1].add(&i2);
halozat[2].add(&i3);
forras a,b,c,d,e;
halozat[3].add(&a);
halozat[4].add(&b);
halozat[5].add(&c);
halozat[6].add(&d);
halozat[7].add(&e);
norgate n(5);
halozat[8].add(&n);
}
void felepit(){
    halozat[0].conn(halozat[7].output(),0);
    halozat[1].conn(halozat[5].output(),0);
    halozat[8].conn(halozat[3].output(),0);
    halozat[8].conn(halozat[4].output(),1);
    halozat[8].conn(halozat[0].output(),2);
    halozat[8].conn(halozat[6].output(),3);
    halozat[8].conn(halozat[1].output(),4);
    halozat[2].conn(halozat[8].output(),0);
}
void start(){
    felepit();
    halozat[2].print();
*/
#endif //ARAMKOR_KOMBHAL_H
