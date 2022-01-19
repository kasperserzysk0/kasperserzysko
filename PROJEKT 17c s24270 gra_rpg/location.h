//
//  Location.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 17/12/2021.
//

#ifndef location_h
#define location_h

enum LocationType{
    friendly,
    cave,
    old_mine,
    old_mine_boss,
    valley,
    valley_boss,
    forest,
    forest_boss,
    city,
    city_boss
};

class Location {
    
    std::string name;
    bool discovered;
    bool heal;
    bool shop;
    bool enemy;
    bool end_game;
    bool item;
    bool win;
    LocationType type;
    
    
public:
    Location(std::string name, bool discovered, bool heal, bool shop, bool enemy, bool end_game, bool item, bool win, LocationType type) : name(name), discovered(discovered), heal(heal), shop(shop), enemy(enemy), end_game(end_game), item(item), win(win), type(type)
    {}
    std::string getName(){return name;}
    bool getDiscovered(){return discovered;}
    bool getEnemy(){return enemy;}
    bool getEndGame(){return end_game;}
    bool getItem(){return item;}
    bool getHeal(){return heal;}
    bool getShop(){return shop;}
    bool getWin(){return win;}
    LocationType getType(){return type;}
    
    
    void setEnemy(bool enemy){
        this->enemy = enemy;
    }
    void setDiscovered(bool discovered){
        this->discovered = discovered;
    }
    void setItem(bool item){
        this->item = item;
    }
    
};


#endif /* location_h */
