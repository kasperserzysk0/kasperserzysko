//
//  items.h
//  PROJEKT 17c s24270 gra_rpg
//
//  Created by Kasper Serżysko on 21/12/2021.
//

#ifndef items_h
#define items_h
#include "item.h"
#include <map>
#include "location.h"

class Items {
    std::map<int, Item*> items_mine;
    
    
    void insertItemsMine(){
        items_mine.insert(std::make_pair(0, new Item("Miecz", 5, fight)));
        items_mine.insert(std::make_pair(1, new Item("Pierścień", 5,  travel)));
        items_mine.insert(std::make_pair(2, new Item("Książka", 5, experience)));
    }
    
public:
    Items(){
        insertItemsMine();
    }
    
    
    Item* itemDrop(LocationType type){
        switch (type) {
            case old_mine:
                return dropItemMine();
                break;
                
            default:
                break;
        }
        return NULL;
    }
    Item* dropItemMine(){
        int random = Utilities::randomItem();
        return items_mine.at(random);
    }
    
   
};




#endif /* items_h */
