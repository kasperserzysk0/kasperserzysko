//
//  item.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 21/12/2021.
//

#ifndef item_h
#define item_h

enum ItemType{
    fight,
    experience,
    travel,
};

class Item {
    std::string name;
    ItemType type;
    int power;
    
    
public:
    Item(std::string name, int power, ItemType type) : name(name), type(type), power(power)
    {}
    
    int getPower(){return power;}
    
};


#endif /* item_h */
