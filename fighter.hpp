//
//  fighter.hpp
//  FightClub
//
//  Created by Ormir G. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#ifndef fighter_hpp
#define fighter_hpp

#include <stdio.h>
#include <iostream>
#include <time.h> 

class Fighter {
protected:
    std::string name;
    int life;
    int offence;
    int defence;
    
    Fighter(const std::string);
    virtual int specialAttack() const;
    virtual int defend();
public:
    std::string getName () const;
    bool attack (Fighter&, bool);
    virtual void reduceLife(int);
    bool dead() const;
    int getOffence() const;
    int getDefence() const;
    virtual ~Fighter();
};

#endif /* fighter_hpp */
