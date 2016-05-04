//
//  warrior.hpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#ifndef warrior_hpp
#define warrior_hpp

#include <stdio.h>
#include "fighter.hpp"

class Warrior : public Fighter {
public:
    Warrior(const std::string);
    int specialAttack() const;
    ~Warrior();
};

#endif /* warrior_hpp */
