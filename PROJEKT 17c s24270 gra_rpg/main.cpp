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
    
    
    while (true) {
        char choice;
        Utilities::clearScreen();
            std::cout<<"DZIAŁANIA:\ns - Status Postaci\np - Podróż\nb - Sklep\no - Odpocznij\nw - Wyjdź"<<std::endl;
        std::cout<<"-> ";
        std::cin>>choice;
        choice = tolower(choice);
        
        switch (choice) {
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
