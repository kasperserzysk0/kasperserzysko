//
//  areas.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 17/12/2021.
//

#ifndef areas_h
#define areas_h
#include "utill.h"
#include "location.h"
#include <map>
#include <string>

class Areas {
    
    //Mapa posiadająca wszyskie lokalizacje nasej gry!!!
    std::map<std::string, Location*> areas_map;
    
    
    void add_areas(){
        areas_map.insert(std::make_pair("0,0", new Location("jaskinia",0,0,false,false,false,false,false,false, friendly)));
        areas_map.insert(std::make_pair("0,1", new Location("jaskinia północ",0,1,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("1,1", new Location("jaskinia wschód",1,1,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("0,2", new Location("jaskinia wyjście",0,2,false,false,true,false,false,false, cave)));
    }
    
    //Funkcja służy do konwertowania koordynatów i zamiany ich na stringa (klucz mapy jest stringiem)
    std::string coordinatesToString(int x, int y){
        return std::to_string(x) + "," + std::to_string(y);
    }
    
    void enemyEncounterHelp(){
        
    }
    
public:
    Areas(){
        add_areas();
    }
    
    Location* getArea(int x, int y){return areas_map.at(coordinatesToString(x,y));}
    
    //Sprawdza, czy dane koordynaty znajdują się w mapie
    bool existCheck(int x, int y){
        if (areas_map.find(coordinatesToString(x, y)) == areas_map.end()){return false;
        }else return true;}
    
    
    //Funkcja dla każdego rodzaju lokacji, przyporządkowuje losowego przeciwnika oraz zwraca ilość życia, które przeciwnicy zabiorą bohaterowi po spotkaniu
    
    int enemyEncounter(Location* location){
        LocationType type = location->getType();
        int hp_lost = 0;
        std::string enemy;
        int random = Utilities::randomInt();
        
        //początek switcha
        switch (type) {
                
            case cave:{
                std::string enemies[5] = {"Wielki szczur","Blob","Mrówka gigant","Szkielet","Shrek"};//przeciwnicy w jaskini
                if (random<30) {
                    enemy = enemies[0];
                    hp_lost = 10;
                    std::cout<<"\nNatrafiłeś na przeciwnika: "<<enemy<<".\nStraciłeś "<<hp_lost<<"HP"<<std::endl;
                }else if (random>=30 && random<70){
                    enemy = enemies[1];
                    hp_lost = 5;
                    std::cout<<"\nNatrafiłeś na przeciwnika: "<<enemy<<".\nStraciłeś "<<hp_lost<<"HP"<<std::endl;
                }else if (random>=70 && random<90){
                    enemy = enemies[2];
                    hp_lost = 15;
                    std::cout<<"\nNatrafiłeś na przeciwnika: "<<enemy<<".\nStraciłeś "<<hp_lost<<"HP"<<std::endl;
                }else if (random>=90 && random<98){
                    enemy = enemies[3];
                    hp_lost = 20;
                    std::cout<<"\nNatrafiłeś na przeciwnika: "<<enemy<<".\nStraciłeś "<<hp_lost<<"HP"<<std::endl;
                }else if (random>=98 && random<=100){
                    enemy = enemies[4];
                    hp_lost = 50;
                    std::cout<<"\nNatrafiłeś na przeciwnika: "<<enemy<<".\nStraciłeś "<<hp_lost<<"HP"<<std::endl;
                }
                break;
            }
            case friendly:
                hp_lost = 0;
                break;
        }
        //koniec switcha
        return hp_lost;
    }
};


#endif /* areas_h */
