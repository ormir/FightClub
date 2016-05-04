//
//  fighter.cpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#include "fighter.hpp"

Fighter::Fighter(const std::string n) :
name(n),
life(100) {
    
    // Generate offence and defence
    srand ((int)time(0));
    offence = (rand() % 25) + 25;
    defence = (rand() % 25) + 25;
}

std::string Fighter::getName () const {
    return name;
}

int Fighter::specialAttack() const{
    srand ((int)time(0));
    return rand() % offence;
}

bool Fighter::attack(Fighter& f, bool counter) {
    int attk = counter ? defend() : specialAttack();
    
    if (counter) {
        std::cout << "Mighty " << name << " strikes back " << f.getName() << " with " << attk << " !!!" << std::endl << std::endl;
    } else {
        std::cout << "Legendary " << name << " attacks " << f.getName() << " with " << attk << " !!!" << std::endl;
    }
    
    f.reduceLife(attk);
    
    if (f.dead()) return true;
    if (!counter) return f.attack(*this, true);
    
    return false;
}

int Fighter::defend(){
    srand ((int)std::time(0));
    return rand() % defence;
}

void Fighter::reduceLife(int l) {
    life -= l;
    
    if (life < 20 && life + l > 20) {
        std::cout << "--  Master " << name << " is fighting to his last breath ..." << std::endl << std::endl;
    } else if (life < 50 && life + l > 50) {
        std::cout << "-- Fearless " << name << " has less than half of his life to fight for" << std::endl << std::endl;
    }
}

bool Fighter::dead() const {
    return life < 0 ? true : false;
}

int Fighter::getOffence() const {
    return offence;
}

int Fighter::getDefence() const {
    return defence;
}

Fighter::~Fighter() {}

