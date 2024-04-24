//
// Created by dezsibalint on 2024.03.30..
//

#ifndef ARAMKOR_ARAMKORIELEM_H
#define ARAMKOR_ARAMKORIELEM_H
#include "uzenet.h"
#include "cstring"
#include "memtrace.h"
///Absztrakt ősosztály
class aramkorielem {
    char nev[20];
    int bemenetekszama;
    const static int kimenetszam=1;
    uzenet *bemenetek=new uzenet[bemenetekszama];/// Minden lábnak van saját állapota.
    uzenet kimenet;
public:
    aramkorielem():bemenetekszama(0){} ///Default konsturktor

    aramkorielem(int l,char *n):bemenetekszama(l){ strcpy(nev,n);}

    virtual ~aramkorielem(){delete[]bemenetek;}

    virtual  void connect(uzenet &mit,int hova);

    int inputdb()const {return bemenetekszama;}

    virtual void setout(uzenet &to_out);

    uzenet &out();  ///Nem lehet konstans,hiszen azzal a kimenettel fogunk tovább dolgozni,hogy ne másoldójon az adat.

    uzenet getout()const{return kimenet;}
    uzenet getinput(int hanyas)const;

   virtual void print(std::ostream &os=std::cout)const=0;

   char*getnev() {return nev;}

};


#endif //ARAMKOR_ARAMKORIELEM_H
