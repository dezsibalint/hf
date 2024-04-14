//
// Created by dezsibalint on 2024.04.10..
//

#ifndef ARAMKOR_NORGATE_H
#define ARAMKOR_NORGATE_H
#include "aramkorielem.h"

class norgate:public aramkorielem {

public:
    norgate(int bemenetek): aramkorielem(bemenetek,"NORKAPU"){}
    void connect(uzenet &mit, int hova) override;
};


#endif //ARAMKOR_NORGATE_H
