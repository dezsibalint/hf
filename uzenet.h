//
// Created by dezsibalint on 2024.03.30..
//

#ifndef ARAMKOR_UZENET_H
#define ARAMKOR_UZENET_H
#include "iostream"
#include "memtrace.h"
///Üzenet osztály
class uzenet {
    ///Value ha false=0 ha true=1
bool defined;
bool value;
public:
    ///Default konstruktor
    uzenet(){defined= false;}

    ///Setter
    void setval(bool val);

    //Getter
    bool getval()const;

    ///Be lett már állítva állapotba vagy még undefined
    ///@return true ha már be lett állítva, false ha nem
    bool isdefined()const;


};
///Inserter operátor ostremre kiíráshoz.
std::ostream &operator<<(std::ostream &os,const uzenet&ob);

#endif //ARAMKOR_UZENET_H
