//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_VEZETEK_H
#define ARAMKOR_VEZETEK_H
#include "aramkorielem.h"
#include "memtrace.h"
class vezetek: public aramkorielem{

public:
    vezetek(): aramkorielem(1,"Vezetek"){} ///Vezetéknek 1 bemenete van.
   void connect(uzenet &mit);///Amint csatlakoztatjuk kiküldi a kimenetére azt ami a bemenetén van.
void print(std::ostream &os = std::cout) const override;
};


#endif //ARAMKOR_VEZETEK_H
