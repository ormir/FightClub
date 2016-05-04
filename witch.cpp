//
//  witch.cpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 5/3/16.
//
//

#include "witch.hpp"

Witch::Witch(const std::string n):
Fighter(n) {}

int Witch::specialAttack() {
    srand((int)time(0));
    int attk = rand() % offence;
    
    //the witch has the ability to gain the lost life points of the opponent - he loses, she wins because witch
    if(rand()%8 == 0){
        life += attk;
        std::cout << "++Evil Witch " << name << " sucks " << attk << " life points out of her opponent" << std::endl;
    }
    return attk;
}

Witch::~Witch() {}