//
//  witch.cpp
//  FightClub
//
//  Created by dolly sharma on 5/3/16.
//
//

#include "witch.hpp"

Witch::Witch(const std::string n):
Fighter(n) {}

int Witch::specialAttack() {
    srand((int)time(0));
    int attk = rand() % offence;

    if(rand()%8 == 0){
        life += attk;
        std::cout << "++Evil Witch " << name << " sucks " << attk << " life points out of her opponent" << std::endl;
    }
    
    
    return attk;
}

Witch::~Witch() {}