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
    int labakszama;
    uzenet *bemenetek=new uzenet[labakszama-1];/// Minden lábnak van saját állapota.
    uzenet kimenet;
public:
    aramkorielem():labakszama(0){} ///Default konsturktor

    aramkorielem(int l,char *n):labakszama(l){ strcpy(nev,n);}

    virtual ~aramkorielem(){delete[]bemenetek;}
   virtual  void connect(uzenet &mit,int hova);

    int getlab(){return labakszama;}

    virtual void setout(uzenet &to_out);

    uzenet &out();  ///Nem lehet konstans,hiszen azzal a kimenettel fogunk tovább dolgozni,hogy ne másoldójon az adat.

    uzenet getlaball(int hanyas)const;

    void print()const{ ///Ez csak kezdeti debug cél,hogy lássam mit is csinálok
        std::cout<<"A kimenet állapota: ";
        kimenet.kiir();
    }

};


#endif //ARAMKOR_ARAMKORIELEM_H
