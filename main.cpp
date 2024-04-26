#include <iostream>
#include "aramkorielem.h"
#include "forras.h"
#include "vezetek.h"
#include "norgate.h"
#include "invereter.h"
#include "teszthalozat.h"
#include "memtrace.h"
#include "halozat.h"
#include "gtest_lite.h"
#include "sstream"
int main() {
///Teszt A
    //Forrás tesztjei
    forras a(1);


    TEST(forras,create){

            EXPECT_STREQ("Forras",a.getnev());
            ///Kimeneten a bemenet van?
            EXPECT_TRUE(a.out().getval());
    }ENDM
    TEST(forras,exeption){
           EXPECT_THROW(forras b('c'),std::invalid_argument);
    }ENDM
    vezetek v;
    //Vezeték tesztjei
    TEST(vezetek,create){

            EXPECT_STREQ("Vezetek",v.getnev());


    }ENDM
    TEST(vezetek,connect){
            v.connect(a.out());//Forrás kimenetét csatlakoztatjuk a vezeték bemenetéhez.
            EXPECT_TRUE(v.getout().getval());//Vezeték kimenetén lévő állapot az e mint a forrás állapota?
    }ENDM
    //Inverter tesztjei
    invereter i;
    TEST(invereter,create){
            EXPECT_STREQ("Inverter",i.getnev());
    }ENDM

    TEST(invereter,connect){
        i.connect(v.out());
        EXPECT_FALSE(i.out().getval());//Negált eredmény van a kimeneten?
    }ENDM

    //Norgate tesztjei
    norgate n(2);
    TEST(norgate,create){
            EXPECT_STREQ("Norgate",n.getnev());

    }ENDM
    TEST(norgate,connect){
     n.connect(i.out(),0);//0. lábra a vezeték kimenetét kötöm(1)
     n.connect(v.out(),1);//1. lábra az inverter kimenetét (0)
            EXPECT_FALSE(n.out().getval());///Nemvagy kapcsolat értelmében a kimenet állapota 0 kell,hogy legyen.

    }ENDM
    //Hálózati tároló tesztjei
   /* halozatitarolo test[4];
    TEST(halozatitarolo,betesz){

        test[0].add(new forras(1));
        test[1].add(new vezetek);
        test[2].add(new invereter);
        test[3].add(new norgate(2));
            //Bele kerültek-e az elemek?
                EXPECT_STREQ("Forras",test[0].get()->getnev());
                EXPECT_STREQ("Vezetek",test[1].get()->getnev());
                EXPECT_STREQ("Inverter",test[2].get()->getnev());
                EXPECT_STREQ("Norgate",test[3].get()->getnev());

    }ENDM
    TEST(halozatitarolo,mukodes){
        test[1].conn(test[0].get(),0);
        test[2].conn(test[1].get(),0);
        test[3].conn(test[2].get(),0);
        test[3].conn(test[0].get(),1);
            EXPECT_FALSE(test[3].get()->out().getval());// A hálózat végén 0 kell legyen.
    }ENDM
///TesztB
//Teszthélózat tesztjei.
/*teszthalozat th;
    TEST(teszthalozat,felepit){
            EXPECT_NO_THROW(th.felepit()); //Hiba nélkül felépül-e?

    }ENDM
    TEST(teszthalozat,mukodes){

    }ENDM
*/
}
