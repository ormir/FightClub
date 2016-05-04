//
//  yoda.hpp
//  FightClub
//
//  Created by Ormir G. and Nitika K. on 5/4/16.
//
//

#ifndef yoda_hpp
#define yoda_hpp

#include <stdio.h>
#include "fighter.hpp"

class Yoda : public Fighter {
public:
    Yoda(const std::string);
    int specialAttack();
    ~Yoda();
};

#endif /* yoda_hpp */
