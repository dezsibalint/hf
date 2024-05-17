//
// Created by dezsibalint on 2024.03.30..
//

#include "uzenet.h"

void uzenet::setval(bool val) {
    value=val;defined= true;
}

bool uzenet::getval() const {
    return value;
}

bool uzenet::isdefined() const {
    return defined;
}

std::ostream &operator<<(std::ostream &os,const uzenet&ob){
    if(ob.isdefined()){
        return os<<ob.getval();

    } else return os<<"Nem definiált";
}
