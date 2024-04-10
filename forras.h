//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_FORRAS_H
#define ARAMKOR_FORRAS_H

#include "aramkorielem.h"
#include "iostream"
class forras: public aramkorielem{
public:
    forras(): aramkorielem(1,"forras"){
        std::cout<<"Bemenet:";
        bool be;
        std::cin>>be;
        uzenet ou;
        ou.setval(be);
        setout(ou);
    }
};


#endif //ARAMKOR_FORRAS_H
