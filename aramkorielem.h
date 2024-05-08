//
// Created by dezsibalint on 2024.03.30..
//

#ifndef ARAMKOR_ARAMKORIELEM_H
#define ARAMKOR_ARAMKORIELEM_H
#include "cstring"
#include "uzenet.h"
#include "memtrace.h"

///Absztrakt ősosztály
///@param nev Az áramkör elem neve
///@param bemenetekszama Bemenetek száma
///@param kimenetszam Kimenetek száma
///@param bemenetek Bemeneti lábak állapotát tároló tömb
///@param kimenet Kimenet állapota
class aramkorielem {
    char nev[20];
    int bemenetekszama;
    const static int kimenetszam=1;//Minden kapunak csak 1 kimenete van.
    uzenet *bemenetek=new uzenet[bemenetekszama];// Minden lábnak van saját állapota.
    uzenet kimenet;
public:
    aramkorielem():bemenetekszama(0){} ///Default konsturktor 0 bemenettel.

    ///Konstruktor
    ///@param l bemenetek száma
    ///@param n név
    aramkorielem(int l,const char *n):bemenetekszama(l){ strcpy(nev,n);}//Átmásoljuk a nevet.

    ///Destruktor
    virtual ~aramkorielem(){delete[]bemenetek;}

    ///connect függvény
    ///@param mit Bemenet állapota
    ///@param hova Hanyadik bemenetre csatlakozik
    virtual  void connect(uzenet &mit,int hova);

    ///inputdb függvény
    ///@return bemenetek száma
    int inputdb()const {return bemenetekszama;}

    ///Kimenet értékét beállító függvény
    ///@param to_out Kimenet értéke
    virtual void setout(uzenet &to_out);

    ///Kimeneten lévő üzenet referenciát visszaadó függvény
    uzenet &out();  ///Nem lehet konstans,hiszen azzal a kimenettel fogunk tovább dolgozni,hogy ne másoldójon az adat.

    ///Kimenet értékét visszaadó függvény
    ///@return kimenet
    uzenet getout()const{return kimenet;}

    ///Bemenet értékét visszaadó függvény
    ///@param hanyas Hanyadik bemenet aminek az értékét visszaadjuk
    ///@return bemenet[hanyas]
    uzenet getinput(int hanyas)const;

    ///kiíró függvény
    ///@param os Hova írjuk ki
   virtual void print(std::ostream &os=std::cout)const=0;
   ///Nevet visszaadó függvény
   ///@return nev
   const char*getnev()const {return nev;}

};


#endif //ARAMKOR_ARAMKORIELEM_H
