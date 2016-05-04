//
//  club.hpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 30/04/16.
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
#include "yoda.hpp"

class Club {
private:
    //associating string with pointers called Fighter and storing them in the variable 'fighters'
    std::map<std::string, Fighter*> fighters;
public:
    //Constructor
    Club();
    void fight(const std::string, const std::string);
    void rules() const;
    void remove(const std::string);
    void add(std::string, std::string);
    void showFighters() const;
    void lastManStanding();
    //Destructor
    ~Club();
};

#endif /* club_hpp */
