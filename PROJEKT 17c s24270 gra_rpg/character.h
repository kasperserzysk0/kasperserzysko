//
//  character.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 17/12/2021.
//

#ifndef character_h
#define character_h
#include "areas.h"
#include <map>
#include "utill.h"


class Hero {
    int posX = 0;
    int posY = 0;
    int lvl = 0;
    int max_hp = 100 + 5*lvl;
    int hp = max_hp;
    std::string item;
    Location* current_location;
    std::string location;
    Areas area;
    
    
    void availableLocations(){
        std::string north,south,east,west;
        
        if (area.existCheck(posX, posY+1)){
            north = area.getArea(posX, posY+1)->getName();
        }else north = "-";
        if (area.existCheck(posX, posY-1)){
            south = area.getArea(posX, posY-1)->getName();
        }else south = "-";
        if (area.existCheck(posX+1, posY)){
            east = area.getArea(posX+1, posY)->getName();
        }else east = "-";
        if (area.existCheck(posX-1, posY)){
            west = area.getArea(posX-1, posY)->getName();
        }else west = "-";
        
        std::cout<<"Wybierz kierunek podróży:\nn - Północ ("<<north<<")\ns - Południe ("<<south<<")\ne - Wschód ("<<east<<")\nw - Zachód ("<<west<<")"<<std::endl;
        std::cout<<"-> ";
    }
    
    void event(){
        if (current_location->getEnemy()) {
            hp = hp - area.enemyEncounter(current_location);
        }
    }
    void hpCheck(){
        if(hp<0){
            std::cout<<"Nie żyjesz, koniec gry. Spróbuj ponownie!"<<std::endl;
            std::cout<<"Projekt prostej gry rpg,\nKasper Serżysko styczeń 2022"<<std::endl;
            Utilities::placeHolder();
            std::exit(0);
        }
    }
public:
    Hero(){
        current_location = area.getArea(0, 0);
        location = current_location->getName();
    }
    
    //Funkcja pokazuje szczegóły naszej postaci
    void statusCheckOption(){
        Utilities::clearScreen();
        std::cout<<"-STATUS-"<<std::endl;
        std::cout<<"Poziom: "<<lvl<<std::endl;
        std::cout<<"HP: "<<hp<<"/"<<max_hp<<std::endl;
        std::cout<<"Aktualna lokalizacja: "<<location<<std::endl;
        std::cout<<"Wpisz cokolwiek, aby wrócić"<<std::endl;
        std::cout<<"->";
        std::string a;
        std::cin >>a;
        Utilities::placeHolder();
    }
    
    //SYSTEM PODRÓZY
    void travelOption(){
        char choice;
        bool end = true;
        
        
        while (end) {
            Utilities::clearScreen();
            availableLocations();
            std::cin>>choice;
            choice = tolower(choice);
            /*
             Po każdym wyborze funkcja existCheck sprawdza, czy "nie wyszliśmy" poza mapę, jeślie nie, to zmienia naszą pozycję (posX lub posY), znajduje tą pozycje na mapie (z headera "areas.h") i ustawia ją jako naszą current_location.
             */
             
            switch (choice) {
                case 'n':
                    if (area.existCheck(posX, posY+1)) {
                        end = false;
                        posY = posY + 1;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                        
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                case 's':
                    if (area.existCheck(posX, posY-1)) {
                        end = false;
                        posY = posY - 1;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                        
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                case 'e':
                    if (area.existCheck(posX+1, posY)) {
                        end = false;
                        posX = posX + 1;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                        
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                case 'w':
                    if (area.existCheck(posX-1, posY)) {
                        end = false;
                        posX = posX - 1;;
                        current_location = area.getArea(posX, posY);
                        location = current_location->getName();
                        
                    }else{
                        Utilities::errorWrongWay();
                    }
                    break;
                default:
                    Utilities::errorMessage();
                    break;
            }
            if (!end) {
                std::cout<<"Dotarłeś do " <<location<<std::endl;
                Utilities::placeHolder();
                event();
                hpCheck();
                Utilities::placeHolder();
            }
        }
    }
    //travel end
    
    //Funkcja odpoczynku. Podczas odpoczynku istnieje szansa zostania zaatakowanym, jeśli znajdujemy się w lokalizacji z przeciwnikiem. Posiadamy również szanse na odzyskanie większej ilości zdrowia niż normalnie
    
        void restOption(){
            int hp_healed;
            if(current_location->getEnemy()){                               //jeśli jesteśmy w lokalizacji z przeciwnikami
                int random = Utilities::randomInt();
                if (random > 80){                                           //warunek ataku z zaskoczenia
                    std::cout<<"Zostałes zaatakowany podczas odpoczynku"<<std::endl;
                    hp = hp-area.enemyEncounter(current_location);
                    hpCheck();
                }else if(random < 20){
                    hp_healed = 40;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp - max_hp;
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }else{
                    hp_healed = 25;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp - max_hp;
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }
            }else{                                                             //dla lokalizacji bez przeciwników
                int random = Utilities::randomInt();
                if(random < 30){
                    hp_healed = 40;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp - max_hp;
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty jak nigdy dotąd, zyskałeś dodatkowe zdrowie.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty jak nigdy dotąd, zyskałeś dodatkowe zdrowie.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }else{
                    hp_healed = 25;
                    hp = hp + hp_healed;
                    if (hp>max_hp){
                        hp_healed = hp - max_hp;
                        hp = max_hp;
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                    }else
                        std::cout<<"Obudziłeś się wypoczęty.\nOdzyskałeś "<<hp_healed<<" HP"<<std::endl;
                }
            }
        }
};

#endif /* character_h */
