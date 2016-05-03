//
//  warrior.cpp
//  FightClub
//
//  Created by Ormir G. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#include "warrior.hpp"

Warrior::Warrior(const std::string n) :
Fighter(n) {}

int Warrior::specialAttack() const {
    srand ((int)time(0));
    int attk =rand() % offence;
    
    if (rand()%6 == 0) {
        attk *= 2;
        std::cout << "++ Brave " << name << " attacks furiously!" << std::endl;
    }
    return attk;
}

Warrior::~Warrior() {}