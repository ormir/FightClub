//
//  ninja.cpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#include "ninja.hpp"

Ninja::Ninja(std::string n) :
Fighter(n),
damage(0) {}

void Ninja::reduceLife(int d) {
    damage = d;
    life -= d;
    
    if (life < 20 && life + d > 20) {
        std::cout << "--  Master " << name << " is fighting to his last breath ..." << std::endl << std::endl;
    } else if (life < 50 && life + d > 50) {
        std::cout << "-- Fearless " << name << " has less than half of his life to fight for" << std::endl << std::endl;
    }
}

int Ninja::defend() {
    srand ((int)time(0));
    
    // Regain  previous lost life
    if (rand() % 6 == 0) {
        std::cout << "++ " << name << " dodged the " << damage << " attack perfectly!!!" << std::endl << std::endl;
        life += damage;
    }
    
    return rand() % defence;
}

Ninja::~Ninja() {}