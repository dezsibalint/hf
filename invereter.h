//
// Created by dezsibalint on 2024.04.10..
//

#ifndef ARAMKOR_INVERETER_H
#define ARAMKOR_INVERETER_H
#include "aramkorielem.h"

class invereter: public aramkorielem{

public:
    invereter(): aramkorielem(2,"Inverter"){}
    void connect(uzenet &mit, int hova) override;

};


#endif //ARAMKOR_INVERETER_H
