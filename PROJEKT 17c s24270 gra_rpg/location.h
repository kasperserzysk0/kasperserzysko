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
    
};

class Location {
    
    std::string name;
    int posX;
    int posY;
    bool heal;
    bool shop;
    bool enemy;
    bool end_game;
    bool item;
    bool win;
    LocationType type;
    
    
public:
    Location(std::string name, int posX, int posY, bool heal, bool shop, bool enemy, bool end_game, bool item, bool win, LocationType type) : name(name), posX(posX), posY(posY), heal(heal), shop(shop), enemy(enemy), end_game(end_game), item(item), win(win), type(type)
    {}
    std::string getName(){return name;}
    bool getEnemy(){return enemy;}
    LocationType getType(){return type;}
    
};


#endif /* location_h */
