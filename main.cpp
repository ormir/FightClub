//
//  main.cpp
//  FightClub
//
//  Created by Ormir G. on 30/04/16.
//  Copyright © 2016 Ormir Gjurgjej. All rights reserved.
//

#include <iostream>
#include <vector>
#include "club.hpp"

int main(int argc, const char * argv[]) {
    
    Club clb;
    std::string message = "";
    
    std::cout << "FIGHT CLUB" << std::endl;
    std::cout << "Ormir Gjurgjej & Nitika Kumar (c) 2016" << std::endl;
    std::cout << "Type 'rules' for more information" << std::endl;
    
    while (message != "exit") {
        std::cin >> message;
        
        if (message == "add") {
            std::string name, type;
            std::cin >> name;
            std::cin >> type;
            clb.add(name, type);
        } else if (message == "fight") {
            std::string fighter1, fighter2;
            std::cin >> fighter1;
            std::cin >> fighter2;
            clb.fight(fighter1, fighter2);
        }
        else if (message == "rules") clb.rules();
        else if (message == "lms") clb.lastManStanding();
        else if (message == "fighters") clb.showFighters();
        else if (message == "exit") break;
        else {
            std::cout << "Command '" << message << "' not recognised" << std::endl;
            std::cout << "Type 'rules' for more information" << std::endl;
        }
    }
    
    
    return 0;
}
