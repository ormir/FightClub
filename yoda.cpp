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

    //the opponent can't have more than 100 points hence yoda is able to kill the other fighter with just one special attack
    //hashtag(teamyoda);
    if(rand()%5 == 0){
        attk = 100;
        std::cout << "++May the fourth be with you, mighty " << name << "!!" << std::endl;
    }
    
    return attk;
}

Yoda::~Yoda(){}
