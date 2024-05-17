#include <iostream>
#include "gtest_lite.h"
#include "aramkorielem.h"
#include "forras.h"
#include "vezetek.h"
#include "norgate.h"
#include "invereter.h"
#include "teszthalozat.h"
#include "halozat.h"
#include "memtrace.h"

int main() {
///Teszt A
    //Forrás tesztjei
    //Később is kell majd az a forrás ezért teszten kívűl hozzuk létre.
    forras a(1);
   try{ TEST(forras,create){
            EXPECT_STREQ("Forras",a.getnev()); //Létrejött-e az objektum?,és a neve helyes?
            EXPECT_TRUE(a.out().getval()); //A beállított érték van a kimeneten?
    }ENDM

    TEST(forras,exeption){
           EXPECT_THROW(forras b('c'),std::invalid_argument&); //Érvénytelen bemenet tesztje
    }ENDM} catch (std::errc){}

    //Vezeték tesztjei
    ///A vezetéket is fogjuk használni később ezért teszten kívűl hozzuk létre.
    vezetek v;
    TEST(vezetek,create){
        EXPECT_STREQ("Vezetek",v.getnev()); //Létrejött-e az objektum?,és a neve helyes?
    }ENDM

    TEST(vezetek,connect){
            v.connect(a.out());//Forrás kimenetét csatlakoztatjuk a vezeték bemenetéhez.
            EXPECT_TRUE(v.getout().getval());//Vezeték kimenetén lévő állapot az e mint a forrás állapota?
    }ENDM

    //Inverter tesztjei
    ///Az invertert is fogjuk használni később ezért teszten kívűl hozzuk létre.
    invereter i;
    TEST(invereter,create){
            EXPECT_STREQ("Inverter",i.getnev()); //Létrejött-e az objektum?,és a neve helyes?
    }ENDM

    TEST(invereter,connect){
        i.connect(v.out()); //Vezeték kimenetét kötjük az inverter bemenetére.
        EXPECT_FALSE(i.out().getval());//Negált eredmény van a kimeneten?
    }ENDM

    //Norgate tesztjei
    ///A norgate-t is fogjuk használni később ezért teszten kívűl hozzuk létre.
    norgate n(2);
    TEST(norgate,create){
            EXPECT_STREQ("Norgate",n.getnev()); //Létrejött-e az objektum?,és a neve helyes?

    }ENDM
    TEST(norgate,connect){
     n.connect(i.out(),0); //0. lábra a vezeték kimenetét kötöm(1)
     n.connect(v.out(),1); //1. lábra az inverter kimenetét (0)
            EXPECT_FALSE(n.out().getval()); //Nemvagy kapcsolat értelmében a kimenet állapota 0 kell,hogy legyen.

    }ENDM

    //Hálózati tároló tesztjei


    TEST(halozatitarolo,betesz){
            halozatitarolo test[4];

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
            halozatitarolo test[4];
            test[0].add(new forras(1));
            test[1].add(new vezetek);
            test[2].add(new invereter);
            test[3].add(new norgate(2));

            test[1].conn(test[0].get(),0);
            test[2].conn(test[1].get(),0);
            test[3].conn(test[2].get(),0);
            test[3].conn(test[0].get(),1);
            EXPECT_FALSE(test[3].get()->out().getval());// A hálózat végén 0 kell legyen.
        }ENDM


///TesztB
//Teszthálózat tesztjei.
   try{ teszthalozat th(0,0,1,0,1);
    TEST(teszthalozat,felepit){
            EXPECT_NO_THROW(th.felepit()); //Hiba nélkül felépül-e?

    }ENDM

    TEST(teszthalozat,mukodes){//Hamisat várunk az igazságtábla alapján.
            EXPECT_FALSE(th.kimenet());
    }ENDM

    TEST(teszthalozat,3random bemenetre){
        int rand1=rand()%3;
        int rand2=rand()%3;
        int rand3=rand()%3;
        int rand4=rand()%3;
        th.setin(1,rand1,rand2,rand3,rand4);//Az egyik bemenetet fixáljuk,hogy véletlen nehogy pont azt a kombinációt kapjuk amire false kell legyen.
                                                          //Nem túl szép megoldás.
        EXPECT_TRUE(th.kimenet());

        th.setin(rand4,1,rand3,rand2,rand1);
        EXPECT_TRUE(th.kimenet());

        th.setin(rand2,rand1,rand3,1,rand4);
        EXPECT_TRUE(th.kimenet());

    }ENDM} catch (std::errc){}

///Test C

    TEST(testc,teszt){
//4Forrás és 2NOR kapu kapuból álló hálózatot
        halozatitarolo ts[5];
            for (int j = 0; j < 3; ++j) {
                ts[j].add(new forras(0));//0 kezdőértékkel beletesszük,majd később kapnak értéket.
            }
            ts[3].add(new norgate(2));//2db 2 bementű norkapu.
            ts[4].add(new norgate(2));

            ts[0].set(0);//Források kapnak értéket
            ts[1].set(0);
            ts[2].set(0);

            //Csatlakoztatjuk egymáshoz őket.
            ts[3].conn(ts[0].get(),0);
            ts[3].conn(ts[1].get(),1);
            ts[4].conn(ts[2].get(),0);
            ts[4].conn(ts[3].get(),1);

            //Aktuál tesztek
            //Források kimenetének tesztjei.
            EXPECT_FALSE(ts[0].get()->getout().getval());
            EXPECT_FALSE(ts[1].get()->getout().getval());
            EXPECT_FALSE(ts[2].get()->getout().getval());
            //Utánna input tesztek a 2 NOR kapu bemeneteinek inputjai.
            EXPECT_FALSE(ts[3].get()->getinput(0).getval());
            EXPECT_FALSE(ts[3].get()->getinput(1).getval());
            EXPECT_FALSE(ts[4].get()->getinput(0).getval());
            EXPECT_TRUE(ts[4].get()->getinput(1).getval());//Csak erre a bemenetre jön igaz az egyik norkapu kimentéről

            //Kimenet tesztek(2 norkapunak, a 2.norkapu ts[4] az utolsó elem,ő a hálózat kimenete is
            EXPECT_TRUE(ts[3].get()->getout().getval());//Ez az a bemnet
            EXPECT_FALSE(ts[4].get()->getout().getval());
    }ENDM

    ///CINRŐL Felhasználó által megadható 1bemenetű hálózat ami minden bemenetre 0-át ad.
    ///Csak a program bemutatása miatt.
    TEST(testc,felhasznalo){
    forras f;
    norgate nor(2);
    invereter inv;

    ///Hálózat felépítése

    nor.connect(f.out(),0);
    inv.connect(f.out());
    nor.connect(inv.out(),1);

    ///Minden bemenet esetére 0-át várunk.
    EXPECT_FALSE(nor.getout().getval());

    ///Kiírjuk,csak a bemutatás miatt.
    nor.print();
    }ENDM
}
