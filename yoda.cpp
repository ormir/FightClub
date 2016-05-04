//
//  yoda.cpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 5/4/16.
//
//

#include "yoda.hpp"

Yoda::Yoda(const std::string n):
Fighter(n) {}

int Yoda::specialAttack(){
    srand((int)time(0));
    int attk = rand() % offence;
    
    if(rand()%7 == 0){
        attk = 100;
        std::cout << "May the fourth be with you, mighty " << name << "!!" << std::endl;
    }
    
    return attk;
}

Yoda::~Yoda(){}
