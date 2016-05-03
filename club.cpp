//
//  club.cpp
//  FightClub
//
//  Created by Ormir G. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#include "club.hpp"


Club::Club() {}

void Club::fight(const std::string name1, const std::string name2) {
    if(fighters.find(name1) == fighters.end())
        std::cout << "Coldn't find fighter '" << name1 << "'" << std::endl;
    else if (fighters.find(name2) == fighters.end())
        std::cout << "Coldn't find fighter '" << name1 << "'" << std::endl;
    else {
        Fighter * fighter1 = fighters[name1];
        Fighter * fighter2 = fighters[name2];
        
        while (!fighter1->attack(*fighter2, false) &&
               !fighter2->attack(*fighter1, false)) {
            // fight
        }
        
        Fighter * winner = fighter1->dead() ? fighter2 : fighter1;
        std::cout << winner->getName() << " WON!!!!!1111123456" << std::endl;
        
        Fighter * loser = fighter1->dead() ? fighter1 : fighter2;
        remove(loser->getName());
    }
}

void Club::rules() const {
    std::ifstream file("fightclub.txt");
    if (file.is_open()) {
        // Read each line from file
        std::string line;
        while (std::getline(file, line)) std::cout << line << std::endl;
    } else
        std::cout << "FAIL reading help" << std::endl;
    
    file.close();
}

void Club::add(std::string name, std::string type) {
    if (type == "warrior")  fighters[name] = new Warrior(name);
    else if (type == "ninja") fighters[name] = new Ninja(name);
    else if (type == "witch") fighters[name] = new Witch(name);
    else std::cout << "Type '" << type << "' not in the list" << std::endl;
}

void Club::showFighters() const {
    if (fighters.empty())  std::cout << "There are no fighters in the club yet" << std::endl;
    else
    for (auto it = fighters.begin(); it != fighters.end(); ++it)
        std::cout << it->second->getName() << " O:" << it->second->getOffence() << " D:" << it->second->getDefence() << std::endl;
}

void Club::lastManStanding() {
    while (fighters.size() != 1 && !fighters.empty()) {
        srand ((int)time(0));
        auto fighter1 = (std::next(fighters.begin(), (rand() % fighters.size())))->second;
        auto fighter2 = (std::next(fighters.begin(), (rand() % fighters.size())))->second;
        
        if (fighter1 != fighter2 && fighter1->attack(*fighter2, false)) {
            Fighter * dead = fighter2->dead() ? fighter2 : fighter1;
            remove(dead->getName());
        }
    }
    
    if (fighters.size() == 1) {
        std::cout << "Long Live The King '" << fighters.begin()->first << "'" << std::endl;
    }
}

void Club::remove(const std::string name) {
    std::cout << "R.I.P. '" << name << "'" << std::endl;
    delete fighters[name];
    fighters.erase(name);
}

Club::~Club() {
    for (auto it = fighters.begin(); it != fighters.end(); ++it)
        delete it->second;
    
    fighters.clear();
}