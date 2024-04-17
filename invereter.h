//
// Created by dezsibalint on 2024.04.10..
//

#ifndef ARAMKOR_INVERETER_H
#define ARAMKOR_INVERETER_H
#include "aramkorielem.h"
#include "memtrace.h"
class invereter: public aramkorielem{

public:
    invereter(): aramkorielem(1,"Inverter"){} ///Inverternek csak 1 bemenete van
    void connect(uzenet &mit, int hova) override;
    void print() const override;
};
std::ostream &operator<<(std::ostream os,invereter&ob);

#endif //ARAMKOR_INVERETER_H
