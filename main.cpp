#include <iostream>
#include "aramkorielem.h"
#include "forras.h"
#include "vezetek.h"
int main() {
    vezetek v;
    forras f;
    v.connect(f,0);
    v.getuz(0).kiir();
}
