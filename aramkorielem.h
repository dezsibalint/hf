//
// Created by dezsibalint on 2024.03.30..
//

#ifndef ARAMKOR_ARAMKORIELEM_H
#define ARAMKOR_ARAMKORIELEM_H
#include "uzenet.h"
#include "cstring"
///Absztrakt ősosztály
class aramkorielem {
    char nev[20];
    int labakszama;
    uzenet *allapot=new uzenet[labakszama]; /// Minden lábnak van saját állapota. az utolsó láb a kimeneti láb
  //  connection*conn=new connection[labakszama];
public:
    aramkorielem():labakszama(0){}
    aramkorielem(int l,char *n):labakszama(l){ strcpy(nev,n);}
 //   virtual ~aramkorielem()=0;
    virtual void connect(aramkorielem& mit,int hova);
    char* miez() {return nev;}
    void setout(uzenet to_out){
        allapot[labakszama-1]=to_out;
    }
    uzenet getuz(int hanyaslab){return allapot[hanyaslab];}
};


#endif //ARAMKOR_ARAMKORIELEM_H
