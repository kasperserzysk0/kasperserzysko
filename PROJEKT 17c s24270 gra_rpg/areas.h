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
#include <array>

class Areas {
    
    std::map<std::string, Location*> areas_map;         //Mapa posiadająca wszyskie lokalizacje gry

    
    //Funkcja służy do konwertowania koordynatów i zamiany ich na stringa (klucz mapy jest stringiem)
    std::string coordinatesToString(int x, int y){
        return std::to_string(x) + "," + std::to_string(y);
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

    
    
   std::array<int,3> enemyEncounter(LocationType type){
        //LocationType type = location->getType();
        std::array<int, 3> data_array;
        int hp_lost = 0;
        int exp_gain = 0;
        int gold_gain = 0;
        std::string enemy;
        int random = Utilities::randomInt();
        
        //początek switcha
        switch (type) {
                
            case cave:{
                std::string enemies[5] = {"Wielki szczur","Blob","Mrówka gigant","Szkielet","Mały golem"};//przeciwnicy w jaskini
                if (random<30) {
                    enemy = enemies[0];
                    hp_lost = 10;
                    exp_gain = 3;
                    gold_gain = Utilities::randomNumber(2);
                    
                }else if (random>=30 && random<70){
                    enemy = enemies[1];
                    hp_lost = 5;
                    exp_gain = 1;
                    gold_gain = Utilities::randomNumber(2);

                }else if (random>=70 && random<90){
                    enemy = enemies[2];
                    hp_lost = 15;
                    exp_gain = 6;
                    gold_gain = Utilities::randomNumber(2);

                }else if (random>=90 && random<98){
                    enemy = enemies[3];
                    hp_lost = 20;
                    exp_gain = 10;
                    gold_gain = Utilities::randomNumber(6);

                }else if (random>=98 && random<=100){
                    enemy = enemies[4];
                    hp_lost = 50;
                    exp_gain = 30;
                    gold_gain = Utilities::randomNumber(5);

                }
                break;
                
            }       //koniec dla jaskini
                
            case old_mine:{
                std::string enemies[5] = {"Goblin robotnik","Goblin zwiadowca","Goblin wojownik","Goblin szaman","Ogr"};//przeciwnicy w starej kopalni
                if (random<30) {
                    enemy = enemies[0];
                    hp_lost = 10;
                    exp_gain = 3;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=30 && random<70){
                    enemy = enemies[1];
                    hp_lost = 15;
                    exp_gain = 7;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=70 && random<90){
                    enemy = enemies[2];
                    hp_lost = 30;
                    exp_gain = 18;
                    gold_gain = Utilities::randomNumber(6);

                }else if (random>=90 && random<98){
                    enemy = enemies[3];
                    hp_lost = 35;
                    exp_gain = 25;
                    gold_gain = Utilities::randomNumber(10);

                }else if (random>=98 && random<=100){
                    enemy = enemies[4];
                    hp_lost = 85;
                    exp_gain = 55;
                    gold_gain = Utilities::randomNumber(2);

                }
                break;
            }                                   //koniec dla starej kopalni
            case old_mine_boss:{                //BOSS STAREJ KOPALNI
                enemy = "Król Goblinów Abra-Dab";
                hp_lost = 124;
                exp_gain = 100;
                gold_gain = 20;
                areas_map.at(coordinatesToString(-4,-1))->setEnemy(false);
                break;
            }                                   //KONIEC BOSS 
                
            case friendly:
                hp_lost = 0;
                exp_gain = 0;
                gold_gain = 0;
                break;
        }
        data_array[0] = hp_lost;
        data_array[1] = exp_gain;
        data_array[2] = gold_gain;
        std::cout<<"\nNatrafiłeś na przeciwnika: "<<enemy<<".\nStraciłeś "<<hp_lost<<"HP\nZyskałeś: "<<exp_gain<<"EXP i "<<gold_gain<<" złota"<<std::endl;
        //koniec switcha
        return data_array;
    }
    
    
    int trapEncounter(LocationType type){
    
        switch (type) {
            case cave_trap:
                std::cout<<"Sufit korytarza okazał się niestabilny i zawalił się na Ciebie"<<std::endl;
                break;
                
            default:
                break;
        }
        return 100;
    }
    
    
    //wszystkie lokacje
private:
    void add_areas(){
        
        //TYP JASKINIA
        areas_map.insert(std::make_pair("0,0", new Location("jaskinia",true,false,false,false,false,false,false, cave)));
        areas_map.insert(std::make_pair("0,1", new Location("jaskinia - główny korytarz",false,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("1,1", new Location("jaskinia - wschód",false,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("0,2", new Location("jaskinia - północ",false,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("0,3", new Location("jaskinia - wyjście",false,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("-1,2", new Location("jaskinia - zapadnięty korytarz",false,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("-2,2", new Location("jaskinia - podziemne przejście",false,false,false,true,false,false,false, cave)));
        areas_map.insert(std::make_pair("-2,1", new Location("jaskinia - podejrzany pokój",false,false,false,false,false,false,false, cave)));
        areas_map.insert(std::make_pair("-2,0", new Location("jaskinia - pułapka",false,false,false,false,true,false,false, cave_trap)));
        
        //TYP STARA KOPALNIA
        areas_map.insert(std::make_pair("-3,2", new Location("stara kopalnia przejście",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,2", new Location("stara kopalnia - zachód",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,1", new Location("stara kopalnia - podziemny pałac, wejście",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,0", new Location("stara kopalnia - podziemny pałac",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,-1", new Location("stara kopalnia - podziemny pałac, sala tronowa",false,false,false,true,false,false,false, old_mine_boss))); //BOSS STARA KOPALNIA
        areas_map.insert(std::make_pair("-4,3", new Location("stara kopalnia - północ",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,-2", new Location("stara kopalnia - królewski magazyn",false,false,false,false,false,true,false, old_mine)));
    }
};


#endif /* areas_h */
