//
//  main.cpp
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 17/12/2021.
//

#include <iostream>
#include "character.h"
#include "utill.h"
int main(int argc, const char * argv[]) {
    
    Hero hero;
    bool start = false;
    
    while (true) {
        std::string choice;
        Utilities::clearScreen();
        if (!start){std::cout<<"Obudziłeś się w ciemnym korytarzu, nie wiesz gdzie jesteś, musisz jakoś znaleźć wyjście\n"<<std::endl;
		start = true;	
		}
        std::cout<<"DZIAŁANIA:\ns - Status Postaci\np - Podróż\nb - Sklep\no - Odpocznij\nw - Wyjdź"<<std::endl;
        std::cout<<"-> ";
        
        
        
        switch (Utilities::getInput(choice)) {
            case 's':
                hero.statusCheckOption();
                break;
            case 'p':
                hero.travelOption();
                break;
            case 'b':
                
                hero.enterShop();
                break;
            case 'o':
                hero.restOption();
                break;
            case 'w':
                std::exit(0);
                break;
        
            default:
                Utilities::errorMessage();
                break;
            }
    }
    
    return 0;
}
