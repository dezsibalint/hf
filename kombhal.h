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
class kombhal {

public:
    kombhal(){

     invereter i1,i2,i3;
     forras a,b,c,d,e;
     norgate n(5);
     i1.connect(e.out(),0);
     i2.connect(c.out(),0);
     n.connect(a.out(),0);
     n.connect(b.out(),1);
     n.connect(i1.out(),2);
     n.connect(d.out(),3);
     n.connect(i2.out(),4);
     i3.connect(n.out(),0);
     i3.print();
    }
};


#endif //ARAMKOR_KOMBHAL_H
