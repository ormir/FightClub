//
//  ninja.hpp
//  FightClub
//
//  Created by Ormir G. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#ifndef ninja_hpp
#define ninja_hpp

#include <stdio.h>
#include "fighter.hpp"

class Ninja : public Fighter {
private:
    int damage;
public:
    Ninja(const std::string);
    int defend();
    void reduceLife(int);
    ~Ninja();
};

#endif /* ninja_hpp */
