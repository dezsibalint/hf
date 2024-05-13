//
// Created by dezsibalint on 2024.04.10..
//

#include "norgate.h"
///Mindaddig true értéket ad vissza, amíg nem talál 1 igaz bemnetet.
void norgate::connect(uzenet &mit, int hova) {
    aramkorielem::connect(mit,hova);
    uzenet u;
    u.setval(true);
    setout(u);
    for (int i = 0; i < inputdb(); ++i) {//Végigmegy a bemeneteken,ha talál definiált bemenetet, és az igaz, akkor a kimenet false lesz.
        if(getinput(i).isdefined()&& getinput(i).getval()) {
            uzenet out;
            out.setval(false);
            setout(out);
            return; //Nem is kell folyatani hiszen innentől kezdve már nem lehet igaz az eredmény.
        }
    }

}
///Kapott ostreamre kiírja a norgate bemeneinek és kimenetének állapotát.
void norgate::print(std::ostream&os) const {
    for (int i = 0; i < inputdb(); ++i) {
        os<<"A norkapu "<<i+1<< ". bememenetének állapota: "<< this->getinput(i)<<std::endl;
    }
   os<<"A norkpu kimenetének állapota: "<<this->getout()<<std::endl;

}
