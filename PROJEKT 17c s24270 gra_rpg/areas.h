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

            case valley:{
                std::string enemies[5] = {"Bandyta","Najemnik","Bandyta łucznik","Najemny zabójca","Herszt Bandytów"};//przeciwnicy w starej kopalni
                if (random<30) {
                    enemy = enemies[0];
                    hp_lost = 35;
                    exp_gain = 15;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=30 && random<70){
                    enemy = enemies[1];
                    hp_lost = 45;
                    exp_gain = 20;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=70 && random<90){
                    enemy = enemies[2];
                    hp_lost = 65;
                    exp_gain = 30;
                    gold_gain = Utilities::randomNumber(6);

                }else if (random>=90 && random<98){
                    enemy = enemies[3];
                    hp_lost = 80;
                    exp_gain = 45;
                    gold_gain = Utilities::randomNumber(10);

                }else if (random>=98 && random<=100){
                    enemy = enemies[4];
                    hp_lost = 110;
                    exp_gain = 70;
                    gold_gain = Utilities::randomNumber(2);

                }
                break;
            }                          
                case valley_boss:{                //BOSS STAREJ KOPALNI
                enemy = "Południca";
                hp_lost = 200;
                exp_gain = 150;
                gold_gain = 50;
                areas_map.at(coordinatesToString(4,6))->setEnemy(false);
                break;
            }  

            case forest:{                       //LAS
                std::string enemies[5] = {"Leśniczy","Dzik","Wilk","Ghoul","Niedźwiedź"};//przeciwnicy w starej kopalni
                if (random<30) {
                    enemy = enemies[0];
                    hp_lost = 80;
                    exp_gain = 40;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=30 && random<70){
                    enemy = enemies[1];
                    hp_lost = 100;
                    exp_gain = 50;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=70 && random<90){
                    enemy = enemies[2];
                    hp_lost = 130;
                    exp_gain = 60;
                    gold_gain = Utilities::randomNumber(6);

                }else if (random>=90 && random<98){
                    enemy = enemies[3];
                    hp_lost = 165;
                    exp_gain = 80;
                    gold_gain = Utilities::randomNumber(10);

                }else if (random>=98 && random<=100){
                    enemy = enemies[4];
                    hp_lost = 200;
                    exp_gain = 125;
                    gold_gain = Utilities::randomNumber(2);

                }
                break;
            }  

            case forest_boss:{                //BOSS STAREJ KOPALNI
                enemy = "Południca";
                hp_lost = 300;
                exp_gain = 225;
                gold_gain = 100;
                areas_map.at(coordinatesToString(-4,5))->setEnemy(false);
                break;
            }  
            case city:{                       //LAS
                std::string enemies[5] = {"Parobek","Kieszonkowiec","Marynarz","Strażnik","El Szefe"};//przeciwnicy w starej kopalni
                if (random<30) {
                    enemy = enemies[0];
                    hp_lost = 20;
                    exp_gain = 5;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=30 && random<70){
                    enemy = enemies[1];
                    hp_lost = 50;
                    exp_gain = 10;
                    gold_gain = Utilities::randomNumber(4);

                }else if (random>=70 && random<90){
                    enemy = enemies[2];
                    hp_lost = 100;
                    exp_gain = 60;
                    gold_gain = Utilities::randomNumber(6);

                }else if (random>=90 && random<98){
                    enemy = enemies[3];
                    hp_lost = 200;
                    exp_gain = 100;
                    gold_gain = Utilities::randomNumber(10);

                }else if (random>=98 && random<=100){
                    enemy = enemies[4];
                    hp_lost = 250;
                    exp_gain = 150;
                    gold_gain = Utilities::randomNumber(2);

                }
                break;
            }  
            case city_boss:{                //BOSS STAREJ KOPALNI
                enemy = "Kapitan piratów";
                hp_lost = 400;
                exp_gain = 250;
                gold_gain = 400;
                areas_map.at(coordinatesToString(-3,9))->setEnemy(false);
                break;
            }  
            
        }
        data_array[0] = hp_lost;
        data_array[1] = exp_gain;
        data_array[2] = gold_gain;
        std::cout<<"\nNatrafiłeś na przeciwnika: "<<enemy<<".\nStraciłeś "<<hp_lost<<"HP\nZyskałeś: "<<exp_gain<<"EXP i "<<gold_gain<<" złota"<<std::endl;
        //koniec switcha
        return data_array;
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
        areas_map.insert(std::make_pair("-2,0", new Location("jaskinia - pułapka",false,false,false,false,true,false,false, cave)));
        
        //TYP STARA KOPALNIA
        areas_map.insert(std::make_pair("-3,2", new Location("stara kopalnia przejście",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,2", new Location("stara kopalnia - zachód",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,1", new Location("stara kopalnia - podziemny pałac, wejście",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,0", new Location("stara kopalnia - podziemny pałac",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,-1", new Location("stara kopalnia - podziemny pałac, sala tronowa",false,false,false,true,false,false,false, old_mine_boss))); //BOSS STARA KOPALNIA
        areas_map.insert(std::make_pair("-4,3", new Location("stara kopalnia - północ",false,false,false,true,false,false,false, old_mine)));
        areas_map.insert(std::make_pair("-4,-2", new Location("stara kopalnia - królewski magazyn",false,false,false,false,false,true,false, old_mine)));

        //NIZINA
        areas_map.insert(std::make_pair("0,4", new Location("dolina - wejście do kopalni",false,true,false,false,false,false,false, valley)));
        areas_map.insert(std::make_pair("0,5", new Location("dolina - południowe przejście",false,false,false,true,false,false,false, valley)));
        areas_map.insert(std::make_pair("0,6", new Location("dolina - karczma",false,false,true,false,false,false,false, valley)));
        areas_map.insert(std::make_pair("1,6", new Location("dolina - zejście do rzeki",false,false,false,true,false,false,false, valley)));
        areas_map.insert(std::make_pair("2,6", new Location("dolina - wschód",false,false,false,true,false,false,false, valley)));
        areas_map.insert(std::make_pair("3,6", new Location("dolina - głeboka rzeka",false,false,false,false,true,false,false, valley)));
        areas_map.insert(std::make_pair("2,5", new Location("dolina - rzeka",false,false,false,true,false,false,false, valley)));
        areas_map.insert(std::make_pair("3,5", new Location("dolina - most",false,false,false,true,false,false,false, valley)));
        areas_map.insert(std::make_pair("4,5", new Location("dolina - plaża",false,false,false,true,false,false,false, valley)));
        areas_map.insert(std::make_pair("4,6", new Location("dolina - wzgórze",false,false,false,true,false,false,false, valley_boss)));
        areas_map.insert(std::make_pair("5,6", new Location("dolina - stara chata",false,false,true,false,false,false,false, valley)));
        areas_map.insert(std::make_pair("0,7", new Location("dolina - północ",false,false,false,true,false,false,false, valley)));


        //LAS
        areas_map.insert(std::make_pair("-1,6", new Location("las - wejście",false,false,false,true,false,false,false, forest)));
        areas_map.insert(std::make_pair("-2,6", new Location("las - zagajnik",false,false,false,true,false,false,false, forest)));
        areas_map.insert(std::make_pair("-3,6", new Location("las - polana",false,false,false,true,false,false,false, forest)));
        areas_map.insert(std::make_pair("-4,6", new Location("las - kapliczka",false,true,false,false,false,false,false, forest)));
        areas_map.insert(std::make_pair("-4,5", new Location("las - ciemny zagajnik",false,false,false,true,false,false,false, forest_boss)));
        areas_map.insert(std::make_pair("-5,5", new Location("las - mała polana",false,false,false,false,false,true,false, forest)));
        areas_map.insert(std::make_pair("-5,4", new Location("las - jaskinia",false,false,false,false,false,true,false, forest)));
        areas_map.insert(std::make_pair("-6,4", new Location("las - pułapka",false,false,false,false,true,false,false, forest)));
        areas_map.insert(std::make_pair("-4,7", new Location("las - północ",false,false,false,true,false,false,false, forest)));
        areas_map.insert(std::make_pair("-4,8", new Location("las - obrzeża",false,false,false,true,false,false,false, forest)));

        //MIASTO
        areas_map.insert(std::make_pair("0,8", new Location("miasto - wejście południowe",false,false,false,false,false,false,false, city)));
        areas_map.insert(std::make_pair("0,9", new Location("miasto",false,false,true,false,false,false,false, city)));
        areas_map.insert(std::make_pair("0,11", new Location("miasto - świątynia",false,true,false,false,false,false,false, city)));
        areas_map.insert(std::make_pair("1,9", new Location("miasto - brama wschodnia",false,false,false,false,false,false,false, city)));
        areas_map.insert(std::make_pair("-1,9", new Location("miasto - brama zachodnia",false,false,false,true,false,false,false, city)));
        areas_map.insert(std::make_pair("0,10", new Location("miasto - brama północna",false,false,false,true,false,false,false, city)));
        areas_map.insert(std::make_pair("2,9", new Location("miasto - dzielnica wschodnia",false,false,false,true,false,false,false, city)));
        areas_map.insert(std::make_pair("-2,9", new Location("miasto - slumsy",false,false,false,true,false,false,false, city)));
        areas_map.insert(std::make_pair("-2,10", new Location("miasto - dzielnica portowa",false,false,false,true,false,false,false, city)));
        areas_map.insert(std::make_pair("-3,9", new Location("miasto - kryjówka bandytów",false,false,false,true,false,false,false, city_boss)));
        areas_map.insert(std::make_pair("3,9", new Location("miasto - wejście wschodnie",false,false,false,true,false,false,false, city)));
        areas_map.insert(std::make_pair("3,8", new Location("miasto - pułapka",false,false,false,false,true,false,false, city)));
        areas_map.insert(std::make_pair("-4,9", new Location("miasto - koniec",false,false,false,false,false,false,true, city)));
        
    }
    
    
};


#endif /* areas_h */
