//
//  club.hpp
//  FightClub
//
//  Created by Ormir G. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#ifndef club_hpp
#define club_hpp

#include <stdio.h>
#include <fstream>
#include <map>
#include <iterator>
#include "fighter.hpp"
#include "ninja.hpp"
#include "warrior.hpp"
#include "witch.hpp"

class Club {
private:
    std::map<std::string, Fighter*> fighters;
public:
    Club();
    void fight(const std::string, const std::string);
    void rules() const;
    void remove(const std::string);
    void add(std::string, std::string);
    void showFighters() const;
    void lastManStanding();
    ~Club();
};

#endif /* club_hpp */
