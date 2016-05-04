//
//  club.cpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#include "club.hpp"

//Calling the constructor
Club::Club() {}

//function takes two parameters - the two fighters by their name
void Club::fight(const std::string name1, const std::string name2) {
    //if fighter 1 isn't stored in 'fighers'
    if(fighters.find(name1) == fighters.end())
        std::cout << "Coldn't find fighter '" << name1 << "'" << std::endl;
    //if fighter 2 can't be found in 'fighters'
    else if (fighters.find(name2) == fighters.end())
        std::cout << "Coldn't find fighter '" << name1 << "'" << std::endl;
    else {
        //pointers created that point to the elements in the fighters table where the names of the fighters are stored
        Fighter * fighter1 = fighters[name1];
        Fighter * fighter2 = fighters[name2];
        
        
        while (!fighter1->attack(*fighter2, false) &&
               !fighter2->attack(*fighter1, false)) {
            // fight
        }
        
        //check if fighter 1 is dead, if so, fighter 2 is the winner
        Fighter * winner = fighter1->dead() ? fighter2 : fighter1;
        std::cout << winner->getName() << " WON!!!!!!!!" << std::endl;
        
        //check who lost and remove him from the table
        Fighter * loser = fighter1->dead() ? fighter1 : fighter2;
        remove(loser->getName());
    }
}

//opens text file 'rules' to understand the rules of the game
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

//adding fighters to the 'fighters' table, taking the name and the type of the player eg warrior, ninja etc
void Club::add(std::string name, std::string type) {
    if (type == "warrior")  fighters[name] = new Warrior(name);
    else if (type == "ninja") fighters[name] = new Ninja(name);
    else if (type == "witch") fighters[name] = new Witch(name);
    else if (type == "yoda") fighters[name] = new Yoda(name);
    else std::cout << "Type '" << type << "' not in the list" << std::endl;
}

//displays remaining fighters in the 'fighters' table
void Club::showFighters() const {
    if (fighters.empty())  std::cout << "There are no fighters in the club yet" << std::endl;
    else //goes through table and shows the name as well as the offense and defense points of the fighter
    for (auto it = fighters.begin(); it != fighters.end(); ++it)
        std::cout << it->second->getName() << " O:" << it->second->getOffence() << " D:" << it->second->getDefence() << std::endl;
}

//as long as the table isn't empty or there are more than one fighter, let the fighters fight randomly
void Club::lastManStanding() {
    while (fighters.size() != 1 && !fighters.empty()) {
        srand ((int)time(0));
        //select fighters randomly out of the table
        auto fighter1 = (std::next(fighters.begin(), (rand() % fighters.size())))->second;
        auto fighter2 = (std::next(fighters.begin(), (rand() % fighters.size())))->second;
        
        //check if the two chosen fighters are the same or not, if not the same, then start the attack
        if (fighter1 != fighter2 && fighter1->attack(*fighter2, false)) {
            //check who died
            Fighter * dead = fighter2->dead() ? fighter2 : fighter1;
            remove(dead->getName());
        }
    }
    //if only one fighter left--> he be da kiiiing yo
    if (fighters.size() == 1) {
        std::cout << "Long Live The King '" << fighters.begin()->first << "'" << std::endl;
    }
}

//deleting fighters from the table :( dat world be so cruel
void Club::remove(const std::string name) {
    std::cout << "R.I.P. '" << name << "'" << std::endl;
    delete fighters[name];
    fighters.erase(name);
}

//destruction to its fullest
Club::~Club() {
    for (auto it = fighters.begin(); it != fighters.end(); ++it)
        delete it->second;
    
    fighters.clear();
}