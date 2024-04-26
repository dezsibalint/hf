//
// Created by dezsibalint on 2024.04.09..
//

#include "forras.h"

///Csak a kimenetet írjuk ki mert a forrásnak nincs bemenete.
void forras::print(std::ostream&os) const {os<<"A forrás kimenetének állapota: "<<this->getout()<<std::endl;}
