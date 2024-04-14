//
// Created by dezsibalint on 2024.04.09..
//

#ifndef ARAMKOR_VEZETEK_H
#define ARAMKOR_VEZETEK_H
#include "aramkorielem.h"
class vezetek: public aramkorielem{

public:
    vezetek(): aramkorielem(2,"vezetek"){}
   void connect(uzenet &mit);///Amint csatlakoztatjuk kiküldi a kimenetére azt ami a bemenetén van.
};


#endif //ARAMKOR_VEZETEK_H
