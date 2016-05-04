//
//  witch.hpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 5/3/16.
//
//

#ifndef witch_hpp
#define witch_hpp

#include <stdio.h>
#include "fighter.hpp"

class Witch : public Fighter {
public:
    Witch(const std::string);
    int specialAttack();
    ~Witch();
};

#endif /* witch_hpp */
